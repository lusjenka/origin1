#pragma once
#include "hRectangle.h"

class square : public Rectangle {
public:
    square() {
        name = " вадрат: ";
        a = c = b = d = 20;
        A = C = B = D = 90;
    }
private:
    square(int a) {
        this->a = a = c = b;

    }
public:
    void bool_check() override;
};