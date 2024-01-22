#include "Rectangle.h"


Rectangle::Rectangle() {
        name = "Прямоугольник: ";
        a = c = 10;
        b = d = 20;
        A = C = B = D = 90;
    }

Rectangle::Rectangle(int a, int b, int A) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C = B = D;

    }
    void Rectangle::bool_check() {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
