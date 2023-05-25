from math import factorial


def letra_c():
    n = 10  # numero de lampadas
    pi = 0.05  # taxa de mau funcionamento
    x = 2
    resposta = 0
    while x >= 0:
        resposta = resposta + ((factorial(n) / ((factorial(x)) * (factorial(n - x)))) * ((pi ** x) * ((1 - pi) ** (n - x))))
        x = x - 1
    print("Letra C:", resposta)


letra_c()
