#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");

    map <char, int> chars;
    map <char, int>::iterator begin, at, end;

    string str;
    cout << "Ввести строку:" << endl;
    getline(cin, str);

    for (unsigned int i = 0; i < str.length(); i++) {
        chars[str[i]]++;
    }

    vector<pair<char, int>> values(chars.begin(), chars.end());
   
    sort(values.begin(), values.end(), [](auto& left, auto& right) {
        return left.second > right.second;
        });

    for (const auto& pair : values) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
      
    return 0;
}
