#ler para um aqrquivo uma qtd indeterminada de valores reais
#Ler do arquivo os dados para uma matriz de M*N valores
#determinar a soma da primeira linha com a segunda
#exibir a mtriz lida na forma vetor e tabela

def legrava():
    while True:
        num=input('Digite um numero:')
        if num=='': break
        arq.write(num+'\n') # garav um numero por linha
    return

def ler():
    arq.seek(0) # inicio do arquivo
    m=int(input('Digite o numero de linhas:'))
    n=int(input('Digite o numero de colunas:'))
    a=[None]*m
    for i in range(m):
        a[i]=[None]*n
        for j in range(n):
            a[i][j]=int(arq.readline()) # le um dado do arquivo
    return a,m,n

def soma(a,n):
    s=[]
    for i in range(0,n):
        x=a[0][i]+a[1][i]
        s.append(x)
    return s

def impr(a,s,m,n):
    print()
    print('----------- Matriz Lida -----------')
    for i in range(m):
        for j in range(n):
            print('{:>10.2f}'.format(a[i][j]),end='')
        print()
    print()
    print('--------------- Vetor Soma -------------------')
    for i in range(n):
        print('{:>10.2f}'.format(s[i]),end='')
    print()
    return

arq=open('num1.txt','w+')
legrava()
a,m,n=ler()
s=soma(a,n)
impr(a,s,m,n)