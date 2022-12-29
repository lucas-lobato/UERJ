# LUCAS LOBATO DA SILVA AMORIM

def legrava1():
    # este módulo serve para criar o arquivo 1-mestre
    arq1 = open('arq1.txt', 'w+')
    arq2 = open('arq2.txt', 'w+')
    print('{:*^30}'.format('Cadastro de alunos'))
    print('pressione enter para encerrar')
    while True:
        mat = input('Digite a matricula:')
        matt=('Matricula:'+mat)
        if mat == '':
            return
        nome = str(input('Digite o nome:'))
        nomee=('Nome:'+nome)
        arq1.write(mat + ',' + nome + '\n')  # grava
        lista=[]
        while True:
            desc = input('Digite a disciplina:')
            descc=('Disciplina:'+desc)
            if desc=='':break
            nota = input('Digite a nota:')
            notaa=('Nota:'+nota)
            notas=(descc+','+notaa)
            lista.append(notas)
            for i in range(len(lista)):
                arq2.write(matt +','+ nomee + ',' + lista[i] + '\n')  # grava um registro
    arq1.close()
    arq2.close()
    return

def impr():
    arq2 = open('arq2.txt', 'r')
    print()  # muda de linha
    print('{:*^30}'.format('Histórico Escolar'))
    print()
    texto = arq2.readlines()
    for linha in texto :
      print(linha)
    arq2.close()


# programa principal
legrava1()
impr()