#include <iostream>

void rellenar(int *v, int k, int min, int max){
	for(int i = 0; i < k; i++)
		v[i] = (random()% (max - min)) + min;
}

void splitArrayByFirstValue(int v[], int len) {
    int pivot = v[0];
    int left = 1;
    int right = len - 1;
    while (left < right) {
        while (v[left] <= pivot && left < right) {
            left++;
        }
        while (v[right] > pivot && left < right) {
            right--;
        }
        if (left < right) {
            std::swap(v[left], v[right]);
        }
    }
}

void printArray(int* v, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int len = 10;
    int datos[len];

    srand(time(0));
    rellenar(datos, len, -10, 10);
    datos[0] = 0;
    printArray(datos, len);
    splitArrayByFirstValue(datos, len);
    printArray(datos, len);
    return 0;
}