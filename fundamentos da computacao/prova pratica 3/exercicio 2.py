#exercicio 2
#Ler duas litas e mostrar a soma delas

from random import*

X=[]
Y=[]
Z=[]
a=[]
b=[]

def ler (l):
    try:
        j = []
        for i in range(l):
            a = randint(1, 9)
            j.append(int(a))
    except Exception:
        print('Voce fez algo errado. Erro')

    return j

T=int(input('Digite o numero de elementos da lista: '))

Z=[]
a=X=ler(T)
b=Y=ler(T)

for g in range(T):
    h = X[g]+Y[g]
    Z.append(h)

print('A primeira lista é:',X)
print('A segunda lista é:',Y)
print('As listas somadas:',Z)



