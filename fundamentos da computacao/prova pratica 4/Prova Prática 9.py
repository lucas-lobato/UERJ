#exercicio 9

from random import*

def Matrizes(l):
    j = []
    for i in range(l):
        a=randint(1,99)
        j.append(int(a))
    return j

x=[]
a=[]
y=[]
b=[]
c=[]

m = int(input('Digite o numero de elementos: '))
a=x=Matrizes(m)
b=y=Matrizes(m)

for f in range(len(a)):
    for i in range (len(a)-1):
        if a[i] > a[i+1]:
            aux=a[i]
            a[i] = a[i+1]
            a[i+1] = aux

for f in range(m):
    for i in range (m-1):
        if b[i] < b[i+1]:
            aux=b[i]
            b[i] = b[i+1]
            b[i+1] = aux

c.append(a)
c.append(b)
print('Matriz A:') 
print(x)
print('Matriz B:') 
print(y)
print('Matriz C:') 
print(c)
