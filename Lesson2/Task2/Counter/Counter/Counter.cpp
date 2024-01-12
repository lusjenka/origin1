
#include <iostream>

class Counter
{
private:
    int count;
public:
    
    Counter(int count) {
        this->count = count;
    }
    Counter() {
        count = 1;
    }
    int get_priv_field() { return count; }
    
    void plus() {
        count += 1;
    }
    void minus() {
        count -= 1;
    }
        
};
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    Counter counter;
  
      do
        {
        std::cout << "Введите команду('+', '-', '=' или 'x'): ";
        char x;
        std::cin >> x;
            switch (x) {
            case '+': counter.plus();
                break;
            case '-': counter.minus();
                break;
            case '=': std::cout << "Текущее значение счетчика: " << counter.get_priv_field() << "\n";
                break;
            case 'x': std::cout << "До свидания!" << "\n";
                break;
            }
        
        if (x == 'x' || x == 'х') { break; }
        } while (true);
     
    
}




