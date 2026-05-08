#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int opcao, numerojogador, numerocomp, resultado;
    char tipocomparacao;

    // gerar numero aleatorio
    srand(time(0));
    numerocomp = rand() % 100 + 1; // numero entre 1 e 100

    printf("** Menu do Jogo **\n");
    printf(" Voce deve escolher um numero e o tipo de comparacao. \n");
    printf(" M. Maior \n");
    printf(" N. Menor \n");
    printf(" I. Igual \n");

    printf("Escolhe a comparacao: \n");
    scanf("%c", &tipocomparacao);

    printf("Escolha um numero (Entre 1 e 100): \n");
    scanf("%d", &numerojogador);

    switch (tipocomparacao)
    {
    case 'M':
    case 'm':
        printf("Voce escolheu a opcao maior! \n");
        resultado = numerojogador > numerocomp ? 1 : 0;
        break;
    case 'N':
    case 'n':
        printf("Voce escolheu a opcao menor! \n");
        resultado = numerojogador < numerocomp ? 1 : 0;
        break;
    case 'I':
    case 'i':
        printf("Voce escolheu a opcao igual! \n");
        resultado = numerojogador == numerocomp ? 1 : 0;
        break;

    default:
        printf("Opcao invalida!");
        break;
    }
    printf("O numero do computador e: %d e o do jogador e: %d\n", numerocomp, numerojogador);

    if (resultado == 1)
    {
        printf("Parabens, voce venceu! \n");
    } else {
        printf("Que pena, voce perdeu! \n");
    }

}
