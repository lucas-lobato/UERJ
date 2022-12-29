#Numeros triangulares

def pergunta():
    n=int(input('Digite um numero: '))
    return n

def verifica(n):
    triangular=0
    for i in range(n):
        if (i)*(i+1)*(i+2)==n:
            triangular+=1
    if n==0:
        triangular=triangular+1
    return triangular

def impr(triangular):
    if triangular ==1:
        print('Triangular')
    else:
        print('Nao é triangular')

n=pergunta()
triangular=verifica(n)
impr(triangular)