all:	program1 program2 theProgram

theProgram: factMain.o fact.o
	g++ factMain.o fact.o -o factMain

program1: factMain.cpp
	g++ -c -Wall -Werror -std=c++17 factMain.cpp -o factMain.o

program2: fact.cpp
	g++ -c -Wall -Werror -std=c++17 fact.cpp -o fact.o