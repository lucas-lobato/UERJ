from string import *
import re

    
def datainput():
    programa = "program correto; int a, b; begin a:=-2; b:=10 begin if (a<1) then b:=1 end end."
    dado = programa.lower().split(' ')
    return dado

def analisa():
    dado = datainput()
    begin = 0
    end = 0
    padrao_operadores = re.compile("([a-z][0-9]?[:]?){1,32}([=]?[<>]?[<]?[<=]?[>]?[+]?[-]?[*]?[div]?){1}([a-z]?[0-9]?){1,32}")
    tokens = {
        'program':'programa',
        'var':'atribuição',
        'begin':'comando composto',
        'end':'comando composto',
        'if':'comando condicional',
        'then':'comando condicional',
        'else':'comando condicional',
        'while':'comando repetitivo',
        'do':'comando repetitivo',
        'int':'atribuição'
    }
    operadores = {
        ':=':'Operador de relação', 
        '<>':'Operador de relação',
        '<':'Operador de relação',
        '<=':'Operador de relação',
        '>=':'Operador de relação',
        '>':'Operador de relação',
        '+':'Operador aritmetico',
        '-':'Operador aritmetico',
        '*':'Operador aritmetico',
        'div':'Operador aritmetico'
    }
    for i in dado:
        if i in tokens:
            print(f'<{i}, {tokens[i]}>')
            if i == 'begin':
                print('<bloco>')
        else:
            busca = padrao_operadores.search(i)
            if busca:
                aux1 = ''
                aux2 = ''
                aux3 = ['','']
                if '(' in i:
                    i = i.removeprefix('(')
                    i = i.removesuffix(')')
                if ':' in i:
                    aux1 = i.split(':')
                    aux2 = ':='
                    aux3 = i.split('=')
                    print(f'<{aux1[0]},','Identificador>')
                else:
                    if '<' in i:
                        aux1 = i.split('<')
                        if '=' in i:
                            aux2 = '<='
                            aux3 = i.split('=')
                        else:
                            aux2 = '<'
                            aux3 = i.split('<')
                        print(f'<{aux1[0]},','Identificador>')
                    if '>' in i:
                        aux1 = i.split('>')
                        if '=' in i:
                            aux2 = '>='
                            aux3 = i.split('=')
                        else:
                            aux2 = '>'
                            aux3 = i.split('>')
                        print(f'<{aux1[0]},','Identificador>')
                if aux2 in operadores:
                    print(f'<{aux2}, {operadores[aux2]}>')
                if aux3[1] != '':
                    print(f'<{aux3[1]}, Numero>')
            else:
                print(i)
                
analisa()