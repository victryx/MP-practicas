all: bin/main bin/test

bin/test: obj/test.o obj/proceso.o
	g++ obj/proceso.o obj/test.o -o bin/test

bin/main: obj/proceso.o obj/main.o
	g++ obj/proceso.o obj/main.o -o bin/main

obj/proceso.o: src/proceso.cpp include/proceso.h
	g++ -c -I./include src/proceso.cpp -o obj/proceso.o

obj/test.o: src/test.cpp include/doctest.h
	g++ -c -I./include src/test.cpp -o obj/test.o

obj/main.o: src/main.cpp
	g++ -c -I./include src/main.cpp -o obj/main.o

run:
	./bin/main

run-test:
	./bin/test

clean:
	rm obj/*.o
	rm bin/*