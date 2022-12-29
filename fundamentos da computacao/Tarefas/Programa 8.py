#Faça um programa que calcule as raízes de uma equação do segundo grau, na forma ax2 + bx + c. O programa deverá pedir
#os valores de a, b e c e fazer as consistências, informando ao usuário nas seguintes situações:
#Se o usuário informar o valor de A igual a zero, a equação não é do segundo grau e o programa não deve fazer pedir os
#demais valores, sendo encerrado;
#Se o delta calculado for negativo, a equação não possui raizes reais. Informe ao usuário e encerre o programa;
#Se o delta calculado for igual a zero a equação possui apenas uma raiz real; informe-a ao usuário;
#Se o delta for positivo, a equação possui duas raiz reais; informe-as ao usuário;

def variaveis():
    try:
        a=float(input('Digite o valor de a:'))
        if a==0:
            return a
        b=float(input('Digite o valor de b:'))
        c=float(input('Digite o valor de c:'))
    except Exception:
        print('Erro')
    return a,b,c

def calculo(a,b,c):
    delta=(b*b)-(4*a*c)
    if delta < 0:
        print('A equaçao nao possui raizes reais (delta negativo)')
        variaveis()
    elif delta==0:
        print('A equaçao possui apenas uma raiz (delta =0)')
    elif delta > 0:
        print('A equaçao possui duas raizes (delta > 0)')
    raizP=(-b+(delta**1/2)/(2*a))
    raizN=(-b-(delta**1/2))/(2*a)
    return raizP,raizN

def impr(raizP,raizN):
    print('Raiz positiva:',raizN)
    print('Raiz negativa',raizP)

a,b,c=variaveis()
raizP,raizN=calculo(a,b,c)
impr(raizP,raizN)

