# exercicio 8

#O programa deve ser modularizado e exibido com mensagens indicativas Ler uma matriz de mxn valores reais.Classificar
#  e exibir a primeira linha em ordem crescente usar Bubble Sort. Não pode usar sort().Usar Try para validar os dados

def le():
    a=[None]*3
    for i in range (0,3):
        a[i]=[None]*3
        for j in range (3):
            try:
                a[i][j]=float(input('a['+str(i+1)+'],['+str(j+1)+']'))
                break
            except:
                print ('Dado incorreto')
    for i in range (0,3):
        for j in range (3):
            print (a[i][j],)
    return a
def inversa(a):
    n=0
    while n<3:
        if a[i]>a[i+1]:
            a[i+1]=a[i]
    return a
def impr(a):
    for i in range (0,3):
        for j in range (3):
            print (a[i][j])

    return

#main
a=le()
a=inversa(a)
impr(a)
