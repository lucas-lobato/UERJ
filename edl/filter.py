l = ['banana','maca','laranja']
f = 'banana'
i = 0

def ffilter(f,l,i):
    aux = l
    if i >= len(aux):
        return aux
    if aux[i] != f:
        del aux[i]
        return ffilter(f,aux,i)
    else:
        return ffilter(f,aux,i+1)

print(ffilter(f,l,i))