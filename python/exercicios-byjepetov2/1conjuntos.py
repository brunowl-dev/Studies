import random

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = True

if EX1:
    #Crie dois conjuntos com nomes de frutas. Depois, mostre:
    #A união dos dois conjuntos
    #A interseção (frutas que aparecem nos dois)
    #A diferença entre o primeiro e o segundo conjunto
    f1 = {'maça', 'uva', 'morango'}
    f2 = {'morango', 'melancia', 'banana'}
    print(f1 | f2)
    print(f1 & f2)
    print(f1 - f2)

if EX2:
    #Peça ao usuário para digitar 5 números inteiros.
    #Armazene esses números em um conjunto (não pode ter repetição).
    #Depois, mostre:
    #O conjunto completo
    #A quantidade de elementos
    lista = []
    for _ in range(5):
        lista.append(int(input('Digite um número: ')))
    
    conj = set(lista)
    print(conj)
    print(len(conj))

if EX3:
    #Crie um conjunto com as letras da palavra "abacaxi" e outro com as letras de "uva".
    #Mostre:
    #As letras que aparecem nas duas palavras
    #As letras que aparecem só em "abacaxi"
    #As letras que aparecem só em "uva"
    f1 = {'a', 'b', 'a', 'c', 'a', 'x', 'i'}
    f2 = {'u', 'v', 'a'}
    print(f1 & f2)
    print(f1 - f2)
    print(f2 - f1)

if EX4:
    #Peça ao usuário para digitar nomes (um por vez).
    #O programa deve encerrar quando for digitado “fim”.
    #Armazene todos os nomes em um conjunto e depois mostre:
    #Quantos nomes únicos foram digitados
    #A lista de nomes (sem repetição)
    lista = []
    while True:
        nome = input('Digite um nome: ')
        if (nome == 'fim'):
            break
        lista.append(nome)
    conj = set(lista)
    print(f'Foram digitados {len(conj)} nomes únicos')
    print(conj)

if EX5:
    #Crie dois conjuntos com números aleatórios entre 1 e 20 (com 10 números cada).
    #Depois, mostre:
    #Os números que aparecem nos dois conjuntos
    #Os que aparecem só no primeiro
    #Os que aparecem só no segundo
    #A união dos dois conjuntos
    lista1 = []
    lista2 = []
    for _ in range(10):
        num = random.randint(1,20)
        lista1.append(num)
    for _ in range(10):
        num = random.randint(1,20)
        lista2.append(num)
    
    conj1 = set(lista1)
    conj2 = set(lista2)
    print(conj1 & conj2)
    print(conj1 - conj2)
    print(conj2 - conj1)
    print(conj1 | conj2)