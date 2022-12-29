#palindromo


def pergunta():
    frase = input("Digite uma frase ").upper().replace(" ", "")
    return frase

def verificar(frase):
    if frase == frase[::-1]:
        print("A frase é um palíndromo")
    else:
        print('A frase nao é um palindromo')

frase=pergunta()
verificar(frase)