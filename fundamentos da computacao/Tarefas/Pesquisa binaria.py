# pesquisa binaria
nomes = []
# leitura dos nomes
while True:
    nom = input('Digite o nome ')
    if nom == '': break
    nomes.append(nom)

# ordena os nomes
nomes.sort()
# le nome a procurar
nproc = input('Digite o nome a procurar ')
i = 0  # inicio
f = len(nomes) - 1  # fim
achei = False
while i <= f and achei == False:
    m = (i + f) // 2  # posicao media
    if nproc == nomes[m]:
        achei = True
    elif nproc < nomes[m]:
        f = m - 1
    else:
        i = m + 1

# imprime o resultado
if achei:
    print('Nome {:1s} encontrado'.format(nproc))
else:
    print('Nome {:1s} não encontrado'.format(nproc))