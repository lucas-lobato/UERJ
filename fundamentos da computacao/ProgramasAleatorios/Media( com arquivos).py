#Digitar n numeros e mostrar a media entre eles (usando o conteudo de arquivo)

arq=open('arp.txt','w')
while True:
    n=input('Digite um numero: ')
    if n=='':
        break
    arq.write(n+'\n')
arq.close()
arq=open('arp.txt','r')
soma=0
n=0

for i in arq:
    n+=1
    soma+=float(i)
print (soma/n)