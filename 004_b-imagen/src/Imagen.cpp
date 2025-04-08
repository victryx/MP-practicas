#include <pgm.h>
#include <Imagen.h>

void cargarImagen(Imagen & img, std::string file) {
    int fil, col;
    TipoImagen tipo = infoPGM(file.c_str(), fil, col);
    if (tipo == IMG_PGM_TEXTO) {
        liberaMem(img);
        leerPGMTexto(img, file);
    }
    else {
        std::cerr << "Error en la lectura del fichero " << file << std::endl;
        exit(-1);
    }
}

void guardarImagen(Imagen & img, std::string file) {
    escribirPGMTexto(img, file);
}

void reservaMem(Imagen & img, int fil, int col) {
    if (img.M != nullptr) {
        liberaMem(img);
    }
    img.nc = col;
    img.nf = fil;
    img.M = new int*[fil];
    for (int i = 0; i < fil; i++) {
        img.M[i] = new int [col];
    }
}

void liberaMem(Imagen & img) {
    if (img.M != nullptr) {
        for (int i = 0; i < img.nf; i++) {
            delete [] img.M[i];
        }
        delete [] img.M;
        img.M = nullptr;
    }
}

/// @brief copia "profunda" de origen a destino. Requiere (posiblemente)liberar, reservar y copiar
/// Sería el equivalente a la operación destino = origen 
/// \param origen dato de tipo Imagen
/// \param destino dato de tipo Imagen
void copiar(const Imagen & origen, Imagen & destino) {
    liberaMem(destino);
    reservaMem(destino, origen.nf, origen.nc);

    for (int i = 0; i < origen.nf; i++) {
        for (int j = 0; j < origen.nc; j++) {
            destino.M[i][j] = origen.M[i][j];
        }
    }
}

int filtrar(const Imagen & img, const Imagen & filtro, int fila, int columna) {
    int out = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out += filtro.M[i][j] * img.M[i+fila-1][j+columna-1];
        }
    }
    return out;
}

/// @brief aplica el filtro sobre la Imagen img, calculando el nuevo valor para cada pixel. 
/// Se asume que filtro es una matriz de 3 x 3
/// \param img dato de tipo Imagen a procesar
/// \param filtro dato de tipo Imagen de 3x3 que representa el filtro a aplicar
void aplicaFiltro(Imagen & img, const Imagen & filtro) {
    Imagen aux;
    copiar(img, aux);

    for (int i = 1; i < img.nf - 1; i++) {
        for (int j = 1; j < img.nc - 1; j++) {
            img.M[i][j] = filtrar(aux, filtro, i, j);
        }
    }
    
    liberaMem(aux);
}

/// @brief rota la imagen 90º grados en sentido horario. Se modifica la imagen original
/// \param img dato de tipo Imagen
void rotar(Imagen & img) {
    Imagen rotada; 
    reservaMem(rotada, img.nc, img.nf); 

    for (int i = 0; i < img.nf; i++) { 
        for (int j = 0; j < img.nc; j++) {
            rotada.M[j][rotada.nc-1-i] = img.M[i][j];
        }
    }

    copiar(rotada, img);
    liberaMem(rotada);
}


/// @brief Dada una imagen, crea una imagen especular vertical
/// \param origen datos de tipo Imagen de f x c
/// \param destino datos de tipo Imagen de (2*f) x c
void espejoV(const Imagen & origen, Imagen & destino) {
    reservaMem(destino, origen.nf * 2, origen.nc);
    for (int i = 0; i < origen.nf; i++) {
        for (int j = 0; j < origen.nc; j++) {
            int val = origen.M[i][j];
            destino.M[i][j] = val;
            destino.M[destino.nf - 1 - i][j] = val;
        }
    }
}

/// @brief Dada una imagen, crea una imagen especular horizontal
/// \param origen datos de tipo Imagen de f x c
/// \param destino datos de tipo Imagen de f x (2*c)
void espejoH(const Imagen & origen, Imagen & destino) {
    reservaMem(destino, origen.nf, origen.nc * 2);
    for (int i = 0; i < origen.nf; i++) {
        for (int j = 0; j < origen.nc; j++) {
            int val = origen.M[i][j];
            destino.M[i][j] = val;
            destino.M[i][destino.nc - 1 - j] = val;
        }
    }
}

/// @brief Compara si dos datos de tipo Imagen son iguales
/// \param img1 dato de tipo Imagen
/// \param img2 dato de tipo Imagen
/// \return true, si son iguales. False en caso contrario
bool sonIguales(const Imagen & img1, const Imagen & img2) {
    bool iguales = img1.nc == img2.nc && img1.nf == img2.nf;
    for (int i = 0; i < img1.nf && iguales; i++) {
        for (int j = 0; j < img1.nc && iguales; j++) {
            iguales = img1.M[i][j] == img2.M[i][j];
        }
    }
    return iguales;
}


/// @brief Inicializa el dato filtro con parametros predeterminados
/// \param filtro dato de tipo Imagen
/// \param opcion valores válidos:1,2,3,4
void inicializaFiltro(Imagen & filtro, int opcion) {
    if (filtro.M == nullptr)
        reservaMem(filtro, 3, 3);

    switch (opcion){
        case 1:{ // repujado
            filtro.M[0][0] = 2;
            filtro.M[0][1] = -1;
            filtro.M[0][2] = 0;

            filtro.M[1][0] = -1;
            filtro.M[1][1] = 1;
            filtro.M[1][2] = 1;

            filtro.M[2][0] = 0;
            filtro.M[2][1] = 1;
            filtro.M[2][2] = 2;
            break;
        }
        case 2:{ // deteccion bordes
            filtro.M[0][0] = -1;
            filtro.M[0][1] = 0;
            filtro.M[0][2] = 1;

            filtro.M[1][0] = -2;
            filtro.M[1][1] = 0;
            filtro.M[1][2] = 2;

            filtro.M[2][0] = -1;
            filtro.M[2][1] = 0;
            filtro.M[2][2] = 1;
            break;
        }

        case 3:{ // sharpen
            filtro.M[0][0] = 1;
            filtro.M[0][1] = -2;
            filtro.M[0][2] = 1;

            filtro.M[1][0] = -2;
            filtro.M[1][1] = 5;
            filtro.M[1][2] = -2;

            filtro.M[2][0] = 1;
            filtro.M[2][1] = -2;
            filtro.M[2][2] = 1;
            break;
        }

        case 4:{ // desenfoque
            filtro.M[0][0] = 1;
            filtro.M[0][1] = 1;
            filtro.M[0][2] = 1;

            filtro.M[1][0] = 1;
            filtro.M[1][1] = 1;
            filtro.M[1][2] = 1;

            filtro.M[2][0] = 1;
            filtro.M[2][1] = 1;
            filtro.M[2][2] = 1; 
            break;
        }
    }
}

