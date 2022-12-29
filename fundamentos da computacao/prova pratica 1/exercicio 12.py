#Exercicio 12

altura = 0
alta = 0
gigante = 0
qtd1 = 0
qtd2 = 0

while True:
    nome = str(raw_input('Digite seu nome:'))
    altura = float(raw_input('Digite sua altura:'))

    if altura > gigante:
        alta = gigante
        gigante = altura
        qtd2 = qtd1
        qtd1 = 1

    elif altura > alta and altura < gigante:
        alta = altura
        qtd2 = 1

    elif altura == gigante:
        qtd1 = qtd1 + 1

    elif altura == alta:
        qtd2 = qtd2 + 1


    if nome == 'maria':
        break

print('A quantidade de participantes com a maior altura e:', qtd1)
print('A quantidade de participantes com a segunda maior altura e:', qtd2)
