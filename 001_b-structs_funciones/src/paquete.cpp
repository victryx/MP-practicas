#include <paquete.h>
#include <string>

std::string toString(const Paquete &p) {
    return "O: " + std::to_string(p.origen) +
        "\tD: " +  std::to_string(p.destino) + 
        "\tpeso: " + std::to_string(p.peso / 1000.0);
}

bool valoresValidos(int origen, int destino, int peso) {
    return destino > 0 && destino <= 10 && origen > 0  && origen <= 10 && peso > 0;
}

Paquete creaPaquete(int origen, int destino, int peso) {
    Paquete paquete;
    if (valoresValidos(origen, destino, peso)) {
        paquete.origen = origen;
        paquete.destino = destino;
        paquete.peso = peso;
    }
    return paquete;
}

bool esValido(const Paquete &paquete) {
    return valoresValidos(paquete.origen, paquete.destino, paquete.peso);
}