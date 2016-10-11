all: main
main: main.o List.o
	g++ -o main main.o List.o
main.o: main.cpp List.h
	g++ -c main.cpp
List.o: List.cpp
	g++ -c List.cpp
clean:
	rm *.o
