#Faça um programa que leia 2 strings e informe o conteúdo delas seguido do seu comprimento. Informe também se as duas
#strings possuem o mesmo comprimento e são iguais ou diferentes no conteúdo.
#Compara duas strings
#String 1: Brasil Hexa 2006
#String 2: Brasil! Hexa 2006!
#Tamanho de "Brasil Hexa 2006": 16 caracteres
#Tamanho de "Brasil! Hexa 2006!": 18 caracteres
#As duas strings são de tamanhos diferentes.
#As duas strings possuem conteúdo diferente.

def perguntas():
    a=str(input('Digite uma frase:'))
    b=str(input('Digite outra frase:'))
    return a,b

def analise(a,b):
    print('Tamanho de',a,'é:',(len(a)))
    print('Tamanho de', b, 'é:', (len(b)))

    if a==b:
        print('As frases possuem o mesmo conteudo')
    else:
        print('As frases nao possuem o mesmo conteudo')


def analise2(a,b):
    if len(a)==len(b):
        print('As frases possuem o mesmo tamanho')
    else:
        print('As frases nao possuem o mesmo tamanho')

a,b=perguntas()
analise(a,b)
analise2(a,b)
