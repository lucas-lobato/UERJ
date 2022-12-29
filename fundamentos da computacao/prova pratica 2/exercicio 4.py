#exercicio 4

def separar (data):
    separa=data.split('/')
    return separa


def substituir (mes):

    if mes == '01':
        mes='de janeiro de'
    if mes == '02':
        mes='de fevereiro de'
    if mes == '03':
        mes='de marco de'
    if mes == '04':
        mes='de abril de'
    if mes == '05':
        mes='de maio de'
    if mes == '06':
        mes='de junho de'
    if mes == '07':
        mes='de julho de'
    if mes == '08':
        mes='de agosto de'
    if mes == '09':
        mes='de setembro de'
    if mes == '10':
        mes='de outubro de'
    if mes == '11':
        mes='de novembro de'
    if mes == '12':
        mes='de dezembro de'
    return mes

data=str(raw_input('digite sua data de aniversario (dd/mm/aaaa):'))

dia,mes,ano=separar(data)
popotao=substituir(mes)

datanova=dia+' '+popotao+' '+ano

print('voce nasceu em:',datanova)

