ex1 = False
ex2 = True

if ex1:
    #Escreva uma função chamada right_justify, que receba uma string chamada s como
    #parâmetro e exiba a string com espaços suficientes à frente para que a última letra da
    #string esteja na coluna 70 da tela:
        #>>> right_justify('monty')
        #monty
    #Dica: Use concatenação de strings e repetição. Além disso, o Python oferece uma função
    #integrada chamada len, que apresenta o comprimento de uma string, então o valor de
    #len('monty') é 5.
    def right_justify(s):
        repetir = 70 - len(s)
        print(' ' * repetir + s)
    
    s = input('Type the string: ')
    right_justify(s)
    
if ex2:
    def do_twice(f, v):
        f(v)
        f(v)

    def print_spam():
        print('spam')
    
    do_twice(print_spam, 2)