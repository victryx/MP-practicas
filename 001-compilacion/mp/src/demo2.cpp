#include <iostream>
#include "oper2.h"

using namespace std;
int main (int argc, char *argv[]){
	
  double a, b;
  cout << "Introduce el primer valor: ";
  cin >> a;
  cout << "Introduce el segundo valor: ";
  cin >> b;
  cout << "suma(" << a << ", " << b << ") = " << suma(a,b) << endl;
  cout << "resta(" << a << ", " << b << ") = " << resta(a,b) << endl;
  cout << "multiplica(" << a << ", " << b << ") = " << multiplica(a,b) << endl;
  cout << "divide(" << a << ", " << b << ") = " << divide(a,b) << endl;

  return 0;
}
/*
-c para generar el objecto, no genera ejecutable
g++ -c xxx.cpp -o xxx.o 
eso va a fallar porque estań en diferentes carpetas

g++ -c src/demo2.cpp -I./include - o obj/demo2.o

para hacer bibliotecas, usar AR, no g++. 
Las bibliotecas empiezan con lib y tienen extensión .a
ar rvs lib/liboper2.a obj/oper2.o
nombre bilboteca + lista de códigos objeto
*/
