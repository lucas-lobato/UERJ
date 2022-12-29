#exercicio 6

#O programa deve ser modularizado e exibido com mensagens indicativas Ler uma matriz quadrada de m elementos reais.
#  Determinar a soma dos termos da diagonal principal menos a soma dos termos de diagonal secundária.
#  Exibir o resultado com duas casas decimais. Usar Try para validar os dados


from random import*

A=[]
B=[]



def matrizes():
    try:
        x=int(input('Digite a quantidade de colunas: '))
        y=int(input('Digite a quantidade de linhas da matriz: '))
        A=[]
        for i in range(x):
            linha=[]
            for j in range(y):
                f=randint(0,9)
                linha.append(f)
            A.append(linha)

    except Exception:
        print('erro')

    return A,y

matrizes()
print(A)