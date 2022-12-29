#exercicio 13

soma=0
media=0
digitosNome=0
nParticipantes=0
idade=0

print('Para finalizar a contagem de pessoas digite F no nome')

while True:
    nome=str(raw_input('Digite seu nome:'))
    if nome=='F' or nome=='f':
        break
    idade=int(raw_input('Digite sua idade:'))

    nParticipantes=nParticipantes +idade-idade+1
    soma=idade+soma
    media=soma/nParticipantes
    if digitosNome<len(nome):
        #Caso o duas pessoas tenham o nome com o mesmo tamanho, será considerada a primeira pessoa
        maiorNome=nome
        digitosNome=len(nome)



print('O maior nome digitado foi', maiorNome)
print('A media das idades e', media)
              
    

