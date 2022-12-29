#Media salarial e maior salario

soma=0
mediaM=0
mediaF=0
somaM=0
somaF=0
i=0
k=0
j=0
r=0

print('Programa Governamental')
n=int(input('informe o numero de participantes:'))

#parte da repeti��o
for i in range(n):
    a=int(input('Informe a sua idade:'))
    b=str(input('Informe seu sexo (M ou F):'))
    c=int(input('Informe seu sal�rio:'))
    
    if a<30 and a>0:
        if c>r:
            r=c
        

    
#parte da escolha
    if b=='m':
        k=k+1
        somaM=somaM+c

    elif b=='f':
        j=j+1
        somaF=somaF+c


#medias
if k>0:
    mediaM=somaM/k
if j>0:
    mediaF=somaF/j

        
print('A media salarial dos homens e:',mediaM)
print('A media salarial das mulheres e:',mediaF)
print('O maior salario e:',r)