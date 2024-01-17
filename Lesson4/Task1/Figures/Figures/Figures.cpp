#include <iostream>

class Figure
{
protected:
    std::string name;
    int sides_count;
protected:
    Figure (std::string name, int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }
public:
    Figure()
    {
       name = "Фигура";
       sides_count = 0;
    }
public:
    void get_sides_count() {
        std::cout<< name << ": " << sides_count << std::endl;
    }

};
class Triangle : public Figure {
public:
    Triangle() :Figure("Треугольник", 3){
    
    }
};
class Quadrangle : public Figure {
public:
    Quadrangle() :Figure("Четырехугольник", 4) {
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Количество сторон:\n";
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    figure.get_sides_count();
    triangle.get_sides_count();
    quadrangle.get_sides_count();

}

