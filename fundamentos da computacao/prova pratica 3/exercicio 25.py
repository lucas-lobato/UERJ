#exercicio 25

def ler():
    try:
        frase=str(raw_input('Digite uma frase: ')).split()
        frase2=frase[-1]
        return frase2

    except Exception:
        return ler()

def imprimir(frase2):
    print (frase2)

frase2 = ler()
imprimir(frase2)
