all = Tarea2

Tarea2: main.o parser.o
	g++ -std=c++11 main.o parser.o -O2 -o exe
	time ./exe < files/i10000000a.dat > out.dat

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -O2 -Wall

parser.o: parser.cpp
	g++ -std=c++11 -c parser.cpp -O2 -Wall

clean:
	rm -f *.o
	rm exe
