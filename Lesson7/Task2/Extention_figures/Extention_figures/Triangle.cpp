#include "Triangle.h"


    Triangle::Triangle() {
        sides_count = 3;
        name = "�����������: ";
        a = 10;
        b = 20;
        c = 30;
        A = 60;
        B = 50;
        C = 70;
        if (A + B + C != 180) { throw MyEx("����� ����� �� 180!", name); }
    }

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

