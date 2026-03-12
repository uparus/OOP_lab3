#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <random>
#include <ctime>
#include "Field.h"
using namespace std;

Field::Field(size_t const& size) : size(size), field(new int[size * size]), zeroIndex(size* size - 1){
    generateStartField(size);
}
void Field::generateStartField(size_t const& size) {
    /*this->size = size;
    field = new int[size * size];*/
    for (size_t i = 0; i < size * size - 1; i++) {
        field[i] = i + 1;
    }

    field[size * size - 1] = 0;
}
size_t Field::getSize() const { return size; }
size_t Field::getZeroIndex() const { return zeroIndex; }
vector<int> Field::getField() const {
    vector<int> result;
    for (int i = 0; i < size * size; i++) {
        result.push_back(field[i]);
    }
    return result;
}
void Field::shiftUp() {
    if (zeroIndex >= size) {
        int newIndex = zeroIndex - size;
        swap(field[zeroIndex], field[newIndex]);
        zeroIndex = newIndex;
    }
}

void Field::shiftLeft() {
    if (zeroIndex % size != 0) {
        int newIndex = zeroIndex - 1;
        swap(field[zeroIndex], field[newIndex]);
        zeroIndex = newIndex;
    }
}
void Field::shiftDown() {
    if (zeroIndex < size * size - size) {
        int newIndex = zeroIndex + size;
        swap(field[zeroIndex], field[newIndex]);
        zeroIndex = newIndex;
    }
}
void Field::shiftRight() {
    if (zeroIndex % size != size - 1) {
        int newIndex = zeroIndex + 1;
        swap(field[zeroIndex], field[newIndex]);
        zeroIndex = newIndex;
    }
}

enum shuffleOption { SHIFT_RIGHT = 1, SHIFT_LEFT = 2, SHIFT_UP = 3, SHIFT_DOWN = 4 };
void Field::shuffleField() {
    srand(time(NULL));
    const int shuffleAmount = 100;
    for (int i = 0; i < shuffleAmount; i++) {
        int shuffleOption = 1 + rand() % (4 - 1 + 1);
        switch (shuffleOption) {
        case shuffleOption::SHIFT_RIGHT:
            shiftRight();
            break;
        case shuffleOption::SHIFT_LEFT:
            shiftLeft();
            break;
        case shuffleOption::SHIFT_UP:
            shiftUp();
            break;
        case shuffleOption::SHIFT_DOWN:
            shiftDown();
            break;
        }
    }
}
     
   