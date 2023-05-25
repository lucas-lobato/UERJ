from math import factorial


def letra_a():
    n = 10 # numero de lampadas
    pi = 0.05 # taxa de mau funcionamento
    x = 0
    resposta = (factorial(n)/((factorial(x))*(factorial(n - x))))*((pi ** x) * ((1 - pi) ** (n - x)))
    print("Letra A:",resposta)

letra_a()