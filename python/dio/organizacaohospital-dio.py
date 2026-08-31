# Entrada do número de pacientes
n = int(input().strip())

# Lista para armazenar pacientes
pacientes = []

# Loop para entrada de dados
for _ in range(n):
    nome, idade, status = input().strip().split(", ")
    idade = int(idade)
    pacientes.append((nome, idade, status))

# TODO: Ordene por prioridade: urgente > idosos > demais:
def prioridade(paciente):
    if paciente[2] == 'urgente':
        return 0
    elif paciente[2] == 'idoso':
        return 1
    else:
        return 2

pacientes.sort(key=lambda p: (prioridade(p), -p[1]))

# TODO: Exiba a ordem de atendimento com título e vírgulas:
print('Ordem de Atendimento:', end=' ')
print(", ".join(p[0] for p in pacientes))