# Dicionário para agrupar participantes por tema
eventos = {}

# Entrada do número de participantes
n = int(input().strip())

# TODO: Crie um loop para armazenar participantes e seus temas:
for _ in range(n):
    linha = input().strip()

    # Encontra a última ocorrência de vírgula para separar nome e tema
    posicao_espaco = linha.rfind(", ")
    
    # Separa o nome do tema
    nome = linha[:posicao_espaco]
    tema = linha[posicao_espaco + 2:]

    if tema not in eventos:
        eventos[tema] = [nome]
    else:
        eventos[tema].append(nome)
    
    
# Exibe os grupos organizados
for tema, participantes in eventos.items():
    print(f"{tema}: {', '.join(participantes)}")

