# arquivo texto gravar uma qtd indeterminada de nomes
# modulo le e grava
def legrava():
    try:
        arq = open('nomes1.txt', 'a')  # abre para inclusão
    except:
        arq = open('nomes1.txt', 'w')  # abre para escrita
    while True:
        nome = input('digite o nome ')
        if nome == '': break
        arq.write(nome + '\n')  # grava um nome por linha
    arq.close()  # fecha o arquivo
    return


def impr():
    print('Nomes gravados')
    arq = open("nomes1.txt", 'r')  # abre para leitura
    nome = arq.readlines()
    for i in range(len(nome)):
        print(nome[i], end=' ')
    arq.close()


# programa principal
import os

os.chdir("e:/")  # diretorio corrente E
legrava()
impr()