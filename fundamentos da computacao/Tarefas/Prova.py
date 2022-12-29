lista=[1,2,3,4,9,5,6,7,8]
troca=False
l=len(lista)-1
while troca==False:
    troca=True
    for i in range(l):
        if lista[i]>lista[i+1]:
            lista[i],lista[i+1]=lista[i+1],lista[i]
            troca=False
print(lista)
print()
