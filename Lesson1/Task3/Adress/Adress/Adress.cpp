#include <iostream>

struct adress {
    std::string city;
    std::string street;
    int number_house;
    int number_flat;
    int index;
};


void output_stuct(adress& p) {
    std::cout << "Город: " << p.city << "\n"
        << "Улица: " << p.street << "\n"
        << "Номер дома: " << p.number_house << "\n"
        << "Номер квартиры: " << p.number_flat << "\n"
        << "Индекс: " << p.index << "\n";
}

int main(int argc, char** argv) {
    system("chcp 1251>nul");
    adress adr;
    std::cout << "Введите город: \n";
    std::cin >> adr.city;
    std::cout << "Введите улицу: \n";
    std::cin >> adr.street;
    std::cout << "Введите номер дома: \n";
    std::cin >> adr.number_house;
    std::cout << "Введите номер квартиры: \n";
    std::cin >> adr.number_flat;
    std::cout << "Введите ваш индекс: \n";
    std::cin >> adr.index;
    output_stuct(adr);

}
