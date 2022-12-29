lista = [1,2,3,4,5,6,7,8,9,10]
f = 10

def fmap(f,l):
    for i in range(len(l)):
        l[i] = i*f
    return l

print(fmap(f,lista))