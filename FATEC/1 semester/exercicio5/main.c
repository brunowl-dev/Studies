// Mudar o número do exercício na linha abaixo para conseguir rodar.
#define ex18
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "");
    int num;

    printf("Digite seu número! \n");
    scanf("%d", &num);

    printf("O antecessor do número %d é %d, e seu sucessor é %d \n", num, num - 1, num + 1);
    return 0;
}
#endif // ex1

#ifdef ex2
int main ()
{
    setlocale(LC_ALL, "");
    float num, numeroReajuste;

    do {
        printf("Insira um número: \n");
        scanf("%f", &num);

        if (num <= 0) {
            printf("Insira valores positivos! \n\n");
        }
    } while (num <= 0);

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

    do {
        printf("Insira o preço do produto: \n");
        scanf("%f", &preco);

        if (preco <= 0) {
            printf("Insira um número positivo! \n\n");
        }
    } while (preco <= 0);

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

    float horaAula, descontoINSS;
    int numAulas;

    do {
        printf("Insira o valor da hora aula: \n");
        scanf("%f", &horaAula);
        if (horaAula <= 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (horaAula <= 0);

    do {
        printf("Insira a quantidade de aulas ministradas: \n");
        scanf("%d", &numAulas);
        if (numAulas <= 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (numAulas <= 0);

    do {
        printf("Insira a porcentagem de desconto do INSS: \n");
        scanf("%f", &descontoINSS);
        if (descontoINSS <= 0 || descontoINSS > 100) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (descontoINSS <= 0 || descontoINSS > 100);

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
    float percentualImposto;
    float percentualLucro;

    do {
        printf("Insira o preço da fábrica: \n");
        scanf("%f", &precoFabrica);
        if (precoFabrica <= 0) {
            printf("Insira um número positivo! \n\n");
        }
    } while (precoFabrica <= 0);

    do {
        printf("Insira o percentual de lucro desejado: \n");
        scanf("%f", &percentualLucro);
        if (percentualLucro <= 0 || percentualLucro > 100) {
            printf("Insira um número válido! \n\n");
        }
    } while (percentualLucro <= 0 || percentualLucro > 100);

    do {
        printf("Insira o percentual de imposto: \n");
        scanf("%f", &percentualImposto);
        if (percentualImposto <= 0 || percentualImposto > 100) {
            printf("Insira um número válido! \n\n");
        }
    } while (percentualImposto <= 0 || percentualImposto > 100);

    float custoFinal = precoFabrica + (precoFabrica * percentualLucro/100) + (precoFabrica * percentualImposto/100);
    float valorLucro = precoFabrica * percentualLucro/100;
    float valorImposto = precoFabrica * percentualImposto/100;

    printf("\nO valor de lucro do distribuidor é de %.2f, o valor dos impostos foram de %.2f \nO custo final para o consumidor é de %.2f", valorLucro, valorImposto, custoFinal);
    return 0;
}
#endif // ex5

#ifdef ex6
int main()
{
    setlocale(LC_ALL, "");
    /* 6- Elabore um programa que receba o salário de um funcionário e calcule o reajuste desse salário. Considere que o funcionário deve receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Ao final do programa deve apresentar o valor antigo e o novo salário. */
    float salario, salarioAjuste;

    do {
        printf("Insira o seu salário: \n");
        scanf("%f", &salario);
        if (salario <= 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (salario <= 0);

    if (salario < 800) {
        salarioAjuste = salario + (salario * 0.15);
    }

    else{
        if (salario >= 800 && salario <= 1000){
            salarioAjuste = salario + (salario * 0.1);
            }
    }

    if (salario >= 1000) {
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

    do {
        printf("Insira a primeira nota: \n");
        scanf("%f", &nota1);
        if (nota1 < 0) {
            printf("Insira um valor positivo: \n");
        }
    } while (nota1 < 0);

    do {
        printf("Insira a segunda nota: \n");
        scanf("%f", &nota2);
        if (nota2 < 0) {
            printf("Insira um valor positivo: \n");
        }
    } while (nota2 < 0);

    do {
        printf("Insira a terceira nota: \n");
        scanf("%f", &nota3);
        if (nota3 < 0) {
            printf("Insira um valor positivo: \n");
        }
    } while (nota3 < 0);

    do {
        printf("Insira a quarta nota: \n");
        scanf("%f", &nota4);
        if (nota4 < 0) {
            printf("Insira um valor positivo: \n");
        }
    } while (nota4 < 0);

    float media = (nota1 + nota2 + nota3 + nota4) / 4;

    if (media >= 6) {
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
    float num1, num2, num3, num4, soma;

    do {

        do {
            printf("Insira o primeiro número: \n");
            scanf("%f", &num1);
            if (num1 < 10 || num1 >= 25) {
                printf("Número inválido! \n\n");
            }
        } while (num1 < 10 || num1 >= 25);

        do {
            printf("Insira o segundo número: \n");
            scanf("%f", &num2);
            if (num2 < 0) {
                printf("Número inválido! \n\n");
            }
        } while (num2 < 0);

        num3 = num1 + num2;
        num4 = num1 * num2 * num3;

        soma = (num1 * num1) + (num2 * num2) + (num3 * num3) + (num4 * num4);

        if (soma < 50000) {
            printf("Valores inválidos! \nPor favor insira os números novamente.\n\n");
        }
        else {
            printf("%.2f", soma);
        }

    } while (soma < 50000);



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
    else if(b > a) {
        int c = b % a;
        if (c == 0) {
            printf("São múltiplos! \n");
        }
        else {
            printf("Não são múltiplos! \n");
        }
    }
    else {
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

    do {
        printf("Insira o preço do produto: \n");
        scanf("%f", &preco);
        if (preco < 0); {
            printf("Insira um valor positivo! \n\n");
        }
    } while (preco < 0);

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

    int numId;
    char conceito;
    printf("Insira seu número de identificação: \n");
    scanf("%d", &numId);

    float nota1, nota2, nota3, ME;

    do {
        printf("Insira a primeira nota: \n");
        scanf("%f", &nota1);
        if (nota1 < 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (nota1 < 0);

    do {
        printf("Insira a segunda nota: \n");
        scanf("%f", &nota2);
        if (nota2 < 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (nota2 < 0);

    do {
        printf("Insira a terceira nota: \n");
        scanf("%f", &nota3);
        if (nota3 < 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (nota3 < 0);

    do {
        printf("Insira a media dos exercícios: \n");
        scanf("%f", &ME);
        if (ME < 0) {
            printf("Insira um valor positivo! \n\n");
        }
    } while (ME < 0);

    float MA = (nota1 + nota2 * 2 + nota3 * 3 + ME)/7;

    if (MA < 4) {
        conceito = 'E';
        printf("O seu número de identificação é %d\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi REPROVADO!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (4 <= MA && MA < 6) {
    conceito = 'D';
    printf("O seu número de identificação é %d\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi REPROVADO!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (6 <= MA && MA < 7.5) {
    conceito = 'C';
    printf("O seu número de identificação é %d\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else if (7.5 <= MA && MA < 9) {
    conceito = 'B';
    printf("O seu número de identificação é %d\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    else {
        conceito = 'A';
        printf("O seu número de identificação é %d\nSuas notas foram %.2f, %.2f e %.2f, deixando sua média de exercícios em %.2f\nOu seja, sua média de aproveitamento foi de %.2f, seu conceito foi %c e você foi APROVADO, parabéns!\n", numId, nota1, nota2, nota3, ME, MA, conceito);
    }

    return 0;
}
#endif // ex12

#ifdef ex13
int main()
{
    setlocale(LC_ALL, "");
    /* Receba via teclado um número inteiro qualquer e exiba se ele é positivo ou negativo ou zero.  */
    int num;

    printf("Insira o número: \n");
    scanf("%d", &num);

    if (num == 0) {
        printf("O número inserido é zero! \n");
    }

    else if (num > 0 && num != 0) {
        printf("O número inserido é positivo! \n");
    }

    else{
        printf("O número inserido é negativo! \n");
    }

    return 0;
}
#endif // ex13

#ifdef ex14
int main()
{
    setlocale(LC_ALL, "");
    /* Calcule a média aritmética das quatro notas de um aluno e mostre, além do valor da média, uma mensagem de "Aprovado", caso a média seja igual ou superior a 6, ou a mensagem "reprovado", caso contrário. */
    float nota1, nota2, nota3, nota4;
    float media;

    do {
        printf("Insira a primeira nota: \n");
        scanf("%f", &nota1);
        if (nota1 > 10 || nota1 < 0) {
            printf("Insira uma nota válida! \n\n");
        }
    } while (nota1 > 10 || nota1 < 0);

    do {
        printf("Insira a segunda nota: \n");
        scanf("%f", &nota2);
        if (nota2 > 10 || nota2 < 0) {
            printf("Insira uma nota válida! \n\n");
        }
    } while (nota2 > 10 || nota2 < 0);

    do {
        printf("Insira a terceira nota: \n");
        scanf("%f", &nota3);
        if (nota3 > 10 || nota3 < 0) {
            printf("Insira uma nota válida! \n\n");
        }
    } while (nota3 > 10 || nota3 < 0);

    do {
        printf("Insira a quarta nota: \n");
        scanf("%f", &nota4);
        if (nota4 > 10 || nota4 < 0) {
            printf("Insira uma nota válida! \n\n");
        }
    } while (nota4 > 10 || nota4 < 0);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    if (media >= 6) {
        printf("Sua média foi de %.2f, ou seja, você foi APROVADO. Parabéns! \n", media);
    }
    else {
        printf("Sua média foi de %.2f, ou seja, você foi REPROVADO. \n", media);
    }

    return 0;
}
#endif // ex14

#ifdef ex15
int main()
{
    setlocale(LC_ALL, "");
    /* Leia dois valores a e b e os escreve com a mensagem: "São múltiplos" ou "Não são múltiplos". */

    // Dúvida: Fazer com floats ou int?
    int a, b, c;

    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Insira o valor de b: \n");
    scanf("%d", &b);

    if (a > b) {
        c = a % b;
        if (c == 0) {
            printf("São múltiplos! \n");
        }
        else {
            printf("Não são múltiplos! \n");
        }
    }

    else {
        c = b % a;
        if (c == 0) {
            printf("São múltiplos! \n");
        }
        else {
            printf("Não são múltiplos! \n");
        }
    }
    return 0;
}
#endif // ex15

#ifdef ex16
int main()
{
    setlocale(LC_ALL, "");
    /* Receba dois valores a e b e os escreve com a mensagem: "São pares " ou "São ímpares". */
    int a, b;

    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Insira o valor de b: \n");
    scanf("%d", &b);

    int resto1 = a % 2;
    int resto2 = b % 2;

    if (resto1 == 0 && resto2 == 0) {
        printf("São pares! \n");
    }
    else {
        printf("São ímpares! \n");
    }

    return 0;
}
#endif // ex16

#ifdef ex17
int main()
{
    setlocale(LC_ALL, "");
    /* Leia dois números inteiros e mostre o maior deles. Caso sejam iguais informe ao usuário */

    int a, b;

    printf("Insira o valor de a: \n");
    scanf("%d", &a);

    printf("Insira o valor de b: \n");
    scanf("%d", &b);

    if (a == b) {
        printf("São iguais! \n");
    }

    else if(a > b) {
        printf("%d", a);
    }

    else {
        printf("%d", b);
    }
    return 0;
}
#endif // ex17

#ifdef ex18
int main()
{
    setlocale(LC_ALL, "");
    /* Receba três números que garantam a existência de uma equação do 2º grau. Se houver raízes reais exiba-as, caso contrário informe ao usuário. */
    float a, b, c, pre_Delta, delta, x1, x2;

    do {
        do {
        printf("Insira o valor de a: \n");
        scanf("%f", &a);
        if (a == 0) {
            printf("O valor de a não pode ser igual a zero! Por favor insira um outro número. \n\n");
        }
        } while (a == 0);

        printf("Insira o valor de b e c: \n");
        scanf("%f %f", &b, &c);

        printf("f", delta);

    } while (delta < 0);


    return 0;
}
#endif // ex18

#ifdef ex19
int main()
{
    setlocale(LC_ALL, "");
    /* A FATEC RUBENS LARA faz o pagamento de seus professores por hora/aula. Faça um algoritmo que calcule e exiba o salário de um professor. Sabe-se que o valor da hora/aula segue a tabela abaixo: Professor Nível 1 R$55,00 por hora/aula Professor Nível 2 R$67,00 por hora/aula Professor Nível 3 R$78,00 por hora/aula */

    int hora, aula;
    float nivel1 = 55;
    float nivel2 = 67;
    float nivel3 = 78;
    int horaTotal;
    int nivel;
    float salario;

    printf("Insira a quantidade de hora a cada aula: \n");
    scanf("%d", &hora);

    while (hora <= 0) {
        printf("Insira um valor válido! \n");
        scanf("%d", &hora);
    }

    printf("Insira a quantidade de aulas ministradas: \n");
    scanf("%d", &aula);

    while (aula <= 0) {
        printf("Insira um valor válido! \n");
        scanf("%d", &aula);
    }

    horaTotal = aula * hora;


    printf("Insira o nível (1, 2 ou 3): \n");
    scanf("%d", &nivel);

    if (nivel == 1) {
        salario = horaTotal * nivel1;
        printf("O seu salário é de R$%.2f", salario);
    }

    if (nivel == 2) {
        salario = horaTotal * nivel2;
        printf("O seu salário é de R$%.2f", salario);
    }

    if (nivel == 3) {
        salario = horaTotal * nivel3;
        printf("O seu salário é de R$%.2f", salario);
    }

    return 0;
}
#endif // ex19

#ifdef ex20
int main()
{
    setlocale(LC_ALL, "");
    /* Escrever um algoritmo que leia três números quaisquer e informe qual é o maior e se eles forem todos igual informe ao usuário e solicite novos dados */

    float a, b, c;

    printf("Insira o valor de a: \n");
    scanf("%f", &a);

    printf("Insira o valor de b: \n");
    scanf("%f", &b);

    printf("Insira o valor de c: \n");
    scanf("%f", &c);

    if (a == b == c) {
        printf("São iguais! \n");
    }

    if (a > b && a > c) {
        printf("O maior número é %.2f", a);
    }

    if (b > a && b > c) {
        printf("O maior número é %.2f", b);
    }

    if (c > a && c > b) {
        printf("O maior número é %.2f", c);
    }

    return 0;
}
#endif // ex20

#ifdef ex21
int main()
{
    setlocale(LC_ALL, "");
    /* Receba três números que representam os lados de um triângulo e garantam a existência de um triângulo. Informe ao usuário se o triângulo é isóscele, equilátero ou escaleno.

Observações:

a. Garantir que cada lado é menor que a soma dos outros dois lados.

b. O triângulo é equilátero quando todos os lados são iguais.

c. O triângulo é isóscele quando apenas dois lados são iguais.

d. O triângulo é escaleno quando todos os lados são diferentes. */

    float a, b, c;

    printf("Insira o valor de a: \n");
    scanf("%f", &a);

    printf("Insira o valor de b: \n");
    scanf("%f", &b);

    printf("Insira o valor de c: \n");
    scanf("%f", &c);

    while (a > b+c || b > a+c || c > a+b) {
        printf("\nInsira valores válidos, cada lado que tem que ser menor que a soma dos outros dois lados. \n");

        printf("Insira o valor de a: \n");
        scanf("%f", &a);

        printf("Insira o valor de b: \n");
        scanf("%f", &b);

        printf("Insira o valor de c: \n");
        scanf("%f", &c);
    }

    if (a == b && b == c) {
        printf("\nO triângulo com a medida de lado informada é equilátero! \n");
        return 0;
    }
    else {
        if (a != b && b != c) {
            printf("\nO triângulo com a medida de lado informada é escaleno! \n");
            return 0;
        }
        else {
            printf("\nO triângulo com a medida de lado informada é isósceles!");
            return 0;
        }
    }
    return 0;
}
#endif // ex21

#ifdef ex22
int main()
{
    setlocale(LC_ALL, "");
    /* Faça um programa que receba o número de horas trabalhadas e o valor do salário mínimo. Calcule e mostre o salário a receber o seguindo as regras abaixo:
a) a hora trabalhada vale a metade do salário minímo;
b) o salário bruto equivale ao número de horas trabalhadas multiplicado pelo valor da hora trabalhada;
c) o imposto equivale a 3% do salário bruto;
d) o salário a receber equivale ao salário bruto menos o imposto. */

    float valorSM, salarioBruto, imposto;
    int hora;

    printf("Insira o valor do salário mínimo: \n");
    scanf("%f", &valorSM);

    while (valorSM < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &valorSM);
    }

    printf("Insira o número de horas trabalhadas\n");
    scanf("%d", &hora);

    while (hora < 0) {
        printf("Insira um valor válido! \n");
        scanf("%d", &hora);
    }

    salarioBruto = ((0.5 * valorSM) * hora);
    imposto = (0.03 * salarioBruto);

    float salarioLiquido = salarioBruto - imposto;

    printf("\nO salário a receber é de %.2f", salarioLiquido);

    return 0;
}
#endif // ex22

#ifdef ex23
int main()
{
    setlocale(LC_ALL, "");
    /* Cada degrau de uma escada tem X de altura. Faça um programa que receba essa altura e a altura que o usuário deseja subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir seu objetivo, sem se preocupar com a altura do usuário. */

    float alturaDegrau, alturaDesejada;
    int quantDegraus;

    printf("Informe a altura de cada degrau da escada: \n");
    scanf("%f", &alturaDegrau);

    while (alturaDegrau < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &alturaDegrau);
    }

    printf("Informe a altura desejada para alcançar: \n");
    scanf("%f", &alturaDesejada);

    while (alturaDesejada < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &alturaDesejada);
    }

    quantDegraus = alturaDesejada / alturaDegrau;

    printf("Você precisará subir %d degraus", quantDegraus);


    return 0;
}
#endif // ex23

#ifdef ex24
int main()
{
    setlocale(LC_ALL, "");
    /* O IMC – Índice de Massa Corporal é um critério da Organização Mundial de Saúde para dar uma indicação sobre a condição de peso de uma pessoa adulta. A fórmula é IMC = peso / (altura)². Elabore um algoritmo que leia o peso e a altura de um adulto e mostre sua condição de acordo com as condições abaixo:

< 17 - Muito abaixo do peso
17 < x < 18,50 - Abaixo do peso
18,5 < x < 25 - Peso normal
25 < x < 30 - Acima do peso
30 < x < 35 - Obesidade 1
35 < x < 40 - Obesidade 2 (severa)
40 < x - Obesidade 3 (mórbida) */

    float peso, altura, imc;

    printf("Insira o valor do seu peso: \n");
    scanf("%f", &peso);

    while (peso < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &peso);
    }

    printf("Insira o valor da sua altura: \n");
    scanf("%f", &altura);

    while (altura < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &altura);
    }

    imc = peso / (pow(altura, 2));

    if (imc <= 17) {
        printf("\nSeu imc é %.2f, ou seja, você está muito abaixo do peso.\n", imc);
        return 0;
    }

    if (17 < imc && imc <= 18.50) {
    printf("\nSeu imc é %.2f, ou seja, você está abaixo do peso.\n", imc);
    return 0;
    }

    if (18.50 < imc && imc <= 25) {
    printf("\nSeu imc é %.2f, ou seja, você no peso normal.\n", imc);
    return 0;
    }

    if (25 < imc && imc <= 30) {
    printf("\nSeu imc é %.2f, ou seja, você está acima do peso.\n", imc);
    return 0;
    }

    if (30 < imc && imc <= 35) {
    printf("\nSeu imc é %.2f, ou seja, você se enquadra na obesidade 1.\n", imc);
    return 0;
    }

    if (35 < imc && imc <= 40) {
    printf("\nSeu imc é %.2f, ou seja, você se enquadra na obesidade 2.\n", imc);
    return 0;
    }

    if (40 < imc) {
    printf("\nSeu imc é %.2f, ou seja, você se enquadra na obesidade 3.\n", imc);
    return 0;
    }


    return 0;
}
#endif // ex24


#ifdef ex25
int main()
{
    setlocale(LC_ALL, "");
    /* Faça um programa que receba altura e o peso de uma pessoa. De acorda com a tabela e mostre qual a classificação dessa pessoa (de A até I) */

    float altura, peso;

    printf("Insira o valor da sua altura \n");
    scanf("%f", &altura);

    while (altura < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &altura);
    }

    printf("Insira o valor do seu peso: \n");
    scanf("%f", &peso);

    while (peso < 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &peso);
    }

    if (altura < 1.2 && peso <= 60) {
        printf("\nSua classificação é A! \n");
        return 0;
    }

    if (altura < 1.2 && 60 < peso && peso < 90) {
        printf("\nSua classificação é D! \n");
        return 0;
    }

    if (altura < 1.2 && 90 <= peso) {
        printf("\nSua classificação é G! \n");
        return 0;
    }

    if (1.2 <= altura && altura < 1.7 && peso <= 60) {
        printf("\nSua classificação é B! \n");
        return 0;
    }

    if (1.2 <= altura && altura < 1.7 && 60 < peso && peso < 90) {
        printf("\nSua classificação é E! \n");
        return 0;
    }

    if (1.2 <= altura && altura < 1.7 && 90 <= peso) {
        printf("\nSua classificação é H! \n");
        return 0;
    }

    if (1.7 <= altura && peso <= 60) {
        printf("\nSua classificação é C! \n");
        return 0;
    }

    if (1.7 <= altura && 60 < peso && peso < 90) {
        printf("\nSua classificação é F! \n");
        return 0;
    }

    if (1.7 <= altura && 90 <= peso) {
        printf("\nSua classificação é I! \n");
        return 0;
    }

    return 0;
}
#endif // ex25

#ifdef ex26
int main()
{
    setlocale(LC_ALL, "");
    /* . Faça um algoritmo que receba o a idade, o sexo (1 para masculino e 2 para feminino) e salário fixo de um funcionário. Mostre o sexo, a idade e o salário obtido após o acréscimo do abono: */

    int idade, sexo;
    float salario;

    printf("Insira a sua idade: \n");
    scanf("%d", &idade);

    while (idade < 0) {
        printf("Insira um valor válido! \n");
        scanf("%d", &idade);
    }

    printf("Insira o seu sexo (1 para masculino e 2 para feminino): \n");
    scanf("%d", &sexo);

    while (sexo < 0 || sexo > 2) {
        printf("Insira um valor válido! \n");
        scanf("%d", &sexo);
    }

    printf("Insira o valor do seu salário: \n");
    scanf("%f", &salario);

    while (salario < 0 && salario == 0) {
        printf("Insira um valor válido! \n");
        scanf("%f", &salario);
    }

    if (sexo == 1 && idade >= 30) {
        salario = salario + 200;
        printf("\nSeu sexo é masculino, você tem %d anos de idade, e seu novo salário com acréscimo do abono é de R$%.2f", idade, salario);
        return 0;
    }

    if (sexo == 1 && idade < 30) {
        salario = salario + 120;
        printf("\nSeu sexo é masculino, você tem %d anos de idade, e seu novo salário com acréscimo do abono é de R$%.2f", idade, salario);
        return 0;
    }

    if (sexo == 2 && idade >= 30) {
        salario = salario + 220;
        printf("\nSeu sexo é feminino, você tem %d anos de idade, e seu novo salário com acréscimo do abono é de R$%.2f", idade, salario);
        return 0;
    }

    if (sexo == 2 && idade < 30) {
        salario = salario + 130;
        printf("\nSeu sexo é feminino, você tem %d anos de idade, e seu novo salário com acréscimo do abono é de R$%.2f", idade, salario);
        return 0;
    }



    return 0;
}
#endif // ex


