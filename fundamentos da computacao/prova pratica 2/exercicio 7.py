#exercicio 7

def mensagem():
    x=raw_input('Insira sua mensagem: ')
    return x
def cripto(x):
    mcrip=''
    for i in range(len(x)):
        y=ord(x[i])+2
        yi=chr(y)
        mcrip+=yi
    return mcrip
def descrip(mcrip):
    mdescrip=''
    for i in range(len(mcrip)):
        z=ord(mcrip[i])-2
        zi=chr(z)
        mdescrip+=zi
    return mdescrip
def impr(cripto,descrip):
    print 'A mensagem criptografa eh: {:1s}\n A mensgem descriptografada eh: {:1s}'.format(cripto,descrip)
#main
x=mensagem()
mcrip=cripto(x)
mdescrip=descrip(mcrip)
impr(mcrip,mdescrip)
