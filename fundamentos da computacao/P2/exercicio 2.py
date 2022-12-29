#exercicio 2

names=[]
sal=[]

def legrava():
    try:
        arq=open('exercicio2.txt','w')
        while True:
            nomes=input('Digite o seu nome: ')
            if nomes=='': break
            salarios=input('Digite o seu salário: ')
            arq.write(nomes)
            arq.write(' ')
            arq.write(salarios)
            arq.write('\n')
        names.append(nomes)
        sal.append(salarios)
        arq.close()

    except Exception:
        print('Se fudeo otario, errooouuuwww')

    return

def procura():
    arq=open('exercicio2.txt','r')

    n=len(names)-1
    for i in range(0,n):
        for j in range(i+1,n):
            if names[i]>nomes[j]:
                nomes[i],names[j]=names[j],nomes[i]
                sal[i],sal[j]=sal[j],sal[i]
    busca=input('digite o nome que deseja procurar: ')
    achei = True
    inicio,fim=0,n
    meio=0
    while n>0 and achei!=True:
        achei=False
        meio=(inicio+fim)/2
        if busca== names[meio]:
            achei=True
            break
        elif busca>names[meio]:
            inicio=meio+1
        else:
            fim=meio-1
    if achei==True:
        print ('o',busca,'recebe', sal[meio])
    else:
        print ('o',busca,'não foi encontrado')




legrava()
procura()
