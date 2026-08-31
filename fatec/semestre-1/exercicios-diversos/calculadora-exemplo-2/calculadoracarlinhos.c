#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    /* 1- (ENEM 2024) Carlinhos bebeu 4L de espêrma, sendo 2 litros de homens e os outros 2 litros de cavalos. Levando em consideração que em média um cavalo ejacula 100ml e homens 10ml, responda as seguintes questões:
a) Quantos homens Carlinhos chupou?
b) E quantos cavalos? */
    setlocale(LC_ALL, "");
    float ejaculaCavalo, ejaculaHomem, espermaTotal, espermaCavalo, espermaHomem;
    // Todas as unidades estão em mL.
    ejaculaCavalo = 100;
    ejaculaHomem = 10;

    //Inputs em Litros
    do {
        printf("Quantos litros de esperma de homens o Carlinhos bebeu? \n");
        scanf("%f", &espermaHomem);
        if (espermaHomem <= 0) {
            printf("Por favor, insira apenas números positivos. \n\n");
        }
    } while (espermaHomem <= 0);

    do {
        printf("Quantos litros de esperma de cavalos o Carlinhos bebeu? \n");
        scanf("%f", &espermaCavalo);
        if (espermaCavalo <= 0) {
            printf("Por favor, insira apenas números positivos. \n\n");
        }
    } while (espermaCavalo <= 0);

    //Conversão dos inputs em Litros para mililitros.
    float espermaHomem_mL = espermaHomem * 1000;
    float espermaCavalo_mL = espermaCavalo * 1000;

    int homensChupados = espermaHomem_mL / ejaculaHomem;
    int cavalosChupados = espermaCavalo_mL / ejaculaCavalo;

    printf("\nCarlinhos chupou aproximadamente %d homens e %d cavalos.\n", homensChupados, cavalosChupados);
    printf("Carlinhos então chupou cerca de %.0f litros de esperma!\n\n", espermaHomem + espermaCavalo);

    system("pause");
}


