def ler1():
    try:
        l=int(input('Digite o numero de linhas:'))
        c=int(input('Digite o numero de colunas:'))
        matri=[None]*l
        for i in range(l):
            matri[i]=[None]*c
            for j in range(c):
                matri[i][j]=input('Digite o elemento{}{}:'.format([i+1],[j+1]))
    except:
        print('Ooops, dado invalido, tente de novo...')
        return ler1()
    return matri

def soma(matri):
    linha1=matri[0]
    linha3=matri[2]
    for i in linha1:
        for j in linha3:
            soma=(i+1)+(j+1)
    print (soma)


def impr(matri):
    print()
    for i in matri:
        print(i)

matri=ler1()
soma(matri)
impr(matri)