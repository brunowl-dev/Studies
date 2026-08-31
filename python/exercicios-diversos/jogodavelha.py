import os

def escolhe_lado():
    escolha = ''
    while escolha != 'X' and escolha != 'O':
        escolha = input('ESCOLHA: X ou O ')
        if (escolha != 'X' and escolha != 'O'):
            print('ESCOLHA X OU O!')
    return escolha

def input_jogada(lc):
    jogada = 0
    while jogada > 3 or jogada < 1:
        try:
            jogada = int(input(f'DIGITE A {lc} QUE QUER JOGAR: '))
            if jogada > 3 or jogada < 1:
                print('Digite um valor válido!')
                continue
        except ValueError:
            print('Digite um valor válido!')
            continue
    
    return jogada

def printa_tabuleiro(tabuleiro):
    for i in range(3):
        for j in range(3):
            print(tabuleiro[i][j], end = ' ')
        print('')

def verifica_tabuleiro(tabuleiro):
    ## VERIFICAR COLUNAS
    vencedor = ''

    for i in range(3):
        if (tabuleiro[0][i] == tabuleiro[1][i]) and (tabuleiro[1][i] == tabuleiro[2][i]):
            vencedor = tabuleiro[0][i]
            break
    
    ## VERIFICAR LINHAS
    for i in range(3):
        if (tabuleiro[i][0] == tabuleiro[i][1]) and (tabuleiro[i][1] == tabuleiro[i][2]):
            vencedor = tabuleiro[i][0]
            break

    ## VERIFICAR DIAGONAIS
    if (tabuleiro[1][1] == tabuleiro[0][2]) and (tabuleiro[1][1] == tabuleiro[2][0]):
        vencedor = tabuleiro[1][1]
    elif (tabuleiro[1][1] == tabuleiro[0][0]) and (tabuleiro[1][1] == tabuleiro[2][2]):
        vencedor = tabuleiro[1][1]

    return vencedor

# Função "main"
while True:
    # Menuzinho padrão
    os.system('cls')
    try:
        modo = int(input('JOGO DA VELHA\n1-SINGLEPLAYER\n2-SAIR\n'))
        if (modo < 1 or modo > 2):
            print('Digite um valor válido!')
            os.system('pause')
            continue
    except ValueError:
        print('Digite um valor válido!')
        os.system('pause')
        continue

    # Setup do tabuleiro
    tabuleiro = [
        ['.', '.', '.'],
        ['.', '.', '.'],
        ['.', '.', '.']
    ]
    
    #Escolha de O ou X
    player1 = escolhe_lado()
    if (player1 == 'X'):
        player2 = 'O'
    else:
        player2 = 'X'

    vez = 0

    for i in range(9):
        os.system('cls')
        printa_tabuleiro(tabuleiro)
        if (i >= 5):
            vencedor = verifica_tabuleiro(tabuleiro)
            if (vencedor != ''):
                print(f'O JOGADOR {vencedor} VENCEU!')
                break
        elif (i % 2 == 0):
            print("VEZ DO JOGADOR 1\n")
            vez = 1
        else:
            print("VEZ DO JOGADOR 2\n")
            vez = 2

        ## Verifica se o tabuleiro ta vazio
        while True:
            linha = input_jogada("LINHA") - 1
            coluna = input_jogada("COLUNA") - 1

            if tabuleiro[linha][coluna] == '.':
                break
            else:
                print("Posição já ocupada!")

        if vez == 1:
            tabuleiro[linha][coluna] = player1
        else:
            tabuleiro[linha][coluna] = player2

    if vencedor == '':
        print("EMPATE!")

    os.system('pause')
    

    


    