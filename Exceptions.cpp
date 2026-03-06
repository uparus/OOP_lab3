#include <iostream>
#include <conio.h>
#include "Exceptions.h"
using namespace std;

char Exceptions::allowedIndex() {
    char letter = _getch();
    char allowedLetters[] = {'x'};
    int size = sizeof(allowedLetters) / sizeof(allowedLetters[0]);
    for (int i = 0; i < size; i++) {
        if (letter == allowedLetters[i]) return allowedLetters[i];
    }
    return 0;
}