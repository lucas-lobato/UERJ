# ESTE CODIGO IMPLEMENTA UM ANALIZADOR LEXICO PARA O EXEMPLO DE FRAGMENTO DE LINGUAGEM APRESENTADO EM SALA DE AULA (VEJA OS SLIDES DA AULA 4: ANALISE LEXICA: PARTE 2)
# E PODERA SER UTILIZADO COMO PONTO DE PARTIDA PARA IMPLEMENTACAO DO ANALISADOR LEXICO PARA LINGUAGEM ADOTADA NO TRABALHO PROPOSTO.


#NOME TOKENS
PROGRAM = 251
BEGIN = 252
END = 253
ASSIGNMENT = 254
OPARIT = 255
IF = 256
THEN = 257
ELSE = 258
RELOP = 259
ID = 260
NUM = 261

#ATRIBUTOS
LT = 262 # <
LE = 263 # <=
EQ = 264 # ==
NE = 265 # <>
GT = 266 # >
GE = 267 # >=
PLUS = 268 # +
MINUS = 269 # -
DIV = 270 # /
TIMES = 271 # *
PARENTHESES_L = 272 # (
PARENTHESES_R = 273 # )
DOT = 274 # .
SEMICOLON = 275 # ;
COMMA = 276 # ,

class token:
    def __init__(self, nome_token, atributo):
        self.nome_token = nome_token
        self.atributo = atributo        
        

estado = 0
partida = 0
cont_sim_lido = 0
code = ''


def readFile(fileName):

    file = open(fileName, "r")
    if file == None: 
        return None

    code = ''
    while True:
        char = file.read(1)     
        if not char:
            break
        code = code + char
    return code


def falhar(estado):
    partida = 0
    if estado == 0:
        partida = 10
  
    if estado == 10:
        partida = 13

    if estado == 13:
        partida = 36

    if estado == 36:
        partida = 41

    if estado == 41:
        partida = 62
    
    if estado == 100:
        print("Erro encontrado no código")
        print("Erro do compilador")
        exit()

    return partida


