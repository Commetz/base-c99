// 3267 Beecrowd - Passeio no Penhasco
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>   
#include <inttypes.h> 

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884L
#endif

#define INF_L 1e100L    
#define EPS   1e-12L     

typedef struct {
    long double chave; 
    int vertice;      
} NoHeap;

typedef struct {
    NoHeap *dados;   
    int tamanho;    
    int capacidade;
    int sentido;     
} FilaPrioridade;

static FilaPrioridade *criar_fila(int cap, int sentido) {
    FilaPrioridade *f = malloc(sizeof(FilaPrioridade));
    f->capacidade = cap + 5;
    f->dados = malloc(sizeof(NoHeap) * (f->capacidade));
    f->tamanho = 0;
    f->sentido = sentido;
    return f;
}

static void empilhar(FilaPrioridade *f, long double chave, int vertice) {
    if (f->tamanho + 2 >= f->capacidade) {
        f->capacidade *= 2;
        f->dados = realloc(f->dados, sizeof(NoHeap) * f->capacidade);
    }
    int i = ++f->tamanho;
    f->dados[i].chave = chave;
    f->dados[i].vertice = vertice;

    while (i > 1) {
        int p = i >> 1;
        long double kp = f->dados[p].chave;
        long double ki = f->dados[i].chave;
        bool melhor = (f->sentido == 1) ? (ki < kp) : (ki > kp);
        if (!melhor) break;
        NoHeap tmp = f->dados[p];
        f->dados[p] = f->dados[i];
        f->dados[i] = tmp;
        i = p;
    }
}

static NoHeap desempilhar(FilaPrioridade *f) {
    NoHeap topo = f->dados[1];
    f->dados[1] = f->dados[f->tamanho--];
    int i = 1;
    while (1) {
        int l = i << 1, r = l + 1, melhor = i;
        if (l <= f->tamanho) {
            bool melhor_l = (f->sentido == 1) ? (f->dados[l].chave < f->dados[melhor].chave)
                                             : (f->dados[l].chave > f->dados[melhor].chave);
            if (melhor_l) melhor = l;
        }
        if (r <= f->tamanho) {
            bool melhor_r = (f->sentido == 1) ? (f->dados[r].chave < f->dados[melhor].chave)
                                             : (f->dados[r].chave > f->dados[melhor].chave);
            if (melhor_r) melhor = r;
        }
        if (melhor == i) break;
        NoHeap tmp = f->dados[i];
        f->dados[i] = f->dados[melhor];
        f->dados[melhor] = tmp;
        i = melhor;
    }
    return topo;
}

static void liberar_fila(FilaPrioridade *f) {
    free(f->dados);
    free(f);
}

static inline int indice(int x, int y, int larg) {
    return y * larg + x;
}


