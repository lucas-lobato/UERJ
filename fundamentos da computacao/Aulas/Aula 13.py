a=[]

def le(a):
    while True:
        x=input('Digite um nome:')
        if x=='':
            break
        a.append(x)
    return a

def impr(a):
    print(a)

a=le(a)
impr(a)