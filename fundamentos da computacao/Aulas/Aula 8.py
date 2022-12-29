s=k=0
while True:
    x=float(input('Digite um valor:'))
    if x<0:
        break
    s+=x
    k+=1

if k==0:
    print('erro')
else:
    media=s/k
    print('a media é:',media)
