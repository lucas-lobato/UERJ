#exercicio 10

idade=0
q=0
media=0
soma=0
p=0
soma2=0


q=int(raw_input('Informe o numero de pessoas:'))

for i in range(q):
    nome=str(raw_input('Digite seu nome:'))
    idade=int(raw_input('Digite sua idade:'))
    soma=soma+idade
    media=float(soma)/float(q)

    if idade>21 and idade<65:
        soma2=soma2+1

p=(float(100)/float(q))*float(soma2)
        

print('A idade media desse grupo e:',media)
print('A porcentagem de pessoas entre 21 e 65 anos e:',p,'%')

          
      
