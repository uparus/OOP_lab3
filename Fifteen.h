#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Field.h"
using namespace std;

class Fifteen
{
private:
    Field game_field;
    int count;
public:
    Fifteen(size_t size);

    int gameSize() const;
    int getCount() const;
    void draw() const;
    bool isGameOver() const;
    void onKeyPressed(int const& btnCone);
};
