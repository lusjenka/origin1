#include "Ravnostor_Triangle.h"


    Ravnostor_Triangle::Ravnostor_Triangle(int a) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;

    }

    Ravnostor_Triangle::Ravnostor_Triangle() {
        name = "�������������� �����������: ";
        a = 60;
        b = 60;
        c = 60;
        A = 60;
        C = 60;
        B = 60;
        if (a != b) { throw MyEx("������� �� ����� ���� �����. ", name); }
    }

