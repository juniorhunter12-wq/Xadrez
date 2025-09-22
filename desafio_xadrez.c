#include <stdio.h>


// =======================
// FUNÇÕES RECURSIVAS
// =======================

// Torre: move n casas para a direita
void moverTorre(int casas) {
    if (casas == 0) return; // condição de parada
    printf("Direita\n");
    moverTorre(casas - 1); // chamada recursiva
}

// Rainha: move n casas para a esquerda
void moverRainha(int casas) {
    if (casas == 0) return; // condição de parada
    printf("Esquerda\n");
    moverRainha(casas - 1); // chamada recursiva
}

// Bispo: recursivo + loops aninhados
void moverBispo(int casas) {
    if (casas == 0) return; // condição de parada

    // Loop externo (movimento vertical - Cima)
    for (int i = 1; i <= 1; i++) { // apenas 1 passo por recursão
        printf("Cima\n");

        // Loop interno (movimento horizontal - Direita)
        for (int j = 1; j <= 1; j++) {
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // chamada recursiva
}

// =======================
// FUNÇÃO PRINCIPAL
// =======================
int main() {
    int opcao; // variável para armazenar a escolha do usuário

    do {
        // =======================
        // MENU PRINCIPAL
        // =======================
        printf("\n=== Movimentos de Xadrez ===\n");
        printf("1 - Torre (5 casas para a direita)\n");
        printf("2 - Bispo (5 casas na diagonal cima-direita)\n");
        printf("3 - Rainha (8 casas para a esquerda)\n");
        printf("4 - Cavalo (2 casas para cima, 1 para a direita)\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            // -----------------------
            // TORRE (recursiva)
            // -----------------------
            case 1: {
                int movimento_torre = 5;
                printf("\nMovimento da Torre:\n");
                moverTorre(movimento_torre);
                break;
            }

            // -----------------------
            // BISPO (recursivo + loops aninhados)
            // -----------------------
            case 2: {
                int movimento_bispo = 5;
                printf("\nMovimento do Bispo:\n");
                moverBispo(movimento_bispo);
                break;
            }

            // -----------------------
            // RAINHA (recursiva)
            // -----------------------
            case 3: {
                int movimento_rainha = 8;
                printf("\nMovimento da Rainha:\n");
                moverRainha(movimento_rainha);
                break;
            }

            // -----------------------
            // CAVALO (loops complexos)
            // -----------------------
            case 4: {
                int passos_cima = 2;     // cavalo anda 2 casas para cima
                int passos_direita = 1;  // e 1 casa para direita

                printf("\nMovimento do Cavalo:\n");

                // Loop externo controla os movimentos para cima
                for (int i = 1; i <= passos_cima; i++) {
                    if (i == 2) {
                        // quando chegar no segundo passo, avança para a direita
                        for (int j = 1; j <= passos_direita; j++) {
                            if (j == 1) {
                                printf("Direita\n");
                                break; // sai do loop interno após 1 passo
                            }
                        }
                    } else {
                        printf("Cima\n");
                        continue; // vai para o próximo passo do loop externo
                    }
                }

                break;
            }

            // -----------------------
            // SAIR
            // -----------------------
            case 5:
                printf("\nEncerrando o programa. Ate logo!\n");
                break;

            // -----------------------
            // OPÇÃO INVÁLIDA
            // -----------------------
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
