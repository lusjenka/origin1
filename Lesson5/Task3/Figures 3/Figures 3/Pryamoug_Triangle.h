#pragma once
#include "Triangle.h"

class Pryamoug_Triangle : public Triangle {
private:
    Pryamoug_Triangle(int a, int b, int c, int A, int B, int C);
public:
    void bool_check() override;
public:
    Pryamoug_Triangle();
};