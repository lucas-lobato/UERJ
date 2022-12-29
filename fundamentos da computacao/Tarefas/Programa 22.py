#teste de prefixo

def pergunta():
    frase=input('Digite uma palavra:')
    prefixo=input('Digite o prefixo:')
    return frase,prefixo

def verifica(frase,prefixo):
    for i in range (len(prefixo)):
        if prefixo[i]==frase[i]:
            x=True
        else:
            x=False
            return x
    return x

def impr(x):
    if x==True:
        print('É prefixo')
    else:
        print('Não é prefixo')

frase,prefixo=pergunta()
x=verifica(frase,prefixo)
impr(x)