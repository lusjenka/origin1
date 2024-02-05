#pragma once
#include "Triangle.h"

class Ravnostor_Triangle : public Triangle {
private:
    Ravnostor_Triangle(int a);
public:
    Ravnostor_Triangle();
public:
    void bool_check() override;
};