#include <iostream>
#include "MyEx.h"
#include <string>
#include "figure.h"
#include "Quadrangle.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Romb.h"
#include "square.h"
#include "Pryamoug_Triangle.h"
#include "Ravnobed_Triangle.h"
#include "Ravnostor_Triangle.h"



void print_info(Figure* f)
{
    f->print_info();
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Фигуры\n\n";
    
    try {
        Triangle triangle;
        print_info(&triangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << std::endl << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Pryamoug_Triangle pryamoug_Triangle;
        print_info(&pryamoug_Triangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << std::endl << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Ravnostor_Triangle ravnostor_Triangle;
        print_info(&ravnostor_Triangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << std::endl << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Ravnobed_Triangle ravnobed_Triangle;
        print_info(&ravnobed_Triangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << std::endl << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Quadrangle quadrangle;
        print_info(&quadrangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Parallelogram parallelogram;
        print_info(&parallelogram);
    }
    catch (const MyEx& ex)
    {
        std::cout << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Rectangle rectangle;
        print_info(&rectangle);
    }
    catch (const MyEx& ex)
    {
        std::cout << ex.getMessage() << std::endl << std::endl;
    }
    try {
        Romb romb;
        print_info(&romb);
    }
    catch (const MyEx& ex)
    {
        std::cout << ex.getMessage() << std::endl << std::endl;
    }
    try {
        square square;
        print_info(&square);
    }
    catch (const MyEx& ex)
    {
        std::cout << ex.getMessage() << std::endl << std::endl;
    }
}

