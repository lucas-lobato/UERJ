def le():
    nomes=[]
    while True:
        nom=input('Digite o nome:')
        if nom=='':break
        nomes.append(nom)
    return nomes

def pbin(nomes):
    nomes.sort()
    print(nomes)
    nproc=input('Digite o nome a procurar:')
    i=0
    f=len(nomes)-1
    achei=False
    while i<f and achei==False:
        m=(i+f)//2 #posiçao media
        if nproc==nomes[m]:
            achei=True
        elif nproc<nomes[m]:
            f=m-1
        else:
