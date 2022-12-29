#Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. Calcule e mostre o
# total do seu salário no referido mês, sabendo-se que são descontados 11% para o Imposto de Renda, 8% para o INSS e
# 5% para o sindicato, faça um programa que nos dê:

#salário bruto.
#quanto pagou ao INSS.
#quanto pagou ao sindicato.
#o salário líquido.
#calcule os descontos e o salário líquido, conforme a tabela abaixo:
#+ Salário Bruto : R$
#- IR (11%) : R$
#- INSS (8%) : R$
#- Sindicato ( 5%) : R$
#= Salário Liquido : R$

def perguntas():
    salario=float(input('Digite quanto voce ganha por hora: '))
    horas=float(input('Digite a quantidade de horas trabalhadas no mes: '))
    return salario,horas

def sal(salario,horas):
    salbruto=(salario*horas)
    imposto=(salbruto*0.11)
    inss=(salbruto*0.08)
    sindicato=(salbruto*0.05)
    salliquido=(salbruto-imposto-inss-sindicato)
    return salbruto,imposto,inss,sindicato,salliquido

def impr(salbruto,imposto,inss,sindicato,salliquido):
    print('O seu salario bruto é:',salbruto)
    print('Voce pagou:',imposto ,'reais de imspotos')
    print('Voce pagou:' ,inss, 'reais ao inss')
    print('Voce pagou:',sindicato, 'reais ao sindicato')
    print('O seu salario liquido é:',salliquido)

salario,horas=perguntas()
salbruto,imposto,inss,sindicato,salliquido=sal(salario,horas)
impr(salbruto,imposto,inss,sindicato,salliquido)
