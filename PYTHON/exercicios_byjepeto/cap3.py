# Capítulo 3 - Manipulando Strings

EX1 = False
EX2 = False 
EX3 = False
EX4 = False
EX5 = True

if EX1:
    #Peça um nome completo e mostre:
    #Primeira letra de cada nome (inicial)
    #Nome em letras maiúsculas/minúsculas
    nome = input("Digite seu nome: ")
    lista_espacos = []
    for i in range(len(nome)):
        if(nome[i] == " "):
            lista_espacos.append(i)

    #Mostrar letra de cada nome
    print(nome[0])
    for num in lista_espacos:
        print(nome[num+1])
    
if EX2:
    # Faça um programa que conta quantas vogais existem numa frase.
    frase = input("Digite a frase: ")
    vogais = ['a', 'e', 'i', 'o', 'u']
    frase = frase.lower()
    cont_vogais = 0
    for letra in frase:
        if (letra in vogais):
            cont_vogais += 1
    
    print(cont_vogais)

if EX3:
    # Peça um texto e uma palavra, e diga se ela aparece no texto e em que posição.
    texto = input("Digite um texto: ")
    palavra = input("Digite uma palavra agora: ")
    if ((palavra in texto) == True):
        posicao = texto.find(palavra)
        print(f"A palavra esta no texto!, na posicao {posicao}")

if EX4:
    # Receba uma frase e retorne ela ao contrário.
    frase = input("Digite a frase: ")
    print(frase[::-1])

if EX5:
    # Desafio: Crie um validador de CPF (formato 000.000.000-00) que diga se tem 11 números e a pontuação correta (só a estrutura, não precisa validar o CPF real).
    cpf = input("Digite seu CPF no formato (000.000.000-00): ")
    valido = True

    if (len(cpf) != 14):
        valido = False

    elif ((cpf[3] != '.') or (cpf[7] != '.') or (cpf[11] != '-')):
        valido = False
    
    for digito in cpf:
        if digito.isalpha():
            valido = False
    
    if (valido == True):
        print("O CPF eh valido!")
    else:
        print("O CPF eh invalido!")
