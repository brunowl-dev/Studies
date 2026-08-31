EX1 = True

if EX1:
    #EX01 — Decorador de Boas-vindas
    #Crie um decorador boas_vindas que imprime "Bem-vindo!" antes da função original.
    def original(funcao):
        funcao()
        print('Função original executada!')
    
    @original
    def boas_vindas():
        print("Bem-vindo!")

    boas_vindas()