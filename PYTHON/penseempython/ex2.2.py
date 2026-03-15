ex1 = False
ex2 = False
ex3 = True

if ex1:
    #O volume da uma esfera com raio r é: 4/3πr³. Qual é op volume de uma esfera com raio 5?
    pi = 3.14
    r = 5
    volume = 4/3 * pi * r**3
    print(f'Volume é {volume:.2f}cm³')

if ex2:
    #Suponha que o preço de capa de um livro seja R$24,95 , msa as livrarias recebem um desconto de 40%.
    #O transporte custa R$3,00 para o primeiro exemplar e 75 centavos para cada exemplar adicional
    #Qual é o custo total de atacado para 60 cópias ?
    preco = 24.95
    preco = 24.95 - (24.95 * 0.4)

    copias = 60

    total = 3 + (0.75 * (copias - 1)) + (preco * copias)
    print(f'O total é R${total:.2f}')

if ex3:
    #Se eu sair da minha ás 6:52 e correr 1km a um certo passo (8min e 15segundos por km)
    #Então 3km a um passo mais rápido (7min e 12segundos por km)
    #E 1km no mesmo passo usado em primeiro lugar, que horas chego em casa para o café da manhã?
    partida = (6 * 3600) + (52 * 60)
    t = (8 * 60) + 15
    t += 3 * ((7 * 60) + 12)
    t += (8 * 60) + 15
    partida += t
    horas = partida // 3600
    min = (partida % 3600) // 60 
    print(f'Chegada: {horas:.0f}h e {min:.0f}')