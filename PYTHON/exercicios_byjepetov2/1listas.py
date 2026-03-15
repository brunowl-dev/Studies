import random

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = False
DSF = True

if EX1:
    #EX1. Crie uma lista com 5 nomes. Depois, imprima todos os nomes usando um for.
    lista = ['Bruno', 'Rafa', 'Fabio','Luana','Kelly']
    for nome in lista:
        print(nome)

if EX2:
    #EX2. Peça ao usuário 5 números inteiros e armazene em uma lista. Depois:
    #Mostre a soma dos números.
    #Mostre o maior e o menor valor da lista.
    lista = []
    for i in range(5):
        num = int(input(f'Digite um numero para o índice {i}: '))
        lista.append(num)
    print(sum(lista))
    print(max(lista))
    print(min(lista))

if EX3:
    # EX3. Faça um programa que peça ao usuário para digitar quantos números ele quiser (até digitar 0), e armazene-os numa lista. Depois, imprima:
    #A lista original
    #A lista invertida
    #A quantidade de números pares
    lista = []
    pares = 0
    while True:
        num = int(input('Digite um numero: '))
        if(num == 0):
            break
        lista.append(num)
        if(num % 2 == 0):
            pares += 1

    print(lista)
    print(lista[::-1])
    print(f'Tem {pares} números pares')

if EX4:
    # EX4. Crie uma lista com 10 números aleatórios entre 1 e 50. Depois:
    #Crie outra lista só com os números pares
    #Crie outra lista com os números maiores que 25
    #(Use import random e random.randint(1,50) para gerar os números)
    lista1 = []
    lista_pares = []
    lista_25 = []
    for i in range(10):
        num = random.randint(1,50)
        lista1.append(num)
        if num % 2 == 0:
            lista_pares.append(num)
        if num > 25:
            lista_25.append(num)

    print(lista1)
    print(lista_pares)
    print(lista_25)
    
if EX5:
    #EX5. Faça um programa que simule um carrinho de compras:
    #O usuário deve digitar o nome do item até digitar "fim".
    #Armazene os itens numa lista.
    #Ao final, exiba todos os itens digitados com numeração (1. Arroz, 2. Feijão, ...)
    lista = []
    while True:
        item = input('Digite o item a ser comprado, caso queira encerrar, digite "fim"\n')
        if item == 'fim':
            break
        lista.append(item)
    
    for i in range(len(lista)):
        if (i == len(lista)-1):
            print(f'{i+1}. {lista[i]}')
        else:
            print(f'{i+1}. {lista[i]}', end=', ')