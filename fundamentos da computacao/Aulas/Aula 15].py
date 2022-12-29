#ler 5 valores e derterminar quantos sao maores que a media

lista=[]
for i in range(5):
    soma=0
    cont=0
    n=float(input('Digite um numero:'))
    lista.append(n)
    soma+=i
    cont+=1
media=soma/cont

print(lista)
print(soma)
print(cont)
print(media)
for j in lista:
    if j>media:
        print(j)
