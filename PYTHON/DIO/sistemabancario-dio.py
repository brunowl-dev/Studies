saldo = 0.0
LIMITE_SAQUE = 500.0
SAQUES_DIARIOS = 3
extrato = ""
saques_feitos = 0
saque = 0.0

while True:
    opcao = int(input("MENU\n1-Deposito\n2-Saque\n3-Extrato\n4-Saida\n"))

    if (opcao == 1):
        deposito = float(input("Qual o valor que voce deseja depositar? "))
        if(deposito <= 0):
            print("Deposite valores positivos!")
        else:
            saldo += deposito
            extrato += f"Deposito - R${deposito:.2f}\n"
            print("Deposito realizado com sucesso!")

    if (opcao == 2):
        if(saques_feitos < SAQUES_DIARIOS):
            saque = float(input("Qual o valor que voce deseja sacar? "))
            if(saque > LIMITE_SAQUE):
                print("""O valor do saque excedeu seu limite!
Tente fazer a operacao novamente.""")
            else:
                saldo -= saque
                saques_feitos += 1
                extrato += f"Saque - R${saque:.2f}\n"
                print("Saque realizado com sucesso!")
        else:
            print("Voce ja fez seu limite de saques diarios!")

    if (opcao == 3):
        if(extrato == ""):
            print("Extrato vazio!")
        else:
            print(f"O seu saldo eh: {saldo:.2f}")
            print(extrato)

    print("\n")