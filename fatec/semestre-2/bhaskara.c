#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int menu () {
    char iniciar;
    do {
        printf("Deseja iniciar o programa?\nDigite 's' para sim ou 'n' para não\n");
        scanf(" %c", &iniciar);
        if (iniciar != 's' && iniciar != 'n' && iniciar != 'S' && iniciar != 'N') {
            printf("Insira apenas os as letras 's' ou 'n'.\n\n");
        }
    } while (iniciar != 's' && iniciar != 'n' && iniciar != 'S' && iniciar != 'N');

    if (iniciar == 's' || iniciar == 'S') {
        return(1);
    }
    else {
        return(0);
    }
}

#define ex1

#ifdef ex1
int numInput(char letra) {
    int num;
    printf("Digite a variável %c:\n", letra);
    scanf("%d", &num);
    return (num);
}

int main()
{
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int a, b, c;
        float delta, x1, x2;
        do {
            a = numInput('a');
            if (a == 0) {
                printf("O valor de a deve ser diferente de zero!\n");
            }
        } while (a == 0);
        b = numInput('b');
        c = numInput('c');
        delta = sqrt((pow(b,2)) - (4 * a * c));
        if (delta > 0) {
            x1 = (-b + delta) / (2 * a);
            x2 = (-b - delta) / (2 * a);
            printf("O valor x1 é: %.2f\nO valor de x2 é: %.2f\n", x1, x2);
        }
        else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("O valor de x é: %.2f", x1);
        }
        else {
            printf("Não existe raíz real!\n");
        }
    }

    return 0;
}
#endif //ex1
//\n 