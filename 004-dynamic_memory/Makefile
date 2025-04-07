all: build-run

build-run:
	g++ -c funcArrays.cpp -o obj/funcArrays.o
	g++ -c main.cpp -o obj/main.o
	g++ obj/main.o obj/funcArrays.o -o bin/main
	./bin/main

clear:
	rm -rf *.o 