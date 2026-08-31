#Desafio Final – Sistema de Clientes de um Banco
#Crie um sistema que:
#1. Permite cadastrar clientes (nome, CPF e saldo inicial).
    #Armazene os dados num dicionário, onde o CPF é a chave e o valor é outro dicionário com o nome e o saldo.

#2. Permite fazer depósitos e saques.
    #O usuário informa o CPF.
    #Se o CPF existir, pode depositar ou sacar.
    #Se não existir, informe que o cliente não foi encontrado.

#3. Permite ver todos os clientes cadastrados, com nome, CPF e saldo.
#4. Permite listar todos os CPFs únicos (conjunto) e os nomes em ordem alfabética (lista ordenada).
#5. O programa roda em loop até o usuário digitar sair.
clientes = dict()

while True:
    print('MENU\n1-Cadastrar cliente com CPF\n2-Operar(deposito ou saque)\n3-Ver todos os clientes\n4-Listar CPFs')
    opcao = input()
    if (opcao == 'sair'):
        break
    elif(opcao == '1'):
        cpf = input('Digite o CPF: ')
        if len(cpf) != 11:
            print('CPF inválido!')
        else:
            nome = input('Digite o nome do cliente: ')
            saldo = float(input('Digite seu saldo: '))
            cliente = {
                'nome': nome,
                'saldo': saldo,
            }
            clientes[cpf] = cliente

    elif (opcao == '2'):
        cpf = input('Digite o CPF: ')
        if len(cpf) != 11:
            print('CPF inválido!')
        elif cpf not in clientes:
            print('CPF não encontrado!')
        else:
            operacao = int(input('Qual operação você deseja fazer\n1-Depósito\n2-Saque\n'))
            if (operacao != 1 and operacao != 2):
                print('Digite apenas os números 1 ou 2')
            elif(operacao == 1):
                operacao = float(input('Qual o valor que você deseja depositar: '))
                if (operacao <= 0):
                    print('Não é possivel depositar zero reais ou negativo!')
                else:
                    print('Depósito realizado com sucesso!')
                    clientes[cpf]['saldo'] += operacao
            else:
                operacao = float(input('Qual valor você deseja sacar: '))
                if (operacao <= 0 or operacao > clientes[cpf]['saldo']):
                    print('Não é possível sacar esse valor!')
                else:
                    print('Saque feito com sucesso!')
                    clientes[cpf]['saldo'] -= operacao

    elif (opcao == '3'):
        for cpf in clientes.keys():
            print(f'{cpf}: {clientes[cpf]['nome']} - R${clientes[cpf]['saldo']:.2f}')
    
    elif (opcao == '4'):
        conj = set(clientes.keys())
        for cpf in conj:
            print(cpf)