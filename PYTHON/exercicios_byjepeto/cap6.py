# Capítulo 6 - Trabalhando com Conjuntos
import random

EX1 = False
EX2 = False
EX3 = False
EX4 = True
EX5 = False

if EX1:
    #Peça 5 nomes e mostre eles sem repetição.
    lista = []
    for i in range(5):
        nome = input("Digite um nome: ")
        lista.append(nome)

    conjunto = set(lista)
    print(conjunto)

if EX2:
    #Dado dois conjuntos de alunos (quem fez a prova e quem fez o trabalho), mostre:
    #Quem fez os dois.
    #Quem fez só o trabalho.
    #Quem não fez nada.
    conjunto_alunos = {"Bruno", "Thais", "Aguiars", "Fael", "Isadoras", "Relva", "Murilo", "Luis Felipe"}
    conjunto_prova = {"Bruno", "Thais", "Aguiars"}
    conjunto_trabalho = {"Bruno", "Thais", "Aguiars", "Fael", "Isadoras"}
    conjuntos_algo = conjunto_prova.union(conjunto_trabalho)
    conjunto_ambos = conjunto_prova.intersection(conjunto_trabalho)
    conjunto_nada = conjunto_alunos.difference(conjuntos_algo)
    print(f"Os alunos sao: {conjunto_alunos}\nOs que fizeram a prova e trabalho foram {conjunto_ambos}\nOs que fizeram apenas o trabalho foram {conjunto_trabalho}\nOs que nao fizeram nada {conjunto_nada}")

if EX3:
    #Gere 20 números aleatórios entre 1 e 10 e armazene num conjunto. Quantos números diferentes saíram?
    numeros = set()
    cont_iguais = 0
    for i in range(20) :
        numero = random.randint(1,10)
        if (numero in numeros):
            cont_iguais += 1
        numeros.add(numero)
    
    cont_iguais = 20 - cont_iguais
    print(numeros)
    print(f"Sairam {cont_iguais} numeros diferentes!")

if EX4:
    #Compare duas listas e mostre os elementos que só aparecem em uma (use conjuntos).
    lista1 = [1,2,3,4,5]
    lista2 = [5,6,7,8,9]
    conj1 = set(lista1)
    conj2 = set(lista2)
    unicos = conj1 ^ conj2  
    print(unicos)

if EX5:
    #Desafio: Faça um filtro de palavras proibidas. O usuário digita uma frase e o programa verifica se contém alguma das palavras do conjunto censurado.
    lista_proibido = ["estupro", "molestado", "assedio", "neguinho do cabelo duro", "macaco", "primatinha", "raca inferior", "ze gotinha da petrobras", "capa da biblia", "fuhrer", "gas", "heil hitler", "ariano", "paraiba", "cocudo", "baianinho", "cabeca de nois tudo", "escoria"]
    lista_proibido = set(lista_proibido)
    frase = input("Digite a frase: ")
    frase = frase.lower()
    censura = False
    for proibida in lista_proibido:
        if(proibida in frase):
            censura = True
    
    if (censura == True):
        print("CENSURADO!")
    else:
        print("Valido!")