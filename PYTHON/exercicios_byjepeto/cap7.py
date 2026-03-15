#Cap7 - Dicionarios

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = False
EX6 = False
EX7 = False
EX8 = True

if EX1:
    # Crie um dicionário com os seguintes dados:
    # chave: nome de uma fruta, valor: sua cor
    # Exemplo de saída:
    # {'banana': 'amarela', 'maçã': 'vermelha'}
    # Depois, adicione mais uma fruta.
    dicionario = {'banana': 'amarela', 'maçã': 'vermelha'}
    print(dicionario)
    fruta = input("Digite o nome da nova fruta: ")
    cor = input("Digite a cor: ")

    dicionario[fruta] = cor
    print(dicionario)

if EX2:
    # Dado o dicionário:
    frutas = {'banana': 'amarela', 'maçã': 'vermelha', 'uva': 'roxa'}
    # Peça ao usuário o nome de uma fruta e exiba a cor dela.
    # Se não existir, diga: "Fruta não encontrada."
    fruta = input("Digite a fruta que voce quer pesquisar: ")
    fruta = frutas.get(fruta)
    if(fruta != None):
        print(f"A cor eh {fruta}")
    else:
        print("Fruta não encontrada.")

if EX3:
    frutas = {'banana': 'amarela', 'maçã': 'vermelha', 'uva': 'roxa'}
    # Remova a chave 'maçã' do dicionário acima.
    print(frutas)
    frutas.pop("maçã")
    print(frutas)

if EX4:
    # Dado o dicionário:
    alunos = {'Ana': 8.5, 'Carlos': 7.2, 'Bianca': 9.0}
    # Imprima: "Aluno(a) X tem nota Y"
    for aluno in alunos:
        print(f"Aluno {aluno} tem nota {alunos[aluno]:.1f}")

if EX5:
    # Peça ao usuário para digitar uma frase.
    # Conte quantas vezes cada letra aparece (ignorar espaços).
    # Dica: use um dicionário com letras como chave e contagem como valor.
    frase = input("Digite uma frase: ")
    dicionario = {}
    for letra in frase:
        if (dicionario.get(letra) == None):
            contagem = 1
            dicionario[letra] = contagem
        else:
            dicionario[letra] += 1
    
    print(dicionario)

if EX6:
    dicionario = {}
    num_inputs = int(input("Digite o numero de entradas: "))

    for i in range(num_inputs):
        linha = input("Digite nome e tema separados por espaço: ")
        nome, tema = linha.rsplit(' ', 1) 

        if tema not in dicionario:
            dicionario[tema] = []

        dicionario[tema].append(nome)

    # Imprime no formato esperado
    for tema, nomes in dicionario.items():
        print(f"{tema}: {', '.join(nomes)}")

if EX7:
    # Crie uma lista com dicionários, onde cada dicionário representa um produto:
    # {'nome': 'Notebook', 'preco': 3500}
    # {'nome': 'Mouse', 'preco': 150}
    # Depois, some o valor total dos produtos.
    produtos = [
        {'nome': 'Notebook', 'preco': 3500},
        {'nome': 'Mouse', 'preco': 150},
    ]
    total = 0
    for produto in produtos:
        total += produto['preco']
    
    print(total)

if EX8:
    # Peça o nome de 3 alunos e 2 notas pra cada um.
    # Guarde assim:
    # {'Ana': {'nota1': 8, 'nota2': 9}, ...}
    # Depois mostre:
    # Ana - Média: 8.5
    alunos = {}
    for i in range(3):
        nome = input("Digite o nome do aluno: ")
        nota1 = float(input("Digite a nota1 desse aluno: "))
        nota2 = float(input("Digite a nota2 desse aluno: "))
        alunos[nome] = {"nota1": nota1, "nota2": nota2}
    
    for nome, notas in alunos.items():
        media = (notas['nota1'] + notas['nota2']) / 2
        print(f"{nome} - Média: {media:.1f}")



