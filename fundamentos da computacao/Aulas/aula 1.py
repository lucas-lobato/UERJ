def le():
    a=float(input('Digite o primeiro valor: '))
    b=float(input('Digite o segundo valor: '))
    c=float(input('Digite o terceiro valor: '))
    return a,b,c

def media(a,b,c):
    m=(a*3+b*3+c*4)/10
    return m

def impr(media):
    print (media)
    return

x,y,z=le()
m=media(x,y,z)
impr(m)