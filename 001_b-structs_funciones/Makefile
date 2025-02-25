all: bin/prueba

# demo 2 requiere demo2.o y oper2.o (o liboper2.a)
bin/prueba: obj/paquete.o obj/contenedor.o obj/prueba.o
	g++ obj/paquete.o obj/contenedor.o obj/prueba.o -o bin/prueba

obj/paquete.o: src/paquete.cpp include/paquete.h
	g++ -c -I./include src/paquete.cpp -o obj/paquete.o

obj/contenedor.o: src/contenedor.cpp include/contenedor.h
	g++ -c -I./include src/contenedor.cpp -o obj/contenedor.o

obj/prueba.o: src/prueba.cpp
	g++ -c -I./include src/prueba.cpp -o obj/prueba.o

run:
	./bin/prueba < datos.txt

clean:
	rm obj/*.o