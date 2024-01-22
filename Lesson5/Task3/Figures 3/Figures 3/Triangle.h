#pragma once
#include "Figure.h"
class Triangle : public Figure
{
public:
    Triangle();
protected:
    Triangle(int a, int b, int c, int A, int B, int C);
public:
    void print_info() override;
public:
    void bool_check() override;
};