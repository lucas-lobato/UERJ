#Faça um programa para uma loja de tintas. O programa deverá pedir o tamanho em metros quadrados da área a ser pintada.
# Considere que a cobertura da tinta é de 1 litro para cada 3 metros quadrados e que a tinta é vendida em latas de 18
# litros, que custam R$ 80,00. Informe ao usuário a quantidades de latas de tinta a serem compradas e o preço total.

def tamanho():
    area=float(input('Digite a area a ser pintada em metros quadrados:'))
    return area

def preço(area):
    ltintas=(area/3)
    latas=(ltintas/18)
    if latas < 1:
        latas=1
    if latas > 1:
        latas=round(latas+0.5)
    preço=(latas*80)
    return ltintas,latas,preço

def impr(ltintas,latas,preço):
    print('serao necessarios',ltintas,'litros de tinta')
    print('devemos usar',latas,'latas de tinta')
    print('preço:',preço)
    return

area=tamanho()
ltintas,latas,preço=preço(area)
impr(ltintas,latas,preço)

