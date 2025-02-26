#include <contenedor.h>
#include <iostream>

// Agrega un paquete al contenedor, devuelve false en caso de error 
// y true en caso de éxito
bool agregaPaquete(Contenedor &c, const Paquete &p) {
    if (esValido(p) && c.index < c.MAX) {
        c.lista[c.index] = p;
        c.index++;
        c.peso += p.peso;
        return true;
    }
    return false;
}


void mostrarContenedor(const Contenedor &c){
    for (int i = 0; i < c.index; i++) {
        std::cout << "P: " << i << "\t" << toString(c.lista[i]) << "\n";
    }
}

// Peso total del contenedor en kilogramos
double calcularPeso(const Contenedor &c) {
    return c.peso / 1000.0;
}

Contenedor obtienePaquetes(const Contenedor &c, int origen) {
    Contenedor result;
    for (int i = 0; i < c.index; i++) {
        if (c.lista[i].origen == origen) {
            agregaPaquete(result, c.lista[i]);
        }
    }
    return result;
}

// Ordena los paquetes del contenedor con bubble sort
// por origen y destino de forma ascendente
void ordenar(Contenedor &c){
    for (int i = 0; i < c.index; i++) {
        for (int j = i; j < c.index; j++) {
            bool ordenOrigen = c.lista[i].origen > c.lista[j].origen;
            bool ordenDestino = c.lista[i].origen == c.lista[j].origen && c.lista[i].destino > c.lista[j].destino;

            if (ordenOrigen || ordenDestino) {
                std::swap(c.lista[i], c.lista[j]);
            }

            /*
            if (c.lista[i].origen > c.lista[j].origen) {
            } 
            if (c.lista[i].origen == c.lista[j].origen
                        && c.lista[i].destino > c.lista[j].destino) {
                std::swap(c.lista[i], c.lista[j]);
            }
            */
        }
    }
}


// Devuelve la cantidad de paquetes enviados a d desde cualquier origen y su peso total
void enviosDestino(const Contenedor &c, int destino, int &contador, float &kilos) {
    kilos = 0;
    contador = 0;
    for (int i = 0; i < c.index; i++) {
        if (c.lista[i].destino == destino) {
            kilos += c.lista[i].peso;
            contador++;
        }
    }
    kilos /= 1000.0f;
}

// Muestra el número de paquetes y peso total enviado a cada destino
void analisisDestinos(Contenedor &c) {
    int enviosDestino[11] = {0};
    int pesoDestinos[11] = {0};

    for (int i = 0; i < c.index; i++) {
        enviosDestino[c.lista[i].destino]++;
        pesoDestinos[c.lista[i].destino] += c.lista[i].peso;
    }

    for (int i = 0; i < 11; i++) {
        if (enviosDestino[i] > 0) {
            std::cout << "destino " << i << ":\t paqs: " << enviosDestino[i] << "\t peso total: " << pesoDestinos[i] / 1000.0 << "\n";
        }
    }

}