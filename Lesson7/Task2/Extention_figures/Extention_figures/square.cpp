#include "square.h"


    square::square() {
        name = "�������: ";
        a = c = b = d = 20;
        A = C = B = D = 90;

        if (a != d || b!=c || c!=d) { throw MyEx("������� �� �����", name); }
        if (A != 90 || B != 90 || C != 90 || D != 90) { throw MyEx("���� �� 90 ��������. ", name); }
        else if ((A != 90 || B != 90 || C != 90 || D != 90) && (a != d || b != c || c != d)) { throw MyEx("���� �� 90 ��������. ������� �� �����. ", name); }
    }

    square::square(int a) {
        this->a = a = c = b;
    }

