#Aprimore o desafio 093, dos jogadores, porém pra funcionar com mais jogadores
#Inclua um sistema de visualização de detalhes do aproveitamento de cada jogador.
#Menu para o usuario digitar quais dados de qual jogador ele quer ver, caso digite 999, saia.
import os

jogador = dict()
jogadores = list()
continuar = 's'

while (continuar == 's'):
    nome = input('Qual o nome do jogador: ')
    partidas = int(input('Quantas partidas ele jogou: '))
    gols = list()
    for i in range(partidas):
        num = int(input(f'Quantos gols ele fez na partida {i+1}: '))
        gols.append(num)
    total = sum(gols)
    jogador = {
    'Nome': nome, 'Partidas': partidas, 'Gols': gols, 'Total de gols': total
    }
    jogadores.append(jogador.copy())
    continuar = input('Deseja continuar, s para sim, n para não: ')

i = 0
os.system('cls')
for jogador in jogadores:
    print(f'{i} - {jogador['Nome']}; {jogador['Gols']}; {jogador['Total de gols']}')
    i += 1

dados = int(input('Mostrar dados de qual jogador: '))
while (dados != 999):
    print(f'Levantamento do jogador {jogadores[dados]['Nome']}')
    for i, g in enumerate(jogadores[dados]['Gols']):
        print(f'    Na partida {i+1}, fez {g} gols')
    dados = int(input('Mostrar dados de qual jogador: '))



