#include "Pryamoug_Triangle.h"

Pryamoug_Triangle::Pryamoug_Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
Pryamoug_Triangle::Pryamoug_Triangle() {
    name = "Прямоугольный треугольник: ";
    a = 60;
    b = 40;
    c = 30;
    C = 90;
    A = 20;
    B = 70;
}
    void Pryamoug_Triangle::bool_check() {
        if (C == 90)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
