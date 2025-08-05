#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10
// Tamanho dos navios
#define TAMANHO_NAVIO 3
// Símbolos para representar o tabuleiro
#define AGUA '0'
#define NAVIO '3'

int main() {
    // Inicializa o tabuleiro com água (0)
    char tabuleiro[TAMANHO][TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1 - Horizontal (linha 2, coluna 3)
    int linha_navio1 = 2;
    int coluna_navio1 = 3;
    
    // Verifica se o navio cabe no tabuleiro
    if (coluna_navio1 + TAMANHO_NAVIO <= TAMANHO) {
        for (int j = coluna_navio1; j < coluna_navio1 + TAMANHO_NAVIO; j++) {
            tabuleiro[linha_navio1][j] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal não cabe nas coordenadas especificadas.\n");
        return 1;
    }

    // Navio 2 - Vertical (linha 5, coluna 7)
    int linha_navio2 = 5;
    int coluna_navio2 = 7;
    
    // Verifica se o navio cabe no tabuleiro
    if (linha_navio2 + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = linha_navio2; i < linha_navio2 + TAMANHO_NAVIO; i++) {
            // Verifica sobreposição com o navio horizontal
            if (tabuleiro[i][coluna_navio2] == NAVIO) {
                printf("Erro: Navios estão se sobrepondo.\n");
                return 1;
            }
            tabuleiro[i][coluna_navio2] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical não cabe nas coordenadas especificadas.\n");
        return 1;
    }

    // Imprime o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n"); // Cabeçalho das colunas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}