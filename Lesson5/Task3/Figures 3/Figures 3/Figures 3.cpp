#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Romb.h"
#include "Square.h"
#include "Pryamoug_Triangle.h"
#include "Ravnobed_Triangle.h"
#include "Ravnostor_Triangle.h"


int main()
{
    setlocale(LC_ALL, "rus");
    
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    Pryamoug_Triangle pryamoug_Triangle;
    Ravnostor_Triangle ravnostor_Triangle;
    Ravnobed_Triangle ravnobed_Triangle;
    Parallelogram parallelogram;
    Rectangle rectangle;
    Romb romb;
    square square;

    Figure* par_child = &figure;
    par_child->print_info();

    Figure* par_child1 = &triangle;
    par_child1->print_info();

   Figure* par_child2 = &quadrangle;
    par_child2->print_info();

    Figure* par_child3 = &pryamoug_Triangle;
    par_child3->print_info();

    Figure* par_child4 = &ravnostor_Triangle;
    par_child4->print_info();

    Figure* par_child5 = &ravnobed_Triangle;
    par_child5->print_info();

    Figure* par_child6 = &parallelogram;
    par_child6->print_info();

    Figure* par_child7 = &rectangle;
    par_child7->print_info();

    Figure* par_child8 = &romb;
    par_child8->print_info();

    Figure* par_child9 = &square;
    par_child9->print_info();


}


