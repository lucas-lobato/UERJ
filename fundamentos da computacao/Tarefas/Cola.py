# ler uma martiz de mxm de valore reais
# determinar a soma da diag principal menos diag secundaria
# le a matriz
m = int(input('Digite m '))  # qtd linhas e colunas
a = [None] * m  # cria uma linha com m valores
for i in range(m):
    a[i] = [None] * m  # para cada m cria uma coluna com n valores
    for j in range(m):
        a[i][j] = float(input('Digite o  termo A[' + str(i + 1) + ',' + str(j + 1) + '] --> '))

# calcula a diferença
# dp -diagonal principal
# ds - diagonal secundária
dp = ds = 0
for i in range(0, m):
    dp += a[i][i]
    ds += a[m - (i + 1)][i]
s = dp - ds

# imprime
print('\n{:*^30}\n'.format('Matriz Lida'))
for i in range(m):
    for j in range(m):
        print('{:>10.2f}'.format(a[i][j]), end=' ')
    print()
print('\n{:*^30}\n'.format('Diferença escalar'))
print(('{:>10.2f}').format(s))