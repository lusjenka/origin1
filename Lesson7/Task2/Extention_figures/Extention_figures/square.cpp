#include "square.h"


    square::square() {
        name = "Квадрат: ";
        a = c = b = d = 20;
        A = C = B = D = 90;

        if (a != d || b!=c || c!=d) { throw MyEx("Стороны не равны", name); }
        if (A != 90 || B != 90 || C != 90 || D != 90) { throw MyEx("Углы не 90 градусов. ", name); }
        else if ((A != 90 || B != 90 || C != 90 || D != 90) && (a != d || b != c || c != d)) { throw MyEx("Углы не 90 градусов. Стороны не равны. ", name); }
    }

    square::square(int a) {
        this->a = a = c = b;
    }

