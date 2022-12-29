frase=input('Digite uma frase: ')
fraseI=''
for i in range(len(frase)-1,-1,-1):
    fraseI+=frase[i]
    print(fraseI)
