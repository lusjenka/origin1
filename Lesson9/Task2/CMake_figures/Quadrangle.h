#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
public:
    Quadrangle();
protected:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
public:
    void print_info() override;
public:
    void bool_check() override;
};