#remover um dado em um arquivo

def ler():
    try:
        arq=open('arquivo.txt','w')
        while True:
            nomes=input('Digite o nome:')
            if nomes=='':break
            idade=input('Digite a idade:')
            print('-'*60)
            ident=(nomes+','+idade)
            arq.write(ident+'\n')
        arq.close()
    except:
        print('Ooops, dado invalido, tente de novo...')
        return ler()
    return

def procura():
    try:
        arq=open('arquivo.txt','r')
        lista=[]
        nomep=input('Digite o nome a ser removido:')
        for i in arq:
            i=i.split(',')
            if i[0]!=nomep:
                lista.append(i)
        arq.close()
    except:
        print('Dado invalido, tente de novo:')
        return procura()
    return lista

def impr(lista):
    print()
    print('Arquivo alterado -->')
    for i in lista:
        print('{}'.format(i))
    print()
    print('Fim')

ler()
lista=procura()
impr(lista)
