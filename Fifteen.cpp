#include <iostream>
#include <vector>
#include <conio.h>
#include "Fifteen.h"
using namespace std;

Fifteen::Fifteen(size_t size) {
    game_field.generateStartField(size);
}
int Fifteen::getCount() const { return count; }
void Fifteen::draw() const {
    vector<int> field = game_field.getField();
    int size = game_field.getSize();

    for (int i = 0; i < size * size; i++) {
        cout << field[i];
        if ((i + 1) % size == 0) {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
}
bool Fifteen::isGameOver() const {
    vector<int> field = game_field.getField();
    int size = game_field.getSize();

    for (int i = 0; i < size * size - 1; i++) {
        if (field[i] != (i + 1)) return false;
    }

    return field[size * size - 1] == 0;
}
void Fifteen::onKeyPressed(int const& btnCone) {
    switch (btnCone) {
    case 72: {
        game_field.shiftUp();
        count++;
        break;
    }
    case 80: {
        game_field.shiftDown();
        count++;
        break;
    }
    case 75: {
        game_field.shiftLeft();
        count++;
        break;
    }
    case 77: {
        game_field.shiftRight();
        count++;
        break;
    }
    }
}
int Fifteen::gameSize() const {
    int size = game_field.getSize();
    return size;
}

