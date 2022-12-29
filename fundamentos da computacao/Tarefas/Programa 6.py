#Faça um Programa que leia um número inteiro menor que 1000 e imprima a quantidade de centenas, dezenas e unidades do mesmo.
#Observando os termos no plural a colocação do "e", da vírgula entre outros. Exemplo:
#326 = 3 centenas, 2 dezenas e 6 unidades
#12 = 1 dezena e 2 unidades Testar com: 326, 300, 100, 320, 310,305, 301, 101, 311, 111, 25, 20, 10, 21, 11, 1, 7 e 16

def pergunta():
    num = int(input('Digite o numero:'))
    if num > 1000 or num == 1000:
        print('Voce digitou um valor igual ou acima de 1000, favor digitar um valor menor que 1000')
    return num


def impr(num):
    num=str(num)
    if len(str(num)) == 1:
        if num == 1:
            print(num, ' unidade.')
        else:
            print(num, ' unidades.')

    elif len(str(num)) == 2:
        print(num[0],'dezenas')
        print(num[1],'unidades')

    elif len(str(num)) == 3:
        print(num[0], 'centenas')
        print(num[1], 'dezenas')
        print(num[2], 'unidades')



num = pergunta()
impr(num)