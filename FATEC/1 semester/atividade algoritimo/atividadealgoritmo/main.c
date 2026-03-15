#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define ex4
#define funcoes

#ifdef funcoes
int menu() {
    int iniciar;
    do {
        printf("Deseja iniciar o programa?\n0-N�o\n1-Sim\n");
        scanf("%d", &iniciar);
        if (iniciar != 1 && iniciar != 0) {
            printf("Insira apenas os n�meros 0 ou 1.\n\n");
        }
    } while (iniciar != 1 && iniciar != 0);

    return (iniciar);
}

float inputNota() {
    float nota;
    do {
        printf("Digite a respectiva nota: \n");
        scanf("%f", &nota);
        if (nota < 0 || nota > 10) {
            printf("Valor inv�lido! Por favor insira apenas valores entre 0 e 10.\n\n");
        }
    } while (nota < 0 || nota > 10);

    return(nota);
}

float inputMedida() {
    float medida;

    do {
        printf("Digite a medida: \n");
        scanf("%f", &medida);
        if (medida < 0) {
            printf("Valor inv�lido! \n\n");
        }
    } while (medida < 0);

    return (medida);
}
#endif // funcoes

#ifdef ex1
int main()
{
    /* Receba dois n�meros, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser maior ou igual a zero, o terceiro deve ser a soma dos dois primeiros e o quarto � o produto dos tr�s n�meros anteriores. Calcule e exiba a soma dos quadrados de cada um dos quatro n�meros. Caso o resultado seja menor que 50000, solicite novos dados*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();

    float a, b, c, d, soma;

    if (start == 1) {
        do {
            do {
                printf("Digite o valor de a: \n");
                scanf("%f", &a);
                if (a < 10 || a > 25) {
                    printf("O valor de a deve ser entre 10 e 25.\n\n");
                }
            } while (a < 10 || a > 25);
            do {
                printf("Digite o valor de b: \n");
                scanf("%f", &b);
                if (b < 0) {
                    printf("O valor de b tem que ser maior que 0.\n\n");
                }
            } while (b < 0);

            c = a + b;
            d = a * b * c;
            soma = pow(a,2) + pow(b,2) + pow(c,2) + pow(d,2);
            if (soma < 50000) {
                printf("O valor da soma dos quadrados � %.2f, logo, os valores inseridos foram inv�lidos.\nPor favor, digite novamente.\n\n", soma);
            }
            else {
                printf("O valor da soma dos quadrados � %.2f", soma);
            }
        } while (soma < 50000);
    }
    return 0;
}
#endif // ex1

#ifdef ex2
int main()
{
    /* Leia o n�mero de identifica��o, as 3 notas obtidas por um aluno nas 3 verifica��es e a m�dia dos exerc�cios que fazem parte da avalia��o. Calcular a m�dia de aproveitamento, usando a f�rmula:
MA = (Nota1 + Nota2 x 2 + Nota3 x 3 + ME)/7
A atribui��o de conceitos obedece a tabela abaixo:
M�dia de Aproveitamento Conceito
9,0 A
7,5 e < 9,0 B
6,0 e < 7,5 C
4,0 e < 6,0 D
< 4,0 E
O algoritmo deve escrever o n�mero do aluno, suas notas, a m�dia dos exerc�cios, a m�dia de aproveitamento, o conceito correspondente e a mensagem: APROVADO se o conceito for A, B ou C e REPROVADO se o conceito for D ou E. */

    setlocale(LC_ALL, "");
    int start;
    start = menu();

    int numId;
    float nota1, nota2, nota3, me, ma;
    char conceito;

    if (start == 1) {
        do {
            printf("Digite o seu n�mero de identifica��o: \n");
            scanf("%d", &numId);
            if (numId < 0) {
                printf("N�mero de identifica��o inv�lido! Por favor, digite novamente.\n\n");
            }
        } while (numId < 0);

        nota1 = inputNota();
        nota2 = inputNota();
        nota3 = inputNota();
        me = inputNota();

        ma = (nota1 + (nota2 * 2) + (nota3 * 3) + me) / 7;

        if (ma < 4) {
            conceito = 'E';
            printf("Seu n�mero de identifica��o � %d.\nSuas notas foram, respectivamente, %.2f %.2f %.2f. E a m�dia dos exerc�cios foi %.2f.\nLogo sua m�dia de aproveitamento foi de %.2f, com conceito %c, ou seja, voc� foi REPROVADO!\n", numId, nota1, nota2, nota3, me, ma, conceito);
        }
        else if (ma < 6) {
            conceito = 'D';
            printf("Seu n�mero de identifica��o � %d.\nSuas notas foram, respectivamente, %.2f %.2f %.2f. E a m�dia dos exerc�cios foi %.2f.\nLogo sua m�dia de aproveitamento foi de %.2f, com conceito %c, ou seja, voc� foi REPROVADO!\n", numId, nota1, nota2, nota3, me, ma, conceito);
        }
        else if (ma < 7.5) {
            conceito = 'C';
            printf("Seu n�mero de identifica��o � %d.\nSuas notas foram, respectivamente, %.2f %.2f %.2f. E a m�dia dos exerc�cios foi %.2f.\nLogo sua m�dia de aproveitamento foi de %.2f, com conceito %c, ou seja, voc� foi APROVADO!\n", numId, nota1, nota2, nota3, me, ma, conceito);
        }
        else if (ma < 9) {
            conceito = 'B';
            printf("Seu n�mero de identifica��o � %d.\nSuas notas foram, respectivamente, %.2f %.2f %.2f. E a m�dia dos exerc�cios foi %.2f.\nLogo sua m�dia de aproveitamento foi de %.2f, com conceito %c, ou seja, voc� foi APROVADO!\n", numId, nota1, nota2, nota3, me, ma, conceito);
        }
        else {
            conceito = 'A';
            printf("Seu n�mero de identifica��o � %d.\nSuas notas foram, respectivamente, %.2f %.2f %.2f. E a m�dia dos exerc�cios foi %.2f.\nLogo sua m�dia de aproveitamento foi de %.2f, com conceito %c, ou seja, voc� foi APROVADO!\n", numId, nota1, nota2, nota3, me, ma, conceito);
        }
    }
    return 0;
}
#endif // ex1


