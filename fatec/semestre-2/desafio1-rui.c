#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//\n e ||

char nome_musica1[20], nome_musica2[20], nome_musica3[20];
char nome_autor1[20], nome_autor2[20], nome_autor3[20];
FILE *pa;

void entradaDados() {
    system("cls");
    pa = fopen("desafio.txt", "w");
    printf("Digite o nome da música 1:\n");
    gets(nome_musica1);
    printf("Digite o nome do respectivo autor:\n");
    gets(nome_autor1);
    system("cls");
    printf("Digite o nome da música 2:\n");
    gets(nome_musica2);
    printf("Digite o nome do respectivo autor:\n");
    gets(nome_autor2);
    system("cls");
    printf("Digite o nome da música 3:\n");
    gets(nome_musica3);
    printf("Digite o nome do respectivo autor:\n");
    gets(nome_autor3);
    fwrite(nome_musica1, 1, sizeof(nome_musica1), pa);
    fwrite(nome_autor1, 1, sizeof(nome_autor1), pa);

    fwrite(nome_musica2, 1, sizeof(nome_musica2), pa);
    fwrite(nome_autor2, 1, sizeof(nome_autor2), pa);

    fwrite(nome_musica3, 1, sizeof(nome_musica3), pa);
    fwrite(nome_autor3, 1, sizeof(nome_autor3), pa);
    fclose(pa);
}

void listarDados() {
    system("cls");
    pa = fopen("desafio.txt", "r");

    fread(nome_musica1, sizeof(nome_musica1), 1, pa);
    fread(nome_autor1, sizeof(nome_autor1), 1, pa);
    fread(nome_musica2, sizeof(nome_musica2), 1, pa);
    fread(nome_autor2, sizeof(nome_autor2), 1, pa);
    fread(nome_musica3, sizeof(nome_musica3), 1, pa);
    fread(nome_autor3, sizeof(nome_autor3), 1, pa);

    printf("MÚSICAS\n");
    if (nome_musica1[0] != '*') {
        printf("%s - %s\n", nome_autor1, nome_musica1);
    }
    if (nome_musica2[0] != '*') {
        printf("%s - %s\n", nome_autor2, nome_musica2);
    }
    if (nome_musica3[0] != '*') {
        printf("%s - %s\n", nome_autor3, nome_musica3);
    }
    system("pause");
    fclose(pa);
}

int pesquisaMusica() {
    system("cls");
    pa = fopen("desafio.txt", "r");

    fread(nome_musica1, sizeof(nome_musica1), 1, pa);
    fread(nome_autor1, sizeof(nome_autor1), 1, pa);
    fread(nome_musica2, sizeof(nome_musica2), 1, pa);
    fread(nome_autor2, sizeof(nome_autor2), 1, pa);
    fread(nome_musica3, sizeof(nome_musica3), 1, pa);
    fread(nome_autor3, sizeof(nome_autor3), 1, pa);

    int resultado = -1, i, j;
    char pesquisa[20];
    printf("Digite o nome da música a ser pesquisada:\n");
    gets(pesquisa);
    for(i = 0; i < 3; i++) {
        for(j = 0; pesquisa[j] != '\0'; j++) {
            if(i == 0) {
                if (pesquisa[j] != nome_musica1[j]) {
                    break;
                }
            }
            if(i == 1) {
                if (pesquisa[j] != nome_musica2[j]) {
                    break;
                }
            }
            if(i == 2) {
                if (pesquisa[j] != nome_musica3[j]) {
                    break;
                }
            }
        }
        if (i == 0 && pesquisa[j] == '\0') {
                    resultado = i;
                    printf("Música encontrada!\n");
                    printf("%s - %s\n", nome_autor1, nome_musica1);
                    break;
                }
        if (i == 1 && pesquisa[j] == '\0') {
                    resultado = i;
                    printf("Música encontrada!\n");
                    printf("%s - %s\n", nome_autor2, nome_musica2);
                }
        if (i == 2 && pesquisa[j] == '\0') {
                    resultado = i;
                    printf("Música encontrada!\n");
                    printf("%s - %s\n", nome_autor3, nome_musica3);
                }
    }
    if (resultado == -1) {
        printf("Nenhum música foi encontrada!\n");
    }
    system("pause");
    return(resultado);
    fclose(pa);
}

