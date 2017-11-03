all = Tarea1

Tarea1: main.o graph.o
	g++ -std=c++11 main.o graph.o -o exe
	./exe < t1-test/medium-input.dat

memcheck: main.o graph.o
	g++ -std=c++11 -g main.o graph.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe < input.txt

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -Wall

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp -Wall

unionfind.o: unionfind.cpp
	g++ -std=c++11 -c graph.cpp -Wall

union: unionmain.cpp unionfind.o
	g++ -std=C++11 unionmain.c unionfind.o -o exe
	./exe < t1-test/medium-input.dat

clean:
	rm -f *.o
	rm exe
