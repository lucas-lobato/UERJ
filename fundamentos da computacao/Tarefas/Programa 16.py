#Escreva programa que tenha uma função que receba um inteiro não-negativo n e imprima a soma dos n primeiros números
#primos. Por exemplo: Para n=3, resultado 10=2+3+5. Para n=7, resultado 58=2+3+5+7+11+13+17. Para n=100, resultado 24133

limite=int(input('Digite o numero de primos a serem somados:'))
numero = 2
c = 1
p = 0
print ("Primos: "),
while numero < limite:
    i = numero -1
    while i > 1:
        if numero % i == 0: break
        c += 1
        i -= 1
    else:
        print (numero),
        p += 1
    numero += 1
print(c)
print(p)
