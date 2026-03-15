#Crie um programa que gerencie o aproveitamento de um jogador de futebol
#O programa vai ler o nome do jogador e quantas partidas ele jogou
#Depois vai ler a quantidade de gols feitos em cada partida
#No final, tudo isso será guardado em um dicionário, incluindo to total de gols no camp

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

print(f'O jogador {jogador['Nome']} jogou {jogador['Partidas']}')
for i in range(jogador['Partidas']):
    print(f'    Na partida {i+1}, fez {jogador['Gols'][i]}')
print(f'O jogador {jogador['Nome']} fez um total de {jogador['Total de gols']}')