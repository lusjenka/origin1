#pragma once
#include "Parallelogram.h"

class Rectangle : public Parallelogram {
public:
    Rectangle();
private:
    Rectangle(int a, int b, int A);
public:
    void bool_check() override;
};