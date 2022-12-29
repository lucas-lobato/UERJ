# ler um uma qtd indeterminada de nomes e data de nascimento
# exibir em duas listas os valores um por linha
# ordenar por data
def le():
    lista = []
    while True:
        nom=input('Nome:')
        if nom == '': break
        idade =input('Data de nascimento:')
        nome = nom + ',' + idade
        lista.append(nome)
        lista.sort()
    return lista


def descon(lista):
    nome = []
    idade = []
    l = []
    for i in lista:
        l = i.split(',')
        nome.append(l[0])
        idade.append(l[1])

    return nome, idade


def impr(nome, idade):
    n = len(nome)
    # cabeçalho
    print('\n{:*^30}\n'.format('Valores lidos'))
    print('{:20s}{:10s}\n'.format('Nome', 'Idade'))
    for j in range(n):
        print('{:<20s} {:<10s}'.format(nome[j], idade[j]))
    return


# programa principal
l = le()
n, i = descon(l)
impr(n, i)
