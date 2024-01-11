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
    std::string getLog() {
        std::string k;
        std::string z = ", ";
        k = sity + z + street + z + std::to_string(house) + z + std::to_string(flat);// строка для записи в файл
        std::cout << sity << " " << street << " " << house << " " << flat << std::endl;//выводим для наглядности
        return k;
    }
    void sort(address* addresses, int size) {
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size - 1; ++i) {
                if (addresses[i].sity > addresses[i + 1].sity) {
                    address tmp = addresses[i];
                    addresses[i] = addresses[i + 1];
                    addresses[i + 1] = tmp;
                }
            }
        }

    }
       
    void setLog(std::ifstream& fin)
    {
        fin >> this->sity;
        fin >> this->street;
        fin >> this->house;
        fin >> this->flat;
    }
   
};

int main()
{
    setlocale(LC_ALL, "rus");

    std::ifstream fin("../in.txt");

    int i = 0, size_arr;
    if (fin.is_open()) {
        std::string word;
        fin >> word;
        size_arr = std::stoi(word);

        address* address_arr = new address[size_arr];//выделяем память под массив
        

       for (int i = 0; i < size_arr; i++) {
            
            address_arr[i].setLog(fin);
        }

       address_arr[size_arr].sort(address_arr, size_arr);

       std::ofstream fout("../out.txt");
       fout << size_arr << std::endl;

        for(int i = 0; i < size_arr; i++)
        {
            fout << address_arr[i].getLog()<<std::endl;
            
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

