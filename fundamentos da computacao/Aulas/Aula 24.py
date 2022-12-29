# ler uma matriz 3x3 valores. Classificar em ordem ascendente a 1a linha
def le():
    a=[None]*3 #cria um vetor com 3 valores
    for i in range(0,3):
        a[i]=[None]*3 #para cada linha cria uma 3 colunas
        for j in range(3):
            a[i][j]=float(input('a['+str(i+1)+'],['+str(j+1)+']:'))
    return a
#ordenando a primeira linha
def ord(a):
    for i in range (3-1):
        for j in range(i+1,3):
            if a[0][i]>a[0][j]:
                a[0][i],a[0][j]=a[0][j],a[0][i]
    return a[0]
a= ord(le())
print ('\n Imprimindo a primeira linha \n')
for i in a:
    print (i,end=' ')