#pragma once
#include "hParallelogram.h"

class Romb : public Parallelogram {
public:
    Romb() {
        name = "Ромб: ";
        a = c = b = d = 30;
        A = C = 60;
        B = D = 75;
    }
private:
    Romb(int a, int A, int B) {
        this->a = a = c = b;
        this->A = A = C;
        this->B = B = D;
    }
public:
    void bool_check() override;
};
