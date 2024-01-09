#include <iostream>
#include <fstream>
#include <string>

class address {
    private:
        std::string sity;
        std::string street;
        int house;
        int flat;
    public:
        address(std::string sity, std::string street, int house, int flat) {
            this->sity = sity;
            this->street = street;
            this->house = house;
            this->flat = flat;
          }
        address() {
            sity = "Неизвестно";
            street = "Неизвестно";
            house = 0;
            flat = 0;
        }
    public:
        std::string get_output_address(std::string sity, std::string street, int house, int flat) {
            std::string k;
            std::string z = ", ";
            k = sity + z + street + z + std::to_string(house) + z + std::to_string(flat);// строка для записи в файл
            std::cout  << sity << " " << street << " " << house << " " << flat << std::endl;//выводим для наглядности
            return k;
            }

};

int main()
{
    setlocale(LC_ALL, "rus");
   
    std::ifstream fin ("../in.txt");
    
    int i = 0,size_arr;
    if (fin.is_open()) {
        std::string word;
        fin >> word;
        size_arr = std::stoi(word);

        std::string* address_arr = new std::string[(size_arr * 4) + 1];//выделяем память под массив
        fin.close();
        std::ifstream fin2("../in.txt");

        while (getline(fin2, address_arr[i]))//считываем из файла и помещаем в массив
        {
            ++i;
        };

        address ad;

        std::ofstream fout("../out.txt");
        fout << size_arr << std::endl;//выводим кол-во адресов

        for (int i = (size_arr * 4); i > 0; i -= 4) {

            fout << ad.get_output_address(address_arr[i - 3], address_arr[i - 2], std::stoi(address_arr[i - 1]), std::stoi(address_arr[i])) << std::endl;//записываем в файл
        }

        fin.close();
        fout.close();
        delete[] address_arr;
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
    return 0;

}

