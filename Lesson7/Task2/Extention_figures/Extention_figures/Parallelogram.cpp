#include "Parallelogram.h"

Parallelogram::Parallelogram() {
        name = "��������������: ";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
        if (a != c || b != d) { throw MyEx("��������������� ������� �� �����", name); }
        else if (A != C || B != D) { throw MyEx("��������������� ���� �� �����", name); }
        else if ((A != C || B != D) && (a != c || b != d)) { throw MyEx("��������������� ���� �� �����. ��������������� ������� �� �����. ", name); }
    }

Parallelogram::Parallelogram(int a, int b, int A, int D) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C;
        this->B = B = D;
    }
