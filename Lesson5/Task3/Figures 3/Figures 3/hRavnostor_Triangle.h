#pragma once
#include "hTriangle.h"

class Ravnostor_Triangle : public Triangle {
private:
    Ravnostor_Triangle(int a) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = 60;
        this->B = 60;
        this->C = 60;

    }
public:
    Ravnostor_Triangle() {
        name = "Равносторонний треугольник: ";
        a = 40;
        b = 40;
        c = 40;
        A = 60;
        B = 60;
        C = 60;
    }
public:
    void bool_check() override;
};