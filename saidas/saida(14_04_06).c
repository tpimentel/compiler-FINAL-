
/*Compilador FOCA*/
#include <iostream>
#include<string.h>
#include<stdio.h>
int main(void)
{
	
	int CompilerVarTemp_1 = 10;
	int CompilerVarTemp_2;	
	CompilerVarTemp_2 = 4;		
	int CompilerVarTemp_4 = 14 - 2;		
	int CompilerVarTemp_3 = 14 * 14;
	int CompilerVarTemp_5 = CompilerVarTemp_3 + CompilerVarTemp_4;
	int CompilerVarTemp_6 = CompilerVarTemp_5;	true
	boolean CompilerVarTemp_7 = true;	false
	boolean CompilerVarTemp_8 = false;
	
	char CompilerVarTemp_9[6];
	strcpy(CompilerVarTemp_9, "Casa ");
	
	char CompilerVarTemp_10[8];
	strcpy(CompilerVarTemp_10, "e muito");
	
	char CompilerVarTemp_11[6];
	strcpy(CompilerVarTemp_11, " cara");
	
	charCompilerVarTemp_15[17];
	strcpy(CompilerVarTemp_15, CompilerVarTemp_13);
	strcat(CompilerVarTemp_15, CompilerVarTemp_11);
	char CompilerVarTemp_16[18];
	strcpy(CompilerVarTemp_16, CompilerVarTemp_15);

label_IF_ini_3:
	if(!(CompilerVarTemp_7))
		goto label_IF_meio_3;
	
	cin >> CompilerVarTemp_1;
	
goto label_IF_fim_3:
label_IF_meio_3:


label_ELIF_ini_2:
	if(!(CompilerVarTemp_9 == "e muito"))
		goto label_ELIF_meio_2;
	
	cout << CompilerVarTemp_16;
	
goto label_ELIF_fim_2:
label_ELIF_meio_2:


label_ELIF_ini_1:
	if(!(CompilerVarTemp_10 == "Casa "))
		goto label_ELIF_meio_1;
	
	cout << "Entrei no ELIF";
	
goto label_ELIF_fim_1:
label_ELIF_meio_1:
	
	
	char CompilerVarTemp_19[12];
	strcpy(CompilerVarTemp_19, "nova string");	CompilerVarTemp_19
	CompilerVarTemp_16 = CompilerVarTemp_19;
label_ELIF_fim_1
label_ELIF_fim_2
label_IF_fim_3
	
	int CompilerVarTemp_20 = 1;

label_WHILE_ini_5:
	if(!(CompilerVarTemp_7))
		goto label_WHILE_fim_5;
	
	CompilerVarTemp_20++;

	cout << CompilerVarTemp_20;
	

label_IF_ini_4:
	if(!(CompilerVarTemp_20 == 10))
		goto label_IF_meio_4;
		CompilerVarTemp_8
	CompilerVarTemp_7 = CompilerVarTemp_8;
goto label_IF_fim_4:
label_IF_meio_4:

label_IF_fim_4

	goto label_WHILE_ini_5:
label_WHILE_fim_5:



	
	int CompilerVarTemp_22 = 0;
label_FOR_ini_6:
	if(!(CompilerVarTemp_22 < 20))
		goto label_FOR_fim_6;
	
	CompilerVarTemp_22++;

	
	cout << CompilerVarTemp_22;
	
	goto label_FOR_ini_6:
label_FOR_fim_6:



	return 0;
}
