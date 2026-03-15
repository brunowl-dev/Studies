import os

menu = """

[d] Depositar
[s] Sacar
[e] Extrato
[u] Cadastrar usuario
[c] Cadastrar conta
[lu] Listar usuários
[lc] Listar contas
[q] Sair

=> """

saldo = 0
limite = 500 
extrato = ""
numero_saques = 0
LIMITE_SAQUES = 3
usuarios = list()
contas = list()
num_contas = 0

def funcDeposito(saldo, valor, extrato, /):
    if valor > 0:
        saldo += valor
        extrato += f"Depósito: R$ {valor:.2f}\n"

    else:
        print("Operação falhou! O valor informado é inválido.")

    return(saldo, extrato)

def funcSaque(*, saldo, valor, extrato, limite, numero_saques, LIMITE_SAQUES):
    excedeu_saldo = valor > saldo

    excedeu_limite = valor > limite

    excedeu_saques = numero_saques >= LIMITE_SAQUES

    if excedeu_saldo:
        print("Operação falhou! Você não tem saldo suficiente.")

    elif excedeu_limite:
        print("Operação falhou! O valor do saque excede o limite.")

    elif excedeu_saques:
        print("Operação falhou! Número máximo de saques excedido.")

    elif valor > 0:
        saldo -= valor
        extrato += f"Saque: R$ {valor:.2f}\n"
        numero_saques += 1
        print(f'Operação feita com sucesso!')

    else:
        print("Operação falhou! O valor informado é inválido.")

    return (saldo, extrato, numero_saques)

def funcExtrato(saldo, /, *, extrato):
    print("\n================ EXTRATO ================")
    print("Não foram realizadas movimentações." if not extrato else extrato)
    print(f"\nSaldo: R$ {saldo:.2f}")
    print("==========================================")

def funcCPF():
    while True:
        cpf = input('Digite seu cpf (somente números, 11 dígitos): ')

        if len(cpf) != 11 or not cpf.isdigit():
            print('CPF inválido!')
            continue

        cpf_existe = False
        for usuario in usuarios:
            if usuario['CPF'] == cpf:
                cpf_existe = True
                print('O CPF já foi cadastrado!')
                break

        if cpf_existe:
            continue

        print('CPF cadastrado com sucesso!')
        return cpf

def funcUsuario():
    nome = input('Digite o seu nome: ')
    dia = input('Digite sua data de nascimento (dia, mes, ano): ')
    mes = input('')
    ano = input('')
    data_nasc = str(f'{dia}/{mes}/{ano}')
    logradouro = input('Digite seu endereço no seguinte formato\nLogradouro, numero, bairro, cidade, sigla do estado\n')
    numero = int(input(''))
    bairro = input('')
    cidade = input('')
    sigla = input('')
    logradouro = str(f'{logradouro} n{numero}, {bairro}; {cidade} - {sigla}')
    usuario = {
        'Nome': nome, 'Data de nascimento': data_nasc, 'CPF': funcCPF(), 'Endereco': logradouro 
    }
    return (usuario)

def funcLU():
    os.system('cls')
    for usuario in usuarios:
        print(f'{usuario['Nome']}, nascido em {usuario['Data de nascimento']}')
        print(f'CPF - {usuario['CPF']}')
        print(f'Residente em {usuario['Endereco']}')
        print('\n')

def funcConta():
    cpf = input('Qual o cpf do usuario: ')
    criada = False
    conta = dict()
    global num_contas
    for i, usuario in enumerate(usuarios):
        if (usuario['CPF'] == cpf):
            agencia = '0001'
            num_contas += 1
            conta = {
                'Agencia': agencia, 'Número da conta': num_contas, 'Usuário': usuario
            }
            print('Conta criada com sucesso!')
            criada = True
            return (conta)
    
    if(criada != True):
        print('Não foi possível criar a conta!')

def funcLC():
    os.system('cls')
    for conta in contas:
        print(f'Agencia: {conta['Agencia']} - {conta['Número da conta']}')
        print(f'{conta['Usuário']}')
        print('\n')

while True:
    opcao = input(menu)

    if opcao == "d":
        valor = float(input("Informe o valor do depósito: "))
        saldo, extrato = funcDeposito(saldo, valor, extrato)

    elif opcao == "s":
        valor = float(input("Informe o valor do saque: "))
        saldo, extrato, numero_saques = funcSaque(saldo = saldo, valor = valor, extrato = extrato, limite = limite, numero_saques = numero_saques, LIMITE_SAQUES = LIMITE_SAQUES)

    elif opcao == "e":
        funcExtrato(saldo, extrato = extrato)

    elif opcao == "u":
        usuarios.append(funcUsuario())

    elif opcao == 'lu':
        funcLU()

    elif opcao == 'c':
        nova_conta = funcConta()
        if nova_conta != None:
            contas.append(nova_conta)

    elif opcao == 'lc':
        funcLC()

    elif opcao == "q":
        break

    else:
        print("Operação inválida, por favor selecione novamente a operação desejada.")
