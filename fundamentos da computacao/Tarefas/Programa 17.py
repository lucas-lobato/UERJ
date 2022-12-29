#Dada uma frase (sem espaços em branco), crie programa que tenha uma função que retorne o maior segmento consecutivo que
#compõe a frase. Exemplo: O maior segmento consecutivo da frase ’AAAAAbbbbbcccccccCCCDDDDDddd’ ´e ’ccccccc’.


lista=[]

def le():
    frase=input('Digite uma frase:')
    return frase

def soma(frase):
    a=len(frase)
    resposta=''
    for i in range(0,a-1):
        div=frase[i]!=frase[i+1]
        frase2=frase.split(div)
        lista.append(frase2)
        resposta=max(lista)


    return resposta

def impr(resposta):
    print('existem',resposta,'segmentos na frase')

frase=le()
resposta=soma(frase)
impr(resposta)