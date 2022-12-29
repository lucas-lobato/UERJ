# ler uma martiz de mxn de valores reais
# determinar a soma da 1 linha com a 2 coluna
# exibir os dados sob a forma de tabela
def ler():
    m = int(input('Digite m:'))  # qtd linhas
    n = int(input('Digite n:'))  # qtd colunas
    a = [None] * m  # cria uma linha com m valores
    for i in range(m):
        a[i] = [None] * n  # para cada m cria uma coluna com n valores
        for j in range(n):
            a[i][j] = float(input('Digite o  termo A[' + str(i + 1) + ',' + str(j + 1) + '] --> '))
    return a, m, n


def soma(a, n):
    s = []
    for i in range(0, n):
        x = a[0][i] + a[i][0]
        s.append(x)
    return s


def impr(a, s, m, n):
    print('{:>30}'.format('\nMatriz Lida\n'))
    for i in range(m):
        for j in range(n):
            print('{:>10.2f}'.format(a[i][j]), end=' ')
        print()
    print('{:310}'.format('\nVetor Soma\n'))
    for i in range(n):
        print('{:>10.2f}'.format(s[i]), end=' ')
    return


a, m, n = ler()
s = soma(a, n)
impr(a, s, m, n)