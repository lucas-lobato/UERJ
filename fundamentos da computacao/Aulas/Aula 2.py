# FACTORIAL() -> CALCULA O FATORIAL DO NUMERO
# ROUND -> ARREDONDA O NUMERO
# RANDOM -> GERA NUMEROS ALEATORIOS
# SHUFFLE() -> EMBARALHA OS VALORES DE UMA LISTA
# CHOICE () -> ESCOLHE UM ELEMENTO DE UMA LISTA ALEATORIAMENTE
# LIST(RANGE()) -> GERA UMA LISTA DE TAMANHO n DETERMINADO NO RANGE
from math import*
from random import*

a=list(range(0,100))
b=choice(a)
c=sample(a,5)
print (a)
print ('')
print (b)
print ('')
print (c)