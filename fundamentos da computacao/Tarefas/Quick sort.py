# leitura dos dados
a = []
while True:
    x = input('Digite um numero ')
    if x == '': break
    a.append(float(x))

# ordena
troca = True
n = len(a) - 1
while n > 0 and troca:
    troca = False
    for i in range(n):
        if a[i] > a[i + 1]:
            a[i], a[i + 1] = a[i + 1], a[i]
            troca = True
    n -= 1
# imprime valores ordenados

print('{:>30}'.format('\nValores ordenados\n'))
for i in a:
    print('{:5.2f}'.format(i), end=' ')