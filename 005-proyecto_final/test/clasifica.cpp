/* 
 * File:   clasifica.cpp
 * Author: David Pelta
 *
  */

#include <iostream>
#include "Particula.h"
#include "Vector2D.h"
#include "ConjuntoParticulas.h"

using namespace std;

/// @brief 
/// @note suponemos que los arrays centros y grupos ya están correctamente inicializados
/// @param parts 
/// @param centros 
/// @param grupos 
void agruparPorProximidad(const ConjuntoParticulas &parts, const Particula *centros, ConjuntoParticulas *grupos, int nCentros);

int centroMasCercano(const Particula &part, const Particula *centros, int nCentros);

int main() {
    ConjuntoParticulas parts;
    Particula* centros = nullptr;
    ConjuntoParticulas* grupos = nullptr;
    int numeroCentros = 0;
    
    /********************************
     *        LECTURA DE DATOS
     *******************************/

    // suponemos la estructura de datosGrupos.txt
    string cabecera;

    cin >> parts;
    cin >> cabecera >> numeroCentros;

    centros = new Particula[numeroCentros];
    grupos = new ConjuntoParticulas[numeroCentros];

    for (int i = 0; i < numeroCentros; i++) {
        cin >> centros[i];
    }

    /********************************
     *        MOSTRAR DATOS LEIDOS
     *******************************/

    cout << "PARTICULAS LEIDAS" << endl;
    cout << parts << endl;
    
    cout << "CENTROS LEIDOS" << endl;
    for(int i = 0; i < numeroCentros; i++) {
        cout << centros[i] << endl;
    }
    
     /********************************************
     *     SE AGREGAN LOS CENTROS A CADA GRUPO
     ********************************************/

    for(int i = 0; i < numeroCentros; i++) {
        grupos[i] += centros[i];
    }
    
    cout << "ESTADO INICIAL DE LOS GRUPOS" << endl;
    for(int i = 0; i < numeroCentros; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }
    
     /********************************************
     *     PROCESAMIENTO DE LOS DATOS
     ********************************************/

    if (numeroCentros > 0) { 
        agruparPorProximidad(parts, centros, grupos, numeroCentros);
    }

    /********************************
     *     MOSTRAR RESULTADOS
     *******************************/

    cout << "ESTADO FINAL DE LOS GRUPOS" << endl;    
    for(int i = 0; i < numeroCentros; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }

    delete [] grupos;
    delete [] centros;

    return 0;
}

void agruparPorProximidad(const ConjuntoParticulas &parts, const Particula *centros, ConjuntoParticulas *grupos, int nCentros) {
    int utiles = parts.getUtiles();
    for (int i = 0; i < utiles; i++) {
        Particula p = parts.obtener(i);
        int grupo = centroMasCercano(p, centros, nCentros);
        grupos[grupo] += p;
    }
}

int centroMasCercano(const Particula &part, const Particula *centros, int nCentros) {
    int nearest = 0;
    float minDist = part.getPos().distancia(centros[0].getPos());

    for (int i = 1; i < nCentros; i++) {
        float curDist = part.getPos().distancia(centros[i].getPos());
        if (curDist < minDist) {
            minDist = curDist;
            nearest = i;
        }
    }
    
    return nearest;
}