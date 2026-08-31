def processar_reservas():
    # Entrada dos quartos disponíveis
    quartos_disponiveis = set(map(int, input().split()))
    
    # Entrada das reservas solicitadas
    reservas_solicitadas = list(map(int, input().split()))

    # TODO: Verifique se cada reserva pode ser confirmada com base na disponibilidade dos quartos: 
    def funcVerificar(solicitacao, quartos):
        if solicitacao in quartos:
            return 1
        else:
            return 0
        
    # TODO: Crie o processamento das reservas:
    confirmadas = list()
    recusadas = list()
    for i in range(len(reservas_solicitadas)):
        verificar = funcVerificar(reservas_solicitadas[i], quartos_disponiveis)
        if (verificar == 1):
            confirmadas.append(reservas_solicitadas[i])
        else:
            recusadas.append(reservas_solicitadas[i])

    # Saída dos resultados conforme especificação
    print("Reservas confirmadas:", " ".join(map(str, confirmadas)))
    print("Reservas recusadas:", " ".join(map(str, recusadas)))

# Chamada da função principal
processar_reservas()