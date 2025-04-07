#include <iostream>
#include "funcArrays.h"

void testRedimensiona();
void testUnionInterseccion();
void testMultiplos();
void printArr(const int *arr, int size);

int main() {
    std::cout << "\n\nTEST REDIMENSIONA\n";
    testRedimensiona();
    std::cout << "\n\nTEST UNION INTERSECCIÓN\n";
    testUnionInterseccion();
    std::cout << "\n\nTEST MÚLTIPLOS\n";
    testMultiplos();
}

void testRedimensiona() {
    int arrSize = 5;
    int *arr1 = new int[arrSize]{0,1,2,3,4};

    printArr(arr1, arrSize);
    redimensiona(arr1, arrSize, 1, arrSize);
    printArr(arr1, arrSize);
    redimensiona(arr1, arrSize, 2, arrSize);
    printArr(arr1, arrSize);
    redimensiona(arr1, arrSize, 3, arrSize);
    printArr(arr1, arrSize);

    delete [] arr1;
}

void testUnionInterseccion() {
    int arr1Size = 5, arr2Size = 10;
    int unionSize = 0, intersectionSize = 0;
    int *arr1 = new int[arr1Size]{0,1,2,3,4};
    int *arr2 = new int[arr2Size]{-100, -40, 0, 2, 3, 100, 40, 30, 11, 12};
    int *unionArr = unir(arr1, arr2, arr1Size, arr2Size, unionSize);
    int *intersectionArr = interseccion(arr1, arr2, arr1Size, arr2Size, intersectionSize);


    std::cout << "Array 1: ";
    printArr(arr1, arr1Size);
    std::cout << "Array 2: ";
    printArr(arr2, arr2Size);

    std::cout << "Array union: ";
    printArr(unionArr, unionSize);
    std::cout << "Array interseccion: ";
    printArr(intersectionArr, intersectionSize);

    delete [] arr1;
    delete [] arr2;
    delete [] unionArr;
    delete [] intersectionArr;
}

void testMultiplos() {
    int arrSize = 10;
    int *arr = new int[arrSize]{0, 2, 6, 9, 12, 20, 22, -2, -3, -6};
    std::cout << "Array: ";
    printArr(arr, arrSize);

    int multiplos2Size = 0;
    int *multiplos2 = nullptr;
    multiplos(arr, arrSize, 2, multiplos2, multiplos2Size);
    std::cout << "Múltiplos de 2 en array: ";
    printArr(multiplos2, multiplos2Size);

    int multiplos3Size = 0;
    int *multiplos3 = nullptr;
    multiplos(arr, arrSize, 3, multiplos3, multiplos3Size);
    std::cout << "Múltiplos de 3 en array: ";
    printArr(multiplos3, multiplos3Size);

    delete [] arr;
    delete [] multiplos2;
    delete [] multiplos3;
}

void printArr(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}