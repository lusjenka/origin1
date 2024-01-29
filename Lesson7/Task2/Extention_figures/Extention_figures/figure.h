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
    Figure(std::string name, int sides_count);
public:
    Figure();
public:
    void get_sides_count();
public:
    void get_figure();
public:
    virtual
        void print_info();
};