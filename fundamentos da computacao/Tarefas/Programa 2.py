#FAÇA UM PROGRAMA QUE FAÇA 5 PERGUNTAS VERIFICANDO SE O INDIVIDUO É INOCENTE,SUSPEITO, CUMPLICE OU ASSASSINO.
#0 PONTOS = INOCENTE, 2 PONTO = SUSPEITO, DE 3 A 4 PONTOS = CUMPLICE E 5 PONTOS = ASSASSINO

def perguntas():
    print('Responda as perguntas de maneira afirmativa ou negativa(sim/nao')
    a=input('Voce telefonou para a vítima ?: ').upper()
    b=input('Voce esteve no local do crime ?: ').upper()
    c=input('Voce morava ou mora perto da vitima ?: ').upper()
    d=input('Voce devia algum dinheiro para a vitima ?: ').upper()
    e=input('Voce ja trabalhou com a vitima ?: ').upper()
    return a,b,c,d,e

def score(a,b,c,d,e):
    pontos=0
    if a=='SIM':
        pontos=pontos+1
    if b=='SIM':
        pontos=pontos+1
    if c=='SIM':
        pontos=pontos+1
    if d=='SIM':
        pontos=pontos+1
    if e=='SIM':
        pontos=pontos+1
    return pontos

def impr(pontos):
    if pontos==2:
        print('Voce é suspeito(a)')
    if pontos > 2 and pontos <5:
        print('Voce é cumplice')
    if pontos==5:
        print('Voce é o assassino(a)')
    else:
        print('Voce é inocente')

a,b,c,d,e=perguntas()
pontos=score(a,b,c,d,e)
impr(pontos)
