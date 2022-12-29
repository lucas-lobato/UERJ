#exercicio 5

from random import*


A=[]
B=[]

def matrizes():
    try:
        x=int(input('Digite a quantidade de colunas: '))
        y=int(input('Digite a quantidade de linhas da matriz: '))
        A=[]
        for i in range(x):
            linha=[]
            for j in range(y):
                f=randint(0,9)
                linha.append(f)
            A.append(linha)

    except Exception:
        print('erro')

    return A,y

def matrizB(A,y):
    try:
        B = []

        for g in range(y):
            h = A[0][g] + A[1][g]
            B.append(h)


    except Exception:
        print('erro 2')

    return B


A,y=matrizes()
B=matrizB(A,y)

for p in range(y):
    print(A[p])

print()
print(B)
