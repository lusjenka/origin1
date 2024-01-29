#include "Pryamoug_Triangle.h"

    Pryamoug_Triangle::Pryamoug_Triangle(int a, int b, int c, int A, int B) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;

    }

    Pryamoug_Triangle::Pryamoug_Triangle() {
        name = "Прямоугольный треугольник: ";
        a = 60;
        b = 40;
        c = 30;
        C = 95;
        A = 20;
        B = 70;
        if (C != 90) { throw MyEx("Угол С не равен 90 градусам.", name); }
    }
