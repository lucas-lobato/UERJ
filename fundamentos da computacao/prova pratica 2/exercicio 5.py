#EXERCICIO 5

nome=str(raw_input('Digite seu nome:'))
idade=int(raw_input('Digite sua idade:'))
salario=float(raw_input('Digite seu salario:'))
sexo=str(raw_input('Digite seu sexo (M ou F):'))
estado=str(raw_input('Digite seu estado civil,(s,c,v,d):'))

if '0' in nome or '1' in nome or '2' in nome or '3' in nome or '4' in nome or '5' in nome or '6' in nome or '7' in nome or '8' in nome or '9' in nome:
    print('erro, voce nao digitou o nome corretamente, tente novamente')

elif idade<0 and idade>150:
    print('erro, voce digitou uma idade invalida, tente de novo')

elif salario<0:
    print('erro, voce digitou um salario invalido, tente novamente')

elif sexo!='m' and sexo!='f':
    print('erro, voce digitou um valor invalido, tente de novo')

elif estado!='s' and estado!='c' and estado!='v' and estado!='d':
    print('erro, voce digitou um estado civil invalido, tente novamente')

else:
    print('Fim do programa sem erros')
