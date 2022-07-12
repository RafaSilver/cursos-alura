#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short main() {
    // variaveis
    short segundos = time(0);
    srand(segundos);
    short numerogrande = rand();
    short numerosecreto = numerogrande % 100;
    short chute = 0;
    short tentativas = 1;
    short pontos = 1000;
    short pontosperdidos = 0;
    short nivel = 0;
    short numerodetentativas = 0;

    // instruçoes
    printf("* Bem-vindo ao nosso jogo de adivinhacao * \n");

    printf("Escolha o nivel de dificuldade: \n");
    printf("(1) Facil (2) Medio (3) Dificil \n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1:
            numerodetentativas = 18;
            break;
        case 2:
            numerodetentativas = 12;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

    for(short i = 1; i <= numerodetentativas; i++) {
        printf("Tentativa %d \n", tentativas);
        printf("Qual vai ser o seu chute: ");
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);
        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos! \n");
            continue;
        }
        if (chute == numerosecreto) {
            break;
        }
        else if (chute > numerosecreto) {
            printf("Seu chute foi maior que o numero secreto... \n");
        }
        else if (chute < numerosecreto) {
            printf("Seu chute foi menor que o numero secreto... \n");
        }
        tentativas++;
        pontosperdidos = abs(chute - numerosecreto);
        pontos = pontos - pontosperdidos;    
    }
    printf("Fim de jogo! \n");
    if (chute == numerosecreto) {
        printf("Voce ganhou! \n");
        printf("Voce acertou em %d tentativas! \n", tentativas);
        printf("Total de pontos: %d \n", pontos);
    }
    else {
        printf("Voce perdeu! Tente de novo!\n");
    }
    
}