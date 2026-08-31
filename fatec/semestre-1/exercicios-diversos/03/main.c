#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Cálculo de um salário líquido de um professor. Serão fornecidos via teclado o valor da hora aula,  o número de aulas dadas e o  desconto do INSS.

    float valorHora;
    int numerodeAulas;
    float porcentagemINSS;

    printf("Quanto você ganha por hora de aula? \n");
    scanf("%f", &valorHora);
    printf("Quantas aulas você ministra? \n");
    scanf("%i", &numerodeAulas);
    printf("Qual é a sua porcentagem do INSS? (sem %) \n");
    scanf("%f", &porcentagemINSS);

    float salarioBruto = valorHora * numerodeAulas;
    float salarioLiquido = salarioBruto - (porcentagemINSS/100 * salarioBruto);

    printf("Seu salário líquido é %.2f", salarioLiquido);
    return 0;
}
