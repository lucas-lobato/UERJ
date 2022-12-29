from datetime import*

def ler():
    try:
        lista=[]
        while True:
            nome=input('Digite o nome:')
            if nome=='':break
            dia=int(input('Digite o dia de nascimento:'))
            mes = int(input('Digite o mes de nascimento:'))
            ano= int(input('Digite o ano de nascimento:'))
            data=date(ano,mes,dia)
            ident=(nome,data)
            lista.append(ident)
            print('-'*60)
    except:
        print('ooops, dado invalido, tente de novo...')
        return ler()
    return lista

def impr(lista):
    print('*'*60)
    print()
    print('Nomes gravados...')
    print()
    for i in lista:
        print(i)
    print()
    print('FIM')

lista=ler()
impr(lista)

