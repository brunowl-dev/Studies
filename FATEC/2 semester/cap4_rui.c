#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex5
 
#ifdef ex1
int main() {
    /*1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:
 
          10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/
    setlocale(LC_ALL, "");
    int a[3], i; long b[3]; unsigned c[3]; float d[3]; double e[3];
    for (i = 0; i < 3; i++) {
        printf("Digite um número do tipo int para o índice %d:\n", i);
        scanf("%d", &a[i]);
 
        printf("Digite um número do tipo long para o índice %d:\n", i);
        scanf("%ld", &b[i]);
 
        printf("Digite um número do tipo unsigned para o índice %d:\n", i);
        scanf("%u", &c[i]);
 
        printf("Digite um número do tipo float para o índice %d:\n", i);
        scanf("%f", &d[i]);
 
        printf("Digite um número do tipo double para o índice %d:\n", i);
        scanf("%lf", &e[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("   %-11d         %-11ld         %-10u\n", a[i], b[i], c[i]);
        printf("            %-8g            %-9g         \n", d[i], e[i]);
    }
}
#endif // ex1
 
#ifdef ex2
int main() {
    /*2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/
    setlocale(LC_ALL, "");
    int v[10], par[5], imp[5], i, h = 0, j = 0;
    for (i = 0; i < 10; i++) {
        printf("Digite um número:\n");
        scanf("%d", &v[i]);
        if (i % 2 == 0) {
            par[h] = v[i];
            h++;
        }
        else {
            imp[j] = v[i];
            j++;
        }
    }
    printf("\n");
    for (i = 0; i < h; i++) {
        printf("Par[%d]:%d\n", i, par[i]);
    }
    for (i = 0; i < j; i++) {
        printf("Impar[%d]:%d\n", i, imp[i]);
    }
    return 0;
}
#endif // ex2
 
#ifdef ex3
int main() {
    /*3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. */
    setlocale(LC_ALL, "");
    int v[10], par[10], imp[10], i, paridade, h = 0, j = 0;
    for (i = 0; i < 10; i++) {
        printf("Digite um número:\n");
        scanf("%d", &v[i]);
        paridade = v[i] % 2;
        if (paridade == 0) {
            par[h] = v[i];
            h++;
        }
        else {
            imp[j] = v[i];
            j++;
        }
    }
    printf("\n");
    for (i = 0; i < h; i++) {
        printf("Par[%d]:%d\n", i, par[i]);
    }
    for (i = 0; i < j; i++) {
        printf("Impar[%d]:%d\n", i, imp[i]);
    }
    return 0;
}
#endif // ex3
 
#ifdef ex4
int main() {
    /*4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/
    setlocale(LC_ALL, "");
    int a[2][3], b[2][3], c[2][3];
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite um número para o vetor A, linha %d, coluna %d:\n", i, j);
            scanf("%d", &a[i][j]);
            printf("Digite um número para o vetor B, linha %d, coluna %d:\n", i, j);
            scanf("%d", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
            }
    }
    printf("Vetor A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Linha %d, coluna %d: %d\n", i, j, a[i][j]);
        }
    }
    printf("Vetor B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Linha %d, coluna %d: %d\n", i, j, b[i][j]);
        }
    }
    printf("Vetor C:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Linha %d, coluna %d: %d\n", i, j, c[i][j]);
        }
    }
    return 0;
}
#endif // ex4
 
#ifdef ex5
int main() {
    /*5 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/
    setlocale(LC_ALL, "");
    int i, j;
    int var = 10;
    int vet[var];
    for (i = 0; i < var; i++) {
        printf("Digite um número para a posição %d:\n", i);
        scanf("%d", &vet[i]);
        if (i >= 1) {
            for (j = i; j > 0; j--) {
                if (vet[j-1] > vet[j]) {
                    vet[j] = vet[j] + vet[j-1];
                    vet[j-1] = vet[j] - vet[j-1];
                    vet[j] = vet[j] - vet[j-1];
                }
            }
        }
        }
    printf("\n");
    for (i = 0; i < var; i++) {
        printf("%d ", vet[i]);
    }
    return 0;
}
#endif // ex5

//\n