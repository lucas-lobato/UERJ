# ESTE CÓDIGO IMPLEMENTA UM ANALIZADOR LÉXICO PARA O EXEMPLO DE FRAGMENTO DE LINGUAGEM APRESENTADO EM SALA DE AULA (VEJA OS SLIDES DA AULA 4: ANÁLISE LÉXICA: PARTE 2)
# E PODERÁ SER UTILIZADO COMO PONTO DE PARTIDA PARA IMPLEMENTAÇÃO DO ANALISADOR LÉXICO PARA LINGUAGEM ADOTADA NO TRABALHO PROPOSTO.


#NOME TOKENS
IF = 256
THEN = 257
ELSE = 258
RELOP = 259
ID = 260
NUM = 261

#ATRIBUTOS
LT = 262
LE = 263
EQ = 264
NE = 265
GT = 266
GE = 267


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
        partida = 9
  
    if estado == 9:
        partida = 12

    if estado == 12: 
        partida = 20

    if estado == 20:
        partida = 25

    if estado == 25:
		#retornar msg de erro
        print("Erro encontrado no código\n")
        cont_sim_lido += 1
    print("Erro do compilador")

    return partida


def proximo_token():

    Token = token(None,None)
    while code[cont_sim_lido] != EOFError:
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
                estado = 7
            else:
                estado = 8
            break

    if estado == 7:
        cont_sim_lido+= 1
        print("<relop, GE>\n")
        Token.nome_token = RELOP
        Token.atributo = GE
        estado = 0
        return Token

    if estado == 8:
        cont_sim_lido+= 1
        print("<relop, GT>\n")
        Token.nome_token = RELOP
        Token.atributo = GT
        #ATENÇÃO - CORREÇÃO: foi acrescentado o comando "estado = 0"
        estado = 0
        return Token

    if estado == 9:
        c = code[cont_sim_lido]
        if((c == ' ') or (c == '\n')):
            estado = 0
            cont_sim_lido += 1
      
        else:
            #implementar ações referentes aos estado */
            estado = falhar()

      #implementar ações para os estados 10, 11, 12*/

    if estado == 12:
        c = code[cont_sim_lido]
        if((c == ' ') or (c == '\n')):
            estado = 0
            cont_sim_lido+= 1
        else:
            #implementar ações referentes aos estado */
            estado = falhar()

        #implementar ações para os estados 13-19*/

    if estado == 20:
        c = code[cont_sim_lido]
        if((c == ' ') or (c == '\n')):
            estado = 0
            cont_sim_lido+= 1
        else:
            #implementar ações referentes aos estado */
            estado = falhar()

        #implementar ações para os estados 21-24*/

    if estado == 25:
        c = code[cont_sim_lido]
        if((c == ' ') or (c == '\n')):
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
  token = proximo_token()
  #...

main()