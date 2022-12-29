import networkx as nx
import matplotlib.pyplot as plt


def menu():
    print('********** MENU **********\n')
    print('Opção (a): Criar novo grafo')
    print('Opção (b): Carregar um grafo existente')
    print('Opção (c): Criar um grafo especial')
    resposta = input('--> ')
    if resposta == 'a' or resposta == 'A':
        menu_opcao_a()
    elif resposta == 'b' or resposta == 'B':
        menu_opcao_b()
    elif resposta == 'c' or resposta == 'C':
        menu_opcao_c()
    else:
        print('Opção inválida, tente de novo...')
        return menu()


def menu_opcao_a():
    n, m = pega_entradas()
    matriz = monta_matriz(n)
    matriz, nome, e = coloca_arestas(matriz, n, m)
    grava_matriz(matriz, nome, n)
    printa_matriz(matriz, n)
    mostra_grafo(n, e)

def menu_opcao_b():
    try:
        print('Digite o nome do grafo a ser mostrado:')
        nome = input('--> ')
        nome_aux = nome + '.txt'
        arquivo = open(nome_aux, 'r')
        matriz = arquivo.read().splitlines()
        matriz_tratada = trata_matriz(matriz)
        arquivo.close()
        n = pega_n(matriz_tratada)
        printa_matriz(matriz_tratada,n)
        e = pega_arestas(matriz_tratada, n)
        mostra_grafo(n,e)

    except FileNotFoundError:
        print('Erro ao tentar abrir o arquivo, tente novamente...')
        return menu_opcao_b()

def menu_opcao_c():
    print("Digite o grafo a ser criado")
    print("1 - Completo")
    print("2 - Bipartido completo")
    print("3 - Estrela")
    print("4 - Caminho")
    print("5 - Ciclo")
    print("6 - Roda")
    print("7 - Cubo")
    numero = input('--> ')
    if numero == '1':
        cria_grafo_completo()
    elif numero == '2':
        cria_grafo_bipartido_completo()
    elif numero == '3':
        cria_grafo_estrela()
    elif numero == '4':
        cria_grafo_caminho()
    elif numero == '5':
        cria_grafo_ciclo()
    elif numero == '6':
        cria_grafo_roda()
    elif numero == '7':
        cria_grafo_cubo()
    else:
        print("erro, tente de novo...")
        return menu_opcao_c()
    
def pega_entradas():
    n = int(input('Digite o número de vertices: '))
    m = int(input('Digite o número de arestas: '))
    return n,m

def monta_matriz(n):
    matriz = [None] * n
    for i in range(n):
        matriz[i] = [None] * n
        for j in range(n):
            matriz[i][j] = 0
    return matriz

def printa_matriz(matriz, n):
    print('{:>30}'.format('\nMatriz Lida\n'))
    vertices = []
    for j in range(n):
        vertices.append(j)
    print('   ',*vertices, sep="  ")
    for i in range(n):
        print(f'{i} |', *matriz[i], '|', sep="  ")

def mostra_grafo(n, e):
    label = []
    for j in range(n):
        label.append(j)
    grafo = nx.Graph()
    for i in range(n):
        grafo.add_node(label[i])
    for k in e:
        grafo.add_edge((label[k[0]]), label[k[1]])
    nx.draw(grafo, with_labels=True)
    plt.show()

def coloca_arestas(matriz, n, m):
    e = []
    for i in range(n):
        for j in range(n):
            if i != j and m > 0 and j > i:
                print(f'\nExiste aresta {i} --- {j} ?')
                resposta = input('---> ')
                if resposta == 'SIM':
                    matriz[i][j] = '1'
                    matriz[j][i] = '1'
                    m = m - 1
                    e.append([i, j])

    nome = input('Qual será o nome do grafo?')
    return matriz, nome, e

def grava_matriz(matriz, nome, n):
    nome_arq = nome + '.txt'
    f = open(nome_arq, mode='w', encoding='utf-8')
    for i in range(n):
        for j in range(n):
            f.write(str(matriz[i][j]) + '  ')
        f.write('\n')
    f.close()

