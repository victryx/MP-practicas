all: bin/demo2

# demo 2 requiere demo2.o y oper2.o (o liboper2.a)
bin/demo2: obj/demo2.o lib/liboper2.a
	g++ obj/demo2.o -L./lib -loper2 -o bin/demo2

lib/liboper2.a: obj/oper2.o
	ar rvs lib/liboper2.a obj/oper2.o

obj/oper2.o: src/oper2.cpp include/oper2.h
	g++ -c -I./include src/oper2.cpp -o obj/oper2.o

obj/demo2.o: src/demo2.cpp
	g++ -c -I./include src/demo2.cpp -o obj/demo2.o

clean:
	rm obj/*.o