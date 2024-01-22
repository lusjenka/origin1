#pragma once
#include "Parallelogram.h"

class Romb : public Parallelogram {
public:
    Romb();
private:
    Romb(int a, int A, int B);
public:
    void bool_check() override;
};
