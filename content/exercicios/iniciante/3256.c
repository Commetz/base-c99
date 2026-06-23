#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int adj[MAXN][4];
int deg[MAXN];
int cor[MAXN]; 
int vizinhosDeMesmaCor[MAXN];

int main() {
    int n, m;
    
    // Leitura principal
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Inicialização do estado "indefinido" (-1)
    for (int i = 1; i <= n; ++i) {
        cor[i] = -1;
        vizinhosDeMesmaCor[i] = 0;
        deg[i] = 0;
    }

    // Leitura das conexões
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        if (deg[u] < 4) adj[u][deg[u]++] = v;
        if (deg[v] < 4) adj[v][deg[v]++] = u;
    }

    // Lógica determinística inspirada no autor original do problema
    for (int v = 1; v <= n; ++v) {
        int vizinhosDeCorZero = 0;
        
        // Conta os vizinhos que já estão na cor 0
        for (int i = 0; i < deg[v]; ++i) {
            int vizinho = adj[v][i];
            if (cor[vizinho] == 0) {
                vizinhosDeCorZero++;
            }
        }

        // Define a cor alvo com base na contagem
        int corAlvo = (vizinhosDeCorZero <= 1) ? 0 : 1;
        int verticeAtual = v;

        // Propaga as mudanças de cor em cascata (efeito dominó)
        while (verticeAtual != 0) {
            cor[verticeAtual] = corAlvo;
            int proximoVertice = 0;

            for (int i = 0; i < deg[verticeAtual]; ++i) {
                int v2 = adj[verticeAtual][i];
                
                if (cor[v2] == corAlvo) {
                    vizinhosDeMesmaCor[verticeAtual]++;
                    vizinhosDeMesmaCor[v2]++;
                    
                    // Se o vizinho estourou o limite de conflitos (2)
                    if (vizinhosDeMesmaCor[v2] == 2) {
                        proximoVertice = v2;
                        
                        // Desfazer contagem do vértice v2 que estourou
                        for (int j = 0; j < deg[v2]; ++j) {
                            int v3 = adj[v2][j];
                            if (cor[v3] == corAlvo) {
                                vizinhosDeMesmaCor[v2]--;
                                vizinhosDeMesmaCor[v3]--;
                            }
                        }
                    }
                }
            }

            // Alterna a cor e segue para arrumar o vizinho que estourou
            corAlvo = 1 - corAlvo;
            verticeAtual = proximoVertice;
        }
    }

    // Identifica se 1 ou 2 grupos foram criados no total
    int tem_0 = 0, tem_1 = 0;
    for (int i = 1; i <= n; ++i) {
        if (cor[i] == 0) tem_0 = 1;
        if (cor[i] == 1) tem_1 = 1;
    }

    // Exibição da saída padronizada (se todos ficaram com 0, apenas 1 grupo é exibido)
    if (tem_1 == 0) {
        printf("1\n");
        for (int i = 1; i <= n; ++i) {
            printf("%d%s", i, (i == n) ? "" : " ");
        }
        printf("\n");
    } else {
        printf("2\n");
        
        // Imprime o Grupo de cor 0
        int first = 1;
        for (int i = 1; i <= n; ++i) {
            if (cor[i] == 0) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
        
        // Imprime o Grupo de cor 1
        first = 1;
        for (int i = 1; i <= n; ++i) {
            if (cor[i] == 1) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
