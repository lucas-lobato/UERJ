/*
 * ESTE CÓDIGO IMPLEMENTA UM ANALIZADOR LÉXICO PARA O EXEMPLO DE FRAGMENTO DE LINGUAGEM APRESENTADO EM SALA DE AULA (VEJA OS SLIDES DA AULA 4: ANÁLISE LÉXICA: PARTE 2)
 * E PODERÁ SER UTILIZADO COMO PONTO DE PARTIDA PARA IMPLEMENTAÇÃO DO ANALISADOR LÉXICO PARA LINGUAGEM ADOTADA NO TRABALHO PROPOSTO.
 * */

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


//NOME TOKENS
#define IF  256
#define THEN  257
#define ELSE  258
#define RELOP  259
#define ID  260
#define NUM  261
#define AND 262
#define BREAK 263
#define DO 264
#define ELSEIF 265
#define END 266
#define FALSE 267
#define FOR 268
#define FUNCTION 269
#define IN 270
#define LOCAL 271
#define NIL 272
#define NOT 273
#define OR 274
#define REPEAT 275
#define RETURN 276
#define TRUE 277
#define UNTIL 278
#define WHILE 279


//ATRIBUTOS
#define LT 280 // <
#define LE 281 // <=
#define EQ 282 // ==
#define NE 283 // -
#define GT 284 // >
#define GE 285 // >=
#define PL 286 // +
#define TM 287 // *
#define DI 288 // /
#define IC 289 // ^
#define DF 290 // ~=
#define RC 291 // =
#define LP 292 // (
#define RP 293 // )
#define LK 294 // {
#define RK 295 // }
#define LB 296 // [
#define RB 297 // ]
#define SC 298 // ;
#define DT 299 // .
#define TD 300 // ..
#define CM 301 // ,
#define CL 302 // :
#define VAR 303 // variavel


struct Token {
	int nome_token;
	int atributo;
};


int estado = 0;
int partida = 0;
int cont_sim_lido = 0;
std::string code;


void readFile() {
	std::string nomeArquivo = "programa.txt";

	std::ifstream arquivo(nomeArquivo);

	if (!arquivo.is_open()) {
		std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
	}

	char caractere;

	while (arquivo.get(caractere)) {
		code += caractere;
	}

	arquivo.close();

	std::cout << "Conteudo do arquivo " << nomeArquivo << ":\n" << code;
	std::cout << "\n";
}


int falhar()
{
	//retornar mensagem de erro
	printf("Erro encontrado no codigo\n");
	return 0;
}


