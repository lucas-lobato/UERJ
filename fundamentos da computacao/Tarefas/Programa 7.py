#Faça um programa para o cálculo de uma folha de pagamento, sabendo que os descontos são do Imposto de Renda, que
#depende do salário bruto (conforme tabela abaixo) e 3% para o Sindicato e que o FGTS corresponde a 11% do Salário
#Bruto, mas não é descontado (é a empresa que deposita). O Salário Líquido corresponde ao Salário Bruto menos os
#descontos. O programa deverá pedir ao usuário o valor da sua hora e a quantidade de horas trabalhadas no mês.
#Desconto do IR:
#Salário Bruto até 900 (inclusive) - isento
#Salário Bruto até 1500 (inclusive) - desconto de 5%
#Salário Bruto até 2500 (inclusive) - desconto de 10%
#Salário Bruto acima de 2500 - desconto de 20% Imprima na tela as informações

def pergunta():
    cash=float(input('Digite o valor da hora trabalhada:'))
    horas=float(input('Digite quantas horas voce trabalha por mes:'))
    return cash,horas

def pagamento(cash,horas):
    salario=cash*horas
    if salario > 900 and salario < 1500:
        ir=salario*0.05
        porcento=5
    elif salario > 1500 and salario < 2500:
        ir=salario*0.10
        porcento=10
    elif salario > 2500:
        ir=salario*0.20
        porcento=20
    inss=salario*0.10
    fgts=salario*0.11
    descontos=(inss+ir)
    bruto=(salario-descontos)
    return salario,ir,porcento,inss,fgts,descontos,bruto

def impr(cash,horas,salario,ir,porcento,inss,fgts,descontos,bruto):
    print('Salario bruto:',(cash,'*',horas),salario)
    print('IR ',(porcento),'%',':',ir)
    print('INSS (10%):',inss)
    print('FGTS (11%):',fgts)
    print('descontos:',descontos)
    print('Salario bruto:',bruto)

cash,horas=pergunta()
salario,ir,porcento,inss,fgts,descontos,bruto=pagamento(cash,horas)
impr(cash,horas,salario,ir,porcento,inss,fgts,descontos,bruto)
