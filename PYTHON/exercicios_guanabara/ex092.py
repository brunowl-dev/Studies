#Crie um programa que leia nome, ano de nascimento e carteira de trabalho
#Cadastre-os (com a idade) em um dicionário
#Se a CTPS for diferente de zero, o dicionário terá de receber o ano de contratação
#e salário
#Calcule e acrescrente, além da idade, com quantos anos a pessoa vai se aposentar
#35 anos de contribuição pra se aposentar
import os

nome = input("Digite seu nome: ")
ano_Nasc = int(input("Digite seu ano de nascimento: "))
idade = int(2025 - ano_Nasc)
ctps = int(input("Digite sua carteira de trabalho, caso nao tenha, digite apenas 0: "))
if (ctps != 0):
    ano_Contrato = int(input("Quando voce foi contratado: "))
    salario = float(input("Qual o seu salario: "))
    idade_Aposentadoria = int((ano_Contrato + 35) - ano_Nasc)
    pessoa = {
        'Nome': nome, 'Idade': int(idade), 'CTPS': ctps, 'Ano de contrato': ano_Contrato, 'Salário': salario, 'Aposentadoria': int(idade_Aposentadoria)
    }
    os.system("cls")
    for chave, valor in pessoa.items():
        print(f'{chave} é {valor}')
else:
    pessoa = {
        'Nome': nome, 'Idade': idade
    }
    os.system("cls")
    for chave, valor in pessoa.items():
        print(f'{chave} é {valor}')

             