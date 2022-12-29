#exercicio 4

nomes=[]

def encher():
    try:
        while True:
            nome=input('Digite um nome: ')

            if nome =='':
                break
            nomes.append(nome)

        print('A lista tem',len(nomes), 'nomes')

        for i in nomes:
            print(i)

    except Exception:
        print('erro')

    nomes.sort()

    return nomes

def procurar(nomes):

    nomep=input('Digite o nome a procurar: ')
    inicio=0
    fim=len(nomes)-1
    achei=False

    while inicio<=fim:

        meio=(inicio+fim)//2

        if nomes[meio]==nomep:
            achei=True
            break

        elif nomep>nomes[meio]:
            inicio=meio+1

        else:
            fim=meio-1

    if achei:
        print('Achei')

    else:
        print('Nao achei')

    return

nomes=encher()
procurar(nomes)






