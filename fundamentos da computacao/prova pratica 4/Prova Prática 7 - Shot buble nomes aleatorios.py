#Programa 7
from random import*
def le():
    while True:
        try:
            n = int(raw_input('Digite o numero de nomes: '))
            break
        except:
            print 'Entre com um numero inteiro.'
    return n
def analise(n):
    A = []
    x = 1
    while x <= n:
        a = ''
        a1 = ''
        for i in range(randint(5,10)):
            letra = chr(randint(97,122))
            a += letra
        for i in range(randint(5,10)):
            letra = chr(randint(97,122))
            a1 += letra
        A.append(a + ' ' + a1)
        x +=1
    print '-'*5 + 'Nomes gerados originalmente' + '-'*5
    for i in range(len(A)):
        print A[i]
    return A
def ordenar(A):
    troca = True
    y = len(A) - 1
    while y>0 and troca:
        troca = False
        for i in range(n):
            if i != (n-1):
                if A[i] > A[i+1]:
                    A[i], A[i+1] = A[i+1], A[i]
                    troca = True
        y -= 1
    return A
def impr(A):
    print '-'*5 + 'Nomes ordenados' + '-'*5
    for i in range(len(A)):
        print A[i]
    return
#Main
n = le()
A = analise(n)
A = ordenar(A)
impr(A)

