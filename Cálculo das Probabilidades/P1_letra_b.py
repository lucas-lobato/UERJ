from math import factorial
from scipy.stats import binom


def letra_b():
    n = 10  # numero de lampadas
    pi = 0.05  # taxa de mau funcionamento
    x = 1
    resposta = (factorial(n) / ((factorial(x)) * (factorial(n - x)))) * ((pi ** x) * ((1 - pi) ** (n - x)))
    print("Letra B:", resposta)


letra_b()
