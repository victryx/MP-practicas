#include "proceso.h"
#include <cstring>
#include <string>
#include <iostream>

bool sonIguales(const char cad1[], const char cad2[]) {
    int i = 0;
    bool equal = true;
    while ('\0' != cad1[i] && '\0' != cad2[i] && equal) {
        if (cad1[i] != cad2[i]) {
            equal = false;
        }
        i++;
    }

    return '\0' == cad1[i] && '\0' == cad2[i] && equal;
}

int longitud(const char cad[]) {
    int i = 0;
    while ('\0' != cad[i]) {
        i++;
    }
    return i;
}


// Esta solución asume que la entrada está compuesta por caracteres
// ASCII básicos
int carsUnicos(const char cad1[]) {
    int chars[128] = {0};
    int uniques = 0;
    int i = 0;

    while ('\0' != cad1[i]) {
        chars[cad1[i]]++;
        i++;
    }

    for (i = 0; i < 128; i++) {
        if (chars[i] == 1) {
            uniques++;
        }
    }

    return uniques;
}

// Esta solución asume que la entrada está compuesta por caracteres
// ASCII básicos
// Asumimos que las entradas tienen la misma longitud
bool anagrama(const char cad1[],const char cad2[]) {
    int charsCad1[128] = {0};
    int charsCad2[128] = {0};
    int i = 0;
    bool isAnagram = true;

    while (cad1[i] != '\0') {
        charsCad1[cad1[i]]++;
        charsCad2[cad2[i]]++;
        i++;
    }

    for (i = 0; i < 128 && isAnagram; i++) {
        if (charsCad1[i] != charsCad2[i]) {
            isAnagram = false;
        }
    }
    
    return isAnagram;
}

void sortArray(char arr[]) {
    int len = longitud(arr);
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }   
    }
}

void copyArr(const char src[], char dest[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// En esta solución se comprueba si las cadenas son o no anagramas 
// ordenando previamente los caracteres. 
// Probablemente sea peor porque está ordenando con Bubble sort
bool anagramaOrdenando(const char cad1[], const char cad2[]) {
    char copia1[MAX_SIZE];
    char copia2[MAX_SIZE];

    // Copiar arrays
    copyArr(cad1, copia1);
    copyArr(cad2, copia2);

    // Ordenar copias
    sortArray(copia1);
    sortArray(copia2);

    // Comprobar si son iguales
    int i = 0;
    while (copia1[i] != '\0') {
        if (copia1[i] != copia2[i]) {
            return false; // Un solo return
        }
        i++;
    }

    return true;
}



/**
 * NOTA: Las funciones compress y decompress tienen dos versiones,
 * las primeras no funcionan para comprimir secuencias de más de 9
 * caracteres, las segundas sí.
 */

// Asumimos que la entrada no tiene secuencias de más de 9 caracteres
void compress(const char frase[], char salida []) {
    int left = 0;
    int right = 0;
    int outIndex = 0;

    while(frase[right] != '\0') {
        while (frase[left] == frase[right]) {
            right++;
        }
        char diff = '0' + (right - left);
        salida[outIndex++] = frase[left];
        salida[outIndex++] = diff;
        left = right;
    }
    salida[outIndex] = '\0';
}

// Asumimos que como mucho se comprimen 9 caracteres
void decompress(const char frase[], char salida[]) {
    int i = 0;
    int outIndex = 0;
    while (frase[i] != '\0') {
        char ch = frase[i];
        int digit = frase[i+1] - '0';        
        for (int j = 0; j < digit; j++){
            salida[outIndex++] = ch;
        }
        
        i += 2;
    }
    salida[outIndex] = '\0';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// esta versión admite secuencias de más de 9 caracteres
void advancedCompress(const char frase[], char salida []) {
    int left = 0;
    int right = 0;
    int outIndex = 0;

    while(frase[right] != '\0') {
        while (frase[left] == frase[right]) {
            right++;
        }
        
        salida[outIndex++] = frase[left];

        char diffStr[MAX_SIZE];
        strcpy(diffStr, std::to_string(right - left).c_str());
        int diffStrIndex = 0;
        while (diffStr[diffStrIndex] != '\0') {
            salida[outIndex++] = diffStr[diffStrIndex++];
        }

        left = right;
    }
    salida[outIndex] = '\0';
    
}

// esta versión admite secuencias de más de 9 caracteres
void advancedDecompress(const char frase[], char salida[]) {
    int i = 0;
    int outIndex = 0;
    while (frase[i] != '\0') {
        char ch = frase[i];     // Esto es la letra
        i++;                    // Debería estar seguida por uno o más dígitos

        // Ahora obtenemos los dígitos
        int j = i;

        char digits[4];
        while (isDigit(frase[j])) {
            digits[j - i] = frase[j];
            j++;
        }
        digits[j - i] = '\0';
        int amount = atoi(digits);

        i = j;

        for (int k = 0; k < amount; k++){
            salida[outIndex++] = ch;
        }
    }
    salida[outIndex] = '\0';
}