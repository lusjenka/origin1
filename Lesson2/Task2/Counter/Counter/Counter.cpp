
#include <iostream>

class Counter
{
private:
    int count=1;
public:
    int get_priv_field() { return count; } 
    void set_begin_count(char value) { count = value; }
    void set_priv_field(char value) { 
        switch (value) {
            case '+': count += 1;
                break;
            case '-': count -= 1;
                break;
            case '=': std::cout <<"Текущее значение счетчика: " << get_priv_field() << "\n";
                break;
            case 'x': std::cout << "До свидания!" << "\n";
                break;
    }
    } 
};
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    Counter counter;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите +,сели да: ";
    char ques;
    std::cin >> ques;
    if (ques == '+') {
        std::cout << "\nВведите начальное значение счётчика: ";
        int begin_count;
        std::cin >> begin_count;
        counter.set_begin_count(begin_count);
    }
      do
        {
        std::cout << "Введите команду('+', '-', '=' или 'x'): ";
        char x;
        std::cin >> x;
        counter.set_priv_field(x);
        //std::cout << counter.get_priv_field();
        if (x == 'x' || x == 'х') { break; }
        } while (true);
     
    
}




