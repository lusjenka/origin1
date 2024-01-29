
#include "Romb.h"

    Romb::Romb() {
        name = "Ромб: ";
        a = c = b = d = 30;
        A = 60;
        C = 70;
        B = D = 75;
        if (a != b || c!= b ||b != d) { throw MyEx("Стороны не равны", name); }
        else if (A != C || B != D) { throw MyEx("Противоположные углы не равны", name); }
        else if ((A != C || B != D) && (a != b || c != b || b != d)) { throw MyEx("Противоположные углы не равны. Стороны не равны. ", name); }
    }

    Romb::Romb(int a, int A, int B) {
        this->a = a = c = b;
        this->A = A = C;
        this->B = B = D;
    }
