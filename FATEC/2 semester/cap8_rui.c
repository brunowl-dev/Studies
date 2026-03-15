#include <stdio.h>
#include <locale.h>
#define ex3
#define funcaoMenu

#ifdef funcaoMenu
int funcMenu() {
    int start;
    do {
        printf("MENU\n");
        printf("0-Sair o programa\n");
        printf("1-Iniciar do programa\n");
        scanf("%d", &start);
        if (start != 1 && start != 0) {
            printf("Digite apenas os números 1 ou 0!\n");
        }
    } while (start != 1 && start != 0);
    return (start);
}
#endif // funcaoMenu

#ifdef ex1
int a;
long b;
unsigned c;
float d;
double e;
char f;
unsigned long g;
unsigned char h;
main()
{
    /*1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/
    int i, *pa = &a;
    long *pb = &b;
    unsigned *pc = &c;
    float *pd = &d;
    double *pe = &e;
    char *pf = &f;
    unsigned long *pg = &g;
    unsigned char *ph = &h;
    setlocale(LC_ALL, "");
    while (funcMenu() != 0) {
        printf("Digite um valor int para o ponteiro:\n");
        scanf("%d", pa);

        printf("Digite um valor long para o ponteiro:\n");
        scanf("%ld", pb);

        printf("Digite um valor unsigned para o ponteiro:\n");
        scanf("%u", pc);

        printf("Digite um valor float para o ponteiro:\n");
        scanf("%f", pd);

        printf("Digite um valor double para o ponteiro:\n");
        scanf("%lf", pe);

        printf("Digite um valor char para o ponteiro:\n");
        scanf(" %c", pf);

        printf("Digite um valor unsigned long para o ponteiro:\n");
        scanf("%lu", pg);

        printf("Digite um valor unsigned char para o ponteiro:\n");
        scanf(" %c", ph);
        /*1 - Escreva um programa que receba via teclado usando ponteiros um char,
        int, long, unsigned, float, double, unsigned long e unsigned char,
        e imprima-os no video utilizando ponteiros no seguinte formato:

                10        20        30        40        50        60
        123456789012345678901234567890123456789012345678901234567890
            int                 long                unsigned
                      float               double              char
                 unsigned long       unsigned char*/
printf("    %-11d               %-11ld              %-10u\n         ", *pa, *pb, *pc);
printf("              %-8g                %-9g                %-4c\n", *pd, *pe, *pf);
printf("         %-10lu              %-3u                         \n", *pg, *ph);
    }
    printf("Saindo do programa!\n");
}
#endif //ex1

#ifdef ex2
main()
{
    int num, media = 0, i = 0;
    int *pnum = &num;
    int *pmedia = &media;
    int *pi = &i;
    /*2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.*/
    setlocale(LC_ALL, "");
    while (funcMenu() != 0) {
        for(;;) {
           printf("Digite um valor positivo:\n");
           scanf("%d", pnum);
           if (*pnum < 0) {
            break;
           }
           *pmedia = *pnum + *pmedia;
           *pi = *pi + 1;
        }
        *pmedia = *pmedia / *pi;
        printf("A média dos números é: %d\n", *pmedia);
    }
    printf("Saindo do programa!\n");
}
#endif //ex2

#ifdef ex3
char string1[10], string2[10];
int comparar() {
    int i;
    for (i = 0; string1[i] != '\0'; i++) {
        if (string1[i] != string2[i]) {
            break;
        }
    }
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 1;
    }
    else {
        return 0;
    }
}
main()
{
    /*3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global*/
    setlocale(LC_ALL, "");
    char *ps1 = &string1[0], *ps2 = &string2[0];
    while (funcMenu() != 0) {
        getchar();
        printf("Digite a string 1:\n");
        scanf(" %s", ps1);
        printf("Digite a string 2:\n");
        scanf(" %s", ps2);
        if (comparar() == 1) {
            printf("IGUAIS\n");
        }
        else {
            printf("DIFERENTES\n");
        }

        printf("\n");
    }
    printf("Saindo do programa!\n");
}
#endif //ex3

#ifdef ex4
//Também usar ponteiro para a letra; Ponteiro de vetor, tem que ser global?
char vetor[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w'}, *pv;
int pesquisar(char letra) {
    int resultado = 0, i;
    for (i = 0; i < 13; i++) {
        if (pv[i] == letra) {
            resultado = i + 1;
            break;
        }
    }
    return (resultado);
}
main() {
    /*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como
    informacao para a funcao a letra digitada. (utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
    setlocale(LC_ALL, "");
    char letra;
    pv = &vetor[0];
    while (funcMenu() != 0) {
        printf("Digite uma letra\n");
        scanf(" %c", &letra);
        if (pesquisar(letra) != 0) {
            printf("A letra foi encontrada!\n");
        }
        else {
            printf("A letra não foi encontrada!\n");
        }
        printf("\n");
    }
}
#endif // ex4

#ifdef ex5
struct dados {
    char nome[10];
    char end[20];
    char cidade[10];
    char estado[2];
    int cep;
};
struct dados localizacao[4];
struct dados *p;
void recebeDados() {
    int i;
    for (i = 0; i < 4; i++) {
        printf("Digite o nome para o índice %d:\n", i);
        scanf("%s", &(p+i)->nome);
        printf("Digite o endereço para o índice %d:\n", i);
        scanf("%s", &(p+i)->end);
        printf("Digite o nome da cidade para o índice %d:\n", i);
        scanf("%s", &(p+i)->cidade);
        printf("Digite a sigla do estado para o índice %d:\n", i);
        scanf("%s", &(p+i)->estado);
        printf("Digite o CEP para o índice %d: \n", i);
        scanf("%d", &(p+i)->cep);
    }
}
void imprimeDados() {
    int i;
    for (i = 0; i < 4; i++) {
        printf("Índice %d\nNome - %s\nEndereço - %s\nCidade - %s\nEstado - %s\nCEP - %d\n", i, (p+i)->nome, (p+i)->end, (p+i)->cidade, (p+i)->estado, (p+i)->cep);
        printf("\n");
    }
}
main() {
    /*5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa funcao usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/
    setlocale(LC_ALL, "");
    while (funcMenu() != 0) {
        p = &localizacao[0];
        recebeDados();
        imprimeDados();
        printf("\n");
    }
}
#endif // ex5

#ifdef ex6
struct data {
    int dia, mes, ano;
};
struct data datas[2];
struct data *p;
void calculaDias() {
    int dias, meses, anos;
    dias = ((p+1)->dia - (p+0)->dia) + (((p+1)->mes - (p+0)->mes) * 30) + (((p+1)->ano - (p+0)->ano) * 365);
    printf("O número de dias é: %d\n", dias);
}
main() {
    /*6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano*/
    setlocale(LC_ALL, "");
    p = &datas[0];
    while (funcMenu() != 0) {
        printf("Digite o dia, mês e ano (respectivamente) da data mais antiga:\n");
        scanf("%d %d %d", &(p+0)->dia, &(p+0)->mes, &(p+0)->ano);
        printf("Digite o dia, mês e ano (respectivamente) da data mais nova:\n");
        scanf("%d %d %d", &(p+1)->dia, &(p+1)->mes, &(p+1)->ano);
        calculaDias();
        printf("\n");
    }
}
#endif // ex6
