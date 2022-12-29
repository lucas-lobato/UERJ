#exercicio 18

from random import*

A=[]
B=[]
C=[]


def vetores ():
    try:
        for i in range(A):
            elementosA=int(input('Defina o numero de elementos das linhas: '))
            x=randint(1,99)
            A.append(x)

        for j in range(B):
            elementosB = int(input('Defina o numero de elementos das linhas: '))
            y = randint(1, 99)
            B.append(y)


    except Exception:
        print('Erro')

    return

def matriz():
    try:
        for k in range(0,A):
            C=[A]

        for l in range(0,B):
            C=[B]

        C=[A]+[B]

    except Exception:
        print('erro')

    return C

C=matriz()




