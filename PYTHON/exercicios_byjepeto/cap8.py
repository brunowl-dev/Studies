##CAP8 - Funções

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = False
EX6 = True
EX7 = False
EX8 = False
EX9 = False

if EX1:
    #Função simples:
    #Escreva uma função saudar(nome) que imprime "Salve, [nome]!"
    def saudacao(nome):
        print(f'Salve, {nome}!')
    
    nome = input('Qual seu nome: ')
    saudacao(nome)

if EX2:
    #Função com retorno:
    #Crie uma função dobro(n) que retorna o dobro de um número.
    def dobro(n):
        return n * 2
    
    num = int(input('Digite o numero a ser dobrado: '))
    print(f'O dobro do número é: {dobro(num)}')

if EX3:
    #Função com valor padrão:
    #Escreva uma função contar_regressiva(inicio=10) que conta de inicio até 0.
    def contar_regressiva(inicio):
        for i in range(inicio,-1, -1):
            print(i)
    
    num = int(input('Digite o inicio da contagem: '))
    contar_regressiva(num)

if EX4:
    #Função que retorna múltiplos valores:
    #Crie uma função estatisticas(lista) que retorna a média, o maior e o menor valor da lista.
    def estatistica(lista):
        media = sum(lista) / len(lista)
        maior = max(lista)
        menor = min(lista)
        return media, maior, menor
    
    entrada = input("Digite os números separados por espaço: ")
    lista = list(map(int, entrada.split()))
    print(estatistica(lista))

if EX5:
    #Somar tudo com *args:
    #Escreva uma função soma_tudo(*numeros) que retorna a soma de todos os números passados.
    def soma_tudo(*args):
        resultado = sum(args)
        return resultado

    entrada = input("Digite os números separados por espaço: ")
    lista = list(map(int, entrada.split()))
    print(soma_tudo(lista))

if EX6:
    #Crie uma função chamada cadastrar_pessoa(**dados) que aceita qualquer quantidade de informações sobre uma pessoa (nome, idade, cidade, profissão, etc.).
    #A função deve exibir cada item do cadastro no formato:
    #campo: valor
    def cadastrar_pessoa(**kwargs):
        for chave, valor in kwargs.items():
            print(f'{chave}: {valor}')
    
    nome = input('Digite o nome: ')
    idade = int(input('Digite a idade: '))
    cidade = input('Digite a cidade: ')
    profissao = input('Digite a profissao: ')
    cadastrar_pessoa(Nome=nome, Idade=idade, Cidade=cidade, Profissao=profissao)

if EX7:
    #Crie uma função chamada exibir_info(*args, **kwargs) que:
    #Imprime todos os valores posicionais recebidos (*args) um por um.
    #Em seguida, imprime todos os valores nomeados (**kwargs) no formato:
    def exibir_info(*args, **kwargs):
        print('ARGS')
        for info in args:
            print(info)

        print('KWARGS')
        for chave, valor in kwargs.items():
            print(f'{chave}: {valor}')
    
    linguagem = input('ARGS A: ')
    assunto = input('ARGS B: ')
    
    idioma = input('KWARGS A: ')
    dificuldade = input('KWARGS B: ')
    exibir_info(linguagem, assunto, idioma=idioma, dificuldade=dificuldade)

if EX8:
    #Crie uma função chamada desenhar_figura(nome, cor='azul', tamanho=10) que recebe:
    #nome: nome da figura (obrigatório, argumento posicional)
    #cor: cor da figura (padrão é "azul")
    #tamanho: tamanho da figura (padrão é 10)
    def desenhar_figura(nome, cor='azul', tamanho=10):
        print(f'{nome} - {cor} - {tamanho}')
    
    nome = input('Digite o nome: ')
    cor = input('Digite a cor: ')
    tamanho = input('Digite o tamanho: ')
    desenhar_figura(nome, cor=cor, tamanho=tamanho)

if EX9:
    #Tente chamar a função do exercício 8 (desenhar_figura) passando um argumento posicional depois de um argumento passado por keyword, assim:
    #desenhar_figura(cor='vermelho', 'circulo', tamanho=15)
    #Observe o erro que o Python gera.
    #Tarefa:
    #Explique por que esse erro acontece.
    #Corrija a chamada para que funcione sem erro.

    def desenhar_figura(nome, cor='azul', tamanho=10):
        print(f'{nome} - {cor} - {tamanho}')
    
    #desenhar_figura(cor='vermelho', 'circulo', tamanho=15)
    #Positional argumento follows keyword argumento, se referindo ao circulo no meio, que deveria estar no comeco por ser agumento posicional
    desenhar_figura('circulo', cor='vermelho', tamanho=15)
