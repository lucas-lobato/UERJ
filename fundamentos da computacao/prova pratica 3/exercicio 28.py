def le():
    frases = ''
    while True:
        try:
            frase = raw_input('Digite uma frase: ')
            for i in range(len(frase)):
                if frase[i] != ' ' and frase[i] != ',':
                    frases += frase[i]
            if frases.isalpha() == False:
                frases = ''
                raise
            a = frase.split()
            b = len(a) - 1
            c = a[b]
            break
        except:
            print 'Somente letras'
    return c
def impr(c):
    print c
    return
#main
c = le()
impr(c)
