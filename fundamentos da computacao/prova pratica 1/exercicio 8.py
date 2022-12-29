#exercicio 8

qtdS=0
qtdN=0
porcentagemS=0
porcentagemN=0

while True:
    pergunta=str(raw_input('Voce esta satisfeito com o produto ? ("S" ou "N"):'))

    
    if pergunta=='S':
        qtdS=qtdS+1

    if pergunta=='N':
        qtdN=qtdN+1

    if pergunta=='F':
        break
        
    
    if pergunta!='S' and pergunta!='N' and pergunta!='F':
        
        print('voce nao digitou os valores corretamente, tente de novo')
        break
    

     
porcentagemS=100*float(qtdS)/float(qtdS+qtdN)
porcentagemN=100*float(qtdN)/float(qtdN+qtdS)

if pergunta=='S' or pergunta=='N' or pergunta=='F':  
    print('A porcentagem de pessoas satisfeitas com o produto e',porcentagemS)
    print('A porcentagem de pessoas nao satisfeitas com o produto e',porcentagemN)
    
