print('ler uma quantidade indeterminada de nomes que será associado a um numero de matrícula de 3 letras e 3 algarismos'
      ' gerados aleatoriamente (exemplo:abc001). O número de matrícula é unico e deve ser validado quanto a repetiçao. '
      'Os nomes devem ser validados para caracteres alfabéticos ou espaços em branco. Usando pesquisa binária verificar,'
      ' se um determinado nome (apenas o nome procurado é lido) se enconra na lista lida. A resposta deve exibir o nome'
      ' e matricula com "enconrado" ou "nao encontrado". Pode usar sort() e replace().')


bd=[]
mat=[]

def nomematri():
    while True:
        matri='' #cria uma matricula vazia
        for i in range(3): #gera 3 letras aleatórias
            letra=chr(randint(97,122))
            matri+=letra
        for i in range(3):#gera 3 algarismos
            num=str(randint(0,9))#gera numero entre 0 e 9
            matri+=num #concatena com a matricula
        if matri not in mat: #verifica se existe
            mat.append(matri) #nao existe e adiciona a lista
            break

    while True: #le e valida nome
        try:
            nome=input('Digite um nome: ')
            if nome=='': return bd
            nomer=nome.replace(' ','') #retira o espaço em branco para validar
            if nome.isalpha(): #nome correto atualza bd
                bd.append(nome+',',+matri) #adiciona nome com espaço + matricula aleatória
            else:
                raise
        except:
            print('Nome errado tente outro')


def calc(bd):
    #primeiro vamos ordenar a lista
    bd.sort()
    #vamos descompactar  lista
    nome=[]
    matr=[]
    l=[]
    for i in bd:
        l=i.split(',') #divide cada membro da lista por virgula
        nome.append(l[0]) #primeiro termo é o nome
        matr.append(l[1]) #o segundo a idade
    fim=len(nome)-1
    inicio=0
    nomep=input('Nome a procurar: ')
    achei=False
    while inicio<=fim and achei==False:
        meio=(inicio+fim)//2
        if nome[meio]==nomep:
            achei=True
        elif nomep<=nome[meio]:
            fim=meio-1
        else:
            inicio=meio+1

    return achei,nomep,matr[meio]


def impr(achei,nomep,matr):
    print('\n{:*^30\n'.format('resultado'))
    if achei:
        print('Nome{} encontrado, com matricula {}'.format(matrip,nome[meio]))
    else:
        print('Matricula nao encotrada')

from random import*

bd=nomematri()
achei,matrip,nome[meio]=calc(bd,mat)
impri(achei,matrip,nome)






