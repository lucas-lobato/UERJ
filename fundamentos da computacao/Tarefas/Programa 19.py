#imprimir a ultima palavra de uma frase

def pergunta():
    frase=input('Digite uma frase:').split()
    return frase

def impr(frase):
    palavra=frase[-1]
    print(palavra)

frase=pergunta()
impr(frase)