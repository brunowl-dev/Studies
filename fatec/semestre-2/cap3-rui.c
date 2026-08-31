#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define ex4
 
#ifdef ex1
    /*1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/
int a, b;
int sinal(int num) {
    if (num > 0) {
        num = 1;
    }
    else if (num < 0) {
        num = 0;
    }
    else {
        num = -1;
    }
    return (num);
}
int soma(int a, int b) {
    int i, soma = 0;
    if (a > b) {
        i = b;
        for (i; i < a; i++) {
            soma = soma + i;
        }
    }
    else {
        i = a;
        for (i; i < b; i++) {
            soma = soma + i;
        }
    }
    return (soma);
//Menor ou igual ou só menor?
}
int multiplicacao(int a, int b) {
    int i, produto = 1;
    if (a > b) {
        i = a - 1;
        for (i; i > b; i--) {
            produto = produto * i;
        }
    }
    else {
        i = b - 1;
        for (i; i > a; i--) {
            produto = produto * i;
        }
    }
    return (produto);
}
int main(){
    setlocale(LC_ALL, "");
    printf("Digite dois números:\n");
    scanf("%d %d", &a, &b);
    if (sinal(a) == 1 && sinal(b) == 1) {
        printf("A soma dos números existentes entre %d e %d é: %d\n", a, b, soma(a, b));
    }
    else if (sinal(a) == 0 && sinal(b) == 0) {
        printf("O produto dos números existentes entre %d e %d é: %d\n", a, b, multiplicacao(a, b));
    }
    else {
        printf("A divisão entre %d e %d é: %d\n", a, b, a/b);
    }
    return 0;
}
#endif //ex1
 
#ifdef ex2
    /* 2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
     que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
     mostrado na funcao main().
     Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/
int num;
int somaFat(int num) {
    int i, soma = 0, fatorial = 1;
    for (i = 1; i <= num; i++) {
        fatorial = i * fatorial;
    }
    do {
        soma = (fatorial % 10) + soma;
        fatorial = fatorial / 10;
    } while (fatorial > 0);
    return (soma);
}
int main() {
    setlocale(LC_ALL, "");
    printf("Digite um número:\n");
    scanf("%d", &num);
    printf("A soma dos algorismos do fatorial de %d é: %d\n", num, somaFat(num));
    return 0;
}
#endif // ex2
 
#ifdef ex3
    /*3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
     uma funcao para cada operacoes aritmeticas e passe como parametro os 2
     valores recebidos na funcao main(). Retorne os resultados usando o comando
     return e imprima os 4 resultados no video na funcao main().*/
int soma(int a, int b) {
    int resultado = a + b;
    return (resultado);
}
int sub(int a, int b) {
    int resultado = a - b;
    return (resultado);
}
int prod(int a, int b) {
    int resultado = a * b;
    return (resultado);
}
int divisao(int a, int b) {
    int resultado = a / b;
    return (resultado);
}
int main() {
    setlocale(LC_ALL, "");
    int a, b;
    printf("Digite dois números:\n");
    scanf("%d %d", &a, &b);
    printf("A soma de %d e %d é: %d\n", a, b, soma(a,b));
    printf("A subtração de %d por %d é: %d\n", a, b, sub(a,b));
    printf("O produto de %d por %d é: %d\n", a, b, prod(a,b));
    printf("A divisão de %d por %d é: %d\n", a, b, divisao(a,b));
    return 0;
}
#endif // ex3

#ifdef ex4
    /*4 - Reescreva o programa do exercicio anterior para receber via teclado n
     valores. Os n valores nao sao definidos previamente.*/

int soma = 0, sub = 0, prod = 1;
float division = 1;
void funcSoma(int num) {
    soma = soma + num;
}
void funcSub(int num) {
    sub = sub - num;
}
void funcProd(int num) {
    prod = prod * num;
}
void funcDiv(int num) {
    division = division / num;
}
int main() {
    setlocale(LC_ALL, "");
    int start, num, i = 0;
    do {
        printf("Deseja iniciar o programa?\n1-Sim\n0-Não\n");
        scanf("%d", &start);
        if (start != 1 && start != 0) {
            printf("Digite apenas os valores 0 ou 1!\n");
        }
    } while (start != 1 && start != 0);

    while (start == 1) {
        printf("Digite um número:\n");
        scanf("%d", &num);
        funcSoma(num);
        funcSub(num);
        funcProd(num);
        funcDiv(num);
        if (i == 0) {
            sub = num;
            division = num;
            printf("Digite outro número:\n");
            scanf("%d", &num);
            funcSoma(num);
            funcSub(num);
            funcProd(num);
            funcDiv(num);
            i++;
        }
        printf("Soma - %d\nSubtração - %d\nProduto - %d\nDivisão - %.2f\n", soma, sub, prod, division);    
        do {
            printf("Deseja iniciar o programa novamente?\n1-Sim\n0-Não\n");
            scanf("%d", &start);
            if (start != 1 && start != 0) {
                printf("Digite apenas os valores 0 ou 1!\n");
            }
        } while (start != 1 && start != 0);
        system("cls"); 
    }
    return 0;
}
#endif // ex4