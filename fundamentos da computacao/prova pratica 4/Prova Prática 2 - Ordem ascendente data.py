#Programa 2
from random import *
def le():
    calenda = []
    nomei = ''
    lista = []
    datas = []
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
            lista.append(nome)
        for i in range(len(lista)):
            dia = str(randint(1,31))
            if int(dia) < 10:
                dia = '0'+dia
            mes = str(randint(1,12))
            if int(mes) < 10:
                mes = '0'+mes
            ano = str(randint(2000,2018))
            calenda.append(ano+mes+dia)
            datas.append(dia+'/'+mes+'/'+ano)
    for i in range(len(lista)):
        print '--'*5
        print 'Nome --> ', lista[i]
        print 'Data --> ', datas[i]
    return calenda, lista 
def analise(calenda, lista):
    for i in range(len(lista)-1):
        for j in range(i+1,len(lista)):
            if calenda[i] > calenda[j]:
                calenda[i], calenda[j] = calenda[j], calenda[i]
                lista[i], lista[j] = lista[j], lista[i]
    return calenda, lista
def impr(calenda, lista):
    print '--'*5
    print 'Datas ordenadas:'
    for j in range(len(lista)):
        ano = calenda[j][0:4]
        mes = calenda[j][4:6]
        dia = calenda[j][6:8]
        a = lista[j]
        print '{:5s}, nascido(a) em {:1s}/{:1s}/{:1s}.'.format(a, dia, mes, ano)
    return    
calenda, lista = le() 
calenda, lista = analise(calenda, lista)
impr(calenda, lista)
