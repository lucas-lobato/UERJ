def ler():
    m=int(input('Digite m:'))
    n = int(input('Digite n:'))
    a=[None]*m
    for i in range(m):
        a[i]=[None]*n
        for j in range(n):
            a[i][j]=float(input('Digite um termo:'))
    return a,m,n

def soma(a,m,n):
    c=[None]*m
    for i in range(m):
        c[i]=[None]*n
        for j in range(n):
            c[i][j]=a[i][j]//(max(a[i]))

    return c

def impr(c):
    print(c)

a,m,n=ler()
c=soma(a,m,n)
impr(c)