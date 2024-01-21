#pragma once
#include "hTriangle.h"

class Ravnobed_Triangle : public Triangle {
private:
    Ravnobed_Triangle(int a, int c, int A, int B) {
        this->a = a = b;
        this->c = c;
        this->A = A = C;
        this->B = B;
    }
public:
    Ravnobed_Triangle() {
        name = "Равнобедренный треугольник: ";
        a = 40;
        b = 40;
        c = 30;
        A = 55;
        C = 55;
        B = 70;
    }
public:
    void bool_check() override;
};