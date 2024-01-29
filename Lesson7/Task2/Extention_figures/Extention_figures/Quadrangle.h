#pragma once
#include "figure.h"
#include "MyEx.h"

class Quadrangle : public Figure {
public:
    Quadrangle();
protected:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

};