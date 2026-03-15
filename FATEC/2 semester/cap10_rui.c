#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define funcaoMenu
#define ex4

#ifdef funcaoMenu
int funcMenu() {
    int start;
    do {
        printf("MENU\n");
        printf("0-Sair o programa\n");
        printf("1-Iniciar do programa\n");
        scanf("%d", &start);
        if (start != 1 && start != 0) {
            printf("Digite apenas os números 1 ou 0!\n");
        }
    } while (start != 1 && start != 0);

    return (start);
}
#endif //funcaoMenu

#ifdef ex1
main() {
    /*1 - Escreva um programa para criar e abrir um arquivo. Receba via
    teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo.
    O caracter '0' finaliza a entrada de dados. Abra o arquivo novamente,
    leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).*/
    setlocale(LC_ALL, "");
    FILE *pa;
    char c; int opcao;
    do {
        printf("MENU\n0-Sair\n1-Inserir letras\n2-Listar letras\n");
        scanf("%d", &opcao);
        system("CLS");
        switch(opcao) {
        case 1:
            pa = fopen("ex1.txt", "w");
            for(;;) {
                printf("Digite a letra:\n");
                scanf(" %c", &c);
                putc(c, pa);
                if (c == '0') {
                    break;
                }
            }
            system("CLS");
            fclose(pa);
        case 2:
            pa = fopen("ex1.txt", "r");
            for(;;) {
                c = getc(pa);
                if (c == '0') {
                    break;
                }
                else {
                    printf("%c\n", c);
                }
            }
            system("pause");
            system("cls");
            fclose(pa);
            break;
        }
    } while (opcao != 0);
    printf("Finalizando programa...\n");
    exit(0);
}
#endif // ex1

