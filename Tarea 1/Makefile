all = Tarea1

Tarea1: main.o unionfind.o
	g++ -std=c++11 main.o unionfind.o -o exe
	time ./exe < t1-test/big-input.dat > t1-test/big-out.dat
	git diff --no-index --minimal --word-diff t1-test/big-out.dat t1-test/big-output.dat

memcheck: main.o unionfind.o
	g++ -std=c++11 -g main.o unionfind.o -o exe
	valgrind --leak-check=full --show-leak-kinds=all ./exe < input.txt

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -Wall

unionfind.o: unionfind.cpp
	g++ -std=c++11 -c unionfind.cpp -Wall

clean:
	rm -f *.o
	rm exe
