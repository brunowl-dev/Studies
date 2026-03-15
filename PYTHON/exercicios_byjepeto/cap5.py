# Capítulo 5 - Trabalhando com Tuplas
import os

EX1 = False
EX2 = True
EX3 = False 
EX4 = False
EX5 = False

if EX1:
    #Crie uma tupla com 5 cores e mostre-as uma a uma usando for.
    cores = ('vermelho', 'azul', 'preto', 'branco', 'roxo')
    for cor in cores:
        print(cor)

if EX2:
    #Peça 3 nomes e armazene numa tupla. Depois diga qual começa com a letra “A”.
    tupla = ()
    for i in range(3):
        nome = input("Digite um nome: ")
        tupla += (nome,)

    for i in range(3):
        if("A" in tupla[i].upper()):
            print(f"A letra A esta no item {i}: {tupla[i]}")
            break

if EX3:
    # Crie uma tupla com 10 números e diga:
    # Quantos são pares, e qual o maior.
    lista = (0,1,2,3,4,5,6,7,8,9)
    cont_par = 0
    maior = 0
    for i in range(10):
        if lista[i] % 2 == 0:
            cont_par += 1
        if lista[i] > maior:
            maior = lista[i]
    
    print(f"Tem {cont_par} numeros pares e o maior deles eh {maior}")

if EX4:
    #Crie uma função que retorna (menor, maior, média) de uma tupla de números.
    lista = ()
    num = 1
    media = 0
    while (num != 0):
        num = int(input("Digite o numero: "))
        if(num == 0):
            break
        lista += (num,) 
        media += num
    
    media = media / len(lista)
    maior = max(lista)
    menor = min(lista)
    print(f"O menor numero eh {menor}, o maior numero eh {maior}\nA media eh {media:.2f}")

if EX5:
    #Desafio: Faça uma agenda onde cada contato é uma tupla com (nome, telefone). Mostre a agenda ordenada por nome.
    agenda = ()
    opcao = 0
    while (opcao != 3):
        os.system("cls")
        opcao = int(input("MENU\n1-Registrar um novo contato\n2-Listar os contatos\n3-Sair\n"))
        if(opcao == 3):
            break
        elif(opcao == 1):
            nome = input("Digite o nome: ")
            telefone = input(f"Digite o telefone do(a) {nome}: ")
            agenda += (nome,telefone,)
        elif(opcao == 2):
            for i in range(0,len(agenda), 2):
                print(f"{agenda[i]} - {agenda[i+1]}")
            os.system("pause")
    
    print("Programa finalizado com sucesso!")
