#gera 10 matrizes aleatorias diferentes

def matricula(mat):
    while True: #cria o numero de matricula
        matri='' #cria uma matricula vazia
        for i in range(6): #gera 6 algorismos
            num=str(randint(0,9)) #gera um numero entre0 e 9
            matri+=num #concaten com a matricula

        if matri not in mat: #verifica se existe
            mat.append(matri) #nao existe e adiciona a lista
            return matri,mat #retorna a matricula e a lista

#programa principal
from random import*
mat=[] #cria uma lista de matriculas. è uma vairável global
print('Matriculas')
while True:
    cmat,mat=matricula(mat) #cmat é cada matricula
    print ('{:1s}'.format(cmat))
    if len(mat)==10:break #se existem 10 matriculas
