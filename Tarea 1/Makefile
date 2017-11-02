all = Tarea1

Tarea1: main.o graph.o
	g++ main.o graph.o -o exe 
	./exe < t1-test/big-input.dat

memcheck: main.o graph.o
	g++ -g main.o graph.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe < input.txt

main.o: main.cpp
	g++ -c main.cpp -Wall

graph.o: graph.cpp
	g++ -c graph.cpp -Wall

clean:
	rm -f *.o
	rm exe