#ifdef ex3
int main()
{
    /* Escrever um algoritmo que leia tr�s n�meros quaisquer e informe qual � o maior e se eles forem todos iguais informe ao usu�rio e solicite novos dados. */
    setlocale(LC_ALL, "");
    int start;
    start = menu();

    float a,b,c;
    float maior;

    if (start == 1) {
        printf("Digite tr�s n�meros: \n");
        scanf("%f %f %f", &a, &b, &c);

        if (a > b && a > c) {
            maior = a;
        }
        else if (b > a && b > c) {
            maior = b;
        }
        else {
            maior = c;
        }

        printf("O maior n�mero � %.2f", maior);
    }
    return 0;
}
#endif // ex1

#ifdef ex4
int main()
{
    /* Receba tr�s n�meros que representam os lados de um tri�ngulo e garantam a exist�ncia de um tri�ngulo. Informe ao usu�rio se o tri�ngulo � is�scele, equil�tero ou escaleno.
Observa��es
a. Garantir que cada lado � menor que a soma dos outros dois lados.
b. O tri�ngulo � equil�tero quando todos os lados s�o iguais.
c. O tri�ngulo � is�scele quando apenas dois lados s�o iguais.
d. O tri�ngulo � escaleno quando todos os lados s�o diferentes. */

    setlocale(LC_ALL, "");
    int start;
    start = menu();

    float a, b, c;

    if (start == 1) {
        do {
            a = inputMedida();
            b = inputMedida();
            c = inputMedida();
            if (a > b+c || b > a+c || c > a+b) {
                printf("Os valores de medidas digitados est�o inv�lidos! \n\n");
            }
        } while (a > b+c || b > a+c || c > a+b);

        if (a == b && b == c) {
            printf("O tri�ngulo informado � equil�tero! \n");
        }
        else if (a != b && b != c) {
            printf("O tri�ngulo informado � escaleno! \n");
        }
        else {
            printf("O tri�ngulo informado � is�sceles! \n");
        }
    }
    return 0;
}
#endif // ex1


