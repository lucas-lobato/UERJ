# ler um uma qtd indeterminada de nomes e data de nascimento
# exibir em duas listas os valores um por linha
# ordenar por data

lista=[]

def ler():
    while True:
        try:
            nom=input('Digite um nome:')
            if nom=='':break
            data=input('Digite sua data de nascimento (dd/mm/aaaa):')
            data2=data.split("/")
            ident=(data2[2]+'/'+data2[1]+'/'+data2[0]+'/'+'---'+nom)
            lista.append(ident)

        except Exception:
            print('oops, dado invalido, erro')
    return lista

def ordenar(lista):
    x=len(lista)
    for i in range(x-1):
        for j in range(i+1,x):
            if lista[i]>lista[j]:
                lista[i], lista[j]= lista[j], lista[i]
    return lista,x

def procura(lista,x):
    achei = False
    procNom=input('Digite o nome a ser procurado:')
    for i in range(x):
        if lista[i]==procNom:
            achei=True
    return achei,procNom



def impr(lista,achei,procNom):
    for i in lista:
        print(i)
    print()
    if achei==True:
        print('Nome {} achado'.format(procNom))
    else:
        print('Nome {} não achado'.format(procNom))

lista=ler()
lista,x=ordenar(lista)
achei,procNom=procura(lista,x)
impr(lista,achei,procNom)

