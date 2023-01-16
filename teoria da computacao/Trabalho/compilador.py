# ESTE CODIGO IMPLEMENTA UM ANALIZADOR LEXICO PARA O EXEMPLO DE FRAGMENTO DE LINGUAGEM APRESENTADO EM SALA DE AULA (VEJA OS SLIDES DA AULA 4: ANALISE LEXICA: PARTE 2)
# E PODERA SER UTILIZADO COMO PONTO DE PARTIDA PARA IMPLEMENTACAO DO ANALISADOR LEXICO PARA LINGUAGEM ADOTADA NO TRABALHO PROPOSTO.


#NOME TOKENS
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
    print(code)
    return code


def falhar():
    if estado == 0:
        partida = 10
  
    if estado == 10:
        partida = 13

    if estado == 13: 
        partida = 21

    if estado == 21:
        partida = 26

    if estado == 26:
        print("Erro encontrado no código\n")
        cont_sim_lido += 1
    print("Erro do compilador")

    return partida


def proximo_token(code):
    cont_sim_lido = 0
    estado = 0
    Token = token(None,None)
    while code[cont_sim_lido] != EOFError:
        if estado == 0:
            c = code[cont_sim_lido]
            print(c)
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
                estado = falhar()
            break

        if estado == 1:
            cont_sim_lido += 1
            c = code[cont_sim_lido]

            if(c == '='):
                estado = 2
            elif(c == '>'):
                estado = 3
            else:
                estado = 4
            break

        if estado == 2:
            cont_sim_lido += 1
            print("<relop, LE>\n")
            Token.nome_token = RELOP
            Token.atributo = LE
            estado = 0
            return Token
            break

        if estado == 3:
            cont_sim_lido += 1
            print("<relop, NE>\n")
            Token.nome_token = RELOP
            Token.atributo = NE
            estado = 0
            return Token
            break

        if estado == 4:
            cont_sim_lido+= 1
            print("<relop, LT>\n")
            Token.nome_token = RELOP
            Token.atributo = LT
            estado = 0
            return Token
            break

        if estado == 5:
            cont_sim_lido+= 1
            print("<relop, EQ>\n")
            Token.nome_token = RELOP
            Token.atributo = EQ
            return Token
            break

        if estado == 6:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == '=':
                estado = 8
            else:
                estado = 9
            break

        if estado == 7:
            cont_sim_lido+= 1
            c = code[cont_sim_lido]
            if c == '=':
                cont_sim_lido+= 1
                print("<:=, \n")
                Token.nome_token = ASSIGNMENT
                Token.atributo = ':='
                estado = 0
                return Token
            else:
                estado = 26

        if estado == 8:
            cont_sim_lido+= 1
            print("<relop, GE>\n")
            Token.nome_token = RELOP
            Token.atributo = GE
            estado = 0
            return Token
            

        if estado == 9:
            cont_sim_lido+= 1
            print("<relop, GT>\n")
            Token.nome_token = RELOP
            Token.atributo = GT
            estado = 0
            return Token
        
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
                    estado = falhar()

        if estado == 11:
            cont_sim_lido+= 1
            print("<(, >\n")
            Token.nome_token = RELOP
            Token.atributo = PARENTHESES_L
            estado = 0
            return Token
        
        if estado == 12:
            cont_sim_lido+= 1
            print("<), >\n")
            Token.nome_token = RELOP
            Token.atributo = PARENTHESES_R
            estado = 0
            return Token
        
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
                else:
                    estado = falhar()

        if estado == 14:
            cont_sim_lido+= 1
            print("<., >\n")
            Token.nome_token = RELOP
            Token.atributo = DOT
            estado = 0
            return Token
        
        if estado == 15:
            cont_sim_lido+= 1
            print("<;, >\n")
            Token.nome_token = RELOP
            Token.atributo = SEMICOLON
            estado = 0
            return Token
        
        if estado == 16:
            cont_sim_lido+= 1
            print("<,>\n")
            Token.nome_token = RELOP
            Token.atributo = COMMA
            estado = 0
            return Token
        
        if estado == 17:
            pass 
        
        if estado == 18:
            pass
        
        if estado == 19:
            pass
        
        if estado == 20:
            pass

        if estado == 21:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            elif(c == '+'):
                estado = 22
            elif(c == '-'):
                estado = 23
            elif(c =='*'):
                estado = 24
            elif(c == 'div'):
                estado = 25
            else:
                estado = falhar()

        if estado == 22:
            cont_sim_lido += 1
            print("<oparit, +>\n")
            Token.nome_token = OPARIT
            Token.atributo = PLUS
            estado = 0
            return Token
        if estado == 23:
            cont_sim_lido += 1
            print("<oparit, ->\n")
            Token.nome_token = OPARIT
            Token.atributo = MINUS
            estado = 0
            return Token
        if estado == 24:
            cont_sim_lido += 1
            print("<oparit, *>\n")
            Token.nome_token = OPARIT
            Token.atributo = TIMES
            estado = 0
            return Token
        if estado == 25:
            cont_sim_lido += 1
            print("<oparit, div>\n")
            Token.nome_token = OPARIT
            Token.atributo = DIV
            estado = 0
            return Token
        if estado == 26:
            c = code[cont_sim_lido]
            if (c == ' ') or (c == '\n'):
                estado = 0
                cont_sim_lido+= 1
            else:
            
                #implementar ações referentes aos estado */
                estado = falhar()
                Token.nome_token = -1
                Token.atributo = -1
                return Token
    
    Token.nome_token = EOFError
    Token.atributo = -1
    return Token


def main():
    code = readFile("programa.txt")
    token = proximo_token(code)
  #...

main()