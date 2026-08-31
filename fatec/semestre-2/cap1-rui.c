#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex1

#ifdef ex1
int main() {
    setlocale(LC_ALL, "");
    /*Escreva um programa 
    que permute o conteúdo de duas variáveis sem utilizar uma
     variável auxiliar.*/
    int var1, var2;
    printf("Digite dois números:\n");
    scanf("%d %d", &var1, &var2);
    var1 = var1 + var2;
    var2 = var1 - var2;
    var1 = var1 - var2;
    printf("Variável 1: %d\nVariável 2: %d", var1, var2);
    return 0;
}
#endif //ex1

#ifdef ex2
int main() {
    /*Escreva um programa que receba dados via teclado para variaveis do tipo short,
     long, int, float, double e um char e imprima-os no video no seguinte
     formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/
    setlocale(LC_ALL, "");
    short a;
    printf("Digite um número do tipo short:\n");
    scanf("%hd", &a);
    long b;
    printf("Digite um número do tipo long:\n");
    scanf("%ld", &b);
    int c;
    printf("Digite um número do tipo int:\n");
    scanf("%d", &c);
    float d;
    printf("Digite um número do tipo float:\n");
    scanf("%f", &d);
    double e;
    printf("Digite um número do tipo double:\n");
    scanf("%lf", &e);
    char f;
    printf("Digite um caractere:\n");
    scanf(" %c", &f);
    /*         10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/
    printf("\n    %-6hd              %-11ld         %-11d          \n", a, b, c);
    printf("              %-8g            %-9g           %c          \n", d, e, f);
    return 0;
}
#endif //ex2

#ifdef ex3
int main() {
    setlocale(LC_ALL, "");
    /*3 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
     multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
     teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/
    int limite, user_multiplo, i;
    printf("O múltiplo de qual número você quer descobrir?\n");
    scanf("%d", &user_multiplo);
    printf("E qual o limite mínimo?\n");
    scanf("%d", &limite);

    for (i = 0; i < user_multiplo; i++) {
        if ((limite + i) % user_multiplo == 0) {
            printf("O menor múltiplo de %d maior que %d é: %d\n", user_multiplo, limite, limite + i);
            break;
        }
    }

    return 0;
}
#endif //ex3

#ifdef ex4
int main () {
    setlocale(LC_ALL, "");
    /*4 - Escreva um programa que receba via teclado um tempo em segundos e converta
     para horas, minutos e segundos.
     Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/
    int user_tempo, tempo, segundo, minuto, hora, i;
    do {
        printf("Digite o tempo em segundos:\n");
        scanf("%d", &tempo);
        if (tempo < 60) {
            printf("Digite um valor maior que 60 segundos!\n");
        }
    } while (tempo < 60);

    user_tempo = tempo;
    
    if (tempo < 3600) {
        i = 1;
    }
    else {
        i = 2;
    }

    for (i; i > 0; i--) {
        if (i == 2) {
            hora = tempo / 3600;
            tempo = tempo % 3600;
        }
        else {
            minuto = tempo / 60;
            segundo = tempo % 60;
        }
    }

    if (hora >= 1) {
        printf("Recebemos %d segundos que convertemos para %dh %dmin %d seg\n", user_tempo, hora, minuto, segundo);
    }
    else {
        printf("Recebemos %d segundos que convertemos para %dmin %d seg\n", user_tempo, minuto, segundo);
    }

    return 0;
}
#endif //ex4

#ifdef ex5
int main() {
    setlocale(LC_ALL, "");
    /*Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
     outro número formado pelos dígitos invertidos do número lido.
     Ex:   NúmeroLido = 123
           NúmeroGerado = 321*/
    int num, num_invertido;
    printf("Digite uma centena:\n");
    scanf("%d", &num);
    num_invertido = ((num % 10) * 100) + (((num / 10) % 10) * 10) + (((num / 10) / 10) % 10);
    printf("NúmeroLido = %d\nNúmeroGerado = %d\n", num, num_invertido);
    return 0;
}
#endif //ex5
