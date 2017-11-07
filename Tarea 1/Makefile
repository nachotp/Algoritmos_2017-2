all = Tarea1

Tarea1: main.o unionfind.o
	g++ -std=c++11 main.o unionfind.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -Wall

unionfind.o: unionfind.cpp
	g++ -std=c++11 -c unionfind.cpp -Wall

clean:
	rm -f *.o
	rm exe
