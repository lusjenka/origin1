#include <iostream>
#include "Triangle.h"

    Triangle::Triangle() {
    sides_count = 3;
    name = "Треугольник: ";
    a = 10;
    b = 20;
    c = 30;
    A = 60;
    B = 50;
    C = 70;
}

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    void Triangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << "\nУглы: " << A << ", " << B << ", " << C << std::endl << std::endl;
    };

    void Triangle::bool_check() {
        if (A + B + C == 180)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
