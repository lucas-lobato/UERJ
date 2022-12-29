#exercicio 1

def le():
    calenda=[]
    while True:
        #le o dia e valida >0 e <30
        while True:
            try:
                dia=raw_input('Digite o dia ')
                #flag dia vazio
                if dia=='':
                    
                    return calenda# sai do while do dia
                    
            # converte para inteiro
                diac=int(dia)
                if diac <1 or diac >30:
                    raise
                break
            except:
                print 'Dia invalido - digite novamente'
    # le o mes e valida >0 e <12
        while True:
            #if dia=='':break
            try:
                mes=raw_input('Digite mes ')
                # converte para inteiro
                mesc=int(mes)
                if mesc <1 or mesc >12:
                    raise
                break
            except:
                print 'Mes invalido - digite novamente'
      # le ano e valida >=1900 e <=2018
    
        while True:
            #if dia=='':break
            try:
                ano=raw_input('Digite ano ')
                # converte para inteiro
                anoc=int(ano)
                if anoc <1900 or anoc >2018:
                    raise
                break
            except:
                print 'Ano invalido - digite novamente'
        if dia=='':break # sai do while geral
        data=ano+mes+dia # inverte a data
        calenda.append(data) 
    
def classi(calenda):
    n=len(calenda)
    # bubble sort
    troca = True
    n = n-1
    while n>0 and troca:
        troca = False
        for i in range(n):
            if calenda[i] > calenda[i+1]:
                calenda[i],calenda[i+1] = calenda[i+1],calenda[i]
                troca = True
        n -= 1 
    return calenda
def impr(calenda):
    print 'Datas ordenadas'
    for j in calenda:
        ano=j[0:4]
        mes=j[4:6]
        dia=j[6:8]
        print '{:1s} / {:1s}/{:1s}'.format(dia,mes,ano)
    return    
calenda=le() 
calenda=classi(calenda)
impr(calenda)