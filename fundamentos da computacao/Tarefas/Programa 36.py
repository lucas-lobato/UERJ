def ler():
    try:
        lista=[]
        while True:
            nome=input('Digite o nome:')
            if nome=='':break
            elif nome.isalpha()==False:
                print('Erro no nome')
                raise
            sexo=input('Digite o sexo (M ou F):').upper()
            if sexo !='M' and sexo!='F':
                print('Erro no sexo :P')
                raise
            idade=int(input('Digite a idade:'))
            if idade <0 or idade >110:
                print('Erro na idade')
                raise
            ident=(nome+','+sexo+','+idade)
            lista.append(ident)

    except:
        print('Tente de novo...')
        return ler()
    return lista
def impr(lista):
    for i in lista:
        print(i)

lista=ler()
impr(lista)

