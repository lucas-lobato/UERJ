#achar um carcater em uma frase e dizer a posiçao

def pergunta():
    frase=input('Digite uma frase:')
    carac=input('Digite um caracter:')
    return frase,carac

def verifica(frase,carac):
    achei=False
    for i in range(len(frase)):
        if frase[i]==carac:
            achei=True
            return achei,i

def impr(achei):
    if achei:
        print('O caracter está na {:2d} posição'.format(i+1))
    else:
        print('Nao achado')

frase,carac=pergunta()
achei,i=verifica(frase,carac)
impr(achei)