#exercicio 16

contador=0

p1=str(raw_input('Telefonou para a vitima ? (S ou N)'))
p2=str(raw_input('Esteve no local do crime? (S ou N)'))
p3=str(raw_input('Mora perto da vitima? (S ou N)'))
p4=str(raw_input('Devia para a vitima? (S ou N)'))
p5=str(raw_input('Ja trabalhou com a vitima? (S ou N)'))

if p1 == 'S':
    contador=contador+1
if p2 == 'S':
    contador=contador+1
if p3 == 'S':
    contador=contador+1
if p4 == 'S':
    contador=contador+1
if p5 == 'S':
    contador=contador+1

if contador<=1:
    print('voce e inocente')
if contador ==2:
    print('suspeito')
if contador>2 and contador<5:
    print('cumplice')
if contador == 5:
    print('ASSASSINOOOOOOO')



    
