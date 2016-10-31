install: Truthtable

Truthtable: Truthtable.o main.o
	g++ -o Truthtable Truthtable.o main.o -std=c++11

main.o:
	g++ -c -o main.o main.cpp -std=c++11

Truthtable.o: Truthtable.h Truthtable.cpp
	g++ -c -o Truthtable.o Truthtable.cpp -std=c++11

clean:
	rm Truthtable.o main.o Truthtable