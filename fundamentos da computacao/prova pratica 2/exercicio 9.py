#exercicio 9

qtdVogais=0

frase=str(raw_input('Digite uma frase: ')).upper().split()
palavra=frase[0]

if 'A' in palavra:
    qtdVogais=qtdVogais+1
if 'E' in palavra:
    qtdVogais=qtdVogais+1
if 'I' in palavra:
    qtdVogais=qtdVogais+1
if 'O' in palavra:
    qtdVogais=qtdVogais+1
if 'U' in palavra:
    qtdVogais=qtdVogais+1
    
print (qtdVogais)
