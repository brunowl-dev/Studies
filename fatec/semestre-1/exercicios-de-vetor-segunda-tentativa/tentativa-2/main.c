#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define ex10
#define funcoes

#ifdef funcoes
int menu() {
    int iniciar;
    do {
        printf("Deseja iniciar o programa?\n0-Não\n1-Sim\n");
        scanf("%d", &iniciar);
        if (iniciar != 1 && iniciar != 0) {
            printf("Insira apenas os números 0 ou 1.\n\n");
        }
    } while (iniciar != 1 && iniciar != 0);

    return (iniciar);
}

#endif // funcoes

#ifdef ex1
int main()
{
    /* 1.Armazene sete números reais no vetor chamado vet.
     Após a alimentação de todos os números no vetor vet,
     mostre todos os elementos armazenados no vetor.
     Exiba o produto de todos os numeros armazenados no vetor*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float vet[6];
        float prod = 1;
        for (int i = 0; i <= 6; i++) {
            printf("Digite um valor: \n");
            scanf("%f", &vet[i]);
            prod = prod * vet[i];
        }
        system("cls");
        for (int i = 0; i <= 6; i++) {
            printf("\nNúmero armazenado na posição %d é %.1f", i, vet[i]);
            }
        printf("\nO produto dos números armazenados é %.1f", prod);
        }
        printf("\n");
    return 0;
}
#endif // ex1

#ifdef ex2
int main()
{
    /* Receba seis números quaiquer. Exiba a média desses números.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a[5];
        float soma = 0;
        float media;
        for (int i = 0; i <= 5; i++) {
            printf("Digite um valor qualquer: \n");
            scanf("%f", &a[i]);
            soma = soma + a[i];
        }
        media = soma / 6;
        printf("A média dos números inseridos é %.2f", media);
    }
    return 0;
}
#endif // ex2

#ifdef ex3
int main()
{
    /*Receba sete números positivos. Exiba a soma desses números*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a[6];
        float soma = 0;
        for (int i = 0; i <= 6; i++) {
            do {
                printf("Digite um valor positivo: \n");
                scanf("%f", &a[i]);
                if (a[i] < 0) {
                    printf("Digite apenas valores positivos! \n\n");
                }
            } while (a[i] < 0);
            soma = soma + a[i];
        }

        printf("A soma dos números informados é: %.2f", soma);
    }
    return 0;
}
#endif // ex3

#ifdef ex4
int main()
{
    /* Leia quinze elementos de um vetor. Após a alimentação mostre todos os elementos armazenados no vetor*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int i;
        float a[14];
        for (i = 0; i <= 14; i++) {
            printf("Digite um valor: \n");
            scanf("%f", &a[i]);
        }
        for (i = 0; i <= 14; i++) {
            printf("\n%.1f", a[i]);
        }
    }
    return 0;
}
#endif // ex4

#ifdef ex5
int main()
{
    /* Receba doze números positivos e armazene no vetor A. Após a alimentação de todos os números mostre apenas os números maiores que 121 que estão armazenados no vetor.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int i;
        float a[11];
        for (i = 0; i <= 11; i++) {
            do {
                printf("Digite um número positivo: \n");
                scanf("%f", &a[i]);
                if (a < 0) {
                    printf("Digite apenas números positivos! \n\n");
                }
            } while (a < 0);
        }
        for (i = 0; i <= 11; i++) {
            if (a[i] >= 121) {
                printf("\n%.1f", a[i]);
            }
        }
    }
    return 0;
}
#endif // ex5

#ifdef ex6
int main()
{
    /* Leia oito elementos e armazene-os no vetor A. Construa o vetor B de mesma dimensão com os elementos do vetor A multiplicados por 3. Apresente o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a[7], b[7];
        for (int i = 0; i <= 7; i++) {
            printf("Digite um valor: \n");
            scanf("%f", &a[i]);
            b[i] = a[i] * 3;
        }
        for (int i = 0; i <= 7; i++) {
            printf("Posição %d - A:%.1f; B:%.1f\n", i, a[i], b[i]);
        }
    }
    return 0;
}
#endif // ex6

#ifdef ex7
int main()
{
    /* Faça um programa que armazene num vetor 6 números negativos. Calcule a soma dos seus quadrados; se a soma for inferior a 1000 solicite novos dados. Mostre somente a soma que satisfaz a condição.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a[5];
        float soma = 0;
        do {
            for (int i = 0; i <= 5; i++) {
                do {
                    printf("Digite um valor negativo: \n");
                    scanf("%f", &a[i]);
                    if (a[i] >= 0) {
                        printf("Digite apenas valores negativos! \n\n");
                    }
                } while (a[i] >= 0);
            soma = soma + pow(a[i], 2);
            }
            if (soma < 1000) {
                printf("Digite novos dados! \n\n");
            }
        } while (soma < 1000);
        printf("A soma dos quadrados dos números informados é: %.2f", soma);
        }
    return 0;
}
#endif // ex7

#ifdef ex8
int main()
{
    /*Armazene num vetor dez números positivos. Exiba o conteúdo do vetor. Mostre o maior número, quantas vezes ele foi digitado e em que posições ele apareceu dentro do vetor*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a[9];
        float maior = 0;
        int aparicao = 0;
        for (int i = 0; i <= 9; i++) {
            do {
                printf("Digite um valor positivo: \n");
                scanf("%f", &a[i]);
                if (a[i] < 0) {
                    printf("Digite apenas vlaores positivos! \n\n");
                }
            } while (a[i] < 0);
        if (a[i] >= maior) {
            maior = a[i];
        }
        }

        for (int i = 0; i <= 9; i++) {
            if (a[i] == maior) {
                aparicao = aparicao + 1;
            }
        }

        for (int i = 0; i <= 9; i++) {
            if (a[i] == maior) {
                printf("\nPosição %d = %.2f (maior)", i, a[i]);
            }
            else {
                printf("\nPosição %d = %.2f ", i, a[i]);
            }
        }
        if (aparicao == 1) {
            printf("\nO maior número é %.2f e ele apareceu %d vez!", maior, aparicao);
        }
        else {
            printf("\nO maior número é %.2f e ele apareceu %d vezes!", maior, aparicao);
        }
    }
    return 0;
}
#endif // ex8

#ifdef ex9
int main()
{
    /* Leia o vetor A de uma dimensão máxima de 15 elementos. O usuário poderá digitar a quantidade desejada desde que o valor seja inferior ou igual a 15. Construir um vetor B de mesmo tipo, de modo que cada elemento do vetor B seja fatorial do elemento correspondente do vetor A. Apresentar o conteúdo dos dois vetores*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int max, i, c;
        do {
            printf("Digite o valor máximo de elementos: \n");
            scanf("%d", &max);
            if (max < 1 || max > 15) {
                printf("Digite um valor entre 1 e 15! \n\n");
            }
        } while (max < 1 || max > 15);
        max = max - 1;
        int a[max], b[max];
        int fatorial = 1;

        for (i = 0; i <= max; i++) {
            do {
                printf("Digite um valor: \n");
                scanf("%d", &a[i]);
                if (a[i] < 0) {
                    printf("Digite apenas números positivos! \n\n");
                }
            } while (a[i] < 0);
        }

        for (i = 0; i <= max; i++) {
            for (int c = 0; c < a[i]; c++) {
                fatorial *= (c + 1);
            }
        b[i] = fatorial;
        fatorial = 1;
        }

        for (i = 0; i <= max; i++) {
            printf("Elemento da posição %d: %d \tFatorial da posição %d: %d\n", i, a[i], i, b[i]);
        }
        }
    return 0;
}
#endif // ex9

#ifdef ex10
int main()
{
    /* O usuário poderá digitar a quantidade de números que ele deseja armazenar no vetor A desde que esse valor seja superior a 4 e inferior ou igual a 20. Construa o vetor B da mesma dimensão e com os mesmos elementos do vetor A. Observando que o primeiro elemento de A passa a ser o último de B, o segundo elemento de A passa a ser o penúltimo de B e a assim por diante. Exibir o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int tamanho, i; //Variável para definir o tamanho do vetor e variavel auxiliar para o laço for
        int j = 1; //Variável auxiliar na hora de montar o vetor B
        do { //Laço do-while pra definir o tamanho dos vetores
            printf("Digite a quantidade de números desejados: \n");
            scanf("%d", &tamanho);
            if (tamanho < 4 || tamanho > 20) {
                printf("Digite um valor entre 4 e 20!\n\n");
            }
        } while (tamanho < 4 || tamanho > 20);

        int a[tamanho], b[tamanho]; //Declaração dos vetores com o tamanho definido pelo usuário

        for (i = 0; i < tamanho; i++) { //Laço for pro usuário armazenar os números do vetor A e também processo para armazenar os números do vetor B
            printf("Digite um número para armazenar no vetor A: \n");
            scanf("%d", &a[i]);
            b[tamanho - j] = a[i];
            /* Eu fiz o seguinte pra armazenar de forma invertida, se o tamanho for 4, então o valor máximo de i vai ser 3. Então pra armazenar de uma vez eu fiz o seguinte, a cada vez que o usuário digitar, eu faço essa fórmula (tamanho - j), onde o valor inicial de j é 1 e vai aumentando a cada vez que o laço for é executado
            SUPONDO QUE O TAMANHO QUE O USUÁRIO QUER É 4:
            A - i = 0, B - tamanho - 1 = 3
            A - i = 1, B - tamanho - 2 = 2
            A - i = 2, B - tamanho - 3 = 1
            A - i = 3, B - tamanho - 4 = 0 */
            j++; //Incremento na variável j no fim do laço
        }
        for (i = 0; i < tamanho; i++) { //Print dos vetores
            printf("Posição %d - Vetor A: %d | Vetor B: %d\n", i, a[i], b[i]);
        }
    }
    return 0;
}
#endif // ex10

