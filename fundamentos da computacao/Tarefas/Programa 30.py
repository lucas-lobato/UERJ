# busca binaria em lista

def ler():
    try:
        lista=[]
        while True:
            nums=int(input('Digite um numero:'))
            if nums==00:
                break
            lista.append(nums)
    except:
        print('Erro')
    return lista

def sort(lista):
    x=len(lista)
    for i in range(0,x):
        for j in range(0,x-1):
            if lista[j]>lista[j+1]:
                lista[j],lista[j+1]=lista[j+1],lista[j]
    print(lista)
    return lista

def pesquisa(lista):
    nproc = int(input('Digite o numero a procurar '))
    i = 0  # inicio
    f = len(lista) - 1  # fim
    achei = False
    while i <= f and achei == False:
        m = (i + f) // 2  # posicao media
        if nproc == lista[m]:
            achei = True
        elif nproc < lista[m]:
            f = m - 1
        else:
            i = m + 1
    return achei

def impr(achei):
    if achei==True:
        print('valor encontrado')
    else:
        print('valor nao encontrado')


lista=ler()
lista=sort(lista)
achei=pesquisa(lista)
impr(achei)

