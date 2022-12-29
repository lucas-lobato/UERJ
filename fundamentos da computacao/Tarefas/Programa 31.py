
def matriz():
    try:
        m=[]
        l=int(input('Digite o numero de linhas:'))
        c=int(input('Digite o numero de colunas:'))
        m=[None]*l
        for i in range(l):
            m[i]=[None]*c
            for j in range(c):
                m[i][j]=float(input('Digite o valor {}'.format([i+1]+[j+1])))
    except:
        print('ooops, dado invalido, erro.')
    return m

def colunas(m):
    x=len(m)
    lista=[]
    while True:
        coluns=[]
        for i in range(x):
            if i==i-1:
                break
            for j in range(0,x,3):
                coluns.append(m[i][j])
                lista.append(coluns)

    return lista

def impr(m,lista):
    print(m)
    print(lista)


m=matriz()
lista=colunas(m)
impr(m,lista)