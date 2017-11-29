all = Tarea2

Tarea2: main.o parser.o
	g++ -std=c++11 main.o parser.o -o exe
	time ./exe < files/i100000a.dat > out.dat

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -Wall

parser.o: parser.cpp
	g++ -std=c++11 -c parser.cpp -Wall

clean:
	rm -f *.o
	rm exe
