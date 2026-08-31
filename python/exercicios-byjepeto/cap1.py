# Capítulo 1 – Tipos de Operadores

EX1 = False
EX2 = False
EX3 = False
EX4 = True

if EX1:
    #Faça um programa que receba dois números e exiba:
    #Soma, subtração, multiplicação, divisão, resto e exponenciação.
    num1 = int(input("Digite o primeiro numero: "))
    num2 = int(input("Digite o segundo numero: "))
    print(f"Soma - {num1 + num2}\nSubtracao - {num1 - num2}\nMultiplicacao - {num1 * num2}\nDivisao - {num1 / num2}\nResto - {num1 % num2}\nExponenciacao - {num1 ** num2}")

if EX2:
    #Peça a idade do usuário e diga se ele é maior de idade (use operador relacional).
    idade = int(input("Quantos anos voce tem? "))
    if (idade < 18):
        print("Voce eh menor de idade!")
    else:
        print("Voce eh maior de idade!")

if EX3:
    #Crie um validador de senha com 3 condições lógicas: mínimo 8 caracteres, contém número, contém letra maiúscula.
    senha = input("Digite sua senha: ")
    tem_numero = False
    tem_maiusculo = False

    if (len(senha) < 8):
        print("Digite uma senha com 8 caracteres no minimo!")

    for i in range(len(senha)):
        if(senha[i].isdigit() == True):
            tem_numero = True
            break

    if(tem_numero == False):
        print("Digite pelos menos um numero!")

    for i in range(len(senha)):
        if(senha[i].isupper() == True):
            tem_maiusculo = True
            break

    if(tem_maiusculo == False):
        print("Digite pelo menos uma letra maiuscula!")
    else:
        print("Senha valida!")

if EX4:
    #Faça um jogo de adivinhação onde o usuário tem 3 tentativas para adivinhar um número entre 1 e 10 (use operadores lógicos + controle de tentativas).
    tentativas = 0
    descobrir = 7
    while (tentativas != 3):
        num = int(input("Advinhe um numero: "))
        if(num == descobrir):
            print("Voce acertou!")
            break
        else:
            print("Voce errou, tente novamente!")
            tentativas += 1
    
    if(tentativas == 3):
        print("\nVoce excedeu suas tentativas!")
    
