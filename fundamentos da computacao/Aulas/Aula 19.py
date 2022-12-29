#determinar a soma de 2 matrizes de MxN elementos

def ler():
    a=[None]*m # cria uma lista com m valores
    for i in range(m):
        a[i]=[None]*n # para cada m cria uma coluna com n valores
        for j in range(n):
            a[i][j]=float(input('Digite o termo'+str(i+1)+','+str(j+1)+']-->'))
    return a

def soma(a,b):
    c=[None]*m
    for i in range(m):
        c[i]=[None]*n
        for j in range(n):
            c[i][j]=a[i][j]+b[i][j]
    return c

def impr(a,mensagem):
    print('\n{:*^30}\n'.format(mensagem))
    for i in range(m):
        for j in range(n):
            print('{:>10.2f}'.format(a[i][j]),end='')
        print() # Muda de linha
    return

#Programa principal
m=int(input('Digite m:'))
n=int(input('Digite n:'))
print('{:^30}'.format('Matriz A'))
a=ler()
print('{:^30}'.format('Matriz B'))
b=ler()
c=soma(a,b)
impr(a,'Matriz A')
impr(b,'Matriz B')
impr(c,'Matriz Soma')