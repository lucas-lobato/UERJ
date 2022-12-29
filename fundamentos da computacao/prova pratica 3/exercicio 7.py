#exercicio 7

X=['a','b','c','d']
Y=['0','1','2','3']
Z=[]

def soma(X,Y):
    try:
        S=X[0]+Y[0],X[1]+Y[1],X[2]+Y[2],X[3]+Y[3]
        Z.append(S)
    except Exception:
        print('Erro, digite de novo')
    return S


S=soma(X,Y)

print(X)
print('')
print(Y)
print('')
print(S)