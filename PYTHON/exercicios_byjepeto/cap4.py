# Capítulo 4 - Trabalhando com Listas
import os

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = True 

if EX1:
    #Crie uma lista com 5 nomes e mostre o primeiro e o último.
    lista = []
    for i in range(5):
        nome = input(f"Digite um nome para o indice {i}: ")
        lista.append(nome)
    
    print(f"O primeiro nome eh {lista[0]} e o ultimo nome eh {lista[4]}")

if EX2:
    #Adicione, remova e ordene os itens de uma lista de números.
    opcao = 0
    lista = []
    while (opcao != 4):
        os.system("cls")
        opcao = int(input("MENU\n1-Adicionar numeros a lista\n2-Remover numetros da lista\n3-Ordenar numeros\n4-Sair\n"))
        if(opcao == 4):
            break

        elif(opcao == 1):
            num = int(input("Digite o numero que voce quer adicionar: "))
            lista.append(num)
            print("Numero adicionado com sucesso!")

        elif(opcao == 2):
            num = int(input("Qual numero voce quer remover? "))
            if((num in lista) == True):
                lista.remove(num)
                print("Numero removido com sucesso!")
            else:
                print("O numero nao esta na lista!")
        
        elif(opcao == 3):
            lista.sort()
            print(f"Lista ordenada de forma crescente:\n{lista}")
        os.system("pause")
    print("O programa foi finalizado!")

if EX3:
    #Receba 5 notas e armazene numa lista. Depois calcule a média. 
    lista = []
    soma = 0
    for i in range(5):
        nota = float(input("Digite a nota: "))
        lista.append(nota)
    
    for num in lista:
        soma += num
    media = soma / len(lista)
    print(f"A media eh {media:.2f}")

if EX4:
    #Peça vários números até o usuário digitar -1, e armazene numa lista. Depois mostre:
    #Total, maior, menor e média.
    lista = []
    i = 0
    num = 0
    maior = 0
    total = 0

    while (num != -1):
        num = int(input("Digite um numero: "))
        if (num == -1):
            break
        else:
            lista.append(num)
            if (num > maior):
                maior = num

            if(i == 0):
                menor = num

            elif (num < menor):
                menor = num
        i += 1
    
    for num in lista:
        total += num   

    media = total / len(lista)

    print(f"O total eh {total}\nO maior numero eh {maior} e o menor eh {menor}\nA media total eh {media:.2f}\n")

if EX5:
    #Desafio: Crie um sistema de cadastro de produtos (nome + preço). 
    #O usuário pode adicionar quantos quiser e ao final o programa mostra o produto mais caro e o mais barato.
    lista_preco = []
    lista_produto = []
    opcao = 0
    while (opcao != 3):
        os.system("cls")
        opcao = int(input("1-Cadastrar produto\n2-Mostrar produtos\n3-Sair\n"))
        if(opcao == 3):
            break
        elif(opcao == 1):
            produto = input("Digite o nome do produto: ")
            preco = float(input("Digite o preco: "))
            lista_produto.append(produto)
            lista_preco.append(preco)
        elif(opcao == 2):
            for i in range(len(lista_preco)):
                print(f"{lista_produto[i]} - {lista_preco[i]:.2f}")
        os.system("pause")
    
    print("Programa finalizado!")