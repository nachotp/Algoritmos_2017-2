all = Tarea3

Tarea3: main.o funciones.o
	g++ -std=c++11 main.o funciones.o -O2 -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -O2 -Wall

funciones.o: funciones.cpp
	g++ -std=c++11 -c funciones.cpp -O2 -Wall

clean:
	rm -f *.o
	rm exe
