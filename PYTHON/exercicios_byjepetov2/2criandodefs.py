EX1 = False
EX2 = False
EX3 = False
EX4 = True

if EX1:
    #boas_vindas(nome) – Mostra "Olá, NOME. Seja bem-vindo!"
    def boas_vindas(nome):
        print(f'Olá, {nome}. Seja bem-vindo!')
    
    boas_vindas('Bruno')

if EX2:
    #soma(a, b) – Retorna a soma de dois números.
    def soma(a,b):
        return a+b
    
    a = int(input('Digite o valor de a: '))
    b = int(input('Digite o valor de b: '))
    print(soma(a,b))

if EX3: 
    #eh_par(numero) – Retorna True se for par, False se for ímpar.
    def eh_par(num):
        if num % 2 == 0:
            return True
        else:
            return False
    
    num = int(input('Digite um numero e descubra se ele eh par: '))
    print(eh_par(num))
    

if EX4:
    #maior_valor(lista) – Retorna o maior valor da lista recebida.
    def maior_valor(lista):
        return max(lista)

    lista = []
    while True:
        num = int(input('Digite o número para entrar na lista: '))
        if (num == 0):
            break
        lista.append(num)
    
    print(maior_valor(lista))