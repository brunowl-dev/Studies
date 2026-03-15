#define ex12
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "");
    int num;

    printf("Digite seu número! \n");
    scanf("%d", &num);

    int antecessor = num - 1;
    int sucessor = num + 1;

    printf("O antecessor do número %d é %d, e seu sucessor é %d \n", num, antecessor, sucessor);
    return 0;
}
#endif // ex1

#ifdef ex2
int main ()
{
    setlocale(LC_ALL, "");
    float num, numeroReajuste;
    printf("Insira seu número: \n");
    scanf("%f", &num);

    while (num < 0) {
        printf("Insira um número positivo! \n");
        scanf("%f", &num);
        numeroReajuste = num + (num * 0.1);
        printf("O seu número com reajuste de 10% é %.2f", numeroReajuste);

        return 0;
    }

    numeroReajuste = num + (num * 0.1);
    printf("O seu número com reajuste de 10% é %.2f", numeroReajuste);

    return 0;
}
#endif // ex2

#ifdef ex3
int main ()
{
    setlocale(LC_ALL, "");
    float preco, precoDesconto;

    printf("Insira o preço do produto: \n");
    scanf("%f", &preco);

    while (preco < 0){
        printf("Insira um número positivo! \n");
        scanf("%f", &preco);

        precoDesconto = preco - (preco * 9/100);
        printf("O seu produto com desconto de 9% é %.2f", precoDesconto);
        return 0;
    }

    precoDesconto = preco - (preco * 9/100);
    printf("O seu produto com desconto de 9% é %.2f", precoDesconto);

    return 0;
}
#endif // ex3

#ifdef ex4
int main ()
{
    /* Cálculo de um salário líquido de um professor. Serão fornecidos via teclado o valor da hora aula,  o número de aulas dadas e o  desconto do INSS. */
    setlocale(LC_ALL, "");

    float horaAula;
    printf("Insira o valor da hora aula: \n");
    scanf("%f", &horaAula);

    while (horaAula < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &horaAula);
    }

    int numAulas;
    printf("Insira a quantidade de aulas ministradas: \n");
    scanf("%d", &numAulas);

    while (numAulas < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%d", &numAulas);
    }

    float descontoINSS;
    printf("Insira a porcentagem de desconto do INSS: \n");
    scanf("%f", &descontoINSS);

    while (descontoINSS < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &descontoINSS);
    }

    float salarioBruto = horaAula * numAulas;
    float salarioLiq = salarioBruto - (salarioBruto * descontoINSS/100);

    printf("O seu salário líquido é de %.2f", salarioLiq);


    return 0;
}
#endif // ex4

#ifdef ex5
int main ()
{
/* 5- O custo ao consumidor de um carro novo é a soma do preço da fábrica com o percentual de lucro do distribuidor e dos impostos aplicados ao preço de fábrica. Faça um programa que receba via teclado: O preço de fábrica de um veículo, o percentual de lucro do distribuidor e o percentual de impostos. Calcule e mostre: 
O valor correspondente ao lucro do distribuidor 
O valor correspondente aos impostos 
O preço final do veículo */

    setlocale(LC_ALL, "");
    float precoFabrica;
    printf("Insira o preço da fábrica: \n");
    scanf("%f", &precoFabrica);

    while (precoFabrica < 0) {
        printf("Insira um número positivo: \n");
        scanf("%f", &precoFabrica);
    }

    float percentualLucro;
    printf("Insira o percentual de lucro desejado: \n");
    scanf("%f", &percentualLucro);

    while (percentualLucro < 0) {
        printf("Insira um número válido: \n");
        scanf("%f", &percentualLucro);
    }

    float percentualImposto;
    printf("Insira o percentual de imposto: \n");
    scanf("%f", &percentualImposto);

    while (percentualImposto < 0) {
        printf("Insira um número válido: \n");
        scanf("%f", &percentualImposto);
    }

    float custoFinal = precoFabrica + (precoFabrica * percentualLucro/100) + (precoFabrica * percentualImposto/100);
    float valorLucro = precoFabrica * percentualLucro/100;
    float valorImposto = precoFabrica * percentualImposto/100;

    printf("O valor de lucro do distribuidor é de %.2f, o valor dos impostos foram de %.2f \nO custo final para o consumidor é de %.2f", valorLucro, valorImposto, custoFinal);
    return 0;
}
#endif // ex5

