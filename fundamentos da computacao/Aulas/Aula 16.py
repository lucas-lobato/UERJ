def le():
    nomes=[]
    while True:
        nom=input('Digite um nome:')
        if nom =='': return nomes
        nomes.append(nom)

def lenom():
    nomep=input('Digite o nome procurado:')
    return nomep
def procura(nomes,nomep):
    achei=False
    tam=len(nomes)
    i=0
    while not achei and i<tam:
        if nomes[i]==nomep:
            achei=True
            break
    return achei

def impr(achei):
    if achei==True:
        print('Nome encontrado')
    if achei==False:
        print('Nome nao encontrado')

nomes=le()
nomep=lenom()
achei=procura(nomes,nomep)
impr(achei)
