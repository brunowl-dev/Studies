from abc import ABC, abstractmethod

EX1 = False
EX2 = False
EX3 = False
EX4 = False
EX5 = False
EX6 = False
EX7 = False
EX8 = False
EX9 = False
EX10 = False
EX11 = True

if EX1:
    #Classe básica:
    #Crie uma classe Pessoa com atributos nome e idade. Adicione um método falar() que imprime o nome falando.
    class Pessoa:
        def __init__(self, nome, idade):
            self.nome = nome
            self.idade = idade
        
        def falar(self):
            print(f'{self.nome} falou!')

    nome = input('Qual o nome: ')
    idade = int(input('Qual a idade: '))
    p1 = Pessoa(nome, idade)
    p1.falar()

if EX2:
    #Construtor e método:
    #Adicione um método aniversario() que aumenta a idade da pessoa em 1.
    class Pessoa:
        def __init__(self, nome, idade):
            self.nome = nome
            self.idade = idade
        
        def falar(self):
            print(f'{self.nome} falou!')
        
        def aniversario(self):
            self.idade += 1
            print(f'{self.nome} fez aniversário, fez {self.idade} anos!')

    nome = input('Qual o nome: ')
    idade = int(input('Qual a idade: '))
    p1 = Pessoa(nome, idade)
    p1.falar()
    p1.aniversario()

if EX3:
    #Classe base + herança:
    #Crie uma classe Funcionario com atributos nome e salario, e uma subclasse Gerente que tenha um bônus.
    class Funcionario():
        def __init__(self, nome, salario):
            self.nome = nome
            self.salario = salario

    class Gerente(Funcionario):
        def bonus(self):
            self.salario += 1000
    
    nome = input('Digite o nome: ')
    salario = float(input('Digite o salario base: '))
    f1 = Funcionario(nome, salario)
    print(f'{f1.nome} recebe {f1.salario}!')
    nome = input('Digite o nome: ')
    salario = float(input('Digite o salario base: '))
    g1 = Gerente(nome, salario)
    g1.bonus()
    print(f'{g1.nome} recebe {g1.salario}')

if EX4:
    #Sobrescrevendo método:
    #Na subclasse Gerente, sobrescreva um método exibir_info() que mostre o salário com bônus.
    class Funcionario():
        def __init__(self, nome, salario):
            self.nome = nome
            self.salario = salario

    class Gerente(Funcionario):
        def bonus(self):
            self.salario += 1000
            return self.salario
        
        def exibir_info(self):
            print(f'{self.nome} tem um salário de: {self.salario}\nAgora tem um salário {self.bonus()}')
    
    nome = input('Digite o nome: ')
    salario = float(input('Digite o salario base: '))
    f1 = Funcionario(nome, salario)
    print(f'{f1.nome} recebe {f1.salario}!')
    nome = input('Digite o nome: ')
    salario = float(input('Digite o salario base: '))
    g1 = Gerente(nome, salario)
    g1.exibir_info()

if EX5:
    #Atributo privado:
    #Crie uma classe ContaBancaria com um atributo privado __saldo.
    class ContaBancaria:
        def __init__(self, nome, _saldo):
            self.nome = nome
            self._saldo = _saldo

    cliente = ContaBancaria('Bruno', 3500)
    print(cliente.nome)
    print(cliente._saldo)

if EX6:
    #Getters e setters:
    #Adicione métodos ver_saldo() e depositar(valor).
    class ContaBancaria:
        def __init__(self, nome, _saldo):
            self.nome = nome
            self._saldo = _saldo
        
        @property
        def saldo(self):
            return self._saldo
        
        def depositar(self, valor):
            self._saldo += valor

    cliente = ContaBancaria('Bruno', 2000)
    print(cliente.saldo)
    cliente.depositar(1000)
    print(cliente.saldo)

if EX7:
    #Mesmo método, comportamentos diferentes:
    #Crie uma classe Animal com método falar(), e subclasses Cachorro e Gato que implementam esse método de forma diferente.
    class Animal():
        def __init__(self, nome):
            self.nome = nome

        def falar(self):
            print(f'{self.nome} falou!')
    
    class Gato(Animal):
        def falar(self):
            print(f'Gato de nome {self.nome} miou!')
    
    class Cachorro(Animal):
        def falar(self):
            print(f'Cachorro de nome {self.nome} latiu!')

    a1 = Animal('A1')
    a1.falar()

    g1 = Gato('Frajola')
    g1.falar()

    c1 = Cachorro('Rex')
    c1.falar()

if EX8:
    #Função que recebe qualquer animal:
    #Crie uma função fazer_animal_falar(animal) que chama animal.falar() e teste com os dois bichos.
    class Animal():
        def __init__(self, nome):
            self.nome = nome

        def falar(self):
            print(f'{self.nome} falou!')
    
    class Gato(Animal):
        def falar(self):
            print(f'Gato de nome {self.nome} miou!')
    
    class Cachorro(Animal):
        def falar(self):
            print(f'Cachorro de nome {self.nome} latiu!')

    def animal_falar(animal):
        animal.falar()

    a1 = Animal('A1')
    g1 = Gato('Frajola')
    c1 = Cachorro('Rex')
    lista = [a1, g1, c1]
    for bicho in lista:
        animal_falar(bicho)

if EX9:
    #Classe abstrata com ABC:
    #Crie uma classe abstrata ControleRemoto com o método ligar().
    class Controle(ABC):
        @abstractmethod
        def ligar(self):
            print('Controle ligado!')

if EX10:
    #Subclasses concretas:
    #Crie ControleTV e ControleArCondicionado que implementam ligar() de formas diferentes.
    class Controle(ABC):
        @abstractmethod
        def ligar(self):
            print('Controle ligado!')

    class ControleTV(Controle):
        def ligar(self):
            print('Controle da TV ligado!')

    class ControleArCondicionado(Controle):
        def ligar(self):
            print('Controle do ar condicionado ligado!')
    
    c2 = ControleTV()
    c3 = ControleArCondicionado()
    c2.ligar()
    c3.ligar()

if EX11:
    #Teste de polimorfismo com abstração:
    #Escreva uma função ligar_dispositivo(controle: ControleRemoto) que chama o método ligar() sem saber o tipo exato do controle.
    class Controle(ABC):
        @abstractmethod
        def ligar(self):
            print('Controle ligado!')

    class ControleTV(ABC):
        def ligar(self):
            print('Controle da TV ligado!')

    class ControleArCondicionado(ABC):
        def ligar(self):
            print('Controle do ar condicionado ligado!')
    
    def ligar_controle(controle):
        controle.ligar()

    c2 = ControleTV()
    c3 = ControleArCondicionado()
    lista = [c2, c3]
    for controle in lista:
        ligar_controle(controle)
