#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
class Field
{
private:
    int size;
    int* field;
    int zeroIndex;

    Field(const Field&) = delete;
    Field& operator=(const Field&) = delete;

public:
    Field(size_t const& size = 4);
    void generateStartField(size_t const& size = 4);

    size_t getSize() const;
    size_t getZeroIndex() const;
    vector<int> getField() const;

    void shiftUp();
    void shiftLeft();
    void shiftDown();
    void shiftRight();
    void shuffleField();
    ~Field() {
        delete[] field;
    }
};