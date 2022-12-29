#Elabore um programa para ler uma quantidade indeterminada de valores e calcular a sua media

def pergunta():
    try:
        cont=0
        soma=0
        while True:
            x=float(input('Digite um numero:'))
            if x==0:
                break
            if x!='':
                soma+=x
                cont+=1
    except Exception:
        print('Erro, valor invalido')
    return soma,cont

def media(soma,cont):
    try:
        if cont==0:
            raise
        media=soma/cont
        print('A media dos valores digitados e {}'.format(media))
    except:
        print('Nao foi digitado nenhum valor')

soma,cont=pergunta()
media(soma,cont)

