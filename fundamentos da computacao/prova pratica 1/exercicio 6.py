#exercicio 6

y=0

num=int(raw_input('Digite um numero:'))

for x in range (1,num):

    if num%x==0:
        y=y+1

if y>1:
    print('este numero nao é primo')
else:
    print('este numero é primo')
    
