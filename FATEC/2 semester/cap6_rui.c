#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex2

#ifdef ex1
int main() {
    /*1 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.*/
    setlocale(LC_ALL, "");

    return 0;
}
#endif //ex1

#ifdef ex2
int contBi(int ano_nasc, int ano_atual) {
    int contador = 0, i;
    for (i = ano_nasc; i <= ano_atual; i++) {
        if (i % 100 == 0 && i % 400 == 0) {
            contador++;
        }
        else if(i % 4 == 0) {
            contador++;
        }
    }
    return (contador);
}
int main() {
        /*2 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
        dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
        data (dia, mes e ano) atual.*/
    setlocale(LC_ALL, "");
    int ano_atual = 2025, mes_atual = 3, dia_atual = 25;
    int ano_nasc, mes_nasc, dia_nasc, dias, meses, anos;
    printf("Digite o seu ano, mês e dia de nascimento, respectivamente:\n");
    scanf("%d %d %d", &ano_nasc, &mes_nasc, &dia_nasc);
    dias = (ano_atual - ano_nasc) * 365;
    if (mes_atual > mes_nasc) {
        dias = ((mes_atual - mes_nasc) * 30) + dias - 1;
    }
    else if (mes_atual < mes_nasc) {
        dias = dias - ((mes_nasc - mes_atual) * 30);
    }
    printf("%d\n", dias);  
    if (dia_nasc < dia_atual) {
        dias = (dia_atual - dia_nasc) + (contBi(ano_nasc, ano_atual) + dias);
    }
    else if (dia_nasc > dia_atual) {
        dias = (contBi(ano_nasc, ano_atual) + dias) - (dia_nasc - dia_atual);
    }
    printf("%d\n", dias);         
    return 0;
}
#endif //ex2
//\n  e ||