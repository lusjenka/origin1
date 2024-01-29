#include "Quadrangle.h"

    Quadrangle::Quadrangle() {
        sides_count = 4;
        name = "Четырехугольник: ";
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 110;
        B = 70;
        C = 120;
        D = 60;
        if (A + B + C + D != 360) { throw MyEx("Сумма углов не 360!", name); }
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