#ifdef ex6
int main()
{
    setlocale(LC_ALL, "");
    /* 6- Elabore um programa que receba o salário de um funcionário e calcule o reajuste desse salário. Considere que o funcionário deve receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Ao final do programa deve apresentar o valor antigo e o novo salário. */
    float salario, salarioAjuste;
    printf("Insira o seu salário: \n");
    scanf("%f", &salario);

    while (salario < 0) {
        printf("Insira um valor positivo! \n");
        scanf("%f", &salario);
    }

    if (salario < 800) {
        salarioAjuste = salario + (salario * 0.15);
    }

    if (salario >= 800 && salario <= 1000) {
        salarioAjuste = salario + (salario * 0.1);
    }

    else {
        salarioAjuste = salario + (salario * 0.05);
    }

    printf("Seu salário antigo era de %.2f, seu salário reajustado é de %.2f", salario, salarioAjuste);
    return 0;
}
#endif // ex6

#ifdef ex7
int main()
{
    setlocale(LC_ALL, "");
    /*Leia quatro valores referentes às notas escolares de um aluno e exiba uma mensagem dizendo que ele foi aprovado se a média for maior ou igual a 6. Caso contrário informe que ele está reprovado. Apresente junto à mensagem o valor da média obtida pelo aluno independente de ter sido aprovado ou não. As notas deverão ser maiores ou iguais a zero e menores ou iguais a dez. */
    float nota1, nota2, nota3, nota4;

    printf("Insira a primeira nota: \n");
    scanf("%f", &nota1);

    while (nota1 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota1);
    }

        printf("Insira a segunda nota: \n");
    scanf("%f", &nota2);

    while (nota2 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota2);
    }

    printf("Insira a terceira nota: \n");
    scanf("%f", &nota3);

    while (nota3 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota3);
    }

        printf("Insira a quarta nota: \n");
    scanf("%f", &nota4);

    while (nota4 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota4);
    }

    float media = (nota1 + nota2 + nota3 + nota4) / 4;

    if (media > 6) {
        printf("Sua média foi de %.2f, logo, você foi APROVADO", media);
    }

    else {
        printf("Sua média foi de %.2f, logo, você foi REPROVADO", media);
    }
    return 0;
}
#endif // ex7

#ifdef ex8
int main()
{
    setlocale(LC_ALL, "");
    /* Receba dois números, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser maior ou igual a zero, o terceiro deve ser a soma dos dois primeiros e o quarto é o produto dos três números anteriores. Calcule e exiba a soma dos quadrados de cada um dos quatro números. Caso o resultado seja menor que 50000, solicite novos dados.  */
    float num1;
    printf("Insira o primeiro número: \n");
    scanf("%f", &num1);

    while (num1 < 10 || num1 > 25) {
        printf("Insira um valor válido! \n");
        scanf("%f", &num1);
    }

        float num2;
    printf("Insira o segundo número: \n");
    scanf("%f", &num2);

    while (num2 <= 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &num2);
    }

    float num3 = num1 + num2;

    float num4 = (num1 * num1) + (num2 * num2) + (num3 * num3) + (num4 * num4);

    if (num4 > 50000) {
        printf("%.2f\n", num4);
    }
    else {
        printf("Renicie o programa e insira novos dados! \n");
    }
    return 0;
}
#endif // ex