#ifdef ex2
FILE *pa;
struct contato{
    char nome[10], tel[15];
    int dia, mes;
};
void carrega_dados(struct contato *p) {
    int i;
    for(i = 0; i < 4; i++) { //Usar um fread só
        fread((p+i)->nome, sizeof((p+i)->nome), 1, pa);
        fread((p+i)->tel, sizeof((p+i)->tel), 1, pa);
        fread(&(p+i)->dia, sizeof((p+i)->dia), 1, pa);
        fread(&(p+i)->mes, sizeof((p+i)->mes), 1, pa);
    }
}
void inserir(struct contato *p) {
    system("cls");
    int i;
    for (i = 0; i < 4; i++) {
        getchar();
        printf("Digite o nome do índice %d:\n", i);
        gets((p+i)->nome);
        printf("Digite o telefone do(a) %s\n", (p+i)->nome);
        gets((p+i)->tel);
        printf("Digite o aniversário (dia e mês) do(a) %s\n", (p+i)->nome);
        scanf("%d %d", &(p+i)->dia, &(p+i)->mes);
    }
}
void listar(struct contato *p) {
    system("cls");
    int i;
    for (i = 0; i < 4; i++) {
        if ((p+i)->nome[0] != '*') {
            printf("Nome - %s\nTelefone - %s\nAniversário - %d/%d\n", (p+i)->nome, (p+i)->tel, (p+i)->dia, (p+i)->mes);
            printf("\n");
        }
    }
    system("pause");
}
int pesquisa_nome(struct contato *p) {
    system("cls");
    char nome[10];
    printf("Digite o nome a ser pesquisado:\n");
    scanf(" %s", &nome);
    int i, j, resultado = -1;
    for(j = 0; j < 4; j++) {
        for (i = 0; i < 10; i++) {
            if (nome[i] != (p+j)->nome[i]) {
                break;
            }
            if (nome[i] == '\0' && (p+j)->nome[i] == '\0') {
                resultado = j;
            }
        }
        if (resultado != -1) {
            break;
        }
    }
    if (resultado != -1) {
        printf("Contato encontrado!\n");
        printf("Nome - %s\nTelefone - %s\nAniversário - %d/%d\n", (p+resultado)->nome, (p+resultado)->tel, (p+resultado)->dia, (p+resultado)->mes);
        printf("\n");
        system("pause");
    }
    else {
        printf("Contato não foi encontrado!\n");
        system("pause");
    }
    return (resultado);
}
void listar_letra(struct contato *p) {
    char letra;
    system("cls");
    printf("Digite a letra:\n");
    scanf(" %c", &letra);
    int i, encontrado = 0;
    for (i = 0; i < 4; i++) {
        if (letra == (p+i)->nome[0]) {
            printf("Nome - %s\nTelefone - %s\nAniversário - %d/%d\n", (p+i)->nome, (p+i)->tel, (p+i)->dia, (p+i)->mes);
            printf("\n");
            encontrado++;
        }
    }
    if (encontrado != 0) {
        system("pause");
    }
    else {
        printf("Nenhum contato tem a letra digitada!\n");
        system("pause");
    }
}
void listar_aniversariantes(struct contato *p) {
    system("cls");
    int mes, i, encontrado = 0;
    printf("Digite mês que você quer pesquisar:\n");
    scanf("%d", &mes);
    for (i = 0; i < 4; i++) {
        if (mes == (p+i)->mes) {
            printf("Nome - %s\nTelefone - %s\nAniversário - %d/%d\n", (p+i)->nome, (p+i)->tel, (p+i)->dia, (p+i)->mes);
            encontrado++;
        }
    }
    if (encontrado == 0) {
        printf("Ninguém faz aniversário no mês digitado!\n");
        system("pause");
    }
    else {
        system("pause");
    }
}
void altera_contato(struct contato *p) {
    system("cls");
    int alterar = pesquisa_nome(p);
    if (alterar != -1) {
        getchar();
        printf("Digite o novo nome:\n");
        gets((p+alterar)->nome);
        printf("Digite o telefone do(a) %s\n", (p+alterar)->nome);
        gets((p+alterar)->tel);
        printf("Digite o aniversário (dia e mês) do(a) %s\n", (p+alterar)->nome);
        scanf("%d %d", &(p+alterar)->dia, &(p+alterar)->mes);
    }
}
void excluir_contato(struct contato *p) {
    system("cls");
    int excluir = pesquisa_nome(p);
    if (excluir != -1) {
        (p+excluir)->nome[0] = '*';
        printf("Nome excluído com sucesso!\n");
        system("pause");
    }
}
main() {
    /*2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome completo
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato pesquisando pelo nome completo
    7 - exclui contato pesquisando pelo nome completo
    8 - saida*/
    setlocale(LC_ALL, "");
    struct contato agenda[4], *p; int opcao, i;
    p = &agenda[0];
    pa = fopen("ex2.txt", "r");
    carrega_dados(p);
    do {
        system("cls");
        printf("MENU\n1-Inserir contato\n2-Listar todos os contatos\n3-Pesquisar um contato pelo nome completo\n4-Listar os contatos cujo nome inicia com uma letra digitada\n5-Imprimir os aniversariantes do mês\n6-Altera contato pesquisando pelo nome completo\n7-Exclui contato pesquisando pelo nome completo\n8-Saída\n");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            inserir(p);
            break;
        case 2:
            listar(p);
            break;
        case 3:
            pesquisa_nome(p);
            break;
        case 4:
            listar_letra(p);
            break;
        case 5:
            listar_aniversariantes(p);
            break;
        case 6:
            altera_contato(p);
            break;
        case 7:
            excluir_contato(p);
            break;
        }
    } while (opcao != 8);
    printf("Finalizando o programa\n");
    fclose(pa);
    pa = fopen("ex2.txt", "w");
    for(i = 0; i < 4; i++) {
        fwrite((p+i)->nome, sizeof((p+i)->nome), 1, pa);
        fwrite((p+i)->tel, sizeof((p+i)->tel), 1, pa);
        fwrite(&(p+i)->dia, sizeof(int), 1, pa);
        fwrite(&(p+i)->mes, sizeof(int), 1, pa);
    }
    fclose(pa);
    exit(0);
}
#endif // ex2

