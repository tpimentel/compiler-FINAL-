%{
/*
	Criei algumas funcoes para se trabalhar com o escopó
	pesso que tentem fazer as declaraco dos if/else/else if, e tbm dos comando de repeticao
	lembrando que temos que usar labels e GOTO
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <time.h>

#define YYSTYPE atributos

using namespace std;

//Estrutura para atributos do Yacc
typedef struct
{
	string label;
	string traducao;
	string tipo;
	int tam;
} atributos;

//Estrutura para variaveis
typedef struct _variaveis
{
	string nome_temp;
	string tipo;
	int tam;

} inf_variaveis;

//Estrutura para Cast's
typedef struct _cast
{
	string resultOperacao;
	int operando;
}tipo_cast;
map<string, tipo_cast> gera_map_cast();

//Estrutura para Label's
typedef struct _label
{
	string labelIni;
	string labelMeio;
	string labelFim;
} inf_label;

//Contador de linhas
int nLinha = 1;

//Mapa de variaveis, tabela sintatica
//map<string, inf_variaveis> map_variaveis;

//Mapa de cast's
map<string, tipo_cast> map_cast = gera_map_cast();

//Pilha para armazenar os escopos
vector< map<string, inf_variaveis> > vecEscopo;

//Pilha para armazenar as label's
vector< inf_label > vecLabel;

//Declaracao de funcoes no escopo
int yylex(void);
void yyerror(string);
string createvar(void);
inf_label creatLabel(string estrutura);

//Funcao para criacao de escopo
void criaEscopo();

//Funcao para finalizacao do escopo
void finalizaEscopo();

//retorna o escopo atual
map<string, inf_variaveis> getEscopo();

//insere uma funcao no escopo
void insereVarNoEscopo(string nome, inf_variaveis var);

//retorna as informacoes de uma funcao
inf_variaveis retornaVarDoEscopo(string nome);

//verifica se a funcao esta declarada
bool findVar(string nome);

//funcao para criacao de label's


//Incremento para nomeacao das variaveis temporarias e as labels temporarias
int contadorVar = 0;
int contadorLabel = 0;


%}

%token TK_NUM TK_STRING TK_REAL TK_DOUBLE TK_CHAR TK_LOGICO
%token TK_MAIN TK_ID TK_WRITE TK_READ TK_WHILE TK_FOR
%token TK_FIM TK_ERROR
%token TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_DOUBLE TK_TIPO_STRING TK_TIPO_CHAR TK_TIPO_BOOLEAN TK_TIPO_LONG
%token TK_SOMA TK_MENOS TK_MULT TK_DIV TK_REST TK_IG TK_PLUS TK_SUB
%token TK_COMP TK_LT TK_GT TK_LTE TK_GTE TK_DIFF
%token TK_OR TK_AND TK_NOT
%token TK_IF TK_ELSE TK_ELSE_IF

%start S

%left TK_SOMA TK_MENOS 
%left TK_MULT TK_DIV
%nonassoc '=' TK_LT TK_GT 

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO{
				//armazena a saida do codigo
				stringstream saida;
				saida 	<< "\n/*Compilador FOCA*/\n" 
						<< "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" 
						<< $5.traducao 
						<< "\n\n\treturn 0;\n}" 
						<< endl; 

				//exibe saida no terminal
				cout << saida.str();

				// criar arquivo de saida
				stringstream fileOUTname; 
				fileOUTname << "saidas/saida(" << __TIME__ << ").c";

				ofstream myfile;
				myfile.open (fileOUTname.str().c_str());
				myfile << saida.str();
				myfile.close();
			};

BLOCO		: INIT_ESCOP '{' COMANDOS '}'{	
				$$.traducao = $3.traducao;

				finalizaEscopo();
			};

