#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define ex6
#define funcMenu

#ifdef funcMenu
int menu () {
    char iniciar;
    do {
        printf("Deseja iniciar o programa?\nDigite 's' para sim ou 'n' para não\n");
        scanf(" %c", &iniciar);
        if (iniciar != 's' && iniciar != 'n' && iniciar != 'S' && iniciar != 'N') {
            printf("Insira apenas os as letras 's' ou 'n'.\n\n");
        }
    } while (iniciar != 's' && iniciar != 'n' && iniciar != 'S' && iniciar != 'N');

    if (iniciar == 's' || iniciar == 'S') {
        return(1);
    }
    else {
        return(0);
    }
}
#endif // funcMenu

#ifdef ex1
float a[10];
float b[10];
Armazena() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Digite um número para armazenar no vetor: \n");
        scanf("%f", &a[i]);
    }
}
vetor_B() {
    int i, paridade;
    for (i = 0; i < 10; i++) {
        paridade = i % 2;
        if (paridade == 0) {
            b[i] = a[i] + 2;
        }
        else {
            b[i] = a[i] + 3;
        }
    }
}
Exiba() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Posição %d - A: %.2f; B: %.2f\n", i, a[i], b[i]);
    }
}
int main()
{
    /* Crie o programa dividido em funções:

a) Função Armazena: é utilizada para guardar dez números quaisquer no vetor A.

b) Função Vetor_B: construa o vetor B de mesma dimensão com os elementos do vetor A baseado nas seguintes condições: se o índice for par soma dois ao conteúdo do vetor, caso o índice seja ímpar some três ao conteúdo do vetor A.

c) Exiba: exiba no interior desta função o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        Armazena();
        vetor_B();
        Exiba();
    }

    return 0;
}
#endif // ex1

#ifdef ex2
float a[12];
Armazena() {
    int i;
    for (i = 0; i < 12; i++) {
        printf("Digite um número para armazenar no vetor: \n");
        scanf("%f", &a[i]);
    }
}
quant_Positivos() {
    int i;
    int numPositivos = 0;
    for (i = 0; i < 12; i++) {
        if (a[i] >= 0) {
            numPositivos = numPositivos + 1;
        }
    }
    if (numPositivos > 0) {
        printf("Foram digitados %d números positivos!\n", numPositivos);
    }
}
int Exiba() {
    int i, contador121 = 0;
    for (i = 0; i < 12; i++) {
        if (a[i] > 121) {
            printf("Posição %d - A: %.2f\n", i, a[i]);
            contador121++;
        }
    }
    return contador121;
}
Negativos() {
    float somaNegativos = 0;
    int i, contador = 0;
    for (i = 0; i < 12; i++) {
        if (a[i] < 0) {
            somaNegativos = somaNegativos + a[i] ;
            contador++;
        }
    }
    if (contador != 0) {
        somaNegativos = somaNegativos / contador;
        printf("A média dos números negativos é: %.2f\n", somaNegativos);
    }
}
int main()
{
    /* .Crie o programa dividido em funções:

a) Função Armazena: é utilizada para guardar doze números quaisquer no vetor A.

b) Função Quant_Positivos: calcule a quantidade de números positivos contidos no vetor A.

c) Exiba: mostre nesta função em que posições aparecem os números maiores que 121 que estão armazenados no vetor A.

d) Negativos: calcule e exiba no interior desta função a média dos números negativos.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        Armazena();
        quant_Positivos();
        Exiba();
        if (Exiba() == 0) {
            printf("Não foram digitados nenhum número maior que 121!\n");
        }
        Negativos();
    }

    return 0;
}
#endif // ex2

#ifdef ex3
int a[7];
int inverte_A[7];
Armazena() {
    int i;
    for (i = 0; i < 7; i++) {
        printf("Digite um número para armazenar no vetor: \n");
        scanf("%d", &a[i]);
    }
}
float MED_5() {
    float soma = 0;
    int divisor = 0;
    float media;
    int i;
    for (i = 0; i < 7; i++) {
        if (a[i] % 5 == 0) {
            soma = soma + a[i];
            divisor = divisor + 1;
        }
    }
    if (divisor != 0) {
        soma = soma / divisor;
    }
    return (soma);
}
INVERTE() {
    int i, j = 6;
    for (i = 0; i < 7; i++) {
        inverte_A[i] = a[j];
        j--;
    }
    for (i = 0; i < 7; i++) {
        printf("Posição %d - A: %d; Inverte_A: %d\n", i, a[i], inverte_A[i]);
    }
}
float Menor_Num() {
    int menor, i;
    for (i = 0; i < 7; i++) {
        if (i == 0) {
            menor = a[i];
        }
        else if (menor > a[i]) {
            menor = a[i];
        }
    }
    return (menor);
}
int main()
{
    /* Crie o programa dividido em funções:

a) Função Armazena: é utilizada para guardar 7 números positivos no vetor A.

b) Função MED_5: calcule a média dos números que são múltiplos de cinco. Exiba está média no interior da função main.

c) Função INVERTE: armazene no vetor inverte_A os números armazenados no vetor A em ordem inversa. Exiba separadamente o conteúdo de cada vetor.

d) Função Menor_Num: verifique o menor número encontrado no vetor A e exiba no interior da função main.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
    Armazena();
    float media = MED_5();
    if (media != 0) {
        printf("A média dos números múltiplos de cinco é: %.2f\n", media);
    }
    INVERTE();
    int menor_numero = Menor_Num();
    printf("O menor número encontrado no vetor A é: %d\n", menor_numero);
    }
    return 0;
}
#endif // ex3

#ifdef ex4
int x[12];
//Nao achei outra forma de limitar o número de elementos do vetor além desse jeito, determinando um valor máximo a partir do enunciado
    /* Crie o programa dividido em funções:

a) Função Armazena: é utilizada para guardar no mínimo 3 e no máximo 12 números quaisquer no vetor X. Essa quantidade é definida como uma variável local à função main chamada de quant.

b) Função Soma_7: calcule a soma apenas dos números contidos no vetor X que são divisíveis por 7. Exiba esta soma no interior desta função.

c) Função Menor_Par: verifique o menor número par contido no vetor X. Exiba no interior da função main. Caso não tenha nenhum número par no interior do vetor X, informe ao usuário no interior da função main.

d) Função ExibaMenor_Par: exiba em que posições o menor número par apareceu no veotr X.*/
int Armazena(int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Digite um número: \n");
        scanf("%d", &x[i]);
    }
}
int Soma_7(int quantidade) {
    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        if (x[i] % 7 == 0) {
            soma = soma + x[i];
        }
    }
    if (soma != 0) {
        printf("A soma dos números divisíveis por 7 no vetor X é: %d\n", soma);
    }
    else {
        printf("Não foram digitados números divisíveis por 7!\n");
    }
}
int Menor_Par(int quantidade) {
    int menor,i, contpar=0;
    for (i = 0; i < quantidade; i++) {
        if (x[i] % 2 == 0) {
        contpar++;
        if (contpar == 1) {
            menor = x[i];
        }
        else if (menor > x[i]) {
            menor = x[i];
        }
        }
        }

    if (contpar==0) {
        menor=1;
    }
    return (menor);
}
void ExibaMenor_Par(int menor, int quantidade) {
    printf("O menor número par apareceu nas posições:");
    for (int i = 0; i < quantidade; i++) {
        if (x[i] == menor) {
            printf("%d ", i);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int start, menor_par;
    start = menu();
    if (start == 1) {
        int quant;
        do {
            printf("Digite um a quantidade de números para armazenar no vetor X: ");
            scanf("%d", &quant);
            if (quant < 3 || quant > 12) {
                printf("\nA quantidade deve ser entre 3 e 12!\n\n");
            }
        } while (quant < 3 || quant > 12);
        Armazena(quant);
        Soma_7(quant);
        menor_par= Menor_Par(quant);
        if (menor_par == 1) {
            printf("Não foram digitados números pares!\n");
        }
        else {
            printf("O menor número par é: %d\n", menor_par);
            ExibaMenor_Par(menor_par, quant);
        }
    }
    return 0;
}
#endif // ex4

#ifdef ex5
/*Crie o programa dividido em funções:

a. Função Armazenas :armazena no vetor A no mínimo 7 e no máximo 18 números quaisquer. Essa quantidade é determinada pelo usuário e definida como uma variável local à função main chamada de quant.

b. Função VetPositivos: armazene neste vetor apenas os números maiores ou iguais azero contidos no vetor A. Caso não tenha sido encontrado no vetorA nenhum número que satisfaça essas condições informe ao usuário no interior da função main.

c. Função Fatorial:crie uma função que calcule o fatorial de cada número do VetPositivos e o seu fatorial no vetor  FatorialVetPositivos.*/
int a[18];
int VetPositivos[18];
int FatorialVetPositivos[18];
Armazenas(int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        printf("Digite um número para armazenar na posição %d do vetor A: \n", i);
        scanf("%d", &a[i]);
    }
}
int funcVetPositivos(int quantidade) {
    int i, contador = 0;
    for (i = 0; i < quantidade; i++) {
        if (a[i] >= 0) {
            VetPositivos[i] = a[i];
            contador++;
        }
    }
    return (contador);
}
Fatorial(int quantidade) {
    int i, j, fatorial;
    for (i = 0; i < quantidade; i++) {
        if (VetPositivos[i] > 0) {
            for (j = 1; j < VetPositivos[i]; j++) {
                if (j == 1) {
                    fatorial = j * VetPositivos[i];
                }
                else {
                    fatorial = fatorial * j;
                }
            }
            FatorialVetPositivos[i] = fatorial;
        }
        else {
            FatorialVetPositivos[i] = 0;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int start, quant, i;
    start = menu();
    if (start == 1) {
        do {
            printf("Digite a quantidade de elementos para armazenar no vetor: ");
            scanf("%d", &quant);
            if (quant < 7 || quant > 18) {
                printf("\nA quantidade de elementos deve ser entre 7 e 18!\n\n");
            }
        } while (quant < 7 || quant > 18);

        Armazenas(quant);
        if (funcVetPositivos(quant) == 0) {
            printf("Não foi digitado nenhum número positivo!\n");
        }
        Fatorial(quant);
        for (i = 0; i < quant; i++) {
            if (a[i] >= 0) {
                printf("Posição %d - A: %d; Fatorial: %d\n", i, a[i], FatorialVetPositivos[i]);
            }
            else {
                printf("Posiçao %d - A: %d\n", i, a[i]);
            }
        }
    }
    return 0;
}
#endif // ex5

#ifdef ex6
/* 6. Crie o programa dividido em funções:
a) Função Dados :armazena no vetor A no mínimo 5 e no máximo 20 números pares . Essa quantidade é determinada pelo usuário e definida como uma variável local à função main chamada de quant
b) Função Pares: está função deve garantir que apenas números pares devem ser armazenados no vetor A.
c) Função MaiorMult7e11: verifique o maior número que é múltiplo de 7 e 11 ao mesmo tempo contido no vetor A. Exiba no interior da função ExibaMultiplo7e11. Caso não tenha nenhum múltiplo de 7 e 11 ao mesmo tempo contido no vetor A informe ao usuário também no interior da função ExibaMultiplo7e11.
d) Função ExibaMaior Mult7e11: armazene no vetor Mult7e11 apenas os números que estão contidos no vetor A que são múltiplos de 7 e 11.Exiba o maior múltiplo de 7 e 11 contido no vetor A e se não houver nenhum múltiplo de 7 e 11 ao usuário. Exiba se existir o conteúdo do vetor Mult7e11.*/
int a[20];
Dados(int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        a[i] = Pares();
    }
}
int Pares() {
    int num;
    do {
        printf("Digite um número: ");
        scanf("%d", &num);
        if (num % 2 != 0 && num < 0) {
            printf("Digite apenas números pares!\n\n");
        }
    } while (num % 2 != 0 && num < 0);
    return (num);
}
int MaiorMult7e11(int quantidade) {
    int i, num = 0;
    for (i = 0; i < quantidade; i++) {
        if (a[i] % 7 == 0 && a[i] % 11 == 0 && num < a[i]) {
            num = a[i];
        }
    }
    return (num);
}
ExibaMultiplo7e11(int quantidade) {
    int maior = MaiorMult7e11(quantidade);
    if (maior == 0) {
        printf("Não foi digitado nenhum número múltiplo de 7 e 11!\n");
    }
    else {
        printf("O maior número múltiplo de 7 e 11 é: %d\n", maior);
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int start, quant;
    start = menu();
    if (start == 1) {
        do {
            printf("Digite a quantidade de elementos para armazenar no vetor A: ");
            scanf("%d", &quant);
            if (quant < 5 || quant > 20) {
                printf("\nA quantidade de elementos deve ser entre 5 e 20!\n\n");
            }
        } while (quant < 5 || quant > 20);
        Dados(quant);
        ExibaMultiplo7e11(quant);
    }
    return 0;
}
#endif ex6
