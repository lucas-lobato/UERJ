#consertar o numero de telefone

numero=[]

def pergunta():
    num=input('Digite um numero de telefone:')
    return num

def consertar(num):
    if (len(num))==7:
        numN='3'+num
    else:
        numN=num
    return numN

def trac(numN):
    if (len(numN))==8:
        numN=numN[0]+numN[1]+numN[2]+numN[3]+'-'+numN[4]+numN[5]+numN[6]+numN[7]
    return numN

def impr(numN):
    print(numN)

num=pergunta()
numN=consertar(num)
numN=trac(numN)
impr(numN)
