#exercicio 15
#Crie um programa que leia um numero N e imprima os N primeiros numeros primos

n=int(raw_input('digite n:'))
cont=0
qtdprimos=0
verifica=1

while qtdprimos<n:
	cont=0
	for i in range(1,verifica+1):
		if verifica%i==0:
			cont+=1
			
	if cont==2:
		print verifica
		qtdprimos+=1
	verifica+=1
