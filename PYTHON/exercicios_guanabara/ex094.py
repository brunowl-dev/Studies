#Crie um programa que leia nome, sexo e idade e várias pessoas
#Gaurdando os dados de cada pessoa em um dicionário e todos os dicionários em uma lista
#No final, mostre:
#A) Quantas pessoas foram cadastradas
#B) A média de idade do grupo
#C) Uma lista com todas as mulheres
#D) Uma lista com todas as pessoas com idade acima da média
import os

continuar = 's'
media = 0
pessoas = list()

while (continuar == 's'):
    nome = input('Qual o nome: ')
    sexo = input('Qual o sexo (M ou F): ')
    idade = int(input('Quantos anos ele ou ela tem: '))
    pessoa = {
        'Nome': nome, 'Sexo': sexo, 'Idade': idade
    }
    pessoas.append(pessoa)
    continuar = input("Deseja continuar: s para sim, n para não: ")

os.system("cls")
#A)
print(f'Foram cadastradas {len(pessoas)} pessoas\n')
    
#B)
for i in range(len(pessoas)):
    media += pessoas[i]['Idade']
media = media / (len(pessoas))
print(f'A media de idade é de {media} anos\n')

#C)
print('As mulheres cadastradas sao:')
for i in range(len(pessoas)):
    if(pessoas[i]['Sexo'] == 'f') or (pessoas[i]['Sexo'] == 'F'):
        print(f'{pessoas[i]['Nome']} ')

#D)
print('\nAs pessoas com idade acima da media:')
for i in range(len(pessoas)):
    if(pessoas[i]['Idade'] > media):
        print(f'{pessoas[i]['Nome']} ')