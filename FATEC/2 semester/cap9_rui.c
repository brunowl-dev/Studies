#include <stdio.h>
#include <locale.h>
#define funcaoMenu
#define ex3

#ifdef funcaoMenu
int funcMenu() {
    int start;
    do {
        system("cls");
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
#endif //funcaoMenu

#ifdef ex1
struct dados {
        char a;
        int b;
        long c;
        float d;
        double e;
        unsigned char f;
        unsigned int g;
        unsigned long h;
    };
void receberDados(struct dados *p) {
    printf("Digite o char:\n");
    scanf("%c", &p->a);
    getchar();
    printf("Digite o int:\n");
    scanf("%d", &p->b);
    printf("Digite o long:\n");
    scanf("%ld", &p->c);
    printf("Digite o float:\n");
    scanf("%f", &p->d);
    printf("Digite o double:\n");
    scanf("%lf", &p->e);
    printf("Digite o unsigned char:\n");
    scanf(" %c", &p->f);
    getchar();
    printf("Digite o unsigned int:\n");
    scanf("%u", &p->g);
    printf("Digite o unsigned long:\n");
    scanf("%lu", &p->h);
}
void imprimir(struct dados *p) {
    /*              10        20        30        40        50        60        70
            1234567890123456789012345678901234567890123456789012345678901234567890
                char      int       long                float               double
                      unsigned char       unsigned int        unsigned long*/
    printf("    %-4c      %-11d     %-11ld              %-8g                %-9g \n", p->a, p->b, p->c, p->d, p->e);
    printf("          %-3u                %-10u               %-10lu             \n", p->f, p->g, p->h);
}
main()
{
    /*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato, tambem numa funcao.

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/
    setlocale(LC_ALL, "");
    struct dados jockey;
    struct dados *p;
    p = &jockey;
    while (funcMenu() != 0 ) {
        system("cls");
        getchar();
        receberDados(p);
        imprimir(p);
        system("pause");
        printf("\n");
    }
    printf("Saindo do programa!\n");
}
#endif //ex1

#ifdef ex2
void recebeString(char *p1, char *p2) {
    printf("Digite a primeira string:\n");
    scanf("%s", p1);
    getchar();
    printf("Digite a segunda string:\n");
    scanf("%s", p2);
}
int comparar(char *p1, char *p2) {
    int i;
    for (i = 0; p1[i] != '\0'; i++) {
        if (p1[i] != p2[i]) {
            break;
        }
    }
    if (p1[i] == '\0' && p2[i] == '\0') {
        return 1;
    }
    else {
        return 0;
    }
}
main() {
    /*2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/
    setlocale(LC_ALL, "");
    char string1[10], string2[10], *p1, *p2;
    p1 = &string1[0], p2 = &string2[0];
    while (funcMenu() != 0) {
        system("cls");
        recebeString(p1, p2);
        if (comparar(p1,p2) == 1) {
            printf("IGUAIS\n");
        }
        else {
            printf("DIFERENTES\n");
        }
        system("pause");
    }
    printf("Saindo do programa!\n");
}
#endif // ex2

#ifdef ex3
int soma(int *pn1, int *pn2) {
    int resultado = *pn1 + *pn2;
    return(resultado);
}
int sub(int *pn1, int *pn2) {
    int resultado = *pn1 - *pn2;
    return(resultado);
}
int mult(int *pn1, int *pn2) {
    int resultado = *pn1 * *pn2;
    return(resultado);
}
int div(int *pn1, int *pn2) {
    int resultado = *pn1 / *pn2;
    return(resultado);
}
main() {
    /*3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/
    setlocale(LC_ALL, "");
    int i, acumulado = 0, num1, num2, *pn1, *pn2;
    pn1 = &num1;
    pn2 = &num2;
    int opcao;
    do {
        system("cls");
        printf("MENU\n1-Soma\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Saída\n");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 5) {
            printf("Digite uma opção válida!\n");
        }
        switch(opcao) {
        case 1:
            printf("Digite o primeiro e segundo número:\n");
            scanf("%d %d", pn1, pn2);
            acumulado = acumulado + soma(pn1, pn2);
            break;
        case 2:
            printf("Digite o primeiro (este será o minuendo) e segundo número (este será o subtraendo):\n");
            scanf("%d %d", pn1, pn2);
            acumulado = acumulado + sub(pn1, pn2);
            break;
        case 3:
            printf("Digite o primeiro e segundo número:\n");
            scanf("%d %d", pn1, pn2);
            acumulado = acumulado + mult(pn1, pn2);
            break;
        case 4:
            printf("Digite o primeiro (este será o dividendo) e segundo número (este será o divisor):\n");
            scanf("%d %d", pn1, pn2);
            acumulado = acumulado + div(pn1, pn2);
            break;
        }
    } while (opcao != 5);
    printf("O valor acumulado é %d\n", acumulado);
}
#endif // ex3

#ifdef ex4
int pesquisar(char *pl, char *pv) {
    int i, resultado = 0;
    for (i = 0; i < 13; i++) {
        if (*pl == pv[i]) {
            resultado = 1;
            break;
        }
    }
    return (resultado);
}
main() {
    /*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
    setlocale(LC_ALL, "");
    char letra, vetor[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'}, *pl, *pv;
    pl = &letra;
    pv = &vetor[0];
    while (funcMenu() != 0) {
        system("cls");
        printf("Digite a letra a ser pesquisada:\n");
        scanf(" %c", &letra);
        if (pesquisar(pl, pv) == 1) {
            printf("A letra foi encontrada!\n");
        }
        else {
            printf("A letra não foi encontrada!\n");
        }
        system("pause");
        printf("\n");
    }
    printf("Finalizando o programa...\n");
}
#endif // ex4

#ifdef ex5
struct dados {
    char nome[10], end[20], cidade[10], estado[2], cep[11];
};
void receber(struct dados *p) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("Digite o nome do índice %d\n", i);
        gets((p+i)->nome);
        printf("Digite o endereço do(a) %s\n", (p+i)->nome);
        gets((p+i)->end);
        printf("Digite a cidade do(a) %s\n", (p+i)->nome);
        gets((p+i)->cidade);
        printf("Digite a sigla do estado do(a) %s\n", (p+i)->nome);
        gets((p+i)->estado);
        printf("Digite o CEP do(a) %s\n", (p+i)->nome);
        gets((p+i)->cep);
        system("CLS");
    }
}
void imprimir(struct dados *p) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("Nome - %s; Índice %d\n", (p+i)->nome, i);
        printf("Endereço - %s\nCidade - %s\nEstado - %s\nCEP - %s\n", (p+i)->end, (p+i)->cidade, (p+i)->estado, (p+i)->cep);
        printf("\n");
    }
}
main() {
    /*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep*/
    setlocale(LC_ALL, "");
    int opcao;
    struct dados infos[4], *p;
    p = &infos[0];
    do {
        printf("MENU\n1-Receber registros\n2-Imprimir registros\n3-Sair\n");
        scanf("%d", &opcao);
        getchar();
        system("CLS");
        switch(opcao) {
        case 1:
            receber(p);
            break;
        case 2:
            imprimir(p);
            system("pause");
            system("cls");
            break;
        }
    } while (opcao != 3);
    printf("Finalizando o programa...\n");
}
#endif // ex5

#ifdef ex6
struct dados {
    char nome[10], end[20], cidade[10], estado[3], cep[11];
};
void receber(struct dados *p) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("Digite o nome do índice %d\n", i);
        scanf("%s", (p+i)->nome);
        printf("Digite o endereço do(a) %s\n", (p+i)->nome);
        scanf("%s", (p+i)->end);
        printf("Digite a cidade do(a) %s\n", (p+i)->nome);
        scanf("%s", (p+i)->cidade);
        printf("Digite a sigla do estado do(a) %s\n", (p+i)->nome);
        scanf("%s", (p+i)->estado);
        printf("Digite o CEP do(a) %s\n", (p+i)->nome);
        scanf(" %s", (p+i)->cep);
        system("CLS");
    }
}
void imprimir(struct dados *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if((p+i)->nome[0] != '*') {
            printf("Nome - %s; Índice %d\n", (p+i)->nome, i);
        printf("Endereço - %s\nCidade - %s\nEstado - %s\nCEP - %s\n", (p+i)->end, (p+i)->cidade, (p+i)->estado, (p+i)->cep);
        printf("\n");
        }
    }
}
int procurar(struct dados *p) {
    int i, j, resultado = -1;
    char nome[10];
    printf("Digite o nome do registro a ser procurado:\n");
    scanf("%s", &nome);
    for (i = 0; i < 4; i++) {
        for(j = 0; nome[j] != '\0'; j++) {
            if(nome[j] != (p+i)->nome[j]) {
                break;
            }
        }
        if(nome[j] == '\0' && (p+i)->nome[j] == '\0') {
            printf("Registro encontrado!\n");
            printf("Nome - %s; Índice %d\n", (p+i)->nome, i);
            printf("Endereço - %s\nCidade - %s\nEstado - %s\nCEP - %s\n", (p+i)->end, (p+i)->cidade, (p+i)->estado, (p+i)->cep);
            resultado = i;
            break;
        }
    }
    if(resultado == -1) {
        printf("Registro não encontrado!\n");
    }
    return (resultado);
}
void alterar(struct dados *p) {
    int alterar;
    alterar = procurar(p);
    if (alterar != -1) {
        printf("Digite o nome do índice %d\n", alterar);
        scanf("%s", (p+alterar)->nome);
        printf("Digite o endereço do(a) %s\n", (p+alterar)->nome);
        scanf("%s", (p+alterar)->end);
        printf("Digite a cidade do(a) %s\n", (p+alterar)->nome);
        scanf("%s", (p+alterar)->cidade);
        printf("Digite a sigla do estado do(a) %s\n", (p+alterar)->nome);
        scanf("%s", (p+alterar)->estado);
        printf("Digite o CEP do(a) %s\n", (p+alterar)->nome);
        scanf(" %s", (p+alterar)->cep);
        system("CLS");
    }
}
void excluir(struct dados *p) {
    int excluir = procurar(p);
    if (excluir != -1) {
        (p+excluir)->nome[0] = '*';
        printf("Registro excluído com sucesso!\n");
    }
}
main() {
    /*6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.*/
    setlocale(LC_ALL, "");
    int opcao;
    struct dados infos[4], *p;
    p = &infos[0];
    do {
        system("cls");
        printf("MENU\n1-Receber registros\n2-Imprimir registros\n3-Procurar registro\n4-Alterar registro\n5-Excluir registro\n6-Sair\n");
        scanf("%d", &opcao);
        getchar();
        system("CLS");
        switch(opcao) {
        case 1:
            receber(p);
            break;
        case 2:
            imprimir(p);
            system("pause");
            break;
        case 3:
            procurar(p);
            system("pause");
            break;
        case 4:
            alterar(p);
            system("pause");
            break;
        case 5:
            excluir(p);
            system("pause");
            break;
        }
    } while (opcao != 6);
    printf("Finalizando o programa...\n");
}
#endif // ex