COMANDOS	: COMANDO ';' COMANDOS{
				$$.traducao = $1.traducao + $3.traducao;
			}
			| CONDICIONAL COMANDOS{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| LOOP COMANDOS{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| {
				$$.label = "";
				$$.traducao = "";
			}
			;

LOOP		: TK_WHILE '(' OP_OR  ')' BLOCO{
				inf_label infLabel =  creatLabel($1.label);

				if($3.tipo == "boolean"){
					$$.traducao = "\n\n" 
								+ vecLabel.back().labelIni
								+ ":\n\t" 
								+ "if(!(" + $3.traducao + "))\n\t\tgoto " 
								+ vecLabel.back().labelFim
								+ ";\n\t"
								+  $5.traducao
								+ "\n\tgoto " 
								+ vecLabel.back().labelIni
								+ ":\n"
								+ vecLabel.back().labelFim
								+ ":\n"; 

				} else {
					cout << "\tErro linha " << nLinha
						 << " ----- Condicao para While nao eh booleana ------- Erro producao: TK_WHILE '(' OP_OR  ')' BLOCO" << endl;
					exit(1);
				}

			}
			| TK_FOR '(' COMANDO ';' OP_OR ';' ATRIBUICAO')' BLOCO{
				inf_label infLabel =  creatLabel($1.label);

				$$.traducao = "\n\n"
							+ $3.traducao
							+ "\n" 
							+ vecLabel.back().labelIni
							+ ":\n\t"
							+ "if(!(" + $5.traducao + "))\n\t\tgoto "
							+ vecLabel.back().labelFim
							+ ";\n\t"
							+ $7.traducao
							+ "\n\t"
							+ $9.traducao
							+ "\n\tgoto "
							+ vecLabel.back().labelIni
							+ ":\n"
							+ vecLabel.back().labelFim
							+ ":\n";

			}
			;

CONDICIONAL	: TK_IF '(' OP_OR ')' BLOCO BLOCO_ELSE{

				inf_label infLabel =  creatLabel($1.label);

				$$.traducao = 
					"\n\n" + vecLabel.back().labelIni + ":\n\t" 
					+ "if(!(" + $3.traducao + "))\n\t\tgoto " + vecLabel.back().labelMeio + ";\n\t"
					+ $5.traducao + "\ngoto " + vecLabel.back().labelFim + ":\n" + vecLabel.back().labelMeio
					+ ":\n" + $6.traducao + "\n" + vecLabel.back().labelFim;
			}


BLOCO_ELSE	: TK_ELSE_IF '(' OP_OR ')' BLOCO BLOCO_ELSE{
				inf_label infLabel =  creatLabel($1.label);

				$$.traducao = 
					"\n\n" + vecLabel.back().labelIni + ":\n\t" 
					+ "if(!(" + $3.traducao + "))\n\t\tgoto " + vecLabel.back().labelMeio + ";\n\t"
					+ $5.traducao + "\ngoto " + vecLabel.back().labelFim + ":\n" + vecLabel.back().labelMeio 
					+ ":\n" + $6.traducao + "\n" + vecLabel.back().labelFim;
			}
			| TK_ELSE BLOCO{
				$$.traducao = "\t" + $2.traducao;
			}
			| {
				$$.traducao = "";
				$$.label = "";
			}
			;

INIT_ESCOP	: {
				criaEscopo();
				$$.traducao = "";
				$$.label = "";
			};

COMANDO 	: DECLARACAO{				
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| ATRIBUICAO{				
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			| TK_READ TK_ID{
				if(findVar($2.label)){
					inf_variaveis variavel = retornaVarDoEscopo($2.label);
					string varTemp = variavel.nome_temp;

					$$.traducao = "\n\tcin >> " + varTemp + ";\n\t";
				} else {					
					cout << "\tErro linha " << nLinha << " ----- Variavel nao declarada! ------- Erro producao: TK_READ" << endl;
					exit(1);
				}
			}
			| TK_WRITE OP_OR{
				if($2.tipo == "string")
					cout << endl << endl << "string" << endl << endl ;


				$$.traducao = "\n\tcout << " + $2.label + ";\n\t";
				$$.tipo = "void"; 
			}
			| OP_OR {				
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;


ATRIBUICAO 	: TK_ID TK_IG OP_OR{

				//cout << findVar($1.label) << endl << endl;
				
				//if(map_variaveis.find($1.label) != map_variaveis.end()){
				if(findVar($1.label)){
					//inf_variaveis var = map_variaveis[$1.label];
					inf_variaveis var = retornaVarDoEscopo($1.label);

					string castChave = var.tipo + "_" + $2.label + "_" + $3.tipo;

					$$.tipo = var.tipo;

					if(var.tipo == $3.tipo){						

						$$.traducao = "\t" + $3.traducao + "\n\t" + var.nome_temp + " " + $2.label + " " + $3.label + ";";

					} else if(map_cast.find(castChave) != map_cast.end()){

						tipo_cast cast = map_cast[castChave];

						if(cast.operando == 2) {
							$$.traducao = "\t" + $3.traducao + "\n\t" + var.nome_temp + " " + $2.label + " " + "(" + cast.resultOperacao + ") " + $3.label + ";";
						} else {
							cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------- Erro 01 producao: TK_ID TK_IG OP_OR" << endl << endl;
							exit(1);
						}

					} else {
						cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------- Erro 02 producao: TK_ID TK_IG OP_OR" << endl << endl;
						exit(1);
					}

				}else{
					cout << "\tErro linha " << nLinha << " ----- Variavel nao declarada! ------- Erro producao: TK_ID TK_IG OP_OR" << endl;
					exit(1); 
				}
			}
			| TK_ID TK_PLUS{
				if(findVar($1.label)){
					inf_variaveis var = retornaVarDoEscopo($1.label);

					if($1.tipo == "int"){
						$$.traducao = "\n\t" + var.nome_temp + "++;\n" ;
					}
				}
			}
			| TK_ID TK_SUB{
				if(findVar($1.label)){
					inf_variaveis var = retornaVarDoEscopo($1.label);

					if($1.tipo == "int"){
						$$.traducao = "\n\t" + var.nome_temp + "--;\n" ;
					}
				}
			}
			;


DECLARACAO	: TIPO TK_ID TK_IG OP_OR{
				inf_variaveis novo = {createvar(), $1.traducao, $4.tam};

				if(!findVar($2.label)){
					insereVarNoEscopo($2.label, novo);

					$$.label = novo.nome_temp;
					$$.tipo = $1.tipo;

					string castChave = novo.tipo + "_" + $3.label + "_" + $4.tipo;

					if(novo.tipo == $4.tipo){
						//$1.label == "string"
						if($1.tipo == "string"){
							stringstream traducao;
							traducao << "\n\t" << $4.traducao;
							traducao << "\n\t" << "char" << " " << novo.nome_temp << "[" << (novo.tam+1) << "]" << ";";
							traducao << "\n\tstrcpy(" << novo.nome_temp << ", " << $4.label << ");";
							
							$$.traducao = traducao.str();
						} else {
							$$.traducao = "\t" + $4.traducao + "\n\t" + $1.traducao + " " + novo.nome_temp + " " + $3.label + " " + $4.label + ";";
						}

					} else if(map_cast.find(castChave) != map_cast.end()){	
						tipo_cast cast = map_cast[castChave];					

						if(cast.operando == 2) {
							$$.traducao = "\t" + $4.traducao + "\n\t" + $1.traducao + " " + novo.nome_temp + " " + $3.label + " " + "(" + cast.resultOperacao + ") " + $4.label + ";";
						} else {
							cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan  ------ Erro 01 producao: TIPO TK_ID TK_IG OP_OR" << endl << endl;
							exit(1);
						}

					} else {
						cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan  ------ Erro 02 producao: TIPO TK_ID TK_IG OP_OR" << endl << endl;
						exit(1);
					}

				}else{
					cout << "\tErro linha " << nLinha << " ----- Variavel redeclarada! ------ Erro producao: TIPO TK_ID TK_IG OP_OR" << endl;
					exit(1); 
				}
			}

			| TIPO TK_ID{
				inf_variaveis novo = {createvar(), $1.traducao};

				if(!findVar($2.label)){
					insereVarNoEscopo($2.label, novo);
					//map_variaveis[$2.label] = novo;


					$$.label = novo.nome_temp;
					$$.tipo = $1.tipo;
					$$.tam = $2.tam;

					if($1.label == "string") {
						$$.traducao = "\n\t" + $1.traducao + " " + novo.nome_temp + "[" + "1" + "]" + ";";
						$$.traducao = $$.traducao + "\n\tstrcpy(" + novo.nome_temp + ", \"\");";

					} else {
						$$.traducao = "\n\t" + $1.traducao + " " + novo.nome_temp + ";";
					}

				}else{
					cout << "Erro linha " << nLinha << " ----- Variavel redeclarada! ----  Erro producao TIPO TK_ID" << endl;
					exit(1); 

				}
			};

OP_OR		: OP_OR TK_OR OP_AND{
				string var_temp;

				string castChave = $1.tipo + "_" + $2.label + "_" + $3.tipo;

				if(($1.tipo == "boolean") && ($1.tipo == $3.tipo)){
					var_temp = createvar();
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + var_temp + " = " + $1.label + " " + $2.traducao + " " + $3.label + ";";
				
					$$.tipo = "boolean";
				} else {
					cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ----  Erro producao OP_OR TK_OR OP_AND" << endl << endl;
					exit(1);
				}
			}
			| OP_AND{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;

			};

OP_AND		: OP_AND TK_AND REL{
				string var_temp;

				string castChave = $1.tipo + "_" + $2.label + "_" + $3.tipo;

				if(($1.tipo == "boolean") && ($1.tipo == $3.tipo)){
					var_temp = createvar();
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + var_temp + " = " + $1.label + " " + $2.traducao + " " + $3.label + ";";
				
					$$.tipo = "boolean";
				} else {
					cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------ Erro producao OP_AND TK_AND REL" << endl << endl;
					exit(1);
				}
			}
			| REL {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;				
			};

REL			: E RELACOES_OP E {
				string var_temp;

				string castChave = $1.tipo + "_" + $2.label + "_" + $3.tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					var_temp = createvar();

					if(cast.operando == 1){
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + "(" + $3.tipo + ") " + $1.label + " " 
						+ $2.label + " " + $3.label + ";";
					} else if ((cast.operando == 4) && (cast.resultOperacao == "boolean")){
						$$.traducao = $1.label + " " + $2.label + " " + $3.label;
						$$.tipo = "boolean";
					} else {
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + $1.label + " " + $2.label + " " 
						+ "(" + $1.tipo + ") " + $3.label + ";";
					}
				}
			} 
			| E {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;				
			}
			;

E 			: E ARIT_SO_SUB E_TEMP {
				string var_temp = createvar();
				$$.label = var_temp;

				string castChave = $1.tipo + "_" + $2.label + "_" + $3.tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					if(cast.operando == 1){
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + "(" + $3.tipo + ") " + $1.label + " " 
						+ $2.label + " " + $3.label + ";";

					} else if(cast.operando == 2){
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + $1.label + " " + $2.label + " " 
						+ "(" + $1.tipo + ") " + $3.label + ";";

					} else if ((cast.operando == -1) && (cast.resultOperacao == "string")) {
						inf_variaveis novo = {createvar(), "string", $1.tam + $3.tam};

						stringstream trad;
						trad << "\n\tchar"
							 << novo.nome_temp
							 << "[" << (novo.tam + 1) << "];"
							 << "\n\tstrcpy("
							 << novo.nome_temp + ", "
							 << $1.label
							 << ");"
							 << "\n\tstrcat("
							 << novo.nome_temp + ", "
							 << $3.label
							 << ");";

						$$.traducao = trad.str();
						$$.tipo = "string";
						$$.tam = novo.tam + 1;
						$$.label = novo.nome_temp;


					} else {
						cout << "Erro na linha " << nLinha <<": Tipo nao combinan ------ Erro 01 producao: E ARIT_SO_SUB E_TEMP" << endl << endl;
						exit(1);
					}

					$$.tipo = cast.resultOperacao;
				} else if($1.tipo == $3.tipo){
					$$.traducao = $3.traducao + "\t" + $1.traducao + 
					"\n\t" + $1.tipo + " " + var_temp + " = " + 
					$1.label + " " + $2.label + " " + $3.label + ";";

				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan------ Erro 02 producao:  E ARIT_SO_SUB E_TEMP" << endl << endl;
					exit(1);					
				}
			}
			| E_TEMP {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;				
			};


E_TEMP		: E_TEMP ARIT_MU_DI VAL{
				string var_temp = createvar();
				$$.label = var_temp;

				string castChave = $1.tipo + "_" + $2.label + "_" + $3.tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					if(cast.operando == 1){
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
							+ var_temp + " = " + "(" + $3.tipo + ") " + $1.label + " " 
								+ $2.label + " " + $3.label + ";";
					} else if(cast.operando == 2){
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + "int" + " " 
							+ var_temp + " = " + $1.label + " " + $2.label + " " 
								+ "(" + $1.tipo + ") " + $3.label + ";";
					} else {
						cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro 01 producao: E_TEMP ARIT_MU_DI VAL" << endl << endl;
						exit(1);
					}

					$$.tipo = cast.resultOperacao;
				} else if($1.tipo == $3.tipo){
					$$.traducao = $3.traducao + "\t" + $1.traducao + 
						"\n\t" + $1.tipo + " " + var_temp + " = " + 
							$1.label + " " + $2.label + " " + $3.label + ";";
				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro 02 producao: E_TEMP ARIT_MU_DI VAL" << endl << endl;
					exit(1);					
				}
			}
			| NOT {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;				
			};

NOT 		: TK_NOT NOT{
				string var_temp = createvar();

				if($2.tipo == "boolean"){
					$$.traducao = $2.traducao + "\n\t" + "int " + 
						var_temp + " = " + $1.traducao + $2.label + ";";
				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro producao: TK_NOT NOT" << endl << endl;
					exit(1);
				}
			}
			| VAL {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;
			};

VAL 		: '(' OP_OR ')' {
				$$.label = $2.label;
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
			}
			| TK_LOGICO {
				$$.label = $1.traducao;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
			}
			| TK_NUM {
				$$.label = $1.label;
				$$.traducao = "";
				$$.tipo = $1.tipo;
			}
			| TK_ID {
				if(!findVar($1.label)){					
					cout << "\tErro linha " << nLinha << " ----- Variavel NAO declarada! ----- Erro producao: val '(' OP_OR ')' " << endl;
					//exit(1); 
				} 

				inf_variaveis var = retornaVarDoEscopo($1.label);

				$$.label = var.nome_temp;
				$$.traducao = $$.label;
				$$.tipo = var.tipo;

			}
			| TK_REAL {
				$$.label = $1.label;
				$$.traducao = "";
				$$.tipo = $1.tipo;	
			}
			| TK_DOUBLE {
				$$.label = $1.label;
				$$.traducao = "";
				$$.tipo = $1.tipo;	
			}
			| TK_STRING {
				$$.label = "\"" + $1.label + "\"";
				$$.traducao = "";
				$$.tipo = $1.tipo;
				$$.tam = $1.tam;
			};

ARIT_SO_SUB : TK_SOMA
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_MENOS
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			};


ARIT_MU_DI	: TK_MULT
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_DIV
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_REST
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			};

