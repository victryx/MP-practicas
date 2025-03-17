#include <iostream>
using namespace std;

void minAndMaxElements(int v[], int len, int * &min, int * &max ) {
    int *p = v;
    min = p;
    max = p;

    for (int i=0; i<len; i++,p++) {
        if (*max < *p) {
            max = p;
        }
        if (*min > *p) {
            min = p;
        }
    }
}

int main() {
    int arr[10] = {0};
    int len = 10;
    int *min = nullptr, *max = nullptr;
    minAndMaxElements(arr, len, min, max);
    cout << "min = " << *min << endl;
    cout << "max = " << *max << endl;

    return (1);
}