#exercicio 4


list=[]

def le():
    arq = open('exercicio4.txt', 'w')
    while True:
        names=input('Digite um nome:')
        if names=='': break
        ages=input('Digite a idade:')
        registro=(names+' '+ages).split()
        list.append(registro)
        arq.write(str(list))
        arq.write('\n')
    arq.close()

    return

def procura():
    for i in range(list):
        max(list)
        print(max(list))
    return

le()
procura()



