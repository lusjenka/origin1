#pragma once
#include "hParallelogram.h"

class Rectangle : public Parallelogram {
public:
    Rectangle() {
        name = "Прямоугольник: ";
        a = c = 10;
        b = d = 20;
        A = C = B = D = 90;
    }
private:
    Rectangle(int a, int b, int A) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C = B = D;

    }
public:
    void bool_check() override;
};