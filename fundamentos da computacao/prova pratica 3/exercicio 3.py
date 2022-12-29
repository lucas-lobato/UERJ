def ler():
	nomes =[]
	while True:
		nome = raw_input("Digite um nome:")
                if nome == "EOF":
			return nomes
			break
                else:
		        nomes.append(nome)

def bubbleSort(lis):

    if len(lis) <= 1:
        sLis = lis
    else:
        for j in range(0,len(lis)):
            for i in range(0,len(lis)-1):
                if lis[i]<lis[i+1]:
                    vAux = lis[i+1]
                    lis[i+1] = lis[i]
                    lis[i] = vAux
        sLis = lis

    return sLis

listaNomes = []
novaLista = []
listaNomes = ler()
novaLista = bubbleSort (listaNomes)

for i in range(len(listaNomes)):
	    print (novaLista[i])