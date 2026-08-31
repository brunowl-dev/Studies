import os

# Desafio Final – Sistema Bancário com Funções

# Objetivos:
# - Criar um sistema que gerencie clientes, saldos, depósitos, saques, e consulta de contas.
# - Tudo organizado em funções, com parâmetros, retorno e controle de erros.

# Requisitos:

# 1. Cadastrar cliente
#    Função cadastrar_cliente(clientes, cpf, nome, saldo_inicial)
#    - Adiciona o cliente no dicionário clientes (chave: CPF, valor: dict com nome e saldo).

def cadastro_cliente(clientes, cpf, nome, saldo_inicial):
    dados = {
        'nome': nome,
        'saldo': float(saldo_inicial),
    }
    clientes[cpf] = dados
    print('Cliente cadastrado com sucesso!')

# 2. Depositar
#    Função depositar(clientes, cpf, valor)
#    - Soma o valor ao saldo do cliente. Valida CPF e valor positivo.
def depositar(clientes, cpf, valor):
    if(not valida_cpf(cpf)):
        print('CPF não é válido!')
    elif (cpf not in clientes.keys()):
        print('CPF não encontrado!')
    elif (valor <= 0):
        print('Não é possivel depositar esse valor!')
    else:
        clientes[cpf]['saldo'] += valor
        print('Depósito realizado com sucesso!')

# 3. Sacar
#    Função sacar(clientes, cpf, valor)
#    - Subtrai o valor do saldo se houver saldo suficiente. Valida CPF e valor positivo.
def sacar(clientes, cpf, valor):
    if (cpf not in clientes.keys()):
        print('CPF não encontrado!')
    elif (valor <= 0 or valor > clientes[cpf]['saldo']):
        print('Não é possivel sacar esse valor!')
    else:
        clientes[cpf]['saldo'] -= valor
        print('Saque realizado com sucesso!')

# 4. Mostrar clientes
#    Função mostrar_clientes(clientes)
#    - Imprime todos os clientes com CPF, nome e saldo.
def mostrar_clientes(clientes):
    for cpf in clientes.keys():
        print(f"{cpf} - {clientes[cpf]['nome']}: R${clientes[cpf]['saldo']:.2f}")

# 5. Listar CPFs e nomes
#    Função listar_cpfs_e_nomes(clientes)
#    - Retorna um conjunto com os CPFs únicos e uma lista ordenada dos nomes.
def lista_dados(clientes):
    conj1 = set(clientes.keys())
    conj2 = sorted({clientes[cpf]['nome'] for cpf in clientes})
    print(f"CPF's únicos: {conj1}")
    print(f'Nomes: {conj2}')

# 6. Menu Interativo
#    - Loop que chama as funções conforme a escolha do usuário.
#    - Opção para sair.

# Bônus:
# - Faça validações (CPF deve ter 11 dígitos).
# - Mensagens claras para erros e sucesso.
def valida_cpf(cpf):
    return len(cpf) == 11 and cpf.isdigit()

clientes = dict()

while True:
    os.system('cls')
    opcao = int(input('MENU\n1-Cadastrar clientes\n2-Depositar\n3-Sacar\n4-Mostrar clientes\n5-Listar CPFs e nomes\n6-Sair\n'))
    if (opcao == 6):
        break
    elif(opcao == 1):
        cpf = input('Digite o CPF: ')
        if valida_cpf(cpf):
            nome = input('Digite o nome do cliente: ')
            saldo = float(input('Digite o saldo inicial: '))
            cadastro_cliente(clientes, cpf, nome, saldo)
        else:
            print('CPF não é valido!')
            
        os.system('pause')
    elif(opcao == 2):
        cpf = input('Digite o CPF: ')
        if valida_cpf(cpf):
            valor = float(input('Digite o valor a ser depositado: '))
            depositar(clientes, cpf, valor)
            os.system('pause')
        else:
            print('CPF não é valido!')
    elif(opcao == 3):
        cpf = input('Digite o CPF: ')
        if valida_cpf(cpf):
            valor = float(input('Digite o valor a ser depositado: '))
            sacar(clientes, cpf, valor)
        else:
            print('CPF não é valido!')
        
        os.system('pause')
    elif(opcao == 4):
        mostrar_clientes(clientes)
        os.system('pause')
    else:
        lista_dados(clientes)
        os.system('pause')

print('Finalizando o programa...')

