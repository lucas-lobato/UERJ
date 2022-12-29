#ler uma matriz quadrada mXn elemntos e criar uma matriz de mesma dimensão onde os valores da segunda matriz
#sao os valores da primeira sobre o maior valor da linha

a=[[1,2,3],[4,5,6],[7,8,9]]
b=[None]*3
for i in range(3):
    b[i]=[None]*3
    x=max(a[i])
    for j in range(3):
        b[i][j]=a[i][j]//x
print(b)