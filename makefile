install: Truthtable

Truthtable: Table.o main.o
	g++ -o Truthtable Table.o main.o -std=c++11

main.o:
	g++ -c -o main.o main.cpp -std=c++11

Table.o: Table.h Table.cpp
	g++ -c -o Table.o Table.cpp -std=c++11

clean:
	rm Table.o main.o Truthtable