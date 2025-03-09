compilar: 
	gcc -o logicaSuperTrunfo logicaSuperTrunfo.c -Wall -Wextra -Wpedantic -Wreorder -Wunused -Wshadow -Werror=return-type
rodar:
	./logicaSuperTrunfo
limpar:
	rm -rf logicaSuperTrunfo
compilar-rodar:
	gcc -o logicaSuperTrunfo logicaSuperTrunfo.c
	./logicaSuperTrunfo
.PHONY: compilar rodar limpar compilar-rodar