all: bin/main

bin/main: obj/proceso.o obj/main.o
	g++ obj/proceso.o obj/main.o -o bin/main

obj/proceso.o: src/proceso.cpp include/proceso.h
	g++ -c -I./include src/proceso.cpp -o obj/proceso.o

obj/main.o: src/main.cpp
	g++ -c -I./include src/main.cpp -o obj/main.o

run:
	./bin/main

clean:
	rm obj/*.o
	rm bin/*