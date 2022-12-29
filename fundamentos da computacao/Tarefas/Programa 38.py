print('-----Pressione enter para encerrar os loopings-----')
print()
print('**** Historico escolar ****')
def ler1():
    try:
        arq=open('arq.txt','a')
    except:
        arq=open('arq.txt','w')
    try:
        while True:
            nomes=[]
            nome=input('Digite o nome:')
            if nome=='':
                break
            matri=input('Digite a matricula:')
            print()
            aux=int(matri)
            ident=(nome+','+matri+'\n')
            nomes.append(ident)
            for i in nomes:
                arq.write(i+'\n')
    except:
        print('Ooops, erro, tente de novo...')
        return ler1()
    arq.close()

def ler2():
    try:
        arq2=open('arq.txt','w+')
        arq=open('arq.txt','r')
        read=arq.readlines()
        lista=[]
        print()
        print('**** Informações para o arquivo 2 ****')
        print()
        while True:
            matri2=input('Digite a matricula:')
            if matri2=='':
                break
            aux2=int(matri2)
            for i in arq:
                i=i.split(',')
                if i[1]==matri2:
                    return
                else:
                    raise
            nome2=input('Digite o nome do aluno:')
            materia=input('Digite o codigo da materia:')
            nota=input('Digite a nota do aluno:')
            print()
            aux3=float(nota)
            ident2=(matri2+','+nome2+','+materia+','+nota+'\n')
            lista.append(ident2)
        for j in lista:
            arq2.write(j)
        arq2.close()
        arq.close()
    except:
        print('Ooops, erro2, tente de novo...')
        return ler2()
    return lista

def impr(lista):
    print()
    print('**** Matricula escolar ****')
    print()
    for i in lista:
        i=i.split(',')
        print('Matricula {} -- Nome {} -- Disciplina {} -- Nota {}'.format(i[0],i[1],i[2],i[3]))

ler1()
lista=ler2()
impr(lista)




