#include "Rectangle.h"


Rectangle::Rectangle() {
        name = "Прямоугольник: ";
        a = c = 10;
        b = d = 20;
        A = C = B = D = 90;
        if (A != 90) { throw MyEx("Углы не 90 градусов. ", name); }
    }

Rectangle::Rectangle(int a, int b, int A) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C = B = D;

    }

