# arquivo texto gravar uma qtd indeterminada de nomes
# modulo le e grava
#usando o split
def legrava():
    import os
    os.chdir("f:/")  # diretorio corrente E
    arq = open('nomes1.txt', 'w')  # abre para escrita
    while True:
        nome = raw_input('digite o nome ')
        if nome.lower() == 'pare': break
        arq.write(nome + ' ')  # grava um nome por linha
    arq.close()  # fecha o arquivo
    return


def impr():
    print
    'Nomes gravados'
    import os
    os.chdir("f:/ ")  # diretorio corrente E
    arq = open("nomes1.txt", 'r')  # abre para leitura
    nome = arq.read()
    nomez = nome.split(' ')
    print
    nomez
    for i in range(0, len(nomez) - 1):
        print
        nomez[i]
    arq.close()


# programa principal
legrava()
impr()

