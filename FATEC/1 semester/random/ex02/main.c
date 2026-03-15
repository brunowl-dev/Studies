#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroId;
    float nota1, nota2, nota3, mediaExercicios;

    printf("Insira o seu número de identificação: \n");
    scanf("%i", &numeroId);

    printf("Insira o número das suas notas e da sua média de exercícios separando as com um espaço: \n");
    scanf("%f, %f, %f, %f", &nota1, &nota2, &nota3, &mediaExercicios);

    float mediaAproveitamento = (nota1 + (nota2 * 2) + (nota3 * 3) + mediaExercicios) / 7;

    if (mediaAproveitamento < 4)
    {
        printf("Seu número de identificação é: %i \n", numeroId);
        printf("Suas notas 1, 2 e 3 foram respectivamente %.2f, %.2f, %.2f e sua média de exercícios foi de %.2f \n", nota1, nota2, nota3, mediaExercicios);
        printf("Sua méda de aproveitamento foi de %.2f pontos, ou seja seu conceito foi E e você foi reprovado! \n", mediaAproveitamento);
    }

    if (6 > mediaAproveitamento > 4)
    {
        printf("Seu número de identificação é: %i \n", numeroId);
        printf("Suas notas 1, 2 e 3 foram respectivamente %.2f, %.2f, %.2f e sua média de exercícios foi de %.2f \n", nota1, nota2, nota3, mediaExercicios);
        printf("Sua méda de aproveitamento foi de %.2f pontos, ou seja seu conceito foi D e você foi reprovado! \n", mediaAproveitamento);
    }

    if (6 < mediaAproveitamento < 7.5)
    {
        printf("Seu número de identificação é: %i \n", numeroId);
        printf("Suas notas 1, 2 e 3 foram respectivamente %.2f, %.2f, %.2f e sua média de exercícios foi de %.2f \n", nota1, nota2, nota3, mediaExercicios);
        printf("Sua méda de aproveitamento foi de %.2f pontos, ou seja seu conceito foi C e você foi aprovado! \n", mediaAproveitamento);
    }

    if (7.5 < mediaAproveitamento < 9)
    {
        printf("Seu número de identificação é: %i \n", numeroId);
        printf("Suas notas 1, 2 e 3 foram respectivamente %.2f, %.2f, %.2f e sua média de exercícios foi de %.2f \n", nota1, nota2, nota3, mediaExercicios);
        printf("Sua méda de aproveitamento foi de %.2f pontos, ou seja seu conceito foi B e você foi aprovado! \n", mediaAproveitamento);
    }

    if (mediaAproveitamento > 9)
    {
        printf("Seu número de identificação é: %i \n", numeroId);
        printf("Suas notas 1, 2 e 3 foram respectivamente %.2f, %.2f, %.2f e sua média de exercícios foi de %.2f \n", nota1, nota2, nota3, mediaExercicios);
        printf("Sua méda de aproveitamento foi de %.2f pontos, ou seja seu conceito foi A e você foi aprovado! \n", mediaAproveitamento);
    }
    return 0;
}
