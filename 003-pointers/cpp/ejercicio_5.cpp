#include <iostream>

void rellenar(int *v, int k, int min, int max) {
	for (int i = 0; i < k; i++) {
		v[i] = (random() % (max - min)) + min;
    }
}

void printArray(int **v, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << *v[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *&p1, int *&p2) {
    int *aux = p1;
    p1 = p2;
    p2 = aux;
}

void sortPointerArray(int **v, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (*v[i] > *v[j]) {
                swap(v[i], v[j]);
                // swap(*v[i], *v[j]);
            }
        }
    }
}

int main() {
    const int len = 10;
    int arr[len];
    int *pointers[len];
    srand(time(0));
    rellenar(arr, len, -10, 10);

    for (int i = 0; i < len; i++) {
        pointers[i] = &arr[i];
    }

    printArray(pointers, len);
    sortPointerArray(pointers+5, len-5);
    printArray(pointers, len);
    
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}