#include <iostream>
#include "hFigure.h"

/*
class Figure
{
protected:
    int a, b, c, d, A, B, C, D;


public:
    std::string name;
    int sides_count;
protected:
    Figure(std::string name, int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }
public:
    Figure()
    {
        name = "Фигура: ";
        sides_count = 0;
    }
public:
    void get_sides_count() {
        std::cout << name << std::endl;
    }

public:
    virtual
        void print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count << std::endl << std::endl;
    };
public:
    virtual
        void bool_check() {
        if (sides_count == 0)
        {std::cout << "\nПравильная ";}
        else{ std::cout << "\nНеправильная "; }
    };
};
*/
class Triangle : public Figure
{
public:
    Triangle() {
        sides_count = 3;
        name = "Треугольник: ";
        a = 10;
        b = 20;
        c = 30;
        A = 60;
        B = 50;
        C = 70;
    }
protected:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
public:
    void print_info() override {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << "\nУглы: " << A << ", " << B << ", " << C << std::endl << std::endl;
    };
public:
    void bool_check() override {
        if (A+B+C == 180)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Quadrangle : public Figure {
public:
    Quadrangle() {
        sides_count = 4;
        name = "Четырехугольник: ";
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
protected:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
public:
    void print_info() override {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << ", " << d << "\nУглы: " << A << ", " << B << ", " << C << ", " << D << std::endl << std::endl;
    };
public:
    void bool_check() override {
        if (A + B + C + D == 360 && sides_count==4)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Parallelogram : public Quadrangle {

public:

    Parallelogram() {
        name = "Параллелограмм: ";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }
private:
    Parallelogram(int a, int b, int A, int D) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C;
        this->B = B = D;
    }
public:
    void bool_check() override {
        if (A == C && B== D && a==c && b==d)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Rectangle : public Parallelogram {
public:
    Rectangle() {
        name = "Прямоугольник: ";
        a = c = 10;
        b = d = 20;
        A = C = B = D = 90;
    }
private:
    Rectangle(int a, int b, int A) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C = B = D;

    }
public:
    void bool_check() override {
        if (a == c && b == d && A==90 && B==90 && C==90 && D==90)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Romb : public Parallelogram {
public:
    Romb() {
        name = "Ромб: ";
        a = c = b = d = 30;
        A = C = 60;
        B = D = 75;
    }
private:
    Romb(int a, int A, int B) {
        this->a = a = c = b;
        this->A = A = C;
        this->B = B = D;
    }
public:
    void bool_check() override {
        if (a == b && b==c && c == d && A == C && B == D)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class square : public Rectangle {
public:
    square() {
        name = "Квадрат: ";
        a = c = b = d = 20;
        A = C = B = D = 90;
    }
private:
    square(int a) {
        this->a = a = c = b;

    }
public:
    void bool_check() override {
        if (A == C && C == B && B == D && D== 90 && a == c && c== b && b== d)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Pryamoug_Triangle : public Triangle {
private:
    Pryamoug_Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
public:
    void bool_check() override {
        if (C == 90)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
public:
    Pryamoug_Triangle() {
        name = "Прямоугольный треугольник: ";
        a = 60;
        b = 40;
        c = 30;
        C = 90;
        A = 20;
        B = 70;
    }
};
class Ravnobed_Triangle : public Triangle {
private:
    Ravnobed_Triangle(int a, int c, int A, int B) {
        this->a = a = b;
        this->c = c;
        this->A = A = C;
        this->B = B;
    }
public:
    Ravnobed_Triangle() {
        name = "Равнобедренный треугольник: ";
        a = 40;
        b = 40;
        c = 30;
        A = 55;
        C = 55;
        B = 70;
    }
public:
    void bool_check() override {
        if (a==b && A==C)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};
class Ravnostor_Triangle : public Triangle {
private:
    Ravnostor_Triangle(int a) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = 60;
        this->B = 60;
        this->C = 60;

    }
public:
    Ravnostor_Triangle() {
        name = "Равносторонний треугольник: ";
        a = 40;
        b = 40;
        c = 40;
        A = 60;
        B = 60;
        C = 60;
    }
public:
    void bool_check() override {
        if (a == b && b == c && A==B && B==C)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
};

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


