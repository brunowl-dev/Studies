# Capítulo 2 - Estruturas Condicionais e de Repetição

EX1 = False
EX2 = False
EX3 = False
EX4 = True 

if EX1:
    #Peça um número e diga se é positivo, negativo ou zero.
    num = int(input("Digite um numero: "))
    if(num > 0):
        print("O numero eh positivo!")
    elif(num < 0):
        print("O numero eh negativo!")
    else:
        print("O numero eh zero!")

if EX2:
    #Imprima os números de 1 a 20 usando for.
    for num in range(1,21):
        print(num)

if EX3:
    #Peça números ao usuário até que ele digite 0. Ao final, mostre a soma de todos eles (while).
    num = 1
    soma = 0
    while (num != 0):
        num = int(input("Digite um numero: "))
        soma += num
        if(num == 0):
            print("Programa finalizado!")
            break
    print(soma)   
        
if EX4:
    #Crie um menu com 3 opções (soma, média, sair) e faça ele repetir até o usuário escolher sair.
    opcao = 0
    while (opcao != 3):
        opcao = int(input("MENU\n1-Soma\n2-Media\n3-Sair\n"))
        if (opcao == 3):
            break

        numeros = (input("Digite os numeros: "))
        lista = numeros.split()

        if (opcao == 1):
            soma = 0
            for num in lista:
                soma += int(num)
            print(f"A soma eh {soma}")

        else:
            media = 0
            for num in lista:
                media += float(num)
            media = media / len(lista)
            print(f"A media eh {media:.2f}")

    print("Finalizando programa!")