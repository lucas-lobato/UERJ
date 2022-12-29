# arquivo texto gravar uma qtd indeterminada de nomes
# modulo le e grava
#Com tamanho fixo de informaçoes
def legrava():
    import os
    os.chdir ("d:/" ) # diretorio corrente E
    arq=open('nomes1.txt','w') # abre para escrita
    while True:
        nome=raw_input('digite o nome ')
        if nome.lower() == 'pare': break
        nome='%30s' %nome # transforma o texto em 30 bytes
        arq.write(nome) #grava um nome
    arq.close() #fecha o arquivo
    return
def impr():
    print 'Nomes gravados'
    import os
    os.chdir ("d:/ " ) # diretorio corrente E
    arq=open("nomes1.txt",'r') # abre para leitura
    while True:
       nome=arq.read(30)
       if nome=='':
            break
       print nome
    arq.close()
# programa principal
legrava()
impr()