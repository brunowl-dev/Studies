#Inicialze o interpretador e use-o como uma calculadora

ex1 = False
ex2 = False
ex3 = True

if ex1:
    #1- Quanto segundos há em 42 minutos e 42 segundos?
    min = 42
    seg = 42
    min = 42 * 60
    seg += min
    print(f'{seg} segundos!')

if ex2:
    #2- Quantas milhas há em 10 km? Dica: 1mile = 1,61km
    kms = 10
    milhas = 1.61 # conversão de milhas para km
    total = kms / milhas
    print(f'{total:.2f} milhas!')

if ex3:
    #3- Se você correr 10km em 42min e 42 segundos, qual é o seu passo médio? (Tempo por milha em minutos esegundos)Qual é sua velocidade média em milhsa por hora?
    km = 10
    min = 42
    seg = 42
    milhas = km / 1.61
    min = min * 60
    seg += min
    pace = seg / milhas
    min = pace // 60
    seg = pace % 60
    print(f'{min}min e {seg:.1f}segundos por milha!')

    vm = milhas / (((42 * 60) + 60) / 3600)
    print(f'A velocidade média é de {vm:.2f}milhas por hora!')