import os
import smtplib
from email.message import EmailMessage
import time
import mimetypes

def enviar_email(email, nome):
    remetente = 'brunoantoniowl@gmail.com'
    destinatario = email
    assunto = "nerd"
    mensagem = f"oiiii {nome}\nera só pra fazer um programa que envia email pra várias pessoas valeu por ajuda tmjj"
    senha = "xwwa pcte kcga szxx"
    anexo = 'python/image.jpg'

    msg = EmailMessage()
    msg['From'] = remetente
    msg['To'] = email
    msg['Subject'] = assunto
    msg.set_content(mensagem)

    mime_type,_ = mimetypes.guess_type(anexo)
    mime_type, mime_subtype = mime_type.split('/')

    with open(anexo, 'rb') as file:
        msg.add_attachment(file.read(), maintype=mime_type, subtype=mime_subtype, filename = 'oi vai haha')

    with smtplib.SMTP_SSL("smtp.gmail.com",465) as envio:
        envio.login(remetente, senha)
        envio.send_message(msg)

while True:
    os.system('cls')
    opcao = int(input('MENU\n1-Registrar email\n2-Ler email\n3-Enviar mensagens\n4-Sair\n'))
    if (opcao == 1):
        arquivo = open("python/dados.txt", "a")
        email = input('Digite o email: ')
        nome = input('Digite o nome da pessoa: ')
        arquivo.write(email + ";" + nome + "\n")
        arquivo.close()
        print('E-mail adicionado com sucesso!')
        os.system('pause')
    elif (opcao == 2):
        arquivo = open("python/dados.txt", "r")
        for pessoa in arquivo.readlines():
            print(pessoa)
        os.system('pause')
        arquivo.close()
    elif (opcao == 3):
        arquivo = open("python/dados.txt", "r")
        for linha in arquivo.readlines():
            linha = linha.strip()
            dados = linha.split(";")
            email = dados[0]
            nome = dados[1]
            enviar_email(email, nome)
            print(f'Email para {nome} enviado com sucesso!')
            time.sleep(5)
            os.system('cls')
        arquivo.close()
    else:
        print('Programa finalizando...')
        break