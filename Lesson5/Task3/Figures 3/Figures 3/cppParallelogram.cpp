#include "hParallelogram.h"

    void Parallelogram::bool_check()  {
        if (A == C && B == D && a == c && b == d)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };
