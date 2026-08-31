#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Insira o valor de b: \n");
    scanf("%d", &b);

    if (a > b)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d", b);
    }
    return 0;
}
