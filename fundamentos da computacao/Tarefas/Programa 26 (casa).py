# criar duas listas, uma pra nome e outra pra idade dos usuarios, ordenar com bubble sort e fazer uma pesquisa binaria
#para verificar se um nome esta na lista


vetor1=[]
vetor2=[]

def le():
    try:
        while True:
            vetor1=[]
            names=input('Digite um nome:')
            if names=='':break
            ages=int(input('Digite a idade:'))
            vetor1.append(names)
            vetor1.append(ages)
            vetor2.append(vetor1)

    except Exception:
        print('oops, dado invalido')
    return vetor2

def ordena(vetor2):
    troca=False
    n=len(vetor2)-1
    while n>0 and troca==False:
        troca=False
        for i in range(n):
            if vetor2[i]>vetor2[i+1]:
                vetor2[i],vetor2[i+1]=vetor2[i+1],vetor2[i]
                troca=True
        print(vetor2)
    return vetor2

def procura(vetor2):
    try:
        nproc=input('Digite o nome a procurar:')
        k=0
        achei=False
        age=''
        while True and k<len(vetor2):
            if vetor2[k][0]==nproc:
                age = vetor2[k][1]
                achei=True
                break
            else:
                k+=1
    except Exception:
        print('oops, dado invalido')

    return nproc,achei,age

def impr(achei,age):
    if achei==True:
        print('Nome {} encontrado, esta pessoa tem {} anos'.format(nproc,age))
    else:
        print('Nome {} não encontrado'.format(nproc))


vetor2=le()
vetor2=ordena(vetor2)
nproc,achei,age=procura(vetor2)
impr(achei,age)