RELACOES_OP	: TK_LT {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_GT {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_LTE {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_GTE {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_COMP {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_DIFF {
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			};


TIPO 		: TK_TIPO_INT {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "int";
				$$.tam = $1.tam;
			}
			| TK_TIPO_FLOAT {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "float";
				$$.tam = $1.tam;
			}
			| TK_TIPO_DOUBLE {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "double";
				$$.tam = $1.tam;
			}
			| TK_TIPO_STRING {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "string";
				$$.tam = $1.tam;
			}
			| TK_TIPO_CHAR {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "char";
				$$.tam = $1.tam;
			}
			| TK_TIPO_BOOLEAN {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "boolean";
				$$.tam = $1.tam;
			}
			| TK_TIPO_LONG {
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = "long";
				$$.tam = $1.tam;
			};

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG ){
	cout << MSG << endl;
	exit (0);
}

string createvar(){
	stringstream a;
	contadorVar = contadorVar + 1;
	a << "CompilerVarTemp_" << contadorVar;
	return a.str();
}

void criaEscopo(){	
	map<string, inf_variaveis> mapTemp;

	vecEscopo.push_back(mapTemp);
}

void finalizaEscopo(){
	vecEscopo.pop_back();
}


map<string, inf_variaveis> getEscopo(){
	return vecEscopo.back();
}

void insereVarNoEscopo(string nome, inf_variaveis var){
	vecEscopo.back()[nome] = var;

	//map<string, inf_variaveis> mapTemp;
	//mapTemp = getEscopo();

	//mapTemp[var.nome_temp] = var;

}

bool findVar(string nome){
	//for (int i = vecEscopo.size()-1; i >= 0; i--) {
	for (int i = 0; i < vecEscopo.size(); i++){
		map<string, inf_variaveis> mapTemp;
		mapTemp = vecEscopo[i];

		if(mapTemp.find(nome) != mapTemp.end())
			return true;
	}
	return false;
}

inf_variaveis retornaVarDoEscopo(string nome){
	if(findVar(nome)){
		for(int i = 0; i < vecEscopo.size(); i++){
			map<string, inf_variaveis> mapTemp;
			mapTemp = vecEscopo[i];
			
			if(mapTemp.find(nome) != mapTemp.end())
				return mapTemp[nome];
		}
	} else {
		cout << "Erro na linda: " << nLinha << ", variavel nao encontrada" ;
		exit(1);
	}

}

inf_label creatLabel(string estrutura){	
	contadorLabel = contadorLabel + 1;

	stringstream ini;
	ini << "label_" << estrutura << "_ini_" << contadorLabel;

	stringstream meio;
	meio << "label_" << estrutura << "_meio_" << contadorLabel;

	stringstream fim;
	fim << "label_" << estrutura << "_fim_" << contadorLabel;

	inf_label infLabel = {ini.str(), meio.str(), fim.str()};

	vecLabel.push_back(infLabel);	

	return infLabel;
}


map<string, tipo_cast> gera_map_cast(){
	map<string, tipo_cast> tab;

	tipo_cast cast_1 = {"float", 1};
	tab["int_+_float"] = cast_1;
	tab["int_-_float"] = cast_1;
	tab["int_*_float"] = cast_1;
	tab["int_/_float"] = cast_1;

	tipo_cast cast_2 = {"float", 2};
	tab["float_+_int"] = cast_2;
	tab["float_-_int"] = cast_2;
	tab["float_*_int"] = cast_2;
	tab["float_/_int"] = cast_2;
	tab["float_=_int"] = cast_2;

	tipo_cast cast_3 = {"long", 1};
	tab["int_+_long"] = cast_3;
	tab["int_-_long"] = cast_3;
	tab["int_*_long"] = cast_3;
	tab["int_/_long"] = cast_3;	
	tab["int_%_long"] = cast_3;

	tipo_cast cast_4 = {"long", 2};
	tab["long_+_int"] = cast_4;
	tab["long_-_int"] = cast_4;
	tab["long_*_int"] = cast_4;
	tab["long_/_int"] = cast_4;
	tab["long_%_int"] = cast_4;
	tab["long_=_int"] = cast_4;

	tipo_cast cast_5 = {"double", 1};
	tab["int_+_double"] = cast_5;
	tab["int_-_double"] = cast_5;
	tab["int_*_double"] = cast_5;
	tab["int_/_double"] = cast_5;
	tab["long_+_double"] = cast_5;
	tab["long_-_double"] = cast_5;
	tab["long_*_double"] = cast_5;
	tab["long_/_double"] = cast_5;

	tipo_cast cast_6 = {"double", 2};
	tab["double_+_int"] = cast_6;
	tab["double_-_int"] = cast_6;
	tab["double_*_int"] = cast_6;
	tab["double_/_int"] = cast_6;
	tab["double_=_int"] = cast_6;
	tab["double_+_long"] = cast_6;
	tab["double_-_long"] = cast_6;
	tab["double_*_long"] = cast_6;
	tab["double_/_long"] = cast_6;


	tipo_cast cast_8 = {"boolean", 4};	
	tab["int_<_int"] = cast_8;
	tab["int_<_float"] = cast_8;
	tab["int_<_long"] = cast_8;
	tab["int_<_double"] = cast_8;
	tab["int_>_int"] = cast_8;
	tab["int_>_float"] = cast_8;
	tab["int_>_long"] = cast_8;
	tab["int_>_double"] = cast_8;
	tab["int_<=_int"] = cast_8;
	tab["int_<=_float"] = cast_8;
	tab["int_<=_long"] = cast_8;
	tab["int_<=_double"] = cast_8;
	tab["int_>=_int"] = cast_8;
	tab["int_>=_float"] = cast_8;
	tab["int_>=_long"] = cast_8;
	tab["int_>=_double"] = cast_8;
	tab["int_==_int"] = cast_8;
	tab["int_==_float"] = cast_8;
	tab["int_==_long"] = cast_8;
	tab["int_==_double"] = cast_8;

	tab["float_<_float"] = cast_8;
	tab["float_<_int"] = cast_8;
	tab["float_<_long"] = cast_8;
	tab["float_<_double"] = cast_8;
	tab["float_>_float"] = cast_8;
	tab["float_>_int"] = cast_8;
	tab["float_>_long"] = cast_8;
	tab["float_>_double"] = cast_8;
	tab["float_<=_float"] = cast_8;
	tab["float_<=_int"] = cast_8;
	tab["float_<=_long"] = cast_8;
	tab["float_<=_double"] = cast_8;
	tab["float_>=_float"] = cast_8;
	tab["float_>=_int"] = cast_8;
	tab["float_>=_long"] = cast_8;
	tab["float_>=_double"] = cast_8;
	tab["float_==_float"] = cast_8;
	tab["float_==_int"] = cast_8;
	tab["float_==_long"] = cast_8;
	tab["float_==_double"] = cast_8;

	tab["double_<_double"] = cast_8;
	tab["double_<_int"] = cast_8;
	tab["double_<_float"] = cast_8;
	tab["double_<_long"] = cast_8;
	tab["double_>_double"] = cast_8;
	tab["double_>_int"] = cast_8;
	tab["double_>_float"] = cast_8;
	tab["double_>_long"] = cast_8;
	tab["double_<=_double"] = cast_8;
	tab["double_<=_int"] = cast_8;
	tab["double_<=_float"] = cast_8;
	tab["double_<=_long"] = cast_8;
	tab["double_>=_double"] = cast_8;
	tab["double_>=_int"] = cast_8;
	tab["double_>=_float"] = cast_8;
	tab["double_>=_long"] = cast_8;
	tab["double_==_double"] = cast_8;
	tab["double_==_int"] = cast_8;
	tab["double_==_float"] = cast_8;
	tab["double_==_long"] = cast_8;

	tab["long_<_long"] = cast_8;
	tab["long_<_int"] = cast_8;
	tab["long_<_float"] = cast_8;
	tab["long_<_double"] = cast_8;
	tab["long_>_long"] = cast_8;
	tab["long_>_int"] = cast_8;
	tab["long_>_float"] = cast_8;
	tab["long_>_double"] = cast_8;
	tab["long_<=_long"] = cast_8;
	tab["long_<=_int"] = cast_8;
	tab["long_<=_float"] = cast_8;
	tab["long_<=_double"] = cast_8;
	tab["long_>=_long"] = cast_8;
	tab["long_>=_int"] = cast_8;
	tab["long_>=_float"] = cast_8;
	tab["long_>=_double"] = cast_8;
	tab["long_==_long"] = cast_8;
	tab["long_==_int"] = cast_8;
	tab["long_==_float"] = cast_8;
	tab["long_==_double"] = cast_8;

	tab["string_==_string"] = cast_8;

	tipo_cast cast_9 = {"string", -1};
	tab["string_+_string"] = cast_9;
	tab["string_+_int"] = cast_9;
	tab["string_+_double"] = cast_9;
	tab["string_+_long"] = cast_9;
	tab["string_+_boolean"] = cast_9;
	tab["int_+_string"] = cast_9;
	tab["double_+_string"] = cast_9;
	tab["long_+_string"] = cast_9;
	tab["boolean_+_string"] = cast_9;

	tipo_cast cast_0 = {"null", -1};
	tab["int_%_float"] = cast_0;
	tab["int_%_float"] = cast_0;
	tab["int_%_doubla"] = cast_0;
	tab["int_%_double"] = cast_0;
	tab["float_%_int"] = cast_0;
	tab["float_%_float"] = cast_0;
	tab["boolean_+_boolean"] = cast_0;
	tab["boolean_-_boolean"] = cast_0;
	tab["boolean_*_boolean"] = cast_0;
	tab["boolean_/_boolean"] = cast_0;
	tab["boolean_=_boolean"] = cast_0;
	tab["boolean_%_boolean"] = cast_0;
	tab["long_%_double"] = cast_0;
	tab["double_%_double"] = cast_0;
	tab["int_or_int"] = cast_0;
	tab["float_or_float"] = cast_0;
	tab["double_or_double"] = cast_0;
	tab["long_or_long"] = cast_0;
	tab["int_and_int"] = cast_0;
	tab["float_and_float"] = cast_0;
	tab["double_and_double"] = cast_0;
	tab["long_and_long"] = cast_0;


    return tab; 
}