int main() {
    long double amplitude, tempo_travessia;
    if (scanf("%Lf %Lf", &amplitude, &tempo_travessia) != 2) return 0;

    int largura, altura_grid, casa_x, casa_y;
    if (scanf("%d %d %d %d", &largura, &altura_grid, &casa_x, &casa_y) != 4) return 0;

    int N = largura * altura_grid;

    int *alturas = malloc(sizeof(int) * N);
    for (int y = 0; y < altura_grid; ++y) {
        for (int x = 0; x < largura; ++x) {
            int h;
            scanf("%d", &h);
            alturas[indice(x, y, largura)] = h;
        }
    }

    const long double TOTAL_SEGUNDOS = 12.0L * 3600.0L; 
    const long double OMEGA = M_PI / 6.0L; 

    long double *inicio_seguro = malloc(sizeof(long double) * N);
    long double *fim_seguro = malloc(sizeof(long double) * N);

    for (int i = 0; i < N; ++i) {
        long double altura_m = (long double)alturas[i] / 1000.0L;

        long double C = 2.0L * altura_m / amplitude - 1.0L;

        if (C <= -1.0L + 1e-15L) {
            inicio_seguro[i] = 1.0L;
            fim_seguro[i] = 0.0L;
        } else if (C >= 1.0L - 1e-15L) {
            inicio_seguro[i] = 0.0L;
            fim_seguro[i] = TOTAL_SEGUNDOS;
        } else {
            if (C > 1.0L) C = 1.0L;
            if (C < -1.0L) C = -1.0L;

            long double alpha = acosl(C); 
            long double horas_inicio = alpha / OMEGA;
            long double horas_fim = 12.0L - horas_inicio;
            long double seg_inicio = horas_inicio * 3600.0L;
            long double seg_fim = horas_fim * 3600.0L;

            inicio_seguro[i] = seg_inicio + 3600.0L + 1e-10L;
            fim_seguro[i] = seg_fim - 1e-10L;

            if (fim_seguro[i] < inicio_seguro[i]) {
                inicio_seguro[i] = 1.0L;
                fim_seguro[i] = 0.0L;
            }
        }
    }

    long double *menor_tempo = malloc(sizeof(long double) * N);
    long double *maior_tempo = malloc(sizeof(long double) * N);
    for (int i = 0; i < N; ++i) {
        menor_tempo[i] = INF_L;
        maior_tempo[i] = -INF_L;
    }

    int casa = indice(casa_x, casa_y, largura);

    menor_tempo[casa] = 0.0L;
    FilaPrioridade *fila_ida = criar_fila(N + 5, 1);
    empilhar(fila_ida, menor_tempo[casa], casa);

    while (fila_ida->tamanho > 0) {
        NoHeap nh = desempilhar(fila_ida);
        long double t_atual = nh.chave;
        int u = nh.vertice;

        if (t_atual > menor_tempo[u] + EPS) continue;

        int ux = u % largura;
        int uy = u / largura;

        const int dxs[4] = {1, -1, 0, 0};
        const int dys[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; ++k) {
            int nx = ux + dxs[k];
            int ny = uy + dys[k];
            if (nx < 0 || nx >= largura || ny < 0 || ny >= altura_grid) continue;

            int v = indice(nx, ny, largura);

            if (llabs((long long)alturas[v] - (long long)alturas[u]) > 1000LL) continue;

            long double inicio_comum = fmaxl(inicio_seguro[u], inicio_seguro[v]);
            long double fim_comum = fminl(fim_seguro[u], fim_seguro[v]) - tempo_travessia;
            if (fim_comum + EPS < inicio_comum) continue;

            long double t_partida = (t_atual > inicio_comum) ? t_atual : inicio_comum;
            if (t_partida <= fim_comum + EPS) {
                long double t_chegada = t_partida + tempo_travessia;
                if (t_chegada + EPS < menor_tempo[v]) {
                    menor_tempo[v] = t_chegada;
                    empilhar(fila_ida, t_chegada, v);
                }
            }
        }
    }
    liberar_fila(fila_ida);

    maior_tempo[casa] = fim_seguro[casa];
    FilaPrioridade *fila_volta = criar_fila(N + 5, -1);
    empilhar(fila_volta, maior_tempo[casa], casa);

    while (fila_volta->tamanho > 0) {
        NoHeap nh = desempilhar(fila_volta);
        long double t_atual = nh.chave;
        int v = nh.vertice;

        if (t_atual + EPS < maior_tempo[v]) continue;

        int vx = v % largura;
        int vy = v / largura;

        const int dxs[4] = {1, -1, 0, 0};
        const int dys[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; ++k) {
            int ux = vx + dxs[k];
            int uy = vy + dys[k];
            if (ux < 0 || ux >= largura || uy < 0 || uy >= altura_grid) continue;

            int u = indice(ux, uy, largura);

            if (llabs((long long)alturas[u] - (long long)alturas[v]) > 1000LL) continue;

            long double inicio_comum = fmaxl(inicio_seguro[u], inicio_seguro[v]);
            long double fim_comum = fminl(fim_seguro[u], fim_seguro[v]) - tempo_travessia;
            if (fim_comum + EPS < inicio_comum) continue;

            long double t_partida_max = fim_comum;
            long double cap = t_atual - tempo_travessia;
            if (cap < t_partida_max) t_partida_max = cap;

            if (t_partida_max + EPS >= inicio_comum) {
                if (t_partida_max > maior_tempo[u] + EPS) {
                    maior_tempo[u] = t_partida_max;
                    empilhar(fila_volta, maior_tempo[u], u);
                }
            }
        }
    }
    liberar_fila(fila_volta);

    long double melhor_distancia = 0.0L;
    for (int y = 0; y < altura_grid; ++y) {
        for (int x = 0; x < largura; ++x) {
            int i = indice(x, y, largura);
            if (menor_tempo[i] < INF_L/2 && maior_tempo[i] > -INF_L/2 &&
                menor_tempo[i] <= maior_tempo[i] + 1e-9L) {

                long double dx = (long double)(x - casa_x);
                long double dy = (long double)(y - casa_y);
                long double dist = sqrtl(dx*dx + dy*dy) * 10.0L;
                if (dist > melhor_distancia) melhor_distancia = dist;
            }
        }
    }

    printf("%.8Lf\n", melhor_distancia);

    free(alturas);
    free(inicio_seguro);
    free(fim_seguro);
    free(menor_tempo);
    free(maior_tempo);

    return 0;
}
