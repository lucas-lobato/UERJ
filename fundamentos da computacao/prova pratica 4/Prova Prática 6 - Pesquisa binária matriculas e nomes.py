#Programa 6
from random import *
def le():
    matriculas = []
    nomes = []
    m = 0
    while True:
        while True:
            try:
                matricula = raw_input('Digite a matricula: ')
                if matricula == '':
                    break
                if matricula in matriculas:
                    print 'Esta matricula ja foi cadastrada.'
                    raise
                if matricula.isdigit() == False and matricula != '':
                    raise
                else:
                    m += 1
                    matriculas.append(matricula)
            except:
                print 'Entre com um dado valido.'
        if matricula == '':
            break
    return m, matriculas, nomes
def analise(m, matriculas, nomes):
    for i in range (m):
        nome = ''
        for j in range(randint(5,10)):
            letra = chr(randint(97,122))
            nome += letra
        nomes.append(nome)
    for i in range(m):
        print '--'*5
        print 'Matricula: ', matriculas[i]
        print 'Nome: ', nomes[i]
    print '--'*10
    return matriculas, nomes
def pesquisa(matriculas, nomes):
    n = len(matriculas)
    busca = raw_input('Matricula a procurar: ')
    if busca in matriculas:
        a = matriculas.index(busca)
    matriculas.sort()
    achei = False
    inicio, fim = 0, n-1
    while inicio <= fim:
        meio = (inicio + fim)/2
        if busca == matriculas[meio]:
            achei=True
            break
        else:
            if matriculas[meio] < busca:
                inicio = meio + 1
            else:
                fim = meio - 1
    if achei:
        print 'Matricula encontrada ---> ',busca
        print 'Nome ---> ', nomes[a]
    else:
        print 'Matricula nao encontrada ---> ',busca
    return
#Main
m, matriculas, nomes = le()
matriculas, nomes = analise(m, matriculas, nomes)
pesquisa(matriculas, nomes)
