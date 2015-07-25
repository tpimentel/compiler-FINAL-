%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
BINARIO 0b[0-1]+
HEXA [0x0-9|A-F]*
OCTAL 0oct[0-7]+
L_LOW [a-z]
L_UPP [A-Z]
LETTER [a-z|A-Z]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
DOUBLE {NUM}+("."{NUM}+)[dD]
CHAR \'({LETTER}|{NUM})\'
ID {L_LOW}({LETTER}|{DIGITO})*
STRING "\"".*"\""
COMENT ("//"[^\n]*)|("/*"[^"*/"]*"*/")


%%

"\n"		{
				nLinha++;
			}

{DELIM} 	{}

"MAIN"		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_MAIN;
			}

"IN"		{	yylval.label = yytext;
				yylval.traducao = "cin";  
				return TK_READ;
			}

"OUT"		{	yylval.label = yytext;
				yylval.traducao = "cout";  
				return TK_WRITE;

			}


"VI" 		{ 	yylval.label = yytext;
				yylval.traducao = "int";
				return TK_TIPO_INT;
			}
"VF" 		{ 	yylval.label = yytext;
				yylval.traducao = "float"; 
				return TK_TIPO_FLOAT;
			}
"VD" 		{ 	yylval.label = yytext;
				yylval.traducao = "double"; 
				return TK_TIPO_DOUBLE;
			}
"VC" 		{ 	yylval.label = yytext;
				yylval.traducao = "char"; 
				return TK_TIPO_CHAR;
			}
"VS" 		{ 	yylval.label = yytext;
				yylval.traducao = "string"; 
				return TK_TIPO_STRING;
			}
"VB" 		{ 	yylval.label = yytext;
				yylval.traducao = "boolean";
				return TK_TIPO_BOOLEAN;
			}
"VL"		{ 	yylval.label = yytext;
				yylval.traducao = "long"; 
				return TK_TIPO_LONG;
			}

"IF"		{	yylval.label = yytext;
				yylval.traducao = "if"; 
				return TK_IF;
			}

"ELSE"		{	yylval.label = yytext;
				yylval.traducao = "else"; 
				return TK_ELSE;
			}

"ELIF"		{	yylval.label = yytext;
				yylval.traducao = "if";
				return TK_ELSE_IF;
			}

"WHILE"		{	yylval.label = yytext;
				yylval.traducao = "while";
				return TK_WHILE;
			}

"FOR"		{	yylval.label = yytext;
				yylval.traducao = "for";
				return TK_FOR;
			}

[(){}[\];,]	{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return *yytext; 
			}

[+]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_SOMA; 
			}
[\-]		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_MENOS; 
			}
[*]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_MULT; 
			}
[/]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_DIV; 
			}
[%]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_REST; 
			}
[=]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_IG; 
			}

"=="		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_COMP; 
			}
[<]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_LT; 
			}
[>]			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_GT; 
			}
"<="		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_LTE; 
			}
">="		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_GTE; 
			}
"!="		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_DIFF; 
			}

"&&"		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_AND; 
			}
"||"		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_OR; 
			}

"++"		{	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_PLUS;
}

"--"		{	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_SUB;
}

"!"			{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				return TK_NOT; 
			}

"TRUE"		{	yylval.label = yytext;
				yylval.traducao = "true";
				yylval.tipo = "boolean";  
				return TK_LOGICO;
			}

"FALSE"		{	yylval.label = yytext;
				yylval.traducao = "false"; 
				yylval.tipo = "boolean";  
				return TK_LOGICO;
			}			

{ID}		{ 	yylval.label = yytext;
				yylval.traducao = yytext;
				return TK_ID; 
			}
{NUM}		{ 	yylval.label = yytext;
				yylval.traducao = yytext; 
				yylval.tipo = "int";
				return TK_NUM; 
			}
{STRING}    { 	
				string texto = yytext;
				
				texto.replace(texto.begin(), texto.begin() + 1, "");
				texto.replace(texto.end() - 1, texto.end(), "");
				
				yylval.traducao = texto;
				yylval.label = texto;
				yylval.tipo = "string";
				yylval.tam = texto.size();
				
				return TK_STRING;
			}
{REAL}		{	yylval.label = yytext;
				yylval.traducao = yytext;  
				yylval.tipo = "float";
				return TK_REAL; 
			}

{DOUBLE}	{	yylval.label = yytext;
				yylval.traducao = yytext;  
				yylval.tipo = "double";
				return TK_DOUBLE;
			}

{CHAR}		{ 	yylval.label = yytext;
				yylval.traducao = yytext;  
				yylval.tipo = "char";
				return TK_CHAR; 
			}

.			{ *yytext; }

{COMENT}	{
				int i;
				for( i=0; yytext[i]; yytext[i]=='\n'? i++ : *yytext++);
				nLinha+=i;
			}

%%