#include <iostream>
#include "Quadrangle.h"

Quadrangle::Quadrangle() {
        sides_count = 4;
        name = "Четырехугольник: ";
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
   
    Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    void Quadrangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << ", " << d << "\nУглы: " << A << ", " << B << ", " << C << ", " << D << std::endl << std::endl;
    };

    void Quadrangle::bool_check() {
        if (A + B + C + D == 360 && sides_count == 4)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
