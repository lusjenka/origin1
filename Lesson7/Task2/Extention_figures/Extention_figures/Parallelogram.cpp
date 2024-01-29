#include "Parallelogram.h"

Parallelogram::Parallelogram() {
        name = "Параллелограмм: ";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
        if (a != c || b != d) { throw MyEx("Противоположные стороны не равны", name); }
        else if (A != C || B != D) { throw MyEx("Противоположные углы не равны", name); }
        else if ((A != C || B != D) && (a != c || b != d)) { throw MyEx("Противоположные углы не равны. Противоположные стороны не равны. ", name); }
    }

Parallelogram::Parallelogram(int a, int b, int A, int D) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C;
        this->B = B = D;
    }
