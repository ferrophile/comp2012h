all: Brute Fast
Brute: brute.o algorithm.o point.o vector2d.o
	g++ -o Brute brute.o algorithm.o point.o vector2d.o
Fast: fast.o algorithm.o point.o vector2d.o
	g++ -o Fast fast.o algorithm.o point.o vector2d.o
brute.o: brute.cpp brute.h
	g++ -c brute.cpp
fast.o: fast.cpp fast.h
	g++ -c fast.cpp
algorithm.o: algorithm.cpp algorithm.h
	g++ -c algorithm.cpp
point.o: point.cpp point.h
	g++ -c point.cpp
vector2d.o: vector2d.cpp vector2d.h
	g++ -c vector2d.cpp
clean:
	rm *.o
