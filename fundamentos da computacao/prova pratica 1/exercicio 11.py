#exercicio 11

gordo=0
magro=999999999999999999999
ident=0
peso=0
identG=0
identM=0


print('Caso haja dois pesos iguais, o programa ira considerar o primeiro a ser inserido')

for x in range (3):
    ident=int(raw_input('Digite u numero da identificacao do boi:'))
    peso=float(raw_input('Digite o peso,em arroba, do boi:'))

    if peso <=0:
        print('Achou que ia zerar a minha prova ? ACHOU ERRADO OTARIO !!!')
        break
        
    if peso>gordo:
        gordo=peso
        identG=ident

    if peso<magro:
        magro=peso
        identM=ident    
        
if peso >0:
    print('O boi',identG,'e o mais pesado, pesando:', gordo,'arrobas')
    print('O boi',identM,'e o mais magro, pesando:', magro,'arrobas')


    
    

