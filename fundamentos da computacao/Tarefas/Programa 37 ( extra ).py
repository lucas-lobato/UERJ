def legrava1():
    # este mÃ³dulo Ã© para criar o arquivo 1-mestre
    print('{:*^30}'.format('Cadastro de alunos'))
    # le o arquivo para a lista ar1
    try:
        arq1 = open('arq1.txt', 'r')
        ar1 = arq1.readlines()
        arq1.close()
    except:
        ar1 = []

    matr1 = []  # lista com todas matriculas
    nome = []  # lista com todos nomes
    # descompacta se o arquivo existe
    if len(ar1) != 0:
        for mat in ar1:
            valor1 = mat.split(',')
            matr1.append(valor1[0])
            nome.append(valor1[1])
    print('pressione enter para encerrar')
    while True:
        # verifica a digitaÃ§Ã£o
        trans = input('Digite a transaÃ§Ã£o I-inclusÃ£o,A-alteraÃ§Ã£o,E-exclusÃ£o,Enter-sair ')
        if trans == '': break
        while True:
            try:
                mat = input('Digite a matricula ')
                aux = int(mat)
                break
            except:
                print('{:*^30}'.format('erro na matricula'))
        # valida a transaÃ§Ã£o
        if trans.upper() == 'I':
            while True:
                try:
                    if mat in matr1: raise
                    matr1.append(mat)  # inclui na lista de matriculas
                    nomen = input('Digite o nome ')
                    ar1.append(mat + ',' + nomen + '\n')  # adiciona a lista geral
                    break
                except:
                    print('{:*^30}'.format('Matricula existente'))
                    break
        elif trans.upper() == 'A':
            while True:
                try:
                    if mat not in matr1: raise
                    pos = matr1.index(mat)  # posiÃ§Ã£o onde estÃ¡ a matricula
                    nomen = input('Digite o novo nome  ')
                    ar1.pop(pos)  # apaga na lista de nomes
                    ar1.insert(pos, mat + ',' + nomen + '\n')  # insere na posiÃ§Ã£o o novo nome
                    break
                except:
                    print('{:*^30}'.format('Matricula inexistente'))
                    break
        elif trans.upper() == 'E':
            while True:
                try:
                    if mat not in matr1: raise
                    pos = matr1.index(mat)  # posiÃ§Ã£o onde estÃ¡ a matricula
                    matr1.pop(pos)  # apaga a matricula
                    nome.pop(pos)  # apaga na lista de nomes
                    ar1.pop(pos)  # apaga da lista geral
                    break
                except:
                    print('{:*^30}'.format('Matricula inexistente'))
                    break
                # grava o arquivo novamente
    arq1 = open('arq1.txt', 'w')  # apaga o arquivo existente
    for i in ar1:
        arq1.write(i)  # grava
    arq1.close()
    return


def legrava2():
    try:
        arq2 = open('arq2.txt', 'a')
    except:
        arq2 = open('arq2.txt', 'w')
    # este mÃ³dulo Ã© para criar o arquivo 2-transaÃ§Ãµes
    print('{:*^30}'.format('Disciplinas Cursadas'))
    while True:
        mat = input('Digite a matricula ')
        if mat == '':
            return
        cod = input('Digite o cÃ³digo da disciplina ')
        nota = input('Digite a nota ')
        arq2.write(mat + ',' + cod + ',' + nota + '\n')  # grava um registro
    arq2.close()
    return


def impr():
    arq1 = open('arq1.txt', 'r')
    arq2 = open('arq2.txt', 'r')
    ar1 = arq1.readlines()
    ar1.sort()
    ar2 = arq2.readlines()
    ar2.sort()
    print()  # muda de linha
    print('{:*^30}'.format('HistÃ³rico Escolar'))
    k = 0
    tam = len(ar2)
    for mat in ar1:
        valor1 = mat.split(',')
        matr1 = valor1[0]
        nome = valor1[1]

        print(' \nMatricula: {:4s}  Nome:  {:30s}  '.format(matr1, nome))
        soma = 0
        cont = 0
        for j in range(k, tam):
            valor2 = ar2[j].split(',')
            matr2 = valor2[0]
            cod = valor2[1]
            nota = valor2[2]
            if matr2 == matr1:  # <-- se a matricula de arq2 for igual a de arq1
                nota = float(nota)
                soma += nota
                cont += 1
                print('{:1s} -  {:5.1f}'.format(cod, nota))
                k += 1
            else:
                if cont == 0:
                    print('NÃ£o existem matÃ©rias cursadas')
                    break
                else:
                    media = soma / cont
                    print('MÃ©dia= {:5.1f}'.format(media))
                    break
    arq1.close()
    arq2.close()
    return


# programa principal

legrava1()
legrava2()
impr()