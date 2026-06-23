#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *known_words[12] = {
    "be","our","rum","will",
    "dead","hook","ship","blood",
    "sable","avenge","parrot","captain"
};

char line_buf[210];        
char orig_line[210];      
char *cw[210];             
int cw_cnt;              

bool cipher_letters_present[26]; 
int cipher_letters_count;         

int map_ct_to_pt[26];      
bool used_pt[26];         
bool used_pos[210];        

char candidate_plain[210];
char unique_plain[210];  
bool have_solution = false;    
bool multiple_solutions = false;

void apply_mapping_and_store(char *out) {
    int p = 0;
    for (int i = 0; orig_line[i]; ++i) {
        if (orig_line[i] >= 'a' && orig_line[i] <= 'z') {
            int c = orig_line[i] - 'a';
            int m = map_ct_to_pt[c];
            if (m < 0) return; 
            out[p++] = (char)('a' + m);
        } else {
            out[p++] = orig_line[i];
        }
    }
    out[p] = '\0';
}

void backtrack_assign(char **words_in_subset, int n, int idx, int *pos_candidates_counts, int pos_candidates[][210]) {
    if (multiple_solutions) return;

    if (idx == n) {
        int mapped_count = 0;
        for (int c = 0; c < 26; ++c)
            if (cipher_letters_present[c] && map_ct_to_pt[c] != -1) mapped_count++;
        if (mapped_count != cipher_letters_count) return;

        apply_mapping_and_store(candidate_plain);
        if (!have_solution) {
            strcpy(unique_plain, candidate_plain);
            have_solution = true;
        } else {
            if (strcmp(unique_plain, candidate_plain) != 0) {
                multiple_solutions = true;
            }
        }
        return;
    }

    char *w = words_in_subset[idx];
    int wlen = strlen(w);

    for (int pi = 0; pi < pos_candidates_counts[idx]; ++pi) {
        int pos = pos_candidates[idx][pi];
        if (used_pos[pos]) continue;

        bool conflict = false;
        int changes_ct[26], changes_ct_n = 0;
        int changes_pt[26], changes_pt_n = 0;

        char *cwword = cw[pos];
        for (int j = 0; j < wlen; ++j) {
            int c = cwword[j] - 'a';
            int p = w[j] - 'a';
            if (map_ct_to_pt[c] == -1) {
                if (used_pt[p]) { conflict = true; break; }
                map_ct_to_pt[c] = p;
                used_pt[p] = true;
                changes_ct[changes_ct_n++] = c;
                changes_pt[changes_pt_n++] = p;
            } else {
                if (map_ct_to_pt[c] != p) { conflict = true; break; }
            }
        }

        if (!conflict) {
            used_pos[pos] = true;
            backtrack_assign(words_in_subset, n, idx+1, pos_candidates_counts, pos_candidates);
            used_pos[pos] = false;
        }

        for (int z = 0; z < changes_ct_n; ++z) map_ct_to_pt[changes_ct[z]] = -1;
        for (int z = 0; z < changes_pt_n; ++z) used_pt[changes_pt[z]] = false;

        if (multiple_solutions) return;
    }
}

int main() {
    if (!fgets(line_buf, sizeof(line_buf), stdin)) return 0;
    int L = strlen(line_buf);
    if (L > 0 && line_buf[L-1] == '\n') line_buf[L-1] = '\0';
    strncpy(orig_line, line_buf, sizeof(orig_line));
    orig_line[sizeof(orig_line)-1] = '\0';

    char work[210];
    strncpy(work, line_buf, sizeof(work));
    work[sizeof(work)-1] = '\0';

    cw_cnt = 0;
    char *tok = strtok(work, " ");
    while (tok) {
        cw[cw_cnt++] = tok;
        tok = strtok(NULL, " ");
    }

    for (int i = 0; i < 26; ++i) cipher_letters_present[i] = false;
    cipher_letters_count = 0;
    for (int i = 0; i < cw_cnt; ++i) {
        for (int j = 0; cw[i][j]; ++j) {
            int c = cw[i][j] - 'a';
            if (!cipher_letters_present[c]) {
                cipher_letters_present[c] = true;
                cipher_letters_count++;
            }
        }
    }

    int total_masks = 1 << 12;
    for (int mask = 1; mask < total_masks; ++mask) {
        bool used_letters[26] = {0};
        int distinct_in_subset = 0;
        int subset_count = 0;
        for (int i = 0; i < 12; ++i) if (mask & (1<<i)) {
            subset_count++;
            const char *w = known_words[i];
            for (int j = 0; w[j]; ++j) {
                int p = w[j]-'a';
                if (!used_letters[p]) {
                    used_letters[p] = true;
                    distinct_in_subset++;
                }
            }
        }
        if (distinct_in_subset != cipher_letters_count) continue;

        char *words_in_subset[12];
        int wi = 0;
        for (int i = 0; i < 12; ++i) if (mask & (1<<i)) {
            words_in_subset[wi++] = (char*)known_words[i];
        }

        int pos_candidates_counts[12];
        int pos_candidates[12][210];
        bool any_zero = false;
        for (int k = 0; k < wi; ++k) {
            pos_candidates_counts[k] = 0;
            int wlen = strlen(words_in_subset[k]);
            for (int p = 0; p < cw_cnt; ++p) {
                if ((int)strlen(cw[p]) == wlen) {
                    pos_candidates[k][pos_candidates_counts[k]++] = p;
                }
            }
            if (pos_candidates_counts[k] == 0) { any_zero = true; break; }
        }
        if (any_zero) continue;

        for (int c = 0; c < 26; ++c) map_ct_to_pt[c] = -1;
        for (int p = 0; p < 26; ++p) used_pt[p] = false;
        for (int p = 0; p < cw_cnt; ++p) used_pos[p] = false;

        for (int a = 0; a < wi; ++a) {
            for (int b = a+1; b < wi; ++b) {
                if (pos_candidates_counts[b] < pos_candidates_counts[a]) {
                    char *tmpw = words_in_subset[a];
                    words_in_subset[a] = words_in_subset[b];
                    words_in_subset[b] = tmpw;
                    int tmpc = pos_candidates_counts[a];
                    pos_candidates_counts[a] = pos_candidates_counts[b];
                    pos_candidates_counts[b] = tmpc;
                    for (int z = 0; z < 210; ++z) {
                        int t = pos_candidates[a][z];
                        pos_candidates[a][z] = pos_candidates[b][z];
                        pos_candidates[b][z] = t;
                    }
                }
            }
        }

        backtrack_assign(words_in_subset, wi, 0, pos_candidates_counts, pos_candidates);
        if (multiple_solutions) break;
    }

    if (!have_solution || multiple_solutions) {
        printf("Impossible\n");
    } else {
        printf("%s\n", unique_plain);
    }

    return 0;
}

