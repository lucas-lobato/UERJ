#exercicio 2

a=1
somaI=0
somay=0
media=0
x=0
y=0
z=0

while a!=0:
    a=int(raw_input('digite um numero:'))

    if a%2==1:
         x=x+1

    elif a!=0:
        y=y+1
        somay=somay+a

if y!=0:
    media=somay/y

print('A quantidade de numeros pares e:',y)
print('A quantiade de numeros impares e:',x)
print('A media dos numeros pares e:',media)
    


    
    
    
