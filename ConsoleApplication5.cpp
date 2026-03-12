#include <iostream>
#include <vector>
#include <conio.h>
#include "pch.h"
using namespace std;

int getCleanKey() {
    int key = _getch();
    if (key == 224 || key == 0) {
        key = _getch();
    }
    return key;
}


int main() {
    size_t size = 6;
    Fifteen game(size);
    do  {
        system("cls");
        cout << "Table size: " << game.gameSize() << "x" << game.gameSize() << endl;
        game.draw();
        cout << "\nMoves: " << game.getCount() << endl;

        int key = getCleanKey();
        game.onKeyPressed(key);
    } while (!game.isGameOver());


    return 0;
}