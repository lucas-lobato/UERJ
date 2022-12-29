#Gera uma data

from datetime import*
while True:
    try:
        dia=input('Digite o dia: ')
        if dia=='':break
        dia=int(dia)
        mes=int(input('digite o mes: '))
        ano=int(input('digite o ano: '))
        data=date(ano,mes,dia)
        print (data)
    except:
        print('data errada tente novamente')
