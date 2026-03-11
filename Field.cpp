#include <iostream>
#include <vector>
#include <conio.h>
#include "Field.h"
using namespace std;

Field::Field(size_t const& size) : size(size) {
    generateStartField(size);
}
void Field::generateStartField(size_t const& size) {
    zeroIndex = size * size - 1;
    field = new int[size * size];

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