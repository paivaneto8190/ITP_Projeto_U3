#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

// Função para verificar se é seguro colocar uma dama em (linha, coluna)
bool posicaoSegura(char **tabuleiro, int linha, int coluna, int tamanho) {

    // Verifica a linha à esquerda
    for (int i = 0; i < coluna; i++) {
        if (tabuleiro[linha][i] == 'D') {
            return false;
        }
    }

    // Verifica a diagonal superior esquerda
    for (int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 'D') {
            return false;
        }
    }

    // Verifica a diagonal inferior esquerda
    for (int i = linha, j = coluna; i < tamanho && j >= 0; i++, j--) {
        if (tabuleiro[i][j] == 'D') {
            return false;
        }
    }
    
    return true;
}

// Função principal para resolver o problema usando backtracking
bool resolverNQueens(char **tabuleiro, int coluna, int tamanho) {
    // Caso base: todas as damas foram colocadas
    if (coluna >= tamanho) {
        return true;
    }

    // Tenta colocar uma dama em cada linha da coluna atual
    for (int i = 0; i < tamanho; i++) {
        if (posicaoSegura(tabuleiro, i, coluna, tamanho)) {
            tabuleiro[i][coluna] = 'D'; // Coloca a dama

            // Chama a função recursivamente para a próxima coluna
            if (resolverNQueens(tabuleiro, coluna + 1, tamanho)) {
                return true;
            }
            // Se colocar a dama não resultar em solução, remove a dama
            tabuleiro[i][coluna] = '.';
        }
    }
    // Caso nenhuma posição seja válida
    return false;
}

// Função para inicializar e imprimir o tabuleiro
void definirNQueens(int tamanho) {
    // Aloca memória dinamicamente para o tabuleiro
    char **tabuleiro = (char **)malloc(tamanho * sizeof(char *));
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[i] = (char *)malloc(tamanho * sizeof(char));
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Resolver N-Queens e imprimir o resultado
    if (resolverNQueens(tabuleiro, 0, tamanho)) {
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Nao ha solucao para este tamanho de tabuleiro.\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < tamanho; i++) free(tabuleiro[i]);
    free(tabuleiro);
}

int main() {
    char start;
    printf("Digite 'I' para iniciar: ");
    scanf(" %c", &start);
    start = toupper(start);


    while(1){
        if (start == 'I' || start == 'R') {
            int tamanho;
            printf("Digite o tamanho do tabuleiro: ");
            scanf("%d", &tamanho);

            definirNQueens(tamanho);

            sleep(1);
        }

        // Solicita novamente a opção do usuário
        printf("Pressione R para reiniciar ou F para finalizar: ");
        scanf(" %c", &start);
        start = toupper(start);

                if (start == 'R'){
            printf("Reiniciando o jogo...\n");
            sleep(1);
            system("cls");
        }

        if (start == 'F') {
            printf("Jogo finalizado!\n");
            sleep(1);
            break;
        }
    }
}