#ifdef ex3
FILE *pa;
struct dados {
    char nome[10], email[50], cel[15];
};
void incluir(struct dados *p) {
    getchar();
    system("cls");
    pa = fopen("ex3.txt", "a");
    printf("Digite o nome:\n");
    gets(p->nome);
    printf("Digite o e-mail:\n");
    gets(p->email);
    printf("Digite o celular:\n");
    gets(p->cel);
    fwrite(p, sizeof(struct dados), 1, pa);
    fclose(pa);
}
void listar(struct dados *p) {
    system("cls");
    if ((pa = fopen("ex3.txt", "r")) == NULL) {
        printf("Arquivo não existe!\n");
    }
    else {
        for(;;) {
            if (fread(p, sizeof(struct dados), 1, pa) != 1) {
                break;
            }
            else {
                if (p->nome[0] != '*') {
                    printf("Nome - %s\nE-mail - %s\nCelular - %s\n", p->nome, p->email, p->cel);
                    printf("\n");
                }
            }
        }
    }
    system("pause");
    fclose(pa);
}
int pesquisar(struct dados *p) {
    system("cls");
    int i, resultado = -1, j;
    char nome[10];
    getchar();
    printf("Digite o nome:\n");
    gets(nome);
    if ((pa = fopen("ex3.txt", "r")) == NULL) {
        printf("Arquivo não existe!\n");
    }
    else {
        for(j = 0; fread(p, sizeof(struct dados), 1, pa) != 0; j++) {
            for(i = 0; nome[i] != '\0'; i++) {
                if (nome[i] != p->nome[i]) {
                    break;
                }
                if (nome[i] == '\0' && p->nome[i] == '\0') {
                    resultado = j;
                    break;
                }
            }
            if (resultado != -1) {
                printf("Cliente encontrado!\n");
                printf("Nome - %s\nE-mail - %s\nCelular - %s\n", p->nome, p->email, p->cel);
                break;
            }
        }
        if (resultado == -1) {
            printf("Cliente não encontrado!\n");
        }
    }
    system("pause");
    fclose(pa);
    return (resultado);
}
void alterar(struct dados *p) {
    int alterar;
    alterar = pesquisar(p);
    system("cls");
    if (alterar == -1) {
        printf("Arquivo não existe ou cliente não foi encontrado!\n");
    }
    else {
        pa = fopen("ex3.txt", "r+");
        printf("Digite o novo nome:\n");
        gets(p->nome);
        printf("Digite o novo e-mail:\n");
        gets(p->email);
        printf("Digite o novo celular:\n");
        gets(p->cel);
        alterar = alterar * (sizeof(struct dados));
        fseek(pa, alterar, 0);
        fwrite(p, sizeof(struct dados), 1, pa);
        fclose(pa);
        printf("Dados alterados com sucesso!\n");
    }
    system("pause");
}
void excluir(struct dados *p) {
    int excluir;
    excluir = pesquisar(p);
    system("cls");
    if (excluir == -1) {
        printf("Arquivo não existe ou cliente não foi encontrado!\n");
    }
    else {
        pa = fopen("ex3.txt", "r+");
        excluir = excluir * (sizeof(struct dados));
        fseek(pa, excluir, 0);
        p->nome[0] = '*';
        fwrite(p, sizeof(struct dados), 1, pa);
        fclose(pa);
        printf("Dados excluídos com sucesso!\n");
    }
    system("pause");
}
main() {
    /*3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/
    setlocale(LC_ALL, "");
    int opcao;
    struct dados clientes, *p;
    p = &clientes;
    do {
        system("cls");
        printf("MENU\n1-Inclui registros\n2-Listar todos os registros\n3-Pesquisar registro pelo nome\n4-Alterar registro\n5-Exclui registro\n6-Saída\n");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao) {
        case 1:
            incluir(p);
            break;
        case 2:
            listar(p);
            break;
        case 3:
            pesquisar(p);
            break;
        case 4:
            alterar(p);
            break;
        case 5:
            excluir(p);
            break;
        }
    } while (opcao != 6);
    exit(0);
}
#endif // ex3

#ifdef ex4
FILE *pa;
struct mercadorias {
    int id;
    int quant;
    char nome[20];
};
void incluir(struct mercadorias *p) {
    system("cls");
    if((pa = fopen("ex4.txt", "a")) == NULL) {
        pa = fopen("ex4.txt", "w");
    }
    printf("Digite o ID do produto:\n");
    scanf("%d", &p->id);
    getchar();
    printf("Qual o nome do produto?\n");
    gets(p->nome);
    printf("Qual a quantidade desse produto no estoque?\n");
    scanf("%d", &p->quant);
    fwrite(p, sizeof(struct mercadorias), 1, pa);
    printf("Produto cadastrado com sucesso!\n");
    fclose(pa);
}
void listar(struct mercadorias *p) {
    system("cls");
    if ((pa = fopen("ex4.txt", "r")) == NULL) {
        printf("Arquivo não existe!\n");
    }
    else {
        for(;;) {
            if(fread(p, sizeof(struct mercadorias), 1, pa) != 1) {
                break;
            }
            else {
                if (p->nome[0] != '*') {
                    printf("ID - %d\nNome - %s\nQuant - %d\n", p->id, p->nome, p->quant);
                    printf("\n");
                }
            }
        }
    }
    system("pause");
    fclose(pa);
}
int pesquisar(struct mercadorias *p) {
    system("cls");
    int i, resultado = -1, j;
    char nome[10];
    getchar();
    printf("Digite o nome:\n");
    gets(nome);
    if ((pa = fopen("ex4.txt", "r")) == NULL) {
        printf("Arquivo não existe!\n");
    }
    else {
        for(j = 0; fread(p, sizeof(struct mercadorias), 1, pa) != 0; j++) {
            for(i = 0; i < 10; i++) {
                if (nome[i] != p->nome[i]) {
                    break;
                }
                if (nome[i] == '\0' && p->nome[i] == '\0') {
                    resultado = j;
                    break;
                }
            }
            if (resultado != -1) {
                printf("Mercadoria encontrada!\n");
                printf("ID - %d\nNome - %s\nQuant - %d\n", p->id, p->nome, p->quant);
                break;
            }
        }
        if (resultado == -1) {
            printf("Mercadoria não encontrada!\n");
        }
    }
    system("pause");
    fclose(pa);
    return (resultado);
}
void listar_naodisp(struct mercadorias *p) {
    system("cls");
    if ((pa = fopen("ex4.txt", "r")) == NULL) {
        printf("Arquivo não existe!\n");
    }
    else {
        for(;;) {
            if(fread(p, sizeof(struct mercadorias), 1, pa) != 1) {
                break;
            }
            else {
                if (p->nome[0] != '*' && p->quant == 0) {
                    printf("ID - %d\nNome - %s\nQuant - %d\n", p->id, p->nome, p->quant);
                    printf("\n");
                }
            }
        }
    }
    system("pause");
    fclose(pa);
}
void alterar_quant(struct mercadorias *p) {
    int alterar, es;
    alterar = pesquisar(p);
    system("cls");
    if (alterar == -1) {
        printf("Arquivo não existe ou cliente não foi encontrado!\n");
    }
    else {
        pa = fopen("ex4.txt", "r+");
        alterar = alterar * sizeof(struct mercadorias);
        fseek(pa, alterar, 0);
        fread(p, sizeof(struct mercadorias), 1, pa);
        printf("Digite a entrada ou saída do novo produto:\n");
        scanf("%d", &es);
        p->quant = p->quant + es;
        fseek(pa, -sizeof(struct mercadorias), 1);
        fwrite(p, sizeof(struct mercadorias), 1, pa);
        fclose(pa);
        printf("Dados alterados com sucesso!\n");
    }
    system("pause");
}
void alterar_prod(struct mercadorias *p) {
    int alterar;
    alterar = pesquisar(p);
    system("cls");
    if (alterar == -1) {
        printf("Arquivo não existe ou cliente não foi encontrado!\n");
    }
    else {
        pa = fopen("ex4.txt", "r+");
        printf("Digite o nome do novo produto:\n");
        gets(p->nome);
        printf("Digite o ID:\n");
        scanf("%d", &p->id);
        printf("Digite a quantidade:\n");
        scanf("%d", &p->quant);
        alterar = alterar * (sizeof(struct mercadorias));
        fseek(pa, alterar, 0);
        fwrite(p, sizeof(struct mercadorias), 1, pa);
        fclose(pa);
        printf("Dados alterados com sucesso!\n");
    }
    system("pause");
}
void excluir(struct mercadorias *p) {
    int excluir;
    excluir = pesquisar(p);
    system("cls");
    if (excluir == -1) {
        printf("Arquivo não existe ou cliente não foi encontrado!\n");
    }
    else {
        pa = fopen("ex4.txt", "r+");
        excluir = excluir * (sizeof(struct mercadorias));
        fseek(pa, excluir, 0);
        p->nome[0] = '*';
        fwrite(p, sizeof(struct mercadorias), 1, pa);
        fclose(pa);
        printf("Dados excluídos com sucesso!\n");
    }
    system("pause");
}
main() {
    /*4 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/
    setlocale(LC_ALL, "");
    struct mercadorias prods, *p;
    p = &prods;
    int opcao;
    do {
        system("cls");
        printf("MENU\n1-Inclui produtos\n2-Listar todos os produtos\n3-Pesquisar uma mercadoria pela descrição\n4-Listar os produtos não disponíveis\n5-Alterar a quantidade atual de produtos\n6-Altera produtos\n7-Exclui produtos\n8-Saída\n");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            incluir(p);
            break;
        case 2:
            listar(p);
            break;
        case 3:
            pesquisar(p);
            break;
        case 4:
            listar_naodisp(p);
            break;
        case 5:
            alterar_quant(p);
            break;
        case 6:
            alterar_prod(p);
            break;
        case 7:
            excluir(p);
            break;
        }
    } while (opcao != 8);
    printf("Programa encerrando...\n");
    exit(0);
}
#endif // ex4
