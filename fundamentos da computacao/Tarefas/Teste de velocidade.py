import date
from random import*
inicio=date.date()
for i in range(0,100000):
    x=randint(0,100)
    print(i)
fim=date.date()
print(fim-inicio)