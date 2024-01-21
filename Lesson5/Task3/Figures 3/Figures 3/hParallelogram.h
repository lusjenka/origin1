#pragma once
#include "hQuadrangle.h"

class Parallelogram : public Quadrangle {

public:

    Parallelogram() {
        name = "ֿאנאככוכמדנאלל: ";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }
private:
    Parallelogram(int a, int b, int A, int D) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C;
        this->B = B = D;
    }
public:
    void bool_check() override;
};