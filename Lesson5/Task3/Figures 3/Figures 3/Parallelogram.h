#pragma once
#include "Quadrangle.h"

class Parallelogram : public Quadrangle {

public:

    Parallelogram();
private:
    Parallelogram(int a, int b, int A, int D);
public:
    void bool_check() override;
};