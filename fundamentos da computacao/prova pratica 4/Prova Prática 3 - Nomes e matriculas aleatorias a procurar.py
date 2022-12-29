#Programa 3
from random import *
def le():
        nomei = ''
        nomes = []
        matriculas = []
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
        return nomes, matriculas
def analise(nomes, matriculas):
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
        return matriculas
def impr(matriculas):
        n = len(matriculas)
        print '--'*5
        busca = int(raw_input('Matricula a procurar: '))
        if busca in matriculas:
                a = matriculas.index(busca)
        matriculas.sort()
        achei = False
        inicio, fim = 0, n-1
        while inicio <= fim:
                meio = (inicio + fim)//2
                if busca == matriculas[meio]:
                        achei = True
                        break
                else:
                        if matriculas[meio] < busca:
                                inicio = meio + 1
                        else:
                                fim = meio - 1
        if achei:
                print 'Matricula encontrada --> ',busca
                print 'Nome --> ', nomes[a]
        else:
                print 'Matricula nao encontrada --> ',busca
        return
#main
nomes, matriculas = le()
matriculas = analise(nomes, matriculas)
impr(matriculas)
                                
