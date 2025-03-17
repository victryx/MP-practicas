/**
 * @file ejercicio_6.cpp
 * @brief 
 *
 * @author vic
 * @date March 2025
 */
#include <iostream>

const int MAX = 50;

bool isFirstLetter(const char text[], int pos) {
    bool firstInString = pos == 0 && text[pos] != ' ';
    bool previousIsBlank = pos != 0 && text[pos-1] == ' ' && text[pos] != ' ';
    return firstInString || previousIsBlank;
}

bool isLastLetter(const char text[], int pos) {
    return text[pos] != ' ' && (text[pos + 1] == ' ' || text[pos + 1] == '\0');
}

/**
 * NOTA: Las palabras formadas por una sola letra son a la vez principio y final,
 * por lo tanto dos punteros apuntan a esa letra.
 */
char** getEndpoints(char text[]) {
    int i = 0;
    int endpointsIndex = 0;
    char **endpoints = new char*[MAX]; // Array de punteros a char
    while (text[i] != '\0') {
        bool first = isFirstLetter(text, i);
        bool last = isLastLetter(text,i);
        if (first && last) {
            endpoints[endpointsIndex++] = &text[i];
        }
        if (first || last) {
            endpoints[endpointsIndex++] = &text[i];
        }
        i++;
    }
    endpoints[endpointsIndex] = &text[i];

    return endpoints;
}

void printEndpoints(char** endpoints) {
    int i = 0;
    std::string words = "";
    while (*endpoints[i] != '\0') {
        int wordLength = endpoints[i+1] - endpoints[i] + 1;

        for(char *ptr = endpoints[i]; ptr <= endpoints[i+1]; ptr++) {
            words += *ptr;
        }

        words += " -> " + std::to_string(wordLength) + '\n';

        i+=2;
    }

    std::string intro = "La cadena ";
    for (char *ptr = endpoints[0]; ptr < endpoints[i]; ptr++) {
        intro += *ptr;
    }
    intro += "\ncontiene las siguientes palabras:\n";
    

    std::cout << intro << words << std::endl;
}

int main() {
    char text[MAX] = "A VER UNA CASA PERDIDA EN      ALPUJARRAS";

    char** endpoints = getEndpoints(text);
    printEndpoints(endpoints);
    delete [] endpoints;

    return 0;
}