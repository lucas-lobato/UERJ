# Altere o programa anterior de modo que a escada seja invertida.
#FULANO
#FULAN
#FULA
#FUL
#FU
#F

def pergunta():
    n=str(input('Digite o seu nome:'))
    x=(len(n))
    return n,x

def escada(n,x):
    esc=[]
    for i in range (x):
        esc.append(n[i])
    for y in range (x):
        print(esc)
        del esc[x-1-y]

n,x=pergunta()
escada(n,x)