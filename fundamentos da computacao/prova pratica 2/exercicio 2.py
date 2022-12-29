#exercicio 2

frase = raw_input('digite uma frase:')
fraseSemEspacos = frase.replace(' ', '')
fraseTodaMinuscula = fraseSemEspacos.lower()
fraseInvertida = fraseTodaMinuscula[::-1]

if fraseInvertida == fraseTodaMinuscula:
    print 'Esta frase e um palindromo'
else:
    print 'Esta frase nao e um palindromo'
