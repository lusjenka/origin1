#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include "parser.h"

int main()
{
    std::setlocale(LC_ALL, "rus");

    try
    {
        iniParser pars1("test.ini");

        std::cout << "[Section1] var3 = " << pars1.getValue<std::string>("Section1", "var3") << std::endl << std::endl;
        std::cout << "[Section2] var1 = " << pars1.getValue<int>("Section2", "var1") << std::endl << std::endl;
        std::cout << "[Section1] var1 = " << pars1.getValue<double>("Section1", "var1") << std::endl << std::endl;
        std::cout << "[Section2] var2 = " << pars1.getValue<std::string>("Section2", "var2") << std::endl << std::endl;
        std::cout << "[Section10] var5 = " << pars1.getValue<double>("Section10", "var5") << std::endl << std::endl;
       

    }
    catch (const std::runtime_error& ex)
    {
        std::cout << "Îøèáêà. " << ex.what() << std::endl;
    }
   
    return 0;
}