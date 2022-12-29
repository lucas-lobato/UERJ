s=0
contador=0
n=int(input('Digite n:'))
for i in range(n):
    x=float(input('Digite um valor:'))
    if x>5:
        s+=x
        contador+=1
        print(contador)

if contador==0:
    print('nao existem valores maiores que 5')
else:
    media=s/contador

print('O somatorio é:',s)
print('A media dos valores maiores que 5 é:', media)