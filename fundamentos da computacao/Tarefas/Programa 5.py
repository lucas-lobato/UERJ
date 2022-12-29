#As Organizações Tabajara resolveram dar um aumento de salário aos seus colaboradores e lhe contraram para desenvolver o
#programa que calculará os reajustes.
#Faça um programa que recebe o salário de um colaborador e o reajuste segundo o seguinte critério, baseado no salário atual:
#salários até R$ 280,00 (incluindo) : aumento de 20%
#salários entre R$ 280,00 e R$ 700,00 : aumento de 15%
#salários entre R$ 700,00 e R$ 1500,00 : aumento de 10%
#salários de R$ 1500,00 em diante : aumento de 5% Após o aumento ser realizado, informe na tela:
#o salário antes do reajuste;
#o percentual de aumento aplicado;
#o valor do aumento;
#o novo salário, após o aumento.

def pergunta():
    salario=float(input('Digite o seu salario:'))
    return salario

def reajuste(salario):
    if salario == 280 or salario <280:
        salario2=(salario*1.20)
        percentual=20
    elif salario >280 and salario ==700:
        salario2=(salario*1.15)
        percentual=15
    elif salario >700 and salario ==1500:
        salario2=(salario*1.10)
        percentual=10
    else:
        salario2=(salario*1.05)
        percentual=5
    aumento=salario2-salario

    return salario2,aumento,percentual

def impr(salario,salario2,aumento,percentual):
    print('seu salario antes do aumento era:',salario)
    print('Seu salario depois do aumento é:',salario2)
    print('Voce recebeu um aumento de',aumento)
    print('O percentual aplicado foi de',percentual,'porcento')

salario=pergunta()
salario2,aumento,percentual=reajuste(salario)
impr(salario,salario2,aumento,percentual)