void pesquisaAutor() {
    char letra;
    pa = fopen("desafio.txt", "r");
    system("cls");
    fread(nome_musica1, sizeof(nome_musica1), 1, pa);
    fread(nome_autor1, sizeof(nome_autor1), 1, pa);
    fread(nome_musica2, sizeof(nome_musica2), 1, pa);
    fread(nome_autor2, sizeof(nome_autor2), 1, pa);
    fread(nome_musica3, sizeof(nome_musica3), 1, pa);
    fread(nome_autor3, sizeof(nome_autor3), 1, pa);

    printf("Digite a primeira letra do autor a ser pesquisado:\n");
    letra = getchar();
    printf("\n");
    if(letra == nome_autor1[0]) {
        printf("AUTOR ENCONTRADO!\n");
        printf("%s - %s\n", nome_autor1, nome_musica1);
    }
    else if(letra == nome_autor2[0]) {
        printf("AUTOR ENCONTRADO!\n");
        printf("%s - %s\n", nome_autor2, nome_musica2);
    }
    else if(letra == nome_autor3[0]) {
        printf("AUTOR ENCONTRADO!\n");
        printf("%s - %s\n", nome_autor3, nome_musica3);
    }
    else {
        printf("Nenhum autor foi encontrado!\n");
    }
    system("pause");
    fclose(pa);
}

void alterarDados() {
    int alterar = pesquisaMusica();
    if (alterar == -1) {
        return;
    }
    system("cls");
    pa = fopen("desafio.txt", "r");
    fread(nome_musica1, sizeof(nome_musica1), 1, pa);
    fread(nome_autor1, sizeof(nome_autor1), 1, pa);
    fread(nome_musica2, sizeof(nome_musica2), 1, pa);
    fread(nome_autor2, sizeof(nome_autor2), 1, pa);
    fread(nome_musica3, sizeof(nome_musica3), 1, pa);
    fread(nome_autor3, sizeof(nome_autor3), 1, pa);

    if (alterar == 0) {
        printf("Digite o nome da música 1:\n");
        gets(nome_musica1);
        printf("Digite o nome do respectivo autor:\n");
        gets(nome_autor1);
    }
    else if (alterar == 1) {
        printf("Digite o nome da música 2:\n");
        gets(nome_musica2);
        printf("Digite o nome do respectivo autor:\n");
        gets(nome_autor2);
    }
    else {
        printf("Digite o nome da música 3:\n");
        gets(nome_musica3);
        printf("Digite o nome do respectivo autor:\n");
        gets(nome_autor3);
    }
    printf("Dados alterados com sucesso!\n");
    system("pause");

    fclose(pa);
    pa = fopen("desafio.txt", "w");
    fwrite(nome_musica1, 1, sizeof(nome_musica1), pa);
    fwrite(nome_autor1, 1, sizeof(nome_autor1), pa);
    fwrite(nome_musica2, 1, sizeof(nome_musica2), pa);
    fwrite(nome_autor2, 1, sizeof(nome_autor2), pa);
    fwrite(nome_musica3, 1, sizeof(nome_musica3), pa);
    fwrite(nome_autor3, 1, sizeof(nome_autor3), pa);
    fclose(pa);
}

void excluirDados() {
    int excluir = pesquisaMusica();
    if (excluir == -1) {
        return;
    }
    system("cls");
    pa = fopen("desafio.txt", "r");
    fread(nome_musica1, sizeof(nome_musica1), 1, pa);
    fread(nome_autor1, sizeof(nome_autor1), 1, pa);
    fread(nome_musica2, sizeof(nome_musica2), 1, pa);
    fread(nome_autor2, sizeof(nome_autor2), 1, pa);
    fread(nome_musica3, sizeof(nome_musica3), 1, pa);
    fread(nome_autor3, sizeof(nome_autor3), 1, pa);

    if(excluir == 0) {
        nome_musica1[0] = '*';
    }
    if(excluir == 1) {
        nome_musica2[0] = '*';
    }
    else {
        nome_musica3[0] = '*';
    }
    printf("Dados excluídos com sucesso!\n");
    system("pause");

    fclose(pa);
    pa = fopen("desafio.txt", "w");
    fwrite(nome_musica1, 1, sizeof(nome_musica1), pa);
    fwrite(nome_autor1, 1, sizeof(nome_autor1), pa);
    fwrite(nome_musica2, 1, sizeof(nome_musica2), pa);
    fwrite(nome_autor2, 1, sizeof(nome_autor2), pa);
    fwrite(nome_musica3, 1, sizeof(nome_musica3), pa);
    fwrite(nome_autor3, 1, sizeof(nome_autor3), pa);
    fclose(pa);
}

main() {
    setlocale(LC_ALL, "");
    int opcao;
    do {
        system("cls");
        printf("MENU\n1-Entrada de dados\n2-Listar dados\n3-Pesquisar nome da música\n4-Pesquisar autor\n5-Alterar dados\n6-Excluir dados\n7-Sair\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 7 || opcao < 1) {
            printf("Digite apenas números entre 1 e 7!\n");
        }
        else {
            switch(opcao) {
            case 1:
                entradaDados();
                break;
            case 2:
                listarDados();
                break;
            case 3:
                pesquisaMusica();
                break;
            case 4:
                pesquisaAutor();
                break;
            case 5:
                alterarDados();
                break;
            case 6:
                excluirDados();
                break;
            }
        }
    } while (opcao != 7);
}
