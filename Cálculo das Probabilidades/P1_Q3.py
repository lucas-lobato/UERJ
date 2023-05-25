import math
from math import factorial


def questao_3():
    e = math.e
    lamb = 6
    x = 4
    resposta = 0
    while x <= 5:
        resposta = resposta + (((e ** (-lamb)) * (lamb ** x)) / factorial(x))
        x = x + 1
    print("Resposta questão 3: ",resposta)


questao_3()
