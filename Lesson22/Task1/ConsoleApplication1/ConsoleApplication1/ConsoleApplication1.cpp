#include <iostream>
#include <vector>

template <class T>
T sqrt_(T a)
{
    a  *= a;
    return a;
}

int main()
{
    int a = 5;
    std::vector<int> v6{-3, 2, 4, 5}; 
    std::cout << "[IN]: " << a << std::endl << "[OUT]: " << sqrt_(a) <<std::endl;
   
    std::cout << "[IN]: ";
    for(int i = 0; i < v6.size(); i++)
    {
        std::cout << v6.at(i) << " ";
    }
    std::cout << std::endl;
        std::cout << "[OUT]: ";
    for(int i = 0; i < v6.size(); i++)
    {
        std::cout << sqrt_(v6.at(i)) << " ";
    }
    
    return 0;
}
