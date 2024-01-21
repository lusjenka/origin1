#pragma once
#include "hTriangle.h"

class Pryamoug_Triangle : public Triangle {
private:
    Pryamoug_Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
public:
    void bool_check() override;
public:
    Pryamoug_Triangle() {
        name = "Прямоугольный треугольник: ";
        a = 60;
        b = 40;
        c = 30;
        C = 90;
        A = 20;
        B = 70;
    }
};