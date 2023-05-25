from math import factorial


def letra_d():
    n = 10  # numero de lampadas
    pi = 0.05  # taxa de mau funcionamento
    x = 3
    resposta = 0
    while x <= 10:
        resposta = resposta + (
                    (factorial(n) / ((factorial(x)) * (factorial(n - x)))) * ((pi ** x) * ((1 - pi) ** (n - x))))
        x = x + 1
    print("Letra D:", resposta)


letra_d()