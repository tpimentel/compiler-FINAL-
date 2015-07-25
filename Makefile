all: 	
		clear
		lex -o bin/lex.yy.c src/lexica.l
		yacc -o bin/y.tab.c -d src/sintatica.y
		g++ -o bin/glf bin/y.tab.c -lfl
		clear

		./bin/glf < src/exemplo.foca
