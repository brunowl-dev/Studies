#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define ex14
#define menu

#ifdef menu
int menu() {
    int iniciar;
    do {
        printf("Deseja iniciar o programa?\n0-N�o\n1-Sim\n");
        scanf("%d", &iniciar);
        if (iniciar != 1 && iniciar != 0) {
            printf("Insira apenas os n�meros 0 ou 1.\n\n");
        }
    } while (iniciar != 1 && iniciar != 0);

    return (iniciar);
}
#endif // menu

#ifdef ex1
float funcVolume_Esfera(float r) {
    float pi = 3.14;
    float calculo = (4/3 * pi) * (pow(r,3));
    return (calculo);
}
int main()
{
    /* Crie a função Esfera que receba da função main o valor do raio e calcule o volume da esfera o seu volume .Exiba o resultado obtido no interior da função main.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float raio, volume;
        do {
            printf("Digite o valor do raio: \n");
            scanf("%f", &raio);
            if (raio <= 0) {
                printf("Digite um valor válido! \n\n");
            }
        } while (raio <= 0);

        volume = funcVolume_Esfera(raio);

        printf("O volume da esfera de raio %.2fcm é de %.2fcm³\n", raio, volume);
    }

    return 0;
}
#endif // ex1

#ifdef ex2
int numSinal(a) {
    int sinal;
    if (a == 0) {
        sinal = 0;
        printf("O número informado é igual a zero! \n");
    }
    else if (a > 0) {
        sinal = 1;
        printf("O número informado é positivo! \n");
    }
    else {
        sinal = -1;
        printf("O número informado é negativo! \n");
    }
}
int main()
{
    /* Crie a função Verifica que receba da função main um valor do tipo inteiro e declarado localmente na função main. Na função verifica verifique e exiba se o valor é positivo ou negativo ouzero.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int num;
        printf("Digite um número: \n");
        scanf("%d", &num);

        numSinal(num);
    }

    return 0;
}
#endif // ex2

#ifdef ex3
float funcDivisao(float a,float b) {
    float quociente = a / b;
    return (quociente);
}
int main()
{
    /* Crie a função Divisão que receba da função main dois números que possibilitem o cálculo da divisão do primeiro pelo segundo. Exiba na função main os números e o resultado obtido na função Divisão*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float dividendo, divisor, resultado;
        printf("Digite o dividendo: \n");
        scanf("%f", &dividendo);
        printf("Digite o divisor: \n");
        scanf("%f", &divisor);

        resultado = funcDivisao(dividendo, divisor);

        printf("O resultado da divisão de %.1f por %.1f é de: %.2f !\n", dividendo, divisor, resultado);
    }

    return 0;
}
#endif // ex3

#ifdef ex4
float ReajSalNovo(float a) {
    if (a < 800) {
        a = a + (a * 0.15);
    }
    else if (a <= 1000) {
        a = a + (a * 0.1);
    }
    else {
        a = a + (a * 0.05);
    }
    return (a);
}
int main()
{
    /* Crie a função ReajSalNovo que receba da função main o valor do salário e efetue o cálculo do reajuste de salário cada funcionário. Considere que o funcionário deve receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Exiba na função main o salário antigo e novo salário obtido na função.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float salario, salarioReajustado;
        do {
            printf("Digite o seu salário a ser reajustado: \n");
            scanf("%f", &salario);
            if (salario <= 0) {
                printf("Digite um valor válido! \n\n");
            }
        } while (salario <= 0);
        salarioReajustado = ReajSalNovo(salario);

        printf("O seu salário de R$%.2f agora é de R$%.2f !", salario, salarioReajustado);
    }

    return 0;
}
#endif // ex4

#ifdef ex5
int ParImpar(int a) {
    int paridade = a % 2;
    if (paridade == 0) {
        printf("O número digitado é par! \n");
    }
    else {
        printf("O número digitado é ímpar! \n");
    }
}
int main()
{
    /* Crie a função ParImpar que receba da função main um valor do tipo inteiro e maior que zero que verifique se o número é para ou ímpar. Exiba no interior da função Parimpar*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int num;
        do {
            printf("Digite um número para verificar sua paridade: \n");
            scanf("%d", &num);
            if (num < 0) {
                printf("Digite apenas valores positivos! \n\n");
            }
        } while (num < 0);

        ParImpar(num);
    }

    return 0;
}
#endif // ex5

#ifdef ex6
float ReajSalNovo(float a) {
    if (a < 800) {
        a = a + (a * 0.15);
    }
    else if (a <= 1000) {
        a = a + (a * 0.1);
    }
    else {
        a = a + (a * 0.05);
    }
    return (a);
}
int main()
{
    /* Crie a função ReajSalNovo que receba da função main o valor do salário e efetue o cálculo do reajuste de salário cada funcionário. Considere que o funcionário deve receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Exiba na função main o salário antigo e novo salário obtido na função de K números definido pelo usuário. Essa quantidade K deverá ser maior que zero e menor ou igual a 10.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int k;
        do {
            printf("Digite o número de salários que serão reajustados: ");
            scanf("%d", &k);
            if (k <= 0 || k > 10) {
                printf("\nDigite apenas números entre 0 e 10! \n\n");
            }
        } while (k <= 0 || k > 10);

        float salarios[k];

        for (int i = 0; i < k; i++) {
            do {
                printf("Digite o salário %d a ser reajustado: ", i+1);
                scanf("%f", &salarios[i]);
                if (salarios[i] <= 0) {
                    printf("\nDigite valores válidos! \n\n");
                }
            } while (salarios[i] <= 0);
            salarios[i] = ReajSalNovo(salarios[i]);
        }

        for (int i = 0; i < k; i++) {
            printf("Salário %d - R$%.2f\n", i+1, salarios[i]);
        }
    }

    return 0;
}
#endif // ex6

#ifdef ex7
int MediaFibonacci(int num) {
    int lista[num];
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            lista[0] = 0;
        }
        else if (i == 1) {
            lista[1] = 1;
        }
        else {
            lista[i] = lista[i-1] + lista[i-2];
        }
        printf("%d\n", lista[i]);
    }
}
int main()
{
    /* Crie a função MédiaFibonacci que receba da função main um valor do tipo inteiro e maior que zero que represente a quantidade de termos da seqüência e calcule a média dos termos da seqüência. Exiba na função main o resultado obtido na função MédiaFibonacci.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int quant;
        do {
            printf("Digite o número de termos da sequência de Fibonacci: ");
            scanf("%d", &quant);
            if (quant <= 0) {
                printf("\nDigite números maiores que zero! \n\n");
            }
        } while (quant <= 0);

        MediaFibonacci(quant);
    }

    return 0;
}
#endif // ex7

#ifdef ex8
float Delta(float a,float b,float c) {
    float delta = sqrt(pow(b,2) - (4 * a * c));
    return (delta);
}
float input() {
    float a;
    printf("Digite o número: ");
    scanf("%f", &a);
    return (a);
}
int main()
{
    /* Crie a função Delta que receba da função main três números reais que garantem a existência de uma equação do segundo grau. Verifique e exiba dentro da função main se há raízes reais e os seus respectivos valores. Caso contrário informe ao usuário.

Observações:

a. Condição de existência de uma equação do segundo grau: o coeficiente que acompanha o x2 deverá ser um número diferente de zero.

b. Delta maior que zero: a equação possui duas raízes reais e distintas.

c. Delta igual à zero: a equação possui duas raízes iguais.

d. Delta menor que zero: a equação não apresenta raízes reais.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a, b, c;
        do {
            a = input();
            if (a == 0) {
                printf("\nDigite um número diferente de zero! \n\n");
            }
        } while (a == 0);

        b = input();
        c = input();

        float delta = Delta(a, b, c);

        if (delta > 0) {
            float x1 = (-b + delta) / (2 * a);
            float x2 = (-b - delta) / (2 * a);
            printf("As raízes da equação informada são: %.2f e %.2f", x1, x2);
        }
        else if (delta == 0) {
            float x1 = (-b + delta) / (2 * a);
            printf("As raízes da equação informado é: %.2f", x1);
        }
        else {
            printf("A equação informada não tem raízes reais! \n");
        }
    }

    return 0;
}
#endif // ex8

#ifdef ex9
int Fatorial(int a) {
    int fatorial = 1;
    for (int i = 1; i < a; i++) {
        if (i == 1) {
            fatorial = a * i;
        }
        else {
            fatorial = fatorial * i;
        }
    }
    return (fatorial);
}
int main()
{
    /* Crie a função Fatorial que receba da função main um número inteiro maior ou igual a zero e calcule o fatorial desse número. Exiba na função main o número e o seu respectivo fatorial obtido na função Fatorial*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int numero, fatorial;
        do {
            printf("Digite o número: ");
            scanf("%d", &numero);
            if (numero < 0) {
                printf("\nDigite um valor válido! \n\n");
            }
        } while (numero < 0);

        fatorial = Fatorial(numero);

        printf("O fatorial do número %d é: %d\n", numero, fatorial);
    }

    return 0;
}
#endif // ex1

#ifdef ex10
float TipoTriangulo(float a,float b,float c) {
    if (a != b && b != c) {
        printf("O triângulo é escaleno! \n");
    }
    else if (a == b && b == c) {
        printf("O triângulo é equilátero! \n");
    }
    else {
        printf("O triângulo é isósceles! \n");
    }
}
float realInput() {
    float numPositivo;
    do {
        printf("Digite o valor do lado do triângulo: \n");
        scanf("%f", &numPositivo);
        if (numPositivo <= 0) {
            printf("Valor inválido! \n\n");
        }
    } while (numPositivo <= 0);

    return (numPositivo);
}
int main()
{
    /* Crie a função TipoTriangulo que receba da função main três números reais que representam um triangulo já definido no interior da função main. Exiba no interior dessa função o tipo do triangulo baseado nas condições abaixo.

Observações:

a. Garantir que cada lado é menor que a soma dos outros dois lados.

b. O triângulo é eqüilátero quando todos os lados são iguais.

c. O triângulo é isósceles quando apenas dois lados são iguais.

d. O triângulo é escaleno quando todos os lados são diferentes.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float a,b,c;
        do {
            a = realInput();
            b = realInput();
            c = realInput();
            if (a > b + c || b > c + a || c > a + b) {
                printf("\nCada lado deve ser menor que a soma dos outros dois lados! \n\n");
            }
        } while (a > b + c || b > c + a || c > a + b);

        TipoTriangulo(a,b,c);
    }

    return 0;
}
#endif // ex10

#ifdef ex11
int definirCategoria(int idade) {
    int categoria[10];
    for (int i = 0; i < 10; i++) {
        if (idade == 0) {
            categoria[i] = 0;
        }
        else if (idade <= 7) {
            categoria[i] = 1;
        }
        else if (idade <= 10) {
            categoria[i] = 2;
        }
        else if (idade <= 13) {
            categoria[i] = 3;
        }
        else if (idade <= 17) {
            categoria[i] = 4;
        }
        else {
            categoria[i] = 5;
        }
        return (categoria[i]);
    }
}
int main()
{
    /* Crie a função Categoria que receba da função main um valor do tipo inteiro e maior que zero que representa a idade e que verifique a categoria baseada na tabela abaixo. Exiba na função main o número e a categoria de um grupo de K números definido pelo usuário e armazenado no vetor Idades. Essa quantidade K deverá ser maior ou igual a 3 e menor ou igual a 10.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int tam;
        do {
            printf("Digite o número de pessoas: ");
            scanf("%d", &tam);
            if (tam < 3 || tam > 10) {
                printf("\nDigite apenas números entre 3 e 10!\n\n");
            }
        } while (tam < 3 || tam > 10);

        int idade[tam], categoria[tam];
        for (int i = 0; i < tam; i++) {
            do {
                printf("Digite a idade: \n");
                scanf("%d", &idade[i]);
                if (idade[i] < 5) {
                    printf("Apenas são aceitas pessoas com 5 anos ou mais! \n\n");
                }
            } while (idade[i] < 5);
        }

        for (int i = 0; i < tam; i++) {
            categoria[i] = definirCategoria(idade[i]);
            if (categoria[i] == 1) {
                printf("Pessoa %d - Idade: %d, categoria: Infantil A\n", i+1, idade[i]);
            }
            else if (categoria[i] == 2) {
                printf("Pessoa %d - Idade: %d, categoria: Infantil B\n", i+1, idade[i]);
            }
            else if (categoria[i] == 3) {
                printf("Pessoa %d - Idade: %d, categoria: Juvenil A\n", i+1, idade[i]);
            }
            else if (categoria[i] == 4) {
                printf("Pessoa %d - Idade: %d, categoria: Juvenil B\n", i+1, idade[i]);
            }
            else{
                printf("Pessoa %d - Idade: %d, categoria: Adulto\n", i+1, idade[i]);
            }
        }
    }

    return 0;
}
#endif // ex11

#ifdef ex12
float inputNota() {
    float nota;
    do {
        printf("Digite a nota: ");
        scanf("%f", &nota);
        if (nota < 0) {
            printf("\nDigite apenas valores positivos! \n\n");
        }
    } while (nota < 0);

    return (nota);
}
float calcMedia(char c, float n1, float n2, float n3) {
    float media;
    if (c == 'A' || c == 'a') {
        media = (n1 + n2 + n3) / 3;
    }
    else if (c == 'P' || c == 'p') {
        media = ((n1 * 5) + (n2 * 3) + (n3 * 2)) / (5 + 3 + 2);
    }
    else {
        media = 3 / ((1/n1) + (1/n2) + (1/n3));
    }
    return (media);
}
int main()
{
    /* Crie a função Media que receba três notas e uma letra de um aluno . Se a letra for A o procedimento calcula a média aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a sua média harmônica. Exiba na função main a média calculada na função Media.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        float nota1, nota2, nota3;
        char letra;
        do {
            printf("Digite o tipo de média, A para aritmética; P para ponderada e H para harmônica: ");
            scanf(" %c", &letra);
            if (letra != 'A' && letra != 'a' && letra != 'P' && letra != 'p' && letra != 'H' && letra != 'h') {
                printf("\nDigite apenas as letras 'A', 'P' ou 'H'\n\n");
            }
        } while (letra != 'A' && letra != 'a' && letra != 'P' && letra != 'p' && letra != 'H' && letra != 'h');

        nota1 = inputNota();
        nota2 = inputNota();
        nota3 = inputNota();

        float media = calcMedia(letra, nota1, nota2, nota3);

        printf("A média foi de %.2f\n", media);
    }

    return 0;
}
#endif // ex12

#ifdef ex13
int NumeroPositivo() {
    int num;
    do {
        printf("Digite o número: ");
        scanf("%d", &num);
        if (num < 0) {
            printf("\nDigite apenas números positivos! \n\n");
        }
    } while (num < 0);

    return (num);
}
int main()
{
    /* Crie a função NumeroPositivo que garanta o recebimento no seu interior de um número maior que zero.Calcule e escreva dentro da função main a tabuada de 1 até N. Mostre a tabuada na forma: 1 x N = N
                                                             2 x N = 2N*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int num = NumeroPositivo();

        for (int i = 1; i <= num; i++) {
            printf("%d x %d = %d\n", i, num, num * i);
        }
    }

    return 0;
}
#endif // ex13

#ifdef ex14
float funcMedia(int j) {
    float notas[4];
    for (int i = 1; i <= 4; i++) {
        do {
            printf("Digite a nota %d do aluno %d: ", i, j);
            scanf("%f", &notas[i]);
            if (notas[i] < 0 || notas[i] > 10) {
                printf("\nDigite um valor válido!\n\n");
            }
        } while (notas[i] < 0 || notas[i] > 10);
        /*mediaFinal = (mediaFinal + notas[i]) / i;
        printf("%.2f\n", mediaFinal); - por algum motivo , o cálculo começava a abaixar independente do input, então decidi fazer de outra forma o cálculo da média!*/
    }

    float mediaFinal = (notas[1] + notas[2] + notas[3] + notas[4]) / 4;
    return (mediaFinal);
}
int main()
{
    /* Crie a função Média que garanta o recebimento no seu interior de quatro números maiores ou iguais a zero e menores ou iguais a 10 que representam as médias de um aluno. Calcule a média aritmética e exiba o conceito do aluno baseado na tabela abaixo e o seu nome recebido no interior da função main. A quantidade de alunos é definida pelo usuário e é no mínimo 3 e no máximo 50 alunos.
    0 a 4,9 - D
    5 a 6,9 - C
    7 a 8,9 - B
    9 a 10 - A*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int tam, i;
        do {
            printf("Digite o número de alunos: ");
            scanf("%d", &tam);
            if (tam < 3 || tam > 50) {
                printf("\nO número de alunos deve ser entre 3 e 50!\n\n");
            }
         } while (tam < 3 || tam > 50);
        float medias[tam];
        char nome[10], conceitos[tam];
        for (i = 1; i <= tam; i++) {
            medias[i] = funcMedia(i);
            if (medias[i] <= 4.9) {
                conceitos[i] = 'D';
            }
            else if (medias[i] <= 6.9) {
                conceitos[i] = 'C';
            }
            else if (medias[i] <= 8.9) {
                conceitos[i] = 'B';
            }
            else {
                conceitos[i] = 'A';
            }
        }
        for (i = 1; i <= tam ; i++) {
            printf("Digite o nome do aluno %d: \n", i);
            scanf("%s", &nome);
            printf("O aluno(a) %s teve média %.2f e conceito %c\n", nome, medias[i], conceitos[i]);
        }
    }

    return 0;
}
#endif // ex14

#ifdef ex15
float pesoIdeal(char s, float altura) {
    float peso;
    if (s == 'M' || s == 'm') {
        peso = (72.7 * altura) - 58;
    }
    else {
        peso = (62.1 * altura) - 44.7;
    }

    return (peso);
}
int main()
{
    /* Crie a função Peso Ideal que por parâmetro da função main, a altura (alt) e o sexo de uma pessoa e retorna o seu peso ideal.O recebimento da altura que deverá ser maior que zero e do sexo que só poderá ser m ou f será feito no interior da função main. Para homens, calcular o peso ideal usando a fórmula peso ideal = 72.7 x alt - 58 e, para mulheres, peso ideal = 62.1 x alt - 44.7. A quantidade de indivíduos será definida pelo usuário e deverá ser maior que 3 e menor ou igual a 12.*/
    setlocale(LC_ALL, "");
    int start;
    start = menu();
    if (start == 1) {
        int quant;
        do {
            printf("Digite a quantidade de indivíduos: ");
            scanf("%d", &quant);
            if (quant <= 3 || quant > 12) {
                printf("\nO número de indivíduos deve ser entre 4 e 12!\n\n");
            }
        } while (quant <= 3 || quant > 12);
        float pesos[quant], altura[quant];
        char sexos[quant];
        for (int i = 1; i <= quant; i++) {
            do {
                printf("Digite a altura do indivíduo %d: ");
                scanf("%f", &altura[i]);
                if (altura[i] <= 0) {
                    printf("\nO valor da altura deve ser positivo!\n\n");
                }
            } while (altura[i] <= 0);

            do {
                printf("Qual o sexo do indivíduo %d?\nM - masculino; F - feminino\n");
                scanf("%c", &sexos[i]);
                if (sexos[i] != 'M' && sexos[i] != 'm' && sexos[i] != 'f' && sexos[i] != 'F') {
                    printf("Digite apenas as letras 'F' ou 'M'!\n");
                }
            } while (sexos[i] != 'M' && sexos[i] != 'm' && sexos[i] != 'f' && sexos[i] != 'F');
            pesos[i] = pesoIdeal(altura[i], sexos[i]);
        }

        for (int i = 1; i <= quant; i++) {
            if (sexos[i] == 'M' || sexos[i] == 'm') {
                printf("O peso ideal do indivíduo %d é %.2fkg\n");
            }
            else {
                printf("O peso ideal da indivíduo %d é %.2fkg\n");
            }
        }
    }

    return 0;
}
#endif // ex15

