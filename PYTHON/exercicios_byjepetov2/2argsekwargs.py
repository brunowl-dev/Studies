EX1 = False
EX2 = False
EX3 = False
EX4 = True

if EX1:
    #Parâmetros padrão
    #Crie uma função apresentar(nome, cargo="Estagiário") que imprime:
    #"Nome: NOME | Cargo: CARGO"
    #Teste chamando com e sem o segundo argumento.
    def apresentar(nome, cargo='Estagiário'):
        print(f'Nome: {nome}; Cargo: {cargo}')
    
    nome = input('Digite seu nome: ')
    cargo = input('Digite o cargo: ')
    apresentar(nome, cargo)
    apresentar(nome)

if EX2:
    #Crie uma função somar_todos(*numeros) que retorna a soma de todos os valores passados como argumento:
    def somar_todos(*args):
        return sum(args)

    print(somar_todos(1, 2, 3))  # 6
    print(somar_todos(10, 20))   # 30

if EX3:
    #Crie uma função exibir_info(**info) que imprime todas as informações passadas no formato:
    #chave: valor
    #Exemplo:
    def exibir_info(**kwargs):
        for chave, valor in kwargs.items():
            print(f'{chave}: {valor}')

    exibir_info(nome="Bruno", idade=20, curso="Python")

if EX4:
    #Crie uma função perfil(nome, *habilidades, **info_adicional) que:
    #Mostra o nome.
    #Lista as habilidades (se houver).
    #Mostra informações extras (como cidade, idade etc).
    #Exemplo:
    def perfil(nome, *skills, **info_adicional):
        print(nome)
        
        if skills:
            print(skills)

        if info_adicional:
            print(info_adicional)


    perfil("Lash", "Python", "Git", cidade="Santos", idade=20)