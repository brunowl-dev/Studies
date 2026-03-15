EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = True

if EX1:
    #EX1 Crie um dicionário com 5 alunos e as notas que eles tiraram em uma prova. Depois, imprima cada aluno com sua respectiva nota.
    dicionario = {
        'Bruno': 10,
        'Luana': 8,
        'Edu': 10,
        'Isadora': 8,
        'Aguiars': 8,
    }
    for nome, nota in dicionario.items():
        print(f'{nome} - {nota:.2f}')

if EX2:
    #Peça para o usuário digitar o nome e a idade de 3 pessoas. Armazene essas informações em um dicionário (nome como chave e idade como valor). No final, mostre todos os dados.
    pessoas = []
    for _ in range(3):
        nome = input('Digite o nome da pessoa: ')
        idade = int(input(f'Digite a idade do(a) {nome}: '))
        pessoa = {
            nome: idade
        }
        pessoas.append(pessoa)
    for i in range(3):
        print(f'{pessoas[i]}')


if EX3:
    #Crie um dicionário com frutas como chave e o preço por quilo como valor.
    #Depois, peça para o usuário digitar o nome de uma fruta e mostre o preço dela. Se a fruta não existir no dicionário, informe que ela não está disponível.
    frutas = {
        'Melancia': 10.000,
        'Uva': 11.000,
        'Morango': 12.000,
    }
    while True:
        nome = input('Digite o nome da fruta a ser procurada: ')
        if (nome == 'fim'):
            break
        if frutas.get(nome) != None:
            print(f'O preço do {nome} é: R${frutas[nome]:.2f}')
        else:
            print('Não esta disponível')
    
if EX4:
    #Crie um dicionário vazio. Peça para o usuário adicionar pares chave:valor (chave: nome do produto, valor: preço).
    #O usuário pode parar de adicionar quando digitar “fim” como nome do produto.
    #No final, mostre a lista completa de produtos e preços.
    lista = []
    while True:
        entrada = input('Digite o produto e seu preço: ')
        if (entrada == 'fim'):
            break
        nome, preco = entrada.split()
        produto = {
            nome: preco
        }
        lista.append(produto)
    
    for produto in lista:
        print(f'{produto}')

if EX5:
    #Dado um dicionário com o estoque de uma loja (produto: quantidade), escreva um programa que:
    #Peça o nome de um produto e a quantidade desejada para compra
    #Verifique se o produto está no estoque e se há quantidade suficiente
    #Se houver, diminua a quantidade no estoque e informe sucesso
    #Se não, informe que não tem estoque suficiente ou produto não encontrado
    estoque = {
        'Melancia': 10,
        'Morango': 20,
        'Uva': 30,
    }
    while True:
        nome = input('Digite o nome do produto: ')
        if (nome == 'fim'):
            break
        if nome in estoque:
            quantidade = int(input('Digite a quantidade do produto: '))
            if (quantidade > estoque[nome]):
                print('Não há itens suficiente!')
            else:
                estoque[nome] -= quantidade
                print('Compra feita com sucesso!')
        else:
            print('Produto não encontrado!')