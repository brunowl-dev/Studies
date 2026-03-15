#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Receba via teclado um  número positivo e exiba esse valor com reajuste de 10%.

    float numero;

    printf("Digite o número a ser ajustado: \n");
    scanf("%f", numero);

    float numeroAjustado = numero + (0.1*numero);

    printf("O seu número ajustado é %.2f\n", numeroAjustado);
    return 0;
}