Token proximo_token()
{
	Token token;
	char c;
	while (code[cont_sim_lido] != EOF)
	{
		switch (estado)
		{
		case 0:
			c = std::toupper(code[cont_sim_lido]);
			if ((c == ' ') || (c == '\n'))
			{
				estado = 0;
				cont_sim_lido++;
			}
			else if (c == '<') estado = 1;
			else if (c == '=') estado = 5;
			else if (c == '>') estado = 6;
			else if (c == '~') estado = 9;
			else if (c == '+') estado = 10;
			else if (c == '*') estado = 11;
			else if (c == '/') estado = 12;
			else if (c == '^') estado = 13;
			else if (c == '(') estado = 14;
			else if (c == ')') estado = 15;
			else if (c == '{') estado = 16;
			else if (c == '}') estado = 17;
			else if (c == '[') estado = 18;
			else if (c == ']') estado = 19;
			else if (c == ';') estado = 20;
			else if (c == '.') estado = 21;
			else if (c == ',') estado = 23;
			else if (c == ':') estado = 24;
			else if (c == 'I') estado = 25;
			else if (c == 'T') estado = 29;
			else if (c == 'E') estado = 36;
			else if (c == 'R') estado = 45;
			else if (c == 'N') estado = 58;
			else if (c == 'A') estado = 65;
			else if (c == 'B') estado = 68;
			else if (c == 'D') estado = 73;
			else if (c == 'F') estado = 75;
			else if (c == 'L') estado = 89;
			else if (c == 'U') estado = 95;
			else if (c == 'W') estado = 101;
			else if (c == '-') estado = 107;
			else if (std::isalnum(c)) estado = 106;

			else
			{
				estado = 100;
			}
			break;

		case 1:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);

			if ((c == ' ') || (c == '\n'))
			{
				cont_sim_lido++;
				c = std::toupper(code[cont_sim_lido]);
			}

			if (c == '=') estado = 2;
			else if (c == '>') estado = 3;
			else estado = 4;
			break;

		case 2:
			cont_sim_lido++;
			printf("<relop, LE>\n");
			token.nome_token = RELOP;
			token.atributo = LE;
			estado = 0;
			return(token);
			break;

		case 3:
			cont_sim_lido++;
			printf("<relop, NE>\n");
			token.nome_token = RELOP;
			token.atributo = NE;
			estado = 0;
			return(token);
			break;

		case 4:
			cont_sim_lido++;
			printf("<relop, LT>\n");
			token.nome_token = RELOP;
			token.atributo = LT;
			estado = 0;
			return(token);
			break;

		case 5:
			cont_sim_lido++;
			printf("<relop, EQ>\n");
			token.nome_token = RELOP;
			token.atributo = EQ;
			estado = 0;
			return(token);
			break;

		case 6:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);

			if ((c == ' ') || (c == '\n'))
			{
				cont_sim_lido++;
				c = std::toupper(code[cont_sim_lido]);
			}

			if (c == '=') estado = 7;
			else estado = 8;
			break;

		case 7:
			cont_sim_lido++;
			printf("<relop, GE>\n");
			token.nome_token = RELOP;
			token.atributo = GE;
			estado = 0;
			return(token);
			break;

		case 8:
			cont_sim_lido++;
			printf("<relop, GT>\n");
			token.nome_token = RELOP;
			token.atributo = GT;
			estado = 0;
			return(token);
			break;

		case 9:
			c = std::toupper(code[cont_sim_lido]);
			if ((c == ' ') || (c == '\n'))
			{
				estado = 0;
				cont_sim_lido++;
			}
			else if (c == '=') {
				cont_sim_lido++;
				printf("<relop, DF>\n");
				token.nome_token = RELOP;
				token.atributo = DF;
				estado = 0;
				return(token);
				break;
			}
			else
			{
				estado = falhar();
			}
			break;

		case 10:
			cont_sim_lido++;
			printf("<relop, PL>\n");
			token.nome_token = RELOP;
			token.atributo = PL;
			estado = 0;
			return(token);
			break;

		case 11:
			cont_sim_lido++;
			printf("<relop, TM>\n");
			token.nome_token = RELOP;
			token.atributo = TM;
			estado = 0;
			return(token);
			break;

		case 12:
			cont_sim_lido++;
			printf("<relop, DI>\n");
			token.nome_token = RELOP;
			token.atributo = DI;
			estado = 0;
			return(token);
			break;

		case 13:
			cont_sim_lido++;
			printf("<relop, IC>\n");
			token.nome_token = RELOP;
			token.atributo = IC;
			estado = 0;
			return(token);
			break;

		case 14:
			cont_sim_lido++;
			printf("<relop, LP>\n");
			token.nome_token = RELOP;
			token.atributo = LP;
			estado = 0;
			return(token);
			break;

		case 15:
			cont_sim_lido++;
			printf("<relop, RP>\n");
			token.nome_token = RELOP;
			token.atributo = RP;
			estado = 0;
			return(token);
			break;

		case 16:
			cont_sim_lido++;
			printf("<relop, LK>\n");
			token.nome_token = RELOP;
			token.atributo = LK;
			estado = 0;
			return(token);
			break;

		case 17:
			cont_sim_lido++;
			printf("<relop, RK>\n");
			token.nome_token = RELOP;
			token.atributo = RK;
			estado = 0;
			return(token);
			break;

		case 18:
			cont_sim_lido++;
			printf("<relop, LB>\n");
			token.nome_token = RELOP;
			token.atributo = LB;
			estado = 0;
			return(token);
			break;

		case 19:
			cont_sim_lido++;
			printf("<relop, RB>\n");
			token.nome_token = RELOP;
			token.atributo = RB;
			estado = 0;
			return(token);
			break;

		case 20:
			cont_sim_lido++;
			printf("<relop, SC>\n");
			token.nome_token = RELOP;
			token.atributo = SC;
			estado = 0;
			return(token);
			break;

		case 21:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == '.')
			{
				estado = 22;
			}
			else {
				printf("<relop, DT>\n");
				token.nome_token = RELOP;
				token.atributo = DT;
				estado = 0;
				return(token);
				break;
			}
			break;

		case 22:
			cont_sim_lido++;
			printf("<relop, TD>\n");
			token.nome_token = RELOP;
			token.atributo = TD;
			estado = 0;
			return(token);
			break;

		case 23:
			cont_sim_lido++;
			printf("<relop, CM>\n");
			token.nome_token = RELOP;
			token.atributo = CM;
			estado = 0;
			return(token);
			break;

		case 24:
			cont_sim_lido++;
			printf("<relop, CL>\n");
			token.nome_token = RELOP;
			token.atributo = CL;
			estado = 0;
			return(token);

		case 25:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'F') {
				estado = 26;
			}
			else if (c == 'N') {
				estado = 27;
			}
			else if (c == 'D') {
				estado = 28;
			}
			else {
				estado = 106;
			}
			break;

		case 26:
			cont_sim_lido++;
			printf("<token, IF>\n");
			token.nome_token = IF;
			token.atributo = IF;
			estado = 0;
			return(token);

		case 27:
			cont_sim_lido++;
			printf("<token, IN>\n");
			token.nome_token = IN;
			token.atributo = IN;
			estado = 0;
			return(token);

		case 28:
			cont_sim_lido++;
			printf("<token, ID>\n");
			token.nome_token = ID;
			token.atributo = ID;
			estado = 0;
			return(token);

		case 29:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'R') {
				estado = 30;
			}
			else if (c == 'H') {
				estado = 33;
			}
			else {
				estado = 106;
			}
			break;

		case 30:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'U') {
				estado = 31;
			}
			else {
				estado = 106;
			}
			break;

		case 31:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 32;
			}
			else {
				estado = 106;
			}
			break;

		case 32:
			cont_sim_lido++;
			printf("<token, TRUE>\n");
			token.nome_token = TRUE;
			token.atributo = TRUE;
			estado = 0;
			return(token);
			break;

		case 33:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 34;
			}
			else {
				estado = 106;
			}
			break;

		case 34:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 35;
			}
			else {
				estado = 106;
			}
			break;

		case 35:
			cont_sim_lido++;
			printf("<token, THEN>\n");
			token.nome_token = THEN;
			token.atributo = THEN;
			estado = 0;
			return(token);
			break;

		case 36:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 37;
			}
			else if (c == 'L') {
				estado = 39;
			}
			else {
				estado = 106;
			}
			break;

		case 37:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'D') {
				estado = 38;
			}
			else {
				estado = 106;
			}
			break;

		case 38:
			cont_sim_lido++;
			printf("<token, END>\n");
			token.nome_token = END;
			token.atributo = END;
			estado = 0;
			return(token);
			break;

		case 39:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'S') {
				estado = 40;
			}
			else {
				estado = 106;
			}
			break;

		case 40:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 41;
			}
			else {
				estado = 106;
			}
			break;

		case 41:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == ' ' || c == '\n') {
				estado = 42;
			}
			else if (c == 'I') {
				estado = 43;
			}
			else {
				estado = 106;
			}
			break;

		case 42:
			cont_sim_lido++;
			printf("<token, ELSE>\n");
			token.nome_token = ELSE;
			token.atributo = ELSE;
			estado = 0;
			return(token);
			break;

		case 43:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'F') {
				estado = 44;
			}
			else {
				estado = 106;
			}
			break;

		case 44:
			cont_sim_lido++;
			printf("<token, ELSEIF>\n");
			token.nome_token = ELSEIF;
			token.atributo = ELSEIF;
			estado = 0;
			return(token);
			break;

		case 45:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 46;
			}
			else {
				estado = 106;
			}
			break;

		case 46:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'T') {
				estado = 47;
			}
			else if (c == 'L') {
				estado = 51;
			}
			else if (c == 'P') {
				estado = 54;
			}
			else {
				estado = 106;
			}
			break;

		case 47:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'U') {
				estado = 48;
			}
			else {
				estado = 106;
			}
			break;

		case 48:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'R') {
				estado = 49;
			}
			else {
				estado = 106;
			}
			break;

		case 49:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 50;
			}
			else {
				estado = 106;
			}
			break;

		case 50:
			cont_sim_lido++;
			printf("<token, RETURN>\n");
			token.nome_token = RETURN;
			token.atributo = RETURN;
			estado = 0;
			return(token);
			break;

		case 51:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'O') {
				estado = 52;
			}
			else {
				estado = 106;
			}
			break;

		case 52:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'P') {
				estado = 53;
			}
			else {
				estado = 106;
			}
			break;

		case 53:
			cont_sim_lido++;
			printf("<token, RELOP>\n");
			token.nome_token = RELOP;
			token.atributo = RELOP;
			estado = 0;
			return(token);
			break;

		case 54:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 55;
			}
			else {
				estado = 106;
			}
			break;

		case 55:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'A') {
				estado = 56;
			}
			else {
				estado = 106;
			}
			break;

		case 56:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'T') {
				estado = 57;
			}
			else {
				estado = 106;
			}
			break;

		case 57:
			cont_sim_lido++;
			printf("<token, REPEAT>\n");
			token.nome_token = REPEAT;
			token.atributo = REPEAT;
			estado = 0;
			return(token);
			break;

		case 58:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'U') {
				estado = 59;
			}
			else if (c == 'I') {
				estado = 61;
			}
			else if (c == 'O') {
				estado = 63;
			}
			else {
				estado = 106;
			}
			break;

		case 59:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'M') {
				estado = 60;
			}
			else {
				estado = 106;
			}
			break;

		case 60:
			cont_sim_lido++;
			printf("<token, NUM>\n");
			token.nome_token = NUM;
			token.atributo = NUM;
			estado = 0;
			return(token);
			break;

		case 61:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'L') {
				estado = 62;
			}
			else {
				estado = 106;
			}
			break;

		case 62:
			cont_sim_lido++;
			printf("<token, NIL>\n");
			token.nome_token = NIL;
			token.atributo = NIL;
			estado = 0;
			return(token);
			break;

		case 63:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'T') {
				estado = 64;
			}
			else {
				estado = 106;
			}
			break;

		case 64:
			cont_sim_lido++;
			printf("<token, NOT>\n");
			token.nome_token = NOT;
			token.atributo = NOT;
			estado = 0;
			return(token);
			break;

		case 65:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 66;
			}
			else {
				estado = 106;
			}
			break;

		case 66:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'D') {
				estado = 67;
			}
			else {
				estado = 106;
			}
			break;

		case 67:
			cont_sim_lido++;
			printf("<token, AND>\n");
			token.nome_token = AND;
			token.atributo = AND;
			estado = 0;
			return(token);
			break;

		case 68:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'R') {
				estado = 69;
			}
			else {
				estado = 106;
			}
			break;

		case 69:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 70;
			}
			else {
				estado = 106;
			}
			break;

		case 70:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'A') {
				estado = 71;
			}
			else {
				estado = 106;
			}
			break;

		case 71:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'K') {
				estado = 72;
			}
			else {
				estado = 106;
			}
			break;

		case 72:
			cont_sim_lido++;
			printf("<token, BREAK>\n");
			token.nome_token = BREAK;
			token.atributo = BREAK;
			estado = 0;
			return(token);
			break;

		case 73:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'O') {
				estado = 74;
			}
			else {
				estado = 106;
			}
			break;

		case 74:
			cont_sim_lido++;
			printf("<token, DO>\n");
			token.nome_token = DO;
			token.atributo = DO;
			estado = 0;
			return(token);
			break;

		case 75:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'O') {
				estado = 76;
			}
			else if (c == 'A') {
				estado = 78;
			}
			else if (c == 'U') {
				estado = 82;
			}
			else {
				estado = 106;
			}
			break;

		case 76:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'R') {
				estado = 77;
			}
			else {
				estado = 106;
			}
			break;

		case 77:
			cont_sim_lido++;
			printf("<token, FOR>\n");
			token.nome_token = FOR;
			token.atributo = FOR;
			estado = 0;
			return(token);
			break;

		case 78:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'L') {
				estado = 79;
			}
			else {
				estado = 106;
			}
			break;

		case 79:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'S') {
				estado = 80;
			}
			else {
				estado = 106;
			}
			break;

		case 80:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 81;
			}
			else {
				estado = 106;
			}
			break;

		case 81:
			cont_sim_lido++;
			printf("<token, FALSE>\n");
			token.nome_token = FALSE;
			token.atributo = FALSE;
			estado = 0;
			return(token);
			break;

		case 82:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 83;
			}
			else {
				estado = 106;
			}
			break;

		case 83:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'C') {
				estado = 84;
			}
			else {
				estado = 106;
			}
			break;

		case 84:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'T') {
				estado = 85;
			}
			else {
				estado = 106;
			}
			break;

		case 85:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'I') {
				estado = 86;
			}
			else {
				estado = 106;
			}
			break;

		case 86:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'O') {
				estado = 87;
			}
			else {
				estado = 106;
			}
			break;

		case 87:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 88;
			}
			else {
				estado = 106;
			}
			break;

		case 88:
			cont_sim_lido++;
			printf("<token, FUNCTION>\n");
			token.nome_token = FUNCTION;
			token.atributo = FUNCTION;
			estado = 0;
			return(token);
			break;

		case 89:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'O') {
				estado = 90;
			}
			else {
				estado = 106;
			}
			break;

		case 90:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'C') {
				estado = 91;
			}
			else {
				estado = 106;
			}
			break;

		case 91:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'A') {
				estado = 92;
			}
			else {
				estado = 106;
			}
			break;

		case 93:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'L') {
				estado = 94;
			}
			else {
				estado = 106;
			}
			break;

		case 94:
			cont_sim_lido++;
			printf("<token, LOCAL>\n");
			token.nome_token = LOCAL;
			token.atributo = LOCAL;
			estado = 0;
			return(token);
			break;

		case 95:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'N') {
				estado = 96;
			}
			else {
				estado = 106;
			}
			break;

		case 96:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'T') {
				estado = 97;
			}
			else {
				estado = 106;
			}
			break;

		case 97:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'I') {
				estado = 98;
			}
			else {
				estado = 106;
			}
			break;

		case 98:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'L') {
				estado = 99;
			}
			else {
				estado = 106;
			}
			break;

		case 99:
			cont_sim_lido++;
			printf("<token, UNTIL>\n");
			token.nome_token = UNTIL;
			token.atributo = UNTIL;
			estado = 0;
			return(token);
			break;

		case 100:
			estado = falhar();
			break;
		
		case 101:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'H') {
				estado = 102;
			}
			else {
				estado = 106;
			}
			break;

		case 102:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'I') {
				estado = 103;
			}
			else {
				estado = 106;
			}
			break;

		case 103:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'L') {
				estado = 104;
			}
			else {
				estado = 106;
			}
			break;

		case 104:
			cont_sim_lido++;
			c = std::toupper(code[cont_sim_lido]);
			if (c == 'E') {
				estado = 105;
			}
			else {
				estado = 106;
			}
			break;

		case 105:
			cont_sim_lido++;
			printf("<token, WHILE>\n");
			token.nome_token = WHILE;
			token.atributo = WHILE;
			estado = 0;
			return(token);
			break;

		case 106:
			c = std::toupper(code[cont_sim_lido]);
			while (std::isalnum(c)) {
				cont_sim_lido++;
				c = std::toupper(code[cont_sim_lido]);
			}
			std::cout << "<relop, var>\n";
			token.nome_token = VAR;
			token.atributo = VAR;
			estado = 0;
			return(token);
			break;

		case 107:
			cont_sim_lido++;
			printf("<relop, ->\n");
			token.nome_token = NE;
			token.atributo = NE;
			estado = 0;
			return(token);
			break;

		}
	}
}


int main() {
	Token token;
	token.nome_token = 0;
	readFile();

	while (cont_sim_lido < size(code)) {
		token = proximo_token();
	}

	return 0;
}