#exercicio 17

numero = int(raw_input('Digite a quantidade de numeros perfeitos desejados:'))
per=0
i = 0
x=1

for i in range(numero):
    while x!=per:
        x=x+1
        for divisor in range(1, x+1):
            if x % divisor == 0:
                per=per+divisor
        if x==per:
            i=i+1
            print(x)
           # print('os',numero,'primeiros numeros perfeitos sao:',per)
    
       
    