#ifdef ex11
int num_intInput() {
    int a;
    printf("Digite um número: \n");
    scanf("%d", &a);
    return (a);
}
int main()
{
    /* Leia três vetores (A, B e C) de uma dimensão com 5 elementos cada. Construa o vetor D, sendo este a junção dos três outros vetores. Armazene no vetor D o primeiro elemento do vetor A depois do B e do C e assim sucessivamente. Apresentar o conteúdo de todos os vetores. Exiba quantas vezes apareceram números negativos no vetor D.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[5], b[5], c[5], d[15];
        int contador = 0;
        for (int i = 0; i <= 4; i++) {
            a[i] = num_intInput();
            d[i] = a[i];
            if (a[i] < 0) {
                contador = contador + 1;
            }
        }
        for (int i = 0; i <= 4; i++) {
            b[i] = num_intInput();
            d[i+5] = b[i];
            if (b[i] < 0) {
                contador = contador + 1;
            }
        }
        for (int i = 0; i <= 4; i++) {
            c[i] = num_intInput();
            d[i+10] = c[i];
            if (c[i] < 0) {
                contador = contador + 1;
            }
        }

        for (int i = 0; i <= 4; i++) {
            printf("Posição %d - A: %d; B: %d; C: %d\nD: %d %d %d\n", i, a[i], b[i], c[i], d[i], d[i+5], d[i+10]);
        }
        if (contador > 0) {
            printf("Foram digitados %d números negativos!", contador);
        }
    }
    return 0;
}
#endif // ex11

#ifdef ex12
int main()
{
    /* Leia o vetor A com 10 elementos positivos. Construa o vetor B de mesmo tipo, e cada elemento de B deve ser a metade de cada elemento de A. Exiba em que Vetor e em que posições apareceram valores superiores a 4*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[10], b[10];
        int contador = 0;
        for (int i = 0; i < 10; i++) {
            do {
                printf("Digite um número positivo: \n");
                scanf("%d", &a[i]);
                if (a[i] < 0) {
                    printf("Digite apenas números positivos! \n\n");
                }
            } while (a[i] < 0);
            b[i] = a[i] / 2;
        }

        for (int i = 0; i < 10; i++) {
            printf("Posição %d - Vetor A: %d; Vetor B: %d\n", i, a[i], b[i]);
            if (a[i] > 4 && b[i] > 4) {
                printf("Vetor A e B com número maior que 4 na posição %d\n", i);
            }
            else if (a[i] > 4) {
                printf("Vetor A com número maior que 4 na posição %d\n", i);
            }
            else if (b[i] > 4) {
                printf("Vetor B com número maior que 4 na posição %d\n", i);
            }
        }
    }
    return 0;
}
#endif // ex12

#ifdef ex13
int main()
{
    /* Elabore um programa que efetue o cálculo de uma tabuada de um número qualquer e armazene os resultados no vetor A de uma dimensão para 10 elementos. O usuário deverá digitar o número e o programa deverá construir e exibir a tabuada correspondente.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[10], i;
        do {
            printf("Digite um número para efetuar a sua tabuada: \n");
            scanf("%d", &a[0]);
            if (a[0] < 0) {
                printf("Digite apenas números positivos! \n\n");
            }
        } while (a[0] < 0);

        for (i = 1; i <= 10; i++) {
            int produto = a[0] * i;
            printf("%d * %d = %d\n", a[0], i, produto);
        }
    }
    return 0;
}
#endif // ex13

#ifdef ex14
int main()
{
    /* Receba a temperatura média de cada mês do ano e armazene essas temperaturas em um vetor; calcule e mostre a maior, a menor temperatura do ano e a média das temperaturas. Mostre todas as temperaturas armazenadas.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float temp[12];
        float media = 0;
        float maior = 0;
        float menor = 0;
        for (int i = 0; i < 12; i++) {
            do {
                printf("Digite a temperatura média do mês %d: \n", i+1);
                scanf("%f", &temp[i]);
                if (temp[i] < 0) {
                    printf("Digite apenas valores positivos! \n\n");
                }
            } while (temp[i] < 0);
            if (i == 0) {
                maior = temp[i];
                menor = temp[i];
            }
            else if (maior < temp[i]) {
                maior = temp[i];
            }
            else if (menor > temp[i]) {
                menor = temp[i];
            }
            printf("%.2f\n", maior);
            printf("%.2f\n", menor);

            media = (media + temp[i]) / (i+1);
        }
        for (int i = 0; i < 12; i++) {
            printf("Temperatura média do mês %d: %.2f°C\n", i+1, temp[i]);
        }
        printf("A maior temperatura média foi de %.2f°C, a menor foi de %.2f°C.\nA temperatura média anual foi de %.2f°C", maior, menor, media);
    }
    return 0;
}
#endif // ex14

#ifdef ex15
int main()
{
    /* Receba a nota de dez alunos e armazene essas notas em um vetor. Calcule e mostre:

a) A média da classe;

b) A quantidade de alunos aprovados, isto é, com nota >=7;

c) A quantidade de alunos reprovados, isto é, com nota <7.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float notas[10];
        float media = 0;
        int aprovados = 0;
        int reprovados = 0;

        for (int i = 0; i < 10; i++) {
            do {
                printf("Digite a nota do aluno %d: \n", i+1);
                scanf("%f", &notas[i]);
                if (notas[i] < 0) {
                    printf("Digite apenas números positivos! \n\n");
                }
            } while (notas[i] < 0);

            if (notas[i] >= 7) {
                aprovados = aprovados + 1;
            }
            else {
                reprovados = reprovados + 1;
            }
            media = (media + notas[i]) / (i+1);
        }

        for (int i = 0; i < 10; i++) {
            printf("Nota do aluno %d: %.2f\n", i+1, notas[i]);
        }

        if (aprovados > 0) {
            printf("%d alunos foram aprovados!\n", aprovados);
        }
        if (reprovados > 0) {
            printf("%d alunos foram reprovados!\n", reprovados);
        }
    }
    return 0;
}
#endif // ex15

#ifdef ex16
int main()
{
    /* Receba o peso via teclado e o número de identificação gerado pelo programador contendo no máximo de 15 pessoas. A quantidade de indivíduos será definida pelo usuário. Armazene esses dados em dois vetores, o primeiro contendo os pesos e o segundo contendo os números de identificação. Calcule e mostre:

a) Quantas pessoas apresentaram peso superior ao menor peso. Armazene os números de identificação das pessoas que satisfazem essa condição. Mostre o conteúdo desse vetor.

b) Armazene num outro vetor os pesos superiores a 55 quilos e menores ou igual a 80 quilos das pessoas. Mostre o conteúdo desse vetor.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int tam;
        do {
            printf("Digite o tamanho de vetor desejado: \n");
            scanf("%d", &tam);
            if (tam < 0 || tam > 15) {
                printf("Digite apenas números entre 0 e 15! \n\n");
            }
        } while (tam < 0 || tam > 15);

        float vetPeso[tam];
        int numId[tam];
        int menor;
        int contador;

        for (int i = 0; i < tam; i++) {
            do {
                printf("Digite o peso: \n");
                scanf("%f", &vetPeso[i]);
                if (vetPeso[i] < 0) {
                    printf("Digite um valor válido! \n\n");
                }
            } while (vetPeso[i] < 0);
            if (i == 0) {
                menor = vetPeso[i];
            }
            if (menor > vetPeso[i]) {
                menor = vetPeso[i];
            }

            numId[i] = 100 + (i + 1);
        }
        printf("\nVETOR CONTENDO PESO SUPERIOR AO MENOR PESO: \n");
        for (int i = 0; i < tam; i++) {
            if (vetPeso[i] > menor) {
                contador = contador + 1;
                printf("O ID %d apresentou %.2fkg\n", numId[i], vetPeso[i]);
            }
        }
        printf("\nVETOR COM PESOS ENTRE 55 E 80KG: \n");
        for (int i = 0; i < tam; i++) {
            if (vetPeso[i] > 55 && vetPeso[i] <= 80) {
                printf("O ID %d apresentou %.2fkg\n", numId[i], vetPeso[i]);
            }
        }

    }
    return 0;
}
#endif // ex16

#ifdef ex17
int main()
{
    /*Efetue a leitura de dez elementos para o vetor A. Construa o vetor B, observando a seguinte lei de formação: se o valor do índice do vetor for par, o valor do elemento deve ser multiplicado pelo valor 5; sendo o índice ímpar, deverá ser somado ao valor existente o valor 5. Mostre o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[10], b[10];
        for (int i = 0; i < 10; i++) {
            printf("Digite um valor: \n");
            scanf("%d", &a[i]);
            if (i % 2 == 0) {
                b[i] = a[i] * 5;
            }
            else {
                b[i] = a[i] + 5;
            }
        }

        for (int i = 0; i < 10; i++) {
            printf("Posição %d - A: %d; B: %d\n", i, a[i], b[i]);
        }
    }
    return 0;
}
#endif // ex17

#ifdef ex18
int main()
{
    /* Efetue a leitura de dez elementos para o vetor A. No final, apresente a somatória de todos os elementos do vetor A que sejam ímpares. Armazene no vetor B a posição em que estão armazenados os números ímpares. Mostre o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[10], b[10];
        int soma = 0;

        for (int i = 0; i < 10; i++) {
            printf("Digite um número: \n");
            scanf("%d", &a[i]);
            float paridade = a[i] %  2;
            if (paridade != 0) {
                b[i] = i;
                soma = soma + a[i];
            }
        }

        for (int i = 0; i < 10; i++) {
            printf("Posição %d - %d\n", i, a[i]);
        }
        printf("Elementos ímpares nas posições:");
        for (int i = 0; i < 10; i++) {
            float paridade = a[i] %  2;
            if (paridade != 0) {
                printf("%d ", b[i]);
            }
        }
        printf("\nA soma dos números ímpares é de %d", soma);
    }
    return 0;
}
#endif // ex18

#ifdef ex19
int main()
{
    /* Leia 12 elementos inteiros para o vetor A e construa o vetor B com a mesma dimensão, observando a seguinte lei de formação: “Todo elemento do vetor A que for ímpar deve ser multiplicado por 2; caso contrário, o elemento do vetor A deve permanecer constante”. Exiba o conteúdo dos dois vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[12], b[12];
        for (int i = 0; i < 12; i++) {
            printf("Digite um número: \n");
            scanf("%d", &a[i]);
            int paridade = a[i] % 2;
            if (paridade == 0) {
                b[i] = a[i];
            }
            else {
                b[i] = a[i] * 2;
            }
        }

        for (int i = 0; i < 12; i++) {
            printf("Posição %d - A: %d; B: %d\n", i, a[i], b[i]);
        }

        }
    return 0;
}
#endif // ex19

#ifdef ex20
int main()
{
    /* Receba o salário e o número de identificação gerado pelo programador contendo no máximo 13 pessoas. A quantidade de indivíduos será definida pelo usuário. Armazene esses dados em dois vetores, o primeiro contendo os salários e o segundo contendo os números de identificação. Calcule e mostre:

a) Armazene em um vetor os números de identificação de todas as pessoas que apresentam a maior salário.

b) Armazene num outro vetor os números de identificação de todas as pessoas que apresentam a menor salário encontrado. Mostre o conteúdo de todos os vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int tam;
        do {
            printf("Digite o tamanho do vetor: \n");
            scanf("%d", &tam);
            if (tam <= 0 || tam > 13) {
                printf("Digite um número de 0 a 13! \n\n");
            }
        } while (tam <= 0 || tam > 13);

        float salario[tam], maior, menor;
        int numId[tam], vetMaior[tam], vetMenor[tam];

        for (int i = 0; i < tam; i++) {
            do {
                printf("Digite o salário: \n");
                scanf("%f", &salario[i]);
                if (salario[i] <= 0) {
                    printf("Digite um valor válido! \n\n");
                }
            } while (salario[i] <= 0);
            if (i == 0) {
                maior = salario[i];
                menor = salario[i];
            }
            if (maior < salario[i]) {
                maior = salario[i];
            }
            if (menor > salario[i]) {
                menor = salario[i];
            }
            numId[i] = 100 + (i+1);
        }

        for (int i = 0; i < tam; i++) {
            if (salario[i] == maior) {
                vetMaior[i] = numId[i];
            }
            else {
                vetMaior[i] = 0;
            }
            if (salario[i] == menor) {
                    vetMenor[i] = numId[i];
            }
            else {
                vetMenor[i] = 0;
            }
        }

        for (int i = 0; i < tam; i++) {
            if (i == 0) {
                printf("\nLista de funcionários com o maior salário: \n");
            }
            if (vetMaior[i] != 0) {
                printf("%d\n", vetMaior[i]);
            }

            if (i == tam - 1) {
                for (int i = 0; i < tam; i++) {
                    if (i == 0) {
                        printf("\nLista de funcionários com o menor salário: \n");
                    }
                    if (vetMenor[i] != 0) {
                        printf("%d\n", vetMenor[i]);
                    }
                }
            }
        }


    }
    return 0;
}
#endif // ex20

#ifdef ex21
int numInput() {
    int a;
    printf("Digite um número: \n");
    scanf("%d", &a);
    return (a);
}
int main()
{
    /* Leia 8 elementos (valores inteiros) para os vetores A e B de uma dimensão do tipo vetor. Construir vetores C e D de mesmo tipo e dimensão. O vetor C deve ser formado pelos elementos de índice ímpar dos vetores A e B, e O vetor D deve ser formado pelos elementos de índice par dos vetores A e B. Apresente os conteúdos de todos os vetores.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[8], b[8], c[8], d[8];
        for (int i = 0; i < 8; i++){
            if (i == 0) {
                printf("Valores para o vetor A:\n");
            }
            a[i] = numInput();
        }
        for (int i = 0; i < 8; i++){
            if (i == 0) {
                printf("Valores para o vetor B:\n");
            }
            b[i] = numInput();
        }
        for (int i = 0; i < 8; i++){
            int paridade = i % 2;
            if (paridade != 0) {
                c[i] = a[i];
                c[i+3] = b[i];
            }
            else {
                d[i] = a[i];
                d[i+3] = b[i];
            }
        }
        for (int i = 0; i < 8; i++){
            if (i == 0) {
            printf("\nVetores A e B\n");
            }
            printf("Posição %d - A: %d; B: %d\n", i, a[i], b[i]);

            if (i == 7) {
                for (int i = 0; i < 8; i++) {
                    if (i == 0) {
                        printf("\nVetores C e D\n");
                    }
                    printf("Posição %d - C: %d; D: %d\n", i, a[i], b[i]);
                }
            }
        }

        }
    return 0;
}
#endif // ex21

#ifdef ex22
int numInput() {
    int a;
    printf("Digite um número: \n");
    scanf("%d", &a);
    return (a);
}
int main()
{
    /*Leia dois vetores A e B de uma dimensão com 6 elementos. O vetor A deve aceitar apenas a entrada de valores pares, enquanto o vetor B deve aceitar apenas a entrada de valores ímpares. A entrada dos dois vetores deve ser validada pelo programa e não pelo usuário. Construir o vetor C que deverá ser a junção dos vetores A e B, de modo que seja armazenado um elemento do vetor A e em seguida um elemento do vetor B. O vetor C contenha 12 elementos. Exiba os conteúdos dos vetores A e B juntos e depois o conteúdo do vetor C.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a[6], b[6], c[12];
        int paridade;
        int j = 1;
        printf("Vetor A:\n");
        for (int i = 0; i < 6; i++) {
            do {
                a[i] = numInput();
                paridade = a[i] % 2;
                if (paridade != 0) {
                    printf("Digite apenas valores pares!\n\n");
                }
            } while (paridade != 0);
        }

        printf("Vetor B:\n");
        for (int i = 0; i < 6; i++) {
            do {
                b[i] = numInput();
                paridade = b[i] % 2;
                if (paridade == 0) {
                    printf("Digite apenas valores ímpares! \n\n");
                }
            } while (paridade == 0);
            }

        for (int i = 0; i < 12; i++){
            c[i+i] = a[i];
            c[i+j] = b[i];
            j++;
        }

        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                printf("\nVetores A e B:\n");
            }
            printf("Posição %d - A: %d; B: %d\n", i, a[i], b[i]);
        }

        for (int i = 0; i < 12; i++) {
            if (i == 0) {
                printf("\nVetor C:\n");
            }
            printf("Posição %d - C: %d\n", i, c[i]);
        }
        }

    return 0;
    }
#endif // ex22

#ifdef exteste
main(){
    float A[10],maior;
    int i, vezes = 0;
    setlocale(LC_ALL,"");

    for(i=0; i<10; i++)
    {
        do
        {
            printf("Insira 10 números positivos[%d]:",i);
            scanf("%f", &A[i]);
            if(A[i]<=0) {
                printf("Número inválido, Digite apenas números positivos.\n");
            }
            if (i == 0) {
                maior = A[i];
            }
            else if (maior < A[i]) {
                maior = A[i];
            }
        }
        while(A[i]<=0);
    }
    for(i=0; i<10; i++)
    {
        if(A[i] == maior)
        {
            vezes++;
        }
        printf("Os números inseridos no vetor A[%d] são: %.2f\n",i,A[i]);
    }
    printf("O maior número apareceu %d vezes nas posições: ", vezes);
    for(i=0; i<10; i++)
    {
        if (A[i] == maior) {
            printf("%d ", i);
        }
    }
    return 0;
}
#endif // exteste



