#include <stdio.h>
#include <locale.h>
#define ex4
#define funcaoMenu

#ifdef funcaoMenu
int funcMenu() {
    int start;
    do {
        system("cls");
        printf("MENU\n");
        printf("0-Sair o programa\n");
        printf("1-Iniciar do programa\n");
        scanf("%d", &start);
        getchar();
        if (start != 1 && start != 0) {
            printf("Digite apenas os números 1 ou 0!\n");
        }
    } while (start != 1 && start != 0);
    return (start);
}
#endif // funcaoMenu

#ifdef ex1
/*1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faca um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep*/
struct dados {
    char nome[10];
    char end[20];
    char cidade[10];
    char estado[2];
    int cep;
};
struct dados localizacao[4];
void recebeDados() {
    int i;
    for (i = 0; i < 4; i++) {
        system("cls");
        printf("Digite o nome para o índice %d:\n", i);
        scanf("%s", &localizacao[i].nome);
        printf("Digite o endereço para o índice %d:\n", i);
        scanf("%s", &localizacao[i].end);
        printf("Digite o nome da cidade para o índice %d:\n", i);
        scanf("%s", &localizacao[i].cidade);
        printf("Digite a sigla do estado para o índice %d:\n", i);
        scanf("%s", &localizacao[i].estado);
        printf("Digite o CEP para o índice %d: \n", i);
        scanf("%d", &localizacao[i].cep);
    }
}
void imprimeDados() {
    system("cls");
    int i;
    for (i = 0; i < 4; i++) {
        printf("Índice %d\nNome - %s\nEndereço - %s\nCidade - %s\nEstado - %s\nCEP - %d\n", i, localizacao[i].nome, localizacao[i].end, localizacao[i].cidade, localizacao[i].estado, localizacao[i].cep);
        printf("\n");
    }
    system("pause");
}
int main()
{
    setlocale(LC_ALL, "");
    int opcao;
    do {
        printf("MENU\n1-Receber Dados\n2-Imprimir Dados\n3-Sair\n");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 4) {
            printf("Digite uma opção válida!\n");
        }
        switch (opcao) {
        case 1:
            recebeDados();
            break;
        case 2:
            imprimeDados();
            break;
        }
    } while (opcao != 3);
    printf("Saindo do programa!\n");
}
#endif //ex1

#ifdef ex2
/*2 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano*/
struct data {
    int dia, mes, ano;
};
struct data vetor[2];
int calcularDatas() {
    int dias = 0;
    if (vetor[0].dia < vetor[1].dia) {
        dias = (vetor[1].dia - vetor[0].dia);
    }
    else {
        dias = (vetor[0].dia - vetor[1].dia);
    }
    if (vetor[0].mes < vetor[1].mes) {
        dias = dias + ((vetor[1].mes - vetor[0].mes) * 30);
    }
    else {
        dias = dias + ((vetor[0].mes - vetor[1].mes) * 30);
    }
    if (vetor[0].ano < vetor[1].ano) {
        dias = dias + ((vetor[1].ano - vetor[0].ano) * 365);
    }
    else {
        dias = dias + ((vetor[0].ano - vetor[1].ano) * 365);
    }
    return (dias);
}
int main()
{
    setlocale(LC_ALL, "");
    while (funcMenu() != 0) {
        int i;
        for (i = 0; i < 2; i++) {
            printf("Digite o dia, mês e ano do índice %d:\n", i);
            scanf("%d %d %d", &vetor[i].dia, &vetor[i].mes, &vetor[i].ano);
        }
        system("cls");
        printf("A diferença de dias entre as datas é: %d\n", calcularDatas());
        system("pause");
        printf("\n");
    }
    printf("Saindo do programa!\n");
}
#endif //ex2

#ifdef ex3
/*3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/
struct estrutura{
    char a;
    int b;
    long c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long h;
};
struct estrutura dados;
void recebeDados() {
    printf("Digite a variável char:\n");
    dados.a = getchar();
    printf("Digite a variável int:\n");
    scanf("%d", &dados.b);
    printf("Digite a variável long:\n");
    scanf("%ld", &dados.c);
    printf("Digite a variável float:\n");
    scanf("%f", &dados.d);
    printf("Digite a variável double:\n");
    scanf("%lf", &dados.e);
    getchar();
    printf("Digite a variável unsigned char:\n");
    dados.f = getchar();
    printf("Digite a variável unsigned int:\n");
    scanf("%u", &dados.g);
    printf("Digite a variável unsigned long:\n");
    scanf("%lu", &dados.h);
}
void mostrarDados() {
    /*            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/
    printf("    %-4c      %-11d     %-11ld              %-8g                %-9g\n", dados.a, dados.b, dados.c, dados.d, dados.e);
    printf("          %-3u                %-10u               %-10lu\n", dados.f, dados.g, dados.h);
}
int main()
{
    setlocale(LC_ALL, "");
    while (funcMenu() != 0) {
        recebeDados();
        mostrarDados();
        system("pause");
        printf("\n");
    }
    printf("Saindo do programa!\n");
}
#endif //ex3

#ifdef ex4
/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura*/
struct dados {
    char nome[10];
    float peso;
    float altura;
};
struct dados pessoas[4];
void receberDados() {
    int i;
    for (i = 0; i < 4; i++) {
        system("cls");
        printf("Input - Índice %d\n", i);
        printf("Digite o nome da pessoa do índice %d\n", i);
        scanf("%s", &pessoas[i].nome);
        printf("Digite o peso em kg da pessoa do índice %d\n", i);
        scanf("%f", &pessoas[i].peso);
        printf("Digite a altura da pessoa do índice %d em metros e separando com vírgula\n", i);
        scanf("%f", &pessoas[i].altura);
    }
}
void imprimirDados() {
    system("cls");
    int i;
    for (i = 0; i < 4; i++) {
        printf("%s - Índice %d\n", pessoas[i].nome, i);
        printf("%.2f kg\n", pessoas[i].peso);
        printf("%.2f m\n", pessoas[i].altura);
    }
}
void calculaIMC() {
    system("cls");
    int i;
    for (i = 0; i < 4; i++) {
        printf("%s\nIMC - %.2f\n", pessoas[i].nome, pessoas[i].peso/(pessoas[i].altura * pessoas[i].altura));
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int opcao;
    while (opcao != 4) {
        printf("MENU\n");
        printf("1-Receber todos os dados\n2-Imprime todos os dados\n3-Calcular o IMC de todas as pessoas\n4-Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            receberDados();
            break;
        case 2:
            imprimirDados();
            system("pause");
            break;
        case 3:
            calculaIMC();
            system("pause");
            break;
        case 4:
            break;
        }
    }
    printf("Finalizando o programa...\n");
}
#endif //ex4
