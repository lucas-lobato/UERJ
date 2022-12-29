#Criptografar mensagens

frase=input('Digite uma frase:')
fraseC=''
for i in range(0,len(frase)):
    letra=frase[i]
    cod=ord(letra)
    cod1=chr(cod+1)
    fraseC+=cod1
print(fraseC)
fraseD=chr(cod-1)
print(fraseD)