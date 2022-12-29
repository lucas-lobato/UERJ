#Conta espaços em branco e vogais de uma frase

vogais=['a','e','i','o','u']

def pergunta():
    frase=input('Digite uma frase:')
    return frase

def calc(frase):
    contador=0
    contadorE=0
    for i in range (len(frase)):
        if frase[i] in vogais:
            contador=contador+1

        if frase[i] in ' ':
            contadorE=contadorE+1

    return contador,contadorE

def impr(contador,contadorE):
    print('O numero de vogais é:', contador)
    print('O numero de espacos em branco é:',contadorE)

frase=pergunta()
contador,contadorE=calc(frase)
impr(contador,contadorE)