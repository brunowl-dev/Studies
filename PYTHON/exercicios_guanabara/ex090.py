#Faça um programa que leia nome e média de um aluno
#guardando também a situação em um dicionário
#no final, mostre o conteúdo da estrutura na tela
# m < 7 ; reprovado . caso contrario , aprovado

nome = input("Digite o nome do aluno: ")
media = float(input("Digite a media do aluno: "))
if (media < 7):
    aprovado = 'Reprovado'
else:
    aprovado = 'Aprovado'

aluno = {
    'Nome': nome, 'Média': media, 'Situação': aprovado,
}

for chave, valor in aluno.items():
    print(f'{chave} é igual a {valor}')