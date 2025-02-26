// solución anagrama ordenando
// solución anagrama array bool
/*
#include <iostream>

int carsUnicos(char c1[]) {
    int chars[128] = {0};
    int uniques = 0;
    int i = 0;
    while (c1[i] != '\0') {
        if (chars[c1[i]] == 0) {
            uniques++;
        }
        chars[c1[i]]++;
        i++;
    }
    return uniques;
}

int main() {
    char str[] = "AAAbcl";
    std::cout << carsUnicos(str) << std::endl;
}
    
*/