def proximo_token(code, partida):
    cont_sim_lido = 0
    estado = partida
    nome_prog = ''
    nome_num = ''
    Token = token(None,None)
    while cont_sim_lido < len(code):
        #print('caracter lido:', code[cont_sim_lido])
        if estado == 0:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido += 1
            elif(c == '<'):
                estado = 1
            elif(c == '='):
                estado = 5
            elif(c == '>'):
                estado = 6
            elif(c == ':'):
                estado = 7
            else: 
                estado = falhar(estado)

        if estado == 1:
            cont_sim_lido += 1
            c = code[cont_sim_lido]

            if(c == '='):
                estado = 2
            elif(c == '>'):
                estado = 3
            else:
                estado = 4

        if estado == 2:
            cont_sim_lido += 1
            print("<relop, LE>")
            Token.nome_token = RELOP
            Token.atributo = LE
            estado = 0

        if estado == 3:
            cont_sim_lido += 1
            print("<relop, NE>")
            Token.nome_token = RELOP
            Token.atributo = NE
            estado = 0

        if estado == 4:
            cont_sim_lido+= 1
            print("<relop, LT>")
            Token.nome_token = RELOP
            Token.atributo = LT
            estado = 0

        if estado == 5:
            cont_sim_lido+= 1
            print("<relop, EQ>")
            Token.nome_token = RELOP
            Token.atributo = EQ

        if estado == 6:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == '=':
                estado = 8
            else:
                estado = 9

        if estado == 7:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == '=':
                cont_sim_lido+= 1
                print("<:=, >")
                Token.nome_token = ASSIGNMENT
                Token.atributo = ':='
                estado = 0
            else:
                estado = 32

        if estado == 8:
            cont_sim_lido+= 1
            print("<relop, GE>")
            Token.nome_token = RELOP
            Token.atributo = GE
            estado = 0
            

        if estado == 9:
            cont_sim_lido+= 1
            print("<relop, GT>")
            Token.nome_token = RELOP
            Token.atributo = GT
            estado = 0
        
        if estado == 10:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido += 1
            else:
                if c == '(':
                    estado = 11
                elif c == ')':
                    estado = 12
                else:
                    estado = falhar(estado)

        if estado == 11:
            cont_sim_lido+= 1
            print("<(, >")
            Token.nome_token = RELOP
            Token.atributo = PARENTHESES_L
            estado = 0
        
        if estado == 12:
            cont_sim_lido+= 1
            print("<), >")
            Token.nome_token = RELOP
            Token.atributo = PARENTHESES_R
            estado = 0
        
        if estado == 13:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            else:
                if c == '.':
                    estado = 14
                elif c == ';':
                    estado = 15
                elif c == ',':
                    estado = 16
                elif c == 'p': # cheacando se sera escrito 'program'
                    estado = 17
                elif c == 'b': # cheacando se sera escrito 'begin'
                    estado = 24
                elif c.isnumeric(): # checando numeros
                    estado = 31
                elif c == 'i': # cheacando se sera escrito 'if' ou 'int'
                    estado = 32
                elif c == 'v': # cheacando se sera escrito 'var'
                    estado = 44
                elif c == 'e': # cheacando se sera escrito 'end' ou 'else'
                    estado = 47
                elif c == 't': # cheacando se sera escrito 'then'
                    estado = 53
                elif c == 'w': # cheacando se sera escrito 'while'
                    estado = 57
                elif c == 'd': # checando se sera escrito 'do'
                    estado = 35
                else:
                    estado = falhar(estado)

        if estado == 14:
            cont_sim_lido+= 1
            print("<., >")
            Token.nome_token = RELOP
            Token.atributo = DOT
            estado = 0
        
        if estado == 15:
            cont_sim_lido+= 1
            print("<;, >")
            Token.nome_token = RELOP
            Token.atributo = SEMICOLON
            estado = 0
        
        if estado == 16:
            cont_sim_lido+= 1
            print("<,>")
            Token.nome_token = RELOP
            Token.atributo = COMMA
            estado = 0
        
        if estado == 17:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'r':
                estado = 18
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 18:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'o':
                estado = 19
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
            
        if estado == 19:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'g':
                estado = 20
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
            
        if estado == 20:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'r':
                estado = 21
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
            
        if estado == 21:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'a':
                estado = 22
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
            
        if estado == 22:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'm':
                estado = 23
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 23:    
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print("<program, >")
                Token.nome_token = RELOP
                Token.atributo = PROGRAM
                estado = 0
            else:
                estado = 32
            
        if estado == 24:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'e':
                estado = 25
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 25:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'g':
                estado = 26
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 26:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'i':
                estado = 27
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 27:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'n':
                estado = 28
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 28:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ' or c == '\n':
                print("<begin, >")
                Token.nome_token = RELOP
                Token.atributo = BEGIN
                estado = 0
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62

        if estado == 31:
            nome_num = nome_num + code[cont_sim_lido]
            cont_sim_lido+= 1
            if code[cont_sim_lido].isnumeric():
                estado = 31
            else:
                print('<num, ' + nome_num + '>')
                nome_num = ''
                estado = 0
    
        if estado == 32:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'f':
                estado = 33
            elif c == 'n':
                estado = 34
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 33:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<if, >')
                estado = 0
                cont_sim_lido+= 1
            else:
                estado = 100
        
        if estado == 34:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 't':
                print('<int, >')
                estado = 0
                cont_sim_lido+= 1
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 35:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'o':
                estado = 43
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 40
            
        if estado == 36:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            elif(c == '+'):
                estado = 37
            elif(c == '-'):
                estado = 38
            elif(c =='*'):
                estado = 39
            elif(c == 'd'): #div
                estado = 40
            else:
                estado = falhar(estado)

        if estado == 37:
            cont_sim_lido += 1
            print("<oparit, +>")
            Token.nome_token = OPARIT
            Token.atributo = PLUS
            estado = 0
        
        if estado == 38:
            cont_sim_lido += 1
            print("<oparit, ->")
            Token.nome_token = OPARIT
            Token.atributo = MINUS
            estado = 0
        
        if estado == 39:
            cont_sim_lido += 1
            print("<oparit, *>")
            Token.nome_token = OPARIT
            Token.atributo = TIMES
            estado = 0
        
        if estado == 40:
            cont_sim_lido += 1
            if code[cont_sim_lido] == 'i':
                cont_sim_lido += 1
                if code[cont_sim_lido] == 'v':
                    cont_sim_lido += 1
                    if code[cont_sim_lido] == ' ':
                        print("<oparit, div>")
                    else:
                        cont_sim_lido = cont_sim_lido - 3
                        estado = 62
                else:
                    cont_sim_lido = cont_sim_lido - 2
                    estado = 62
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
            Token.nome_token = OPARIT
            Token.atributo = DIV
            estado = 0
        
        if estado == 41:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            else:
                estado = falhar(estado)
                Token.nome_token = -1
                Token.atributo = -1
        
        if estado == 43:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<do, >')
                estado = 0
            else:
                estado = 62
        
        if estado == 44:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'a':
                estado = 45
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 45:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'r':
                estado = 46
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 46:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<var, >')
                estado = 0
            else:
                estado = 62
                
        if estado == 47:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'n':
                estado = 48
            elif c == 'l':
                estado = 50
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 48:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'd':
                estado = 49
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 49:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ' or c == '\n' or c == '.':
                print('<end, >')
                estado = 0
            else:
                estado = 62

        if estado == 50:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 's':
                estado = 51
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 51:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'e':
                estado = 52
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 52:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<else, >')
                estado = 0
            else:
                estado = 62
        
        if estado == 53:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'h':
                estado = 54
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 54:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'e':
                estado = 55
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 55:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'n':
                estado = 56
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 56:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<then, >')
                estado = 0
            else:
                estado = 62
        
        if estado == 57:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'h':
                estado = 58
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 58:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'i':
                estado = 59
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 59:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'l':
                estado = 60
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 60:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == 'e':
                estado = 61
            else:
                cont_sim_lido = cont_sim_lido - 1
                estado = 62
        
        if estado == 61:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == ' ':
                print('<while, >')
                estado = 0
            else:
                estado = 100
        
        if estado == 62:
            c = code[cont_sim_lido]
            if c.isalnum():
                nome_prog = nome_prog + c
                cont_sim_lido+= 1
                estado = 62
            elif c == ' ' or c == '\n' or c == ';' or c == ',' or c == ':' or c == '<' or c == '>' or c == '=':
                print('<id,', nome_prog,'>')
                estado = 0
                nome_prog = ''
            else:
                estado = 100
        
        if estado == 100:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            else:
                estado = falhar(estado)
                Token.nome_token = -1
                Token.atributo = -1
                return Token
        
    
    Token.nome_token = EOFError
    Token.atributo = -1
    return Token


def main():
    code = readFile("programa.txt")
    token = proximo_token(code, 0)
  #...

main()