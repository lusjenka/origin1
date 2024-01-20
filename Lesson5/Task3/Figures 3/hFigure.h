#pragma once
#include <iostream>
class Figure
{
protected:
    int a, b, c, d, A, B, C, D;


public:
    std::string name;
    int sides_count;
protected:
    Figure();
public:
    Figure();
public:
    void get_sides_count();
public:
    virtual
        void print_info();
public:
    virtual
        void bool_check();
};