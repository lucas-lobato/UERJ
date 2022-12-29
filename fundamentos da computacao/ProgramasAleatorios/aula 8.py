# arquivo texto gravar uma qtd indeterminada de nomes
# modulo le e grava
#convertendo arquivo de string para numeros reais
def legrava():
    import os
    os.chdir("d:/")  # diretorio corrente E
    arq = open('num.txt', 'w')  # abre para escrita
    while True:
        num = raw_input('digite o numero  ')
        if num == '9999': break
        num = '%10s' % num  # transforma o texto em 10 bytes
        arq.write(num)  # grava um nome
    arq.close()  # fecha o arquivo
    return


def impr():
    print
    'Numeros gravados'
    import os
    os.chdir("d:/ ")  # diretorio corrente E
    arq = open("num.txt", 'r')  # abre para leitura
    s = 0
    while True:
        num = arq.read(10)
        if num == '':
            break
        nume = float(num)
        s += nume
        print('{:^10.2f}').format(nume)
    print('soma dos valores {:10.2f}').format(s)

    arq.close()


# programa principal
legrava()
impr()
