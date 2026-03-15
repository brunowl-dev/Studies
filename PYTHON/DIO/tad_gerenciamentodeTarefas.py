import os

tarefas = list()

def setarStatus():
    status = int(input('Digite o status da tarefa\n0-Pendente\n1-Em andamento\n2-Concluída\n'))
    if status == 0:
        status = 'Pendente'
    elif status == 1:
        status = 'Em andamento'
    else:
        status = 'Concluída'
    return status

def pesquisaTarefa():
    os.system('cls')
    pesquisa = input('Digite o título da tarefa a ser pesquisada: ')
    encontrado = False
    global tarefas
    for i in range(len(tarefas)):
        if pesquisa == tarefas[i]['Título']:
            encontrado = True
            pesquisa = int(i)
            os.system('pause')
            return i
    if encontrado == False:
        print(f"A tarefa {pesquisa} não foi encontrada!")
        os.system('pause')
        return -1
    
def addTarefa():
    os.system('cls')
    titulo = input('Digite o título da tarefa: ')
    descricao = input('Digite a descricao da tarefa: ')
    tarefa = {
        'Título': titulo,
        'Descrição': descricao,
        'Status': setarStatus()
    }
    return tarefa

def atualizaStatus():
    alterar = pesquisaTarefa()
    if alterar == -1:
        return
    else:
        global tarefas
        tarefas[alterar]['Status'] = setarStatus()
        print('Status alterado com sucesso!')

def listarTarefa():
    os.system('cls')
    status = setarStatus()
    for tarefa in tarefas:
        if tarefa['Status'] == status:
            for chave, valor in tarefa.items():
                print(f'{chave}: {valor}')
    os.system('pause')

def removeTarefa():
    remover = pesquisaTarefa()
    if remover == -1:
        return
    else:
        global tarefas
        tarefas.pop(remover)
        print('Tarefa removida com sucesso!')
        os.system('pause')

while True:
    os.system('cls')
    opcao = int(input("MENU\n1-Adicionar tarefa\n2-Atualizar status de tarefa\n3-Listar tarefa por status\n4-Remover tarefa pelo título\n5-Sair\n"))
    if opcao == 5:
        break
    elif opcao == 1:
        tarefas.append(addTarefa())
        print('Tarefa adicionada com sucesso!')
        os.system('pause')
    elif opcao == 2:
        atualizaStatus()
    elif opcao == 3:
        listarTarefa()
    elif opcao == 4:
        removeTarefa()
    elif opcao == 5:
        break
    else:
        print('Opção inválida!')

print('Programa finalizado!')
