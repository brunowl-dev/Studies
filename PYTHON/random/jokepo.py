import random, os
lista = ['pedra', 'papel', 'tesoura']

while True:
    os.system('cls')
    jogar = input('JOKEMPO\nDIGITE A SUA JOGADA\nDIGITE -1 CASO QUEIRA ENCERRAR\n')
    
    if (jogar == '-1'):
        break

    jogar = jogar.strip()
    jogar = jogar.lower()

    if (jogar != 'pedra') and (jogar != 'papel') and (jogar != 'tesoura'):
        print('JOGADA INVÁLIDA!')
    else:
        if (jogar in lista):
            jogar = lista.index(jogar)
        bot = random.randint(0,2)
        os.system('cls')
        print('SUA JOGADA: ' + lista[jogar])
        print('JOGADA DA MÁQUINA: ' + lista[bot])

        resultado = (jogar - bot) % 3
        if resultado == 0:
            print('EMPATE!')
        elif resultado == 1:
            print('VOCÊ VENCEU!')
        else:
            print('VOCÊ PERDEU!')

    os.system('pause')