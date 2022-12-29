#crie um programa que conte as palavras sem usar o split

def pergunta():
    frase=input('Digite uma frase:')
    return frase

def calc(frase):
    k=frase.count(' ')
    t=k+1
    return t

def impr(t):
    print('A frase contem',t,'palavra(s)')

frase=pergunta()
t=calc(frase)
impr(t)