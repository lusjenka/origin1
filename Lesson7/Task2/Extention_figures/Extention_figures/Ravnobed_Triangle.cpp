#include "Ravnobed_Triangle.h"


    Ravnobed_Triangle::Ravnobed_Triangle(int a, int c, int A, int B) {
        this->a = 45;
        this->b = 45;
        this->c = 60;
        this->A = 60;
        this->B = 80;
        this->C = 60;
    }

    Ravnobed_Triangle::Ravnobed_Triangle() {
        name = "�������������� �����������: ";
        b = a = 40;
        c = 30;
        C = A = 55;
        B = 70;
        if (a != b) { throw MyEx("������� a � b �� �����. ", name); }
        else if (A != C) { throw MyEx("���� ��� ��������� �� �����. ", name); }
        else if (A != C && a != b) { throw MyEx("���� ��� ��������� �� �����. ������� a � b �� �����. ", name); }
    }
