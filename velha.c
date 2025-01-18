#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE 3

void geraTabuleiro(char *tabuleiro);
void jogadaJogador(char *tabuleiro);
void jogadaComputador(char *tabuleiro);
int verificaVencedor(char *tabuleiro);
int tabuleiroCompleto(char *tabuleiro);

int main() {
    char start;
    
    printf("Pressione I para iniciar: ");
    scanf(" %c", &start);
    start = toupper(start);

    while (1) {
        if (start == 'I' || start == 'R') {
            char tabuleiro[SIZE * SIZE];
            for (int i = 0; i < SIZE * SIZE; i++) {
                tabuleiro[i] = '1' + i;
            }

            int vencedor = 0;
            while (!vencedor && !tabuleiroCompleto(tabuleiro)) {
                // Atualiza o tabuleiro
                geraTabuleiro(tabuleiro);

                // Registra a jogada do jogador
                jogadaJogador(tabuleiro);

                // Verifica se o jogador venceu
                vencedor = verificaVencedor(tabuleiro);
                if (vencedor || tabuleiroCompleto(tabuleiro)) break;

                // Registra a jogada do computador
                jogadaComputador(tabuleiro);

                // Verifica se o computador venceu
                vencedor = verificaVencedor(tabuleiro);
                if (vencedor || tabuleiroCompleto(tabuleiro)) break;
            }

            geraTabuleiro(tabuleiro);
            if (vencedor == 1) {
                printf("Jogador X venceu!\n");
            } else if (vencedor == 2) {
                printf("Jogador O venceu!\n");
            } else {
                printf("Empate!\n");
            }
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

    return 0;
}

void geraTabuleiro(char *tabuleiro) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        printf("%c ", tabuleiro[i]);
        if ((i + 1) % SIZE == 0) {
            printf("\n");
        }
    }
}

// Função que registra a jogada do jogador
void jogadaJogador(char *tabuleiro) {
    int pos;
    printf("Escolha a casa, jogador X: ");
    scanf("%d", &pos);
    if (pos >= 1 && pos <= 9 && tabuleiro[pos - 1] != 'X' && tabuleiro[pos - 1] != 'O') {
        tabuleiro[pos - 1] = 'X';
    } else {
        printf("Posição inválida! Tente novamente.\n");
        jogadaJogador(tabuleiro);
    }
}

// Função que registra a jogada do computador
void jogadaComputador(char *tabuleiro) {
    // Garante a aleatoriedade da jogada do computador
    srand(time(NULL));
    int pos;

    // Faça enquanto a posição escolhida pelo computador estiver preenchida com 'X' ou 'O'
    do {
        pos = rand() % 9;
    } while (tabuleiro[pos] == 'X' || tabuleiro[pos] == 'O');
    tabuleiro[pos] = 'O';
}

int verificaVencedor(char *tabuleiro) {
    for (int i = 0; i < SIZE; i++) {
        // Verifica a se linha está preenchida com o mesmo símbolo
        if (tabuleiro[i * SIZE] == tabuleiro[i * SIZE + 1] && tabuleiro[i * SIZE + 1] == tabuleiro[i * SIZE + 2]) {
            return tabuleiro[i * SIZE] == 'X' ? 1 : 2;
        }
        // Verifica se a coluna está preenchida com o mesmo símbolo
        if (tabuleiro[i] == tabuleiro[i + SIZE] && tabuleiro[i + SIZE] == tabuleiro[i + 2 * SIZE]) {
            return tabuleiro[i] == 'X' ? 1 : 2;
        }
    }

    if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8]) {
        return tabuleiro[0] == 'X' ? 1 : 2;
    }
    if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6]) {
        return tabuleiro[2] == 'X' ? 1 : 2;
    }
    return 0;
}

int tabuleiroCompleto(char *tabuleiro) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (tabuleiro[i] != 'X' && tabuleiro[i] != 'O') {
            return 0;
        }
    }
    return 1;
}
