#include <iostream>
#include <vector>
#include <conio.h>
#include "Fifteen.h"
using namespace std;

Fifteen::Fifteen(size_t& size) : count{ 0 },game_field(size) {
    //game_field.generateStartField(size);
    game_field.shuffleField();
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
            cout << "\t";
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

enum options{ARROW_UP = 72, ARROW_DOWN = 80, ARROW_LEFT = 75, ARROW_RIGHT = 77};
void Fifteen::onKeyPressed(int const& btnCone) {
    switch (btnCone) {
    case options::ARROW_UP: {
        game_field.shiftUp();
        count++;
        break;
    }
    case options::ARROW_DOWN: {
        game_field.shiftDown();
        count++;
        break;
    }
    case options::ARROW_LEFT: {
        game_field.shiftLeft();
        count++;
        break;
    }
    case options::ARROW_RIGHT: {
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

