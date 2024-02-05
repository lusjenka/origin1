#pragma once
#include "Rectangle.h"

class square : public Rectangle {
public:
    square();
private:
    square(int a);
public:
    void bool_check() override;
};