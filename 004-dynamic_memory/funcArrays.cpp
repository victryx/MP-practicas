/**
 * @file main.cpp
 * @brief Guión memoria dinámica
 *
 * @author vic
 * @date March 2025
 */

#include <iostream>
#include "funcArrays.h"

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void resizeArray(int *&arr, int util, int &size, int newSize) {
    if (newSize >= util) {
        int *ampliado = new int[newSize];
        for (int i = 0; i < util; i++) {
            ampliado[i] = arr[i];
        }
        delete [] arr;
        arr = ampliado;
        size = newSize;
    }
}

void redimensiona(int *&p, int util, int tipo, int &cap) {
    switch (tipo) {
    case 2:
        resizeArray(p, util, cap, cap+TAM_BLOQUE);
        break;
    case 3:
        resizeArray(p, util, cap, cap*2);
        break;
    default:
        resizeArray(p, util, cap, cap+1);
        break;
    }
}

bool contains(const int *arr, int arrSize, int value) {
    bool contains = false;
    for (int i = 0; i < arrSize && !contains; i++) {
        contains = arr[i] == value;
    }
    return contains;
}

int* unir(const int *v1, const int *v2, int n1, int n2, int &unionSize) {
    unionSize = n1 + n2;
    int *unionArr = new int [unionSize];
    int unionArrIndex = 0;

    for (int i = 0; i < n1; i++) {
        unionArr[unionArrIndex++] = v1[i];
    }

    for (int i = 0; i < n2; i++) {
        if (!contains(v1, n1, v2[i])) {
            unionArr[unionArrIndex++] = v2[i];
        }
    }

    resizeArray(unionArr, unionArrIndex, unionSize, unionArrIndex);
    return unionArr;
}

int* interseccion(const int *v1, const int *v2, int n1, int n2, int &intersectionSize) {
    // Nos aseguramos de que v1 es el array con menos elementos
    // así n1 será el tamaño máximo del array intersección
    if (n1 > n2) {
        std::swap(n1, n2);  
        std::swap(v1, v2);
    }

    int *result = new int[n1];
    int resultIndex = 0;

    for (int i = 0; i < n1; i++) {
        if (contains(v2, n2, v1[i])) {
            result[resultIndex++] = v1[i];
        }
    }

    resizeArray(result, resultIndex, n1, resultIndex);
    intersectionSize = resultIndex;
    return result;
}

void multiplos(const int *v, int n, int nro, int *&multiplos, int &multiplosSize) {
    if (multiplos != nullptr) {
        delete [] multiplos;
    }

    int multiplosIndex = 0;
    multiplos = new int[n];
    for (int i = 0; i < n; i++) {
        if (v[i] % nro == 0) {
            multiplos[multiplosIndex++] = v[i];
        }
    }
    multiplosSize = multiplosIndex;
    resizeArray(multiplos, multiplosSize, n, multiplosSize); 
}