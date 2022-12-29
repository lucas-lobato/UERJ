#Programa 5
from random import *
def le():
        nomei = ''
        nomes = []
        while True:
                try:
                        nome = raw_input('Digite o nome: ')
                        for i in range(len(nome)):
                                if nome[i] != ' ':
                                        nomei += nome[i]
                                if nomei.isalpha() == False and nomei != '':
                                        raise
                except:
                        print 'Somente letras. Digite novamente.'
                if nome == '':
                        break
                nomes.append(nome)
        return nomes
def analise(nomes):
        matriculas = []
        for i in range(len(nomes)):
                a = randint(100000, 999999)
                matriculas.append(a)
                for i in range(len(matriculas)):
                        if i == 0:
                                b = matriculas[i]
                        elif matriculas[i] == b:
                                matriculas.remove(matriculas[i])
                                matriculas.append(randint(100000, 999999))
                                i = 0
        for i in range(len(nomes)):
                print '--'*5
                print 'Nome --> ', nomes[i]
                print 'Matricula --> ', matriculas[i]
        return nomes, matriculas
def impr(nomes, matriculas):
        n = len(nomes)
        print '--'*5
        busca = raw_input('Nome a procurar: ')
        if busca in nomes:
                a = nomes.index(busca)
        nomes.sort()
        achei = False
        inicio, fim = 0, n-1
        while inicio <= fim:
                meio = (inicio + fim)/2
                if busca == nomes[meio]:
                            achei = True
                            break
                else:
                           if nomes[meio] < busca:
                                        inicio = meio + 1
                           else:
                                        fim = meio - 1
        if achei:
                print '--'*5
                print 'Nome encontrado --> ',busca
                print 'Matricula --> ', matriculas[a]
        else:
                print 'Nome nao encontrado --> ',busca
        return
#main
nomes = le()
nomes, matriculas = analise(nomes)
impr(nomes, matriculas)
