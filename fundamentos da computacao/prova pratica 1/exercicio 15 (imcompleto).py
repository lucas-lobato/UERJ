#exercicio 15
#Crie um programa que leia um número N e imprima os N primeiros números primos.

y=0

num=int(raw_input('Digite um numero:'))

for x in range (num):

    if num%x==0:
        y=y+1

