# Ler uma quantidade indeterminada de nomes e gravar em um arquivo
#listar em um arquivo os nomes iniciados com a letra 'a'

def grava():
    try:
        arq=open('nomes.txt','w')
        while True:
            name=input('Digite um nome:')
            if name=='': break
            arq.write(name+'\n')
        arq.close()
    except:
        print('Erro1')
    return

def listar():
    try:
        arq=open('nomes.txt','r')
        lista=arq.readlines()
        lista2=[]
        l=len(lista)
        for i in range(l):
            if lista[i][0]=='a':
                lista2.append(lista[i])
    except:
        print('erro2')
    return lista,lista2

def impr(lista,lista2):
    print('------------------------------------------------')
    print('Nomes gravados:')
    print('')
    for i in lista:
        print(i)
    print('------------------------------------------------')
    print('Nomes que começam com a letra -> a <-')
    print('')
    for j in lista2:
        print(j)

grava()
lista,lista2=listar()
impr(lista,lista2)