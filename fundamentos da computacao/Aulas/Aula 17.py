def le():
    nomes=[]
    while True:
        nom=input('Digite um nome:')
        if nom =='':break
        nomes.append(nom)
    return nomes

def ordem(nomes):
    tam=len(nomes)
    for i in range(tam-1):
        for j in range(i+1,tam):
            if nomes[i]>nomes[j]:
                nomes[i],nomes[j]=nomes[j],nomes[i]
    return nomes

def impr(nomes):
    print('Nomes ordenados')
    for i in nomes:
        print(i)

nomes=le()
nomes=ordem(nomes)
impr(nomes)