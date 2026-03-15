import random
EX1 = False
EX2 = False
EX3 = False
EX4 = True

if EX1:
    #EX1 - Crie uma tupla com 5 cores. Depois, imprima todas as cores usando um laço for.
    cores = ('azul', 'vermelho', 'branco', 'preto', 'roxo')
    for cor in cores:
        print(cor)

if EX2:
    #Peça ao usuário que digite 5 números inteiros e armazene-os em uma tupla. Depois, mostre:
    #A soma dos números
    #O maior número
    #O menor número
    lista = []
    for _ in range(5):
        num = int(input('Digite um número: '))
        lista.append(num)
    
    tupla = tuple(lista)
    print(f'A soma dos números: {sum(tupla)}')
    print(f'O maior número: {max(tupla)}')
    print(f'O menor número: {min(tupla)}')

if EX3:
    #Crie duas tuplas:
    #A primeira com o nome de 4 produtos
    #A segunda com o preço de cada um desses produtos
    #Depois, mostre uma “etiqueta” com os produtos e seus respectivos preços alinhados.
    produtos = ('Arroz', 'Feijão', 'Carne', 'Manteiga')
    preco = (15, 10, 20, 16)
    print('ETIQUETA')
    for i in range(4):
        print(f'{produtos[i]} - R${preco[i]}')

if EX4:
    #Crie uma tupla com 10 números aleatórios entre 1 e 20. Depois, mostre:
    #A tupla completa
    #Uma nova tupla com os valores únicos (sem repetições)
    lista = []
    for _ in range(10):
        num = random.randint(1,20)
        lista.append(num)
    
    tupla = tuple(lista)
    tupla_norepeat = tuple(set(tupla))
    print(tupla)
    print(tupla_norepeat)