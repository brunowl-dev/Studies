# Entrada do usuário
email = input().strip()

# TODO: Verifique as regras do e-mail:
valido = 1
if not ("@" in email) and (("gmail.com" in email) or ("outlook.com" in email)):
    valido = 0  
if (email[0] == "@") or (email[-1] == "@"):
    valido = 0

if (valido == 0):
    print("E-mail inválido")
else:
    print("E-mail válido")