#pragma once
#include "figure.h"
#include "MyEx.h"


class Triangle : public Figure
{
public:
    Triangle();
protected:
    Triangle(int a, int b, int c, int A, int B, int C);
};