#ifdef ex9
int main()
{
    setlocale(LC_ALL, "");
    /* Leia dois valores a e b e os escreve com a mensagem: "São múltiplos" ou "Não são múltiplos".  */
    int a, b;

    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Insira o valor de b: \n");
    scanf("%d", &b);

    if (a > b) {
        int c = a % b;
        if (c == 0) {
            printf("São múltiplos! \n");
        }
        else {
            printf("Não são múltiplos! \n");
        }
    }

    if (b > a) {
        int c = b % a;
        if (c == 0) {
            printf("São múltiplos! \n");
        }
        else {
            printf("Não são múltiplos! \n");
        }
    }

    if (a == b) {
        printf("São múltiplos! \n");
    }

    return 0;
}
#endif // ex9


#ifdef ex10
int main()
{
    setlocale(LC_ALL, "");
    /* Leia o preço de um produto e inflaciona esse preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a 100.  */
    float preco, precoNovo;

    printf("Insira o preço do produto: \n");
    scanf("%f", &preco);

    while (preco < 0) {
        printf("Insira um valor positivo! \n");
        scanf("%f", &preco);
    }

    if (preco >= 100) {
        precoNovo = preco + (preco * 0.2);
        printf("O seu preço inflacionado é %.2f", precoNovo);
    }

    else {
        precoNovo = preco + (preco * 0.1);
        printf("O seu preço inflacionado é %.2f", precoNovo);
    }
    return 0;
}
#endif // ex10

#ifdef ex11
int main()
{
    setlocale(LC_ALL, "");
    /* Leia dois números inteiros e mostre o maior deles. */
    int a, b;
    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Inisra o valor de b: \n");
    scanf("%d", &b);

    if (a > b) {
        printf("%d", a);
    }

    else {
        printf("%d", b);
    }

    return 0;
}
#endif // ex11

#ifdef ex12
int main()
{
    setlocale(LC_ALL, "");
    /* Leia o número de identificação, as 3 notas obtidas por um aluno nas 3 verificações e a média dos exercícios que fazem parte da avaliação. Calcular a média de aproveitamento, usando a fórmula: MA = (Nota1 + Nota2 x 2 + Nota3 x 3 + ME)/7

A atribuição de conceitos obedece a tabela abaixo:
Média de Aproveitamento
Conceito
9,0 A
7,5 e < 9,0 B
6,0 e < 7,5 C
4,0 e < 6,0 D
< 4,0 E
O algoritmo deve escrever o número do aluno, suas notas, a média dos exercícios, a média de aproveitamento, o conceito correspondente e a mensagem: APROVADO se o conceito for A, B ou C e REPROVADO se o conceito for D ou E.  */

    char numId;
    char conceito;
    printf("Insira seu número de identificação: \n");
    scanf("%c", &numId);

    float nota1;
    printf("Insira a nota do primeiro exercício: \n");
    scanf("%f", &nota1);

    while (nota1 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota1);
    }

        float nota2;
    printf("Insira a nota do segundo exercício: \n");
    scanf("%f", &nota2);

    while (nota2 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota2);
    }

        float nota3;
    printf("Insira a nota do terceiro exercício: \n");
    scanf("%f", &nota3);

    while (nota3 < 0) {
        printf("Insira um valor positivo: \n");
        scanf("%f", &nota3);
    }

    float ME = (nota1 + nota2 + nota3) / 3;

    float MA = (nota1 + nota2 * 2 + nota3 * 3 + ME)/7;

    if (MA < 4) {
        conceito = 'E';
        printf("O seu número de identificação é %c\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi REPROVADO!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    if (4 <= MA && MA < 6) {
    conceito = 'D';
    printf("O seu número de identificação é %c\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi REPROVADO!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (6 <= MA && MA < 7.5) {
    conceito = 'C';
    printf("O seu número de identificação é %c\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (7.5 <= MA && MA < 9) {
    conceito = 'B';
    printf("O seu número de identificação é %c\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (9 <= MA) {
        conceito = 'A';
        printf("O seu número de identificação é %c\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    return 0;
}
#endif // ex12
