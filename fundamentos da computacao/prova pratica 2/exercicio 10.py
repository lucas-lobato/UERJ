#exercicio 10

vogais = ["a", "e", "i", "o", "u"]
nada = [' ']
qtdVogais= 0
qtdNada= 0

frase = str(raw_input("Digite uma frase: ")).lower()

for i in range (len(frase)):
	if frase[i] in vogais :
		qtdVogais += 1

	elif frase[i] in nada :
		qtdNada += 1

print 'A quantidade de vogais e:',qtdVogais, 'A quantidade de espaços em branco e:',qtdNada
