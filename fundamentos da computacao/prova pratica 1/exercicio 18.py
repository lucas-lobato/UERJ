#exercicio 18
#Crie um programa que imprima a soma dos n primeiros termos da série de Fibonnacci

num=0
t1=0
t2=1
cont=3
soma=0


print('--'*22)
print('Soma de n valores da sequencia de fibonacci')
print('--'*22)

n=int(raw_input('Escreva a quantidade de numeros da sequencia de Fibonnacci que deseja somar:'))
print(' {} {} '.format(t1,t2))
while cont<=n:
    t3=t1+t2
    print('{}'.format(t3))
    t1=t2
    t2=t3
    cont+=1
    soma=t1+t2+t3-1
    
print('A soma vale',soma)
