#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <forward_list>

int main()
{
    std::string s;
   
    std::getline(std::cin, s);
    std::stringstream ss(s);
    std::vector<std::string> vec;
    while (ss >> s) vec.push_back(s);
    for (auto e : vec) std::cout << e << ",";
    std::forward_list<std::string> fl{ vec.begin(), vec.end() };
    fl.sort();
    fl.unique();
    for (auto e : fl) std::cout << e << ",";


}