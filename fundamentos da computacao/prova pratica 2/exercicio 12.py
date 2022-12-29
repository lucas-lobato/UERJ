#exercicio 12

qtdjoao=0

while True:    

    nome = str(raw_input("Digite seu nome: ")).lower()

    if 'joao' in nome:
        qtdjoao+= 1

    if nome == '':
        break
        
print 'A quantidade de vezes que joao aparece e:',qtdjoao
