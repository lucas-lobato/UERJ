from math import*
s=0
n=int(input('Digite n:'))
x=float(input('Digite um valor:'))
for i in range(1,n+1):
    s+=x**i/factorial(i)
print('A soma é:',s)