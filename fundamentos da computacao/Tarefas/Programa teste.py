from time import*
from random import*
t0=clock()
for i in range(0,1000):
    x=randint(0,100)
    print(i)
ti=clock()
print(ti-t0)
