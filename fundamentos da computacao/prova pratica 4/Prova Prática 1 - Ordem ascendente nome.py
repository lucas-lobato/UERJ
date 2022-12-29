#Programa 1
from random import *
def le():
    tudo = []
    n = 0
    nomei = ''
    while True:
        while True:
            try:
                nome = raw_input('Digite o nome: ')
                for i in range(len(nome)):
                    if nome[i] != ' ':
                        nomei += nome[i]
                    if nomei.isalpha() == False and nomei != '':
                        nomei = ''
                        raise
                break
            except:
                print 'Somente letras.'
        if nome == '':
            break
        else:
            tudo.append(nome)
            n += 2
        ano = randint(2000,2018)
        dia = randint(0,31)
        if dia < 10:
            dia = '0'+str(dia)
        mes  = randint(0,12)
        if mes < 10:
            mes = '0'+str(mes)
        data = str(dia)+'/'+str(mes)+'/'+str(ano)
        tudo.append(data)
    return n, tudo
def analise(n, tudo):
    for i in range(0,n-1,2):
        for j in range(i+2,n,2):
            if tudo[i] > tudo[j]:
                tudo[i], tudo[j] = tudo[j], tudo[i]
                tudo[i+1], tudo[j+1] = tudo[j+1], tudo[i+1]
    return tudo
def impr(tudo):
    for i in range(0,len(tudo),2):
        print tudo[i],', nascido(a) em ',tudo[i+1]+'.'
    return
#main
n, tudo = le()
tudo = analise(n, tudo)
impr(tudo)
