#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float numInput() {
    float num;
    scanf("%f", &num);
    return (num);
}

int main() {
    setlocale(LC_ALL, "");
    float num1, num2;
    int i = 0;

    while (i == 0) {
        printf("\tCalculadora do Wai Lu\n");
        printf("Digite um dos seguintes números para selecionar a operação desejada:\n");
        printf("1-Adição\n");
        printf("2-Subtração\n");
        printf("3-Divisão\n");
        printf("4-Multiplicação\n");
        printf("5-Resto de uma divisão\n");
        printf("6-Encerrar o programa\n");
        scanf("%d", &i);

        if (i < 1 || i > 6) {
            printf("Opção inválida!\n");
            i = 0;
        }
        else if (i == 1) {
            printf("Digite o primeiro número\n");
            num1 = numInput();
            printf("Digite o segundo número:\n");
            num2 = numInput();
            printf("O resultado da soma é %.2f\n", num1 + num2);
        }
        else if (i == 2) {
            printf("Digite o primeiro número\n");
            num1 = numInput();
            printf("Digite o segundo número:\n");
            num2 = numInput();
            printf("O resultado da subtração é %.2f\n", num1 - num2);
        }
        else if (i == 3) {
            printf("Digite o primeiro número\n");
            num1 = numInput();
            printf("Digite o segundo número:\n");
            num2 = numInput();
            printf("O resultado da divisão é %.2f\n", num1 / num2);
        }
        else if (i == 4) {
            printf("Digite o primeiro número\n");
            num1 = numInput();
            printf("Digite o segundo número:\n");
            num2 = numInput();
            printf("O resultado da multiplicação é %.2f\n", num1 * num2);
        }
        else if (i == 5) {
            printf("Digite o primeiro número\n");
            num1 = numInput();
            int num1_resto = num1;
            printf("Digite o segundo número:\n");
            num2 = numInput();
            int num2_resto = num2;
            printf("O resultado do resto da divisão é %d\n", num1_resto % num2_resto);
        }
        else {
            break;
        }

        printf("Deseja executar o programa novamente?\n");
        printf("Digite 7 para sim e 6 para não\n");
        scanf("%d", &i);
        if (i == 7) {
            i = 0;
        }
        
    }

    printf("Programa encerrado!\n");

    return 0;
}