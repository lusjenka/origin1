#pragma once
#include "hFigure.h"
class Triangle : public Figure
{
public:
    Triangle() {
        sides_count = 3;
        name = "Треугольник: ";
        a = 10;
        b = 20;
        c = 30;
        A = 60;
        B = 50;
        C = 70;
    }
protected:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
public:
    void print_info() override;
public:
    void bool_check() override;
};