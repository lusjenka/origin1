#include "Rectangle.h"


Rectangle::Rectangle() {
        name = "�������������: ";
        a = c = 10;
        b = d = 20;
        A = C = B = D = 90;
        if (A != 90) { throw MyEx("���� �� 90 ��������. ", name); }
    }

Rectangle::Rectangle(int a, int b, int A) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C = B = D;

    }

