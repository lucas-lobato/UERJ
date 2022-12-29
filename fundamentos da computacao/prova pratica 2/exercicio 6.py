#exercicio 6

vogais = ["a", "e", "i", "o", "u"]
consoantes = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'y', 'z']
qtdVogais= 0
qtdConsoantes= 0

frase = str(raw_input("Digite uma frase: ")).lower()

for i in range (len(frase)):
	if frase[i] in vogais :
		qtdVogais += 1

	elif frase[i] in consoantes :
		qtdConsoantes += 1

print 'A quantidade de vogais e:',qtdVogais, 'A quantidade de consoantes e:',qtdConsoantes
