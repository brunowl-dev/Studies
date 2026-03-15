#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "");


    int numeroId;
    float nota1, nota2, nota3, mediaExercicios;

    printf("Insira o seu número de identificação: \n");
    scanf("%i", &numeroId);

    printf("Insira o número das suas notas e da sua média de exercícios separando as com uma vírgula: \n");
    scanf("%f, %f, %f, %f", &nota1, &nota2, &nota3, &mediaExercicios);

    float mediaAproveitamento = (nota1 + (nota2 * 2) + (nota3 * 3) + mediaExercicios) / 7;

    char conceito;

    if (mediaAproveitamento < 4.0) {
        conceito = 'E';
        printf("Seu número de identificação é %i \n Suas notam foram, respectivamente: %.2f, %.2f, %.2f, %.2f. \n Sua média de aproveitamento foi de %.2f e seu conceito foi %c, ou seja, você foi REPROVADO! \n", numeroId, nota1, nota2, nota3, mediaExercicios, mediaAproveitamento, conceito);
    }

    if (mediaAproveitamento >= 4.0 && mediaAproveitamento < 6.0) {
        conceito = 'D';
        printf("Seu número de identificação é %i \n Suas notam foram, respectivamente: %.2f, %.2f, %.2f, %.2f. \n Sua média de aproveitamento foi de %.2f e seu conceito foi %c, ou seja, você foi REPROVADO! \n", numeroId, nota1, nota2, nota3, mediaExercicios, mediaAproveitamento, conceito);
    }

    if (mediaAproveitamento >= 6.0 && mediaAproveitamento < 7.5) {
        conceito = 'C';
        printf("Seu número de identificação é %i \n Suas notam foram, respectivamente: %.2f, %.2f, %.2f, %.2f. \n Sua média de aproveitamento foi de %.2f e seu conceito foi %c, ou seja, você foi APROVADO! \n", numeroId, nota1, nota2, nota3, mediaExercicios, mediaAproveitamento, conceito);
    }

    if (mediaAproveitamento >= 7.5 && mediaAproveitamento < 9.0) {
        conceito = 'B';
        printf("Seu número de identificação é %i \n Suas notam foram, respectivamente: %.2f, %.2f, %.2f, %.2f. \n Sua média de aproveitamento foi de %.2f e seu conceito foi %c, ou seja, você foi APROVADO! \n", numeroId, nota1, nota2, nota3, mediaExercicios, mediaAproveitamento, conceito);
    }

    if (mediaAproveitamento >= 9.0) {
        conceito = 'A';
        printf("Seu número de identificação é %i \n Suas notam foram, respectivamente: %.2f, %.2f, %.2f, %.2f. \n Sua média de aproveitamento foi de %.2f e seu conceito foi %c, ou seja, você foi APROVADO! \n", numeroId, nota1, nota2, nota3, mediaExercicios, mediaAproveitamento, conceito);
    }


    return 0;
}
