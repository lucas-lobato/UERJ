# recorrencia de uma plavra em uma frase

def le():
    frase=input('Digite uma frase:')
    palavra=input('Digite uma palavra:')
    return frase,palavra

def cont(frase,palavra):
    a=len(frase)
    b=len(palavra)
    contador=0
    for i in range(a):
        if frase[i:i+b]==palavra:
            contador+=1
    return contador

def impr(contador):
    print('A palavra',palavra,' aparece',str(contador),'veze(s) na frase')

frase,palavra=le()
contador=cont(frase,palavra)
impr(contador)