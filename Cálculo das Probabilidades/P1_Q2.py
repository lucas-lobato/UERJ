import math
from math import factorial


def questao_2():
    e = math.e
    lamb = 1.93
    x = 0
    resposta = 0
    while x <= 1:
        resposta = resposta + (((e ** (-lamb)) * (lamb ** x)) / factorial(x))
        x = x + 1
    resposta = 1 - resposta # probabilidade total - probabilidade auxiliar
    print("Resposta questão 2: ", resposta)


questao_2()
