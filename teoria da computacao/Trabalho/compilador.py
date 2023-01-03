from string import *
import re

    
def datainput():
    programa = "program correto; int a, b; begin a:=-2; b:=10 begin if (a<1) then b:=1 end end."
    dado = programa.lower().split(' ')
    return dado

def analisa():
    dado = datainput()
    print(dado)
    begin = 0
    end = 0
    padrao_operadores = re.compile("([a-z][0-9]?[:]?){1,32}([=]?[<>]?[<]?[<=]?[>]?[+]?[-]?[*]?[div]?){1}([a-z]?[0-9]?){1,32}")
    tokens = {
        'program':'<programa>',
        'var':'<atribuição>',
        'begin':'<comando composto>',
        'end':'<comando composto>',
        'if':'<comando condicional>',
        'then':'<comando condicional>',
        'else':'<comando condicional>',
        'while':'<comando repetitivo>',
        'do':'<comando repetitivo>',
        'int':'<atribuição>'
    }
    operadores = {
        '=':'Operador de relação', 
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
            print(f'<{i}>, ',tokens[i])
            if i == 'begin':
                print('<bloco>')
        else:
            busca = padrao_operadores.search(i)
            if busca:
                if ':' in i:
                    aux1 = i.split(':')
                    print(f'<{aux1[0]}>','<Identificador>')
                else:
                    if '<' in i:
                        aux1 = i.split('<')
                        print(f'<{aux1[0]}>','<Identificador>')
                    if '>' in i:
                        aux1 = i.split('>')
                        print(f'<{aux1[0]}>','<Identificador>')
                #print()
                #print(,'<Numero>')
                
analisa()