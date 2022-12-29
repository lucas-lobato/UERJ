def ler():
    try:
        arq=open('arq.txt','a')
    except:
        arq=open('arq.txt','w')
    try:
        numeros=[]
        while True:
            numeros=input('Digite um numero:')
