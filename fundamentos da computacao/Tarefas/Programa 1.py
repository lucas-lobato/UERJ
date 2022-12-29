#João Papo-de-Pescador, homem de bem, comprou um microcomputador para controlar o rendimento diário de seu trabalho.
#Toda vez que ele traz um peso de peixes maior que o estabelecido pelo regulamento de pesca do estado de São Paulo
#(50 quilos) deve pagar uma multa de R$ 4,00 por quilo excedente. João precisa que você faça um programa que leia a
#variável peso (peso de peixes) e calcule o excesso. Gravar na variável excesso a quantidade de quilos além do limite
#e na variável multa o valor da multa que João deverá pagar. Imprima os dados do programa com as mensagens adequadas.

def peso():
    kilos=float(input('Digite o peso em kilos de peixe coletado: '))
    return kilos

def excedente(kilos):
    excesso=0
    if kilos > 50: excesso=(kilos-50)
    return excesso

def multa(excesso):
    mult=0
    if excesso>0:
        mult=(excesso*4)
    return mult

def impr(kilos,excesso,multa):
    print ('Foram coletados',kilos,'de peixe')
    print ('Joao teve um excedente de',excesso,'kilos de peixe')
    print ('Joao devera pagar uma multa de',multa,'reais')
    return

kilos=peso()
excesso=excedente(kilos)
mult=multa(excesso)
impr(kilos,excesso,mult)
