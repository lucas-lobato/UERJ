# ler matriz e ordenar a primeira linha

def ler():
    try:
        l=int(input('Digite o numero de linhas:'))
        c=int(input('Digite o numero de colunas:'))
        matriz=[None]*l
        for i in range(l):
            matriz[i]=[None]*c
            for j in range(c):
                matriz[i][j] = int(input('Digite o elemento {}:'.format(([i + 1] + [j + 1]), '-->')))

    except:
        print('ooops, dado invalido, erro, tente novamente !')
    return matriz,c

def ordena(matriz,c):
    x=len(matriz)
    for i in range(x-1):
        for j in range(i+1,c):
            if matriz[0][i]>matriz[0][j]:
                matriz[0][i],matriz[0][j]=matriz[0][j],matriz[0][i]
    return matriz

def impr(matriz):
    print(matriz)

matriz,c=ler()
matriz=ordena(matriz,c)
impr(matriz)