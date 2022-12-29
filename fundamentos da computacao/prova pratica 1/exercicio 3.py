#exercicio 3


preco=0
maiorP=0
nome=''


while True:
	
	itens=str(raw_input('Digite o nome do produto:'))
	preco=float(raw_input('Informe o preco do produto:'))
	
	if preco>maiorP:
		maiorP=preco
		nome=itens
	
	if itens=='XXX':
		break


print('O pruduto mais caro e o:',nome)