def pergunta():
    a=float(input('Digite um valor:'))
    b=float(input('Digite mais um valor:'))
    c=float(input('Digite um ultimo valor:'))
    return a,b,c

def escolha(a,b,c):
    if a > b and a > c:
        print(a)
    elif b > a and b > c:
        print(b)
    elif c > b and c > a:
        print(c)
    elif a==b==c:
        print('Os tres valores sao iguais')

a,b,c=pergunta()
escolha(a,b,c)
