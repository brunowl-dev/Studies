#Crie um programa onde 4 jogadores joguem um dado e tenham resultados aleatorios
#Guarde esses resultados em um dicionário
#No final, coloque esse dicionário em ordem, sabendo que o vencedor
#tirou o maior numero no dado
import random

jogadores = list()
jogador1 = {'nome': 'jogador1', 'numero': random.randint(1,6)}
jogador2 = {'nome': 'jogador2', 'numero': random.randint(1,6)}
jogador3 = {'nome': 'jogador3', 'numero': random.randint(1,6)}
jogador4 = {'nome': 'jogador4', 'numero': random.randint(1,6)}
jogadores.append(jogador1)
jogadores.append(jogador2)
jogadores.append(jogador3)
jogadores.append(jogador4)
jogadores.sort(key=lambda x: x['numero'], reverse=True)

for i in range(0, 4):
    print(f'{i+1} lugar - {jogadores[i]['nome']} tirou {jogadores[i]['numero']}')