def pega_arestas(matriz, n):
    e = []
    for i in range(n):
        for j in range(n):
            if i != j and j > i:
                if matriz[i][j] == '1':
                    e.append([i, j])
    return e

def pega_n(matriz):
    aux = matriz[0]
    n = 0
    for i in aux:
        if i == '1' or i == '0':
            n = n + 1
    return n

def trata_matriz(matriz):
    matriz_tratada = []
    for i in matriz:
        aux = ''
        for j in i:
            if j == '1' or j == '0':
                aux = aux + j
        matriz_tratada.append(aux)
    return matriz_tratada

def cria_grafo_completo():
    n = int(input("Digite n: "))
    if n < 3:
        print("n deve ser maior que 2, tente de novo...")
        return cria_grafo_completo()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    aux = 0
    for j in range(n):
        for k in range(n - aux):
            k = k + aux
            if j != k:
                e.append([j, k])
        aux += 1

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "completo$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_bipartido_completo():
    n = int(input("Digite n: "))
    if n < 4:
        print("n deve ser maior que 3, tente de novo...")
        return cria_grafo_bipartido_completo()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    for j in range(n):
        for k in range(n):
            if j < (n / 2):
                if k >= (n - 1) / 2:
                    e.append([j, k])

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "bipartidocompleto$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_estrela():
    n = int(input("Digite n: "))
    if n < 3:
        print("n deve ser maior que 2, tente de novo...")
        return cria_grafo_estrela()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    for j in range(n):
        if j > 0:
            e.append([0, j])

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "estrela$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_caminho():
    n = int(input("Digite n: "))
    if n < 2:
        print("n deve ser maior que 1, tente de novo...")
        return cria_grafo_caminho()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    for j in range(n - 1):
        for k in range(n - 1):
            if j == k:
                e.append([j, k + 1])

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "caminho$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_ciclo():
    n = int(input("Digite n: "))
    if n < 3:
        print("n deve ser maior que 2, tente de novo...")
        return cria_grafo_ciclo()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    for j in range(n - 1):
        for k in range(n - 1):
            if j == k:
                e.append([j, k + 1])
        if j == n - 2:
            e.append([0, j + 1])

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "ciclo$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_roda():
    n = int(input("Digite n: "))
    n = n - 1
    if n < 2:
        print("n deve ser maior que 2, tente de novo...")
        return cria_grafo_roda()
    m = n + 1
    v = []
    for i in range(n + 1):
        v.append(i)
    e = []
    for j in range(n - 1):
        for k in range(n - 1):
            if j == k:
                e.append([j, k + 1])
        if j == n - 2:
            e.append([0, j + 1])

    for element in range(n):
        e.append([n, element])

    n = n + 1
    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "roda$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)

def cria_grafo_cubo():
    n = int(input("Digite n: "))
    n = 2 ** n
    if n < 2:
        print("n deve ser maior que 1, tente de novo...")
        return cria_grafo_cubo()
    m = n
    v = []
    for i in range(n):
        v.append(i)
    e = []
    for j in range(n - 1):
        for k in range(n - 1):
            if j == k:
                e.append([j, k + 1])

    for cont in range((n // 2) - 1):
        e.append([cont, n - cont - 1])

    if n > 4:
        for cont2 in range(0, n - 1, 4):
            e.append([cont2, cont2 + 3])

    if n > 8:
        for cont3 in range(0, n - 1, 8):
            e.append([cont3, cont3 + 7])

    M = [None] * n
    for x in range(n):
        M[x] = [None] * m
        for y in range(m):
            M[x][y] = 0
            for z in e:
                if (z[0] == v[x] and z[1] == v[y]) or (z[0] == v[y] and z[1] == v[x]):
                    M[x][y] = 1

    g = (v, e)
    printa_matriz(M, n)
    g_name = "cubo$n" + str(n) + "$"
    grava_matriz(M, g_name, n)
    mostra_grafo(n, e)


menu()