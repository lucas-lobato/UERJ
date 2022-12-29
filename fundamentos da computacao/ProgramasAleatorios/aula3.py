#grava uma quantidade inderterminada de valores no arquivo
#ler os dados e calcular a media aritmetica

def le():
    while True:
        x=input('Digite um numero: ')
        if x=='': break
        arq.write(x+'\n')
    return

def calc():
    arq.seek(0)
    soma=cont=0
    j=arq.readlines()
    print(j)
    for i in j:
        soma+=float(i)
        cont+=1
    media=soma/cont
    print('Media=',media)
    arq.close()
    return


arq=open('e:prog1.txt','w+')
le()
calc()