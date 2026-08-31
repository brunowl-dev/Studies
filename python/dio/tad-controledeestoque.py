import os
produtos = list()

def pesquisaProduto(lista):
    nome = input('Digite o nome do produto a ser pesquisado: ')
    encontrado = False
    for i in range(len(lista)):
        if nome == lista[i]['Nome']:
            encontrado = int(i)
            print('Produto encontrado com sucesso')
            return encontrado
    if encontrado == False:
        print('Produto não encontrado')
        os.system('pause')
        return -1

def addProduto():
    os.system('cls')
    nome = input('Digite o nome do produto: ')
    quantidade = int(input(f'Qual a quantidade de {nome}: '))
    preco = float(input(f'Qual o preço do {nome}: '))
    produto = {
        'Nome': nome,
        'Quantidade': quantidade,
        'Preço': f'R${preco:.2f}'
    }
    return produto

def atualizaQuant(lista):
    os.system('cls')
    atualiza = pesquisaProduto(lista)
    if atualiza == -1:
        return
    else:
        quantidade = int(input('Digite a nova quantidade do produto: '))
        lista[atualiza]['Quantidade'] = quantidade
        print('Quantidade atualizada com sucesso!')
        os.system('pause')

def consultaPreco(lista):
    os.system('cls')
    consulta = pesquisaProduto(lista)
    if consulta == -1:
        return
    else:
        for chave, valor in lista[consulta].items():
            print(f'{chave}: {valor}')

def listaProd_Valor(lista):
    min = int(input('Digite o valor mínimo que você deseja pesquisar: '))
    for produto in lista:
        if produto['Quantidade'] < min:
            for chave, valor in produto.items():
                print(f'{chave}: {valor}')

while True:
    os.system('cls')
    opcao = int(input("1-Adicionar produto\n2-Atualizar quantidade do produto\n3-Consultar preço do produto\n4-Listar todos os produtos com estoque abaixo de um valor mínimo\n5-Sair\n"))
    if opcao == 1:
        produtos.append(addProduto())
        print('Produto adicionado com sucesso!')
        os.system('pause')
    elif opcao == 2:
        atualizaQuant(produtos)
    elif opcao == 3:
        consultaPreco(produtos)
        os.system('pause')
    elif opcao == 4:
        listaProd_Valor(produtos)
        os.system('pause')
    elif opcao == 5:
        break
    else:
        print('Opção inválida!')

print('Programa finalizado!')