#Programa 10
from random import *
def le1():
    A = []
    while True:
        try:
            m = int(raw_input('Digite o numero de elementos da matriz A: '))
            for i in range(m):
                a = randint(1,8)
                A.append(a)
            break
        except:
            print 'Entre com um numero inteiro!'
    print A
    return A, m

def le2(A, m):
    b = 1
    B = [None]*m
    for i in range(m):
        B[i] = [None]*3
        for j in range(3):
            if j == 0:
                B[i][j] = A[i] + 5
            elif j == 1:
                for k in range(1, A[i]+ 1):
                    b *= k
                B[i][j] = b
                b = 1
            elif j == 2:
                B[i][j] = A[i]*A[i]
    return B, m

def impr(B, m):
    for i in range(m):
        for j in range(3):
            print B[i][j],
        print
    return

#Main
A, m = le1()
B, m = le2(A, m)
impr(B, m)
