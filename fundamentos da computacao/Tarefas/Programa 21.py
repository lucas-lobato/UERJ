#Palindromo sem usar o [::-1]

def pergunta():
    fraseC=input('Digite uma frase:')
    return fraseC

def verifica(fraseC):
    frase=fraseC.replace(' ','')
    fraseI=''
    for x in range(len(frase) -1, -1, -1):
        aux = fraseI + frase[x]
        fraseI = aux
    if frase==fraseI:
        print('É palindromo')
    else:
        print('Nao é palindromo')

fraseC=pergunta()
verifica(fraseC)
