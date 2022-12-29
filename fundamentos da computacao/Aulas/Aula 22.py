a=[]
b=[]

for i in range(6):
    x=int(input('Digite um valor:'))
    a.append(x)
for i in range(6):
    if (i+1) %2==0:
        z=a[i]*2
    else:
        z=a[i]*3
    b.append(z)
for i in a:
    print(i)
print('\n')
for i in b:
    print(i)