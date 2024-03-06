#include <iostream>

enum class months
{
    Ботинки_вездеходы = 1,
    Метла,
    Верблюд,
    Кентавр,
    Орёл,
    Верблюд_быстроход,
    Ковёр_самолет
};

class Transport
{
protected:
    int type;
    int id;
    std::string name;
    int speed;
    int time_driving;
    int time_rest_1;
    int ratio_1;
public:
    void gonka(int* arr, int type, int dist) {
        this->type = type;
        std::cout << name << "Результаты гонки: " << dist << std::endl;
    }
};
class Zemlya :public Transport
{
public:
    Zemlya(){
        type = 1;//наземный
        name = "Гонка для наземного транспорта";
    }
    

};
class Vozduh :public Transport
{
public:
    Vozduh() {
        type = 2;//воздушный
        name = "Гонка для воздушного транспорта";
    }

};
class Vozduh_Zemlya :public Transport
{
public:
    Vozduh_Zemlya() {
        type = 3;//наземный и воздушный
        name = "Гонка для наземного и воздушного транспорта";
    }

};

class Botinki_vezdehody :public Zemlya
{
public:
    int time_rest_2;
public:
    Botinki_vezdehody() {
        name = "Ботинки-вездеходы";
        id = 1;
        speed = 6;
        time_driving = 60;
        time_rest_1 = 10;
        time_rest_2 = 5;
    }
    int result(int dist) {
        int time_not_rest, all_time;
        time_not_rest = dist / speed;
        all_time = time_not_rest;
        if (time_not_rest > time_driving) {
            all_time = all_time + time_rest_1;
            if ((time_not_rest - time_driving) > time_driving) {
                for (int i = time_not_rest - time_driving; i > time_driving; i = i - time_driving) {
                    all_time = all_time + time_rest_2;
                }
            }
        }
        return all_time;
    }
};//1

class Metla :public Vozduh
{
public:
    Metla() {
        id = 2;
        name = "Метла";
        speed = 20;
    }
    double result(int dist) {
        double new_dist, all_time;

        new_dist = static_cast<double>(dist);

        if (dist >= 1000) {
            new_dist = static_cast<double>(dist) * (1- static_cast<double>(dist/1000)/100) ;
        }
        all_time = new_dist / speed;
        return all_time;
    }

};

class Verblud_bystrohod :public Zemlya
{
public:
    double time_rest_2;
    int time_rest_3;
public:
    Verblud_bystrohod() {
        id = 6;
        name = "Верблюд-быстроход";
        speed = 40;
        time_driving = 10; // Время движения до отдыха
        time_rest_1 = 5; // Длительность первого отдыха 
        time_rest_2 = 6.5; // Длительность второго отдыха 
        time_rest_3 = 8; // Длительность всех последующих отдыхов 
    }
    double result(int dist) {
        double time_not_rest, all_time;
        time_not_rest = static_cast<double>(dist) / speed; //Время без учета отдыха
        all_time = time_not_rest;
        if (time_not_rest > time_driving) {
            all_time = all_time + time_rest_1;
            if ((time_not_rest - time_driving) > time_driving) {
                all_time = all_time + time_rest_2;
            }
            if((time_not_rest - time_driving - time_driving) > time_driving){
                for (int i = time_not_rest - time_driving*2; i > time_driving; i = i - time_driving) {
                    all_time = all_time +time_rest_3;
                }
            }
        }
        return all_time;
    }
};

class Kentavr :public Zemlya
{
public:
    Kentavr() {
        id = 4;
        name = "Кентавр";
        speed = 15;
        time_driving = 8;
        time_rest_1 = 2;
       
    }
    int result(int dist) {
        int time_not_rest, all_time;
        time_not_rest = dist / speed;
        all_time = time_not_rest;
        if ((time_not_rest - time_driving) > time_driving) {
                for (int i = time_not_rest; i > time_driving; i = i - time_driving) {
                    all_time = all_time + time_rest_1;
        }
        }
        return all_time;
    }
};

class Orel :public Vozduh
{
public:
    Orel() {
        id = 5;
        name = "Орёл";
        speed = 8;
        
    }
    double result(int dist) {
        double new_dist, all_time;

        new_dist = static_cast<double>(dist)*0.94;
                
        all_time = new_dist / speed;
        return all_time;
    }

};

class Verblud :public Zemlya
{
public:
    int time_rest_2;
public:
    Verblud() {
        id = 3;
        name = "Верблюд";
        speed = 10;
        time_driving = 30;
        time_rest_1 = 5;
        time_rest_2 = 8;
    }
    int result(int dist) {
        int time_not_rest, all_time;
        time_not_rest = dist / speed;
        all_time = time_not_rest;
        if (time_not_rest > time_driving) {
            all_time = all_time + time_rest_1;
            if ((time_not_rest - time_driving) > time_driving) {
                for (int i = time_not_rest - time_driving; i > time_driving; i = i - time_driving) {
                    all_time = all_time + time_rest_2;
                }
            }
        }
        return all_time;
    }
};

class Kover_samolet :public Vozduh
{
public:
    double ratio_1;
    double ratio_2;
    double ratio_3;
public:
    Kover_samolet() {
        id = 7;
        name = "Ковёр-самолёт";
        speed = 10;
        ratio_1 = 0.97;
        ratio_2 = 0.9;
        ratio_3 = 0.95;
    }
    double result(int dist) {
        double new_dist, all_time;
        
        new_dist = static_cast<double>(dist);
               
        if ((dist >= 1000) && (dist < 5000)) {
            new_dist = static_cast<double>(dist) * ratio_1;
        }
        else if ((dist >= 5000) && (dist < 10000)) {
            new_dist = static_cast<double>(dist) * ratio_2;
        }
        else if ((dist >= 10000) && (dist < 100000)) {
            new_dist = static_cast<double>(dist) * ratio_3;
        }
        all_time = new_dist / speed;
        return all_time;
    }

};

void print_razdelitel() {
    std::cout << "------------------------------------------------------\n";
}
void print_reg() {
    std::cout << "1. Ботинки-вездеходы \n2. Метла \n3. Верблюд \n4. Кентавр \n5. Орёл \n6. Верблюд-быстроход \n7. Ковёр-самолет\n0. Завершить регистрацию\n";
}
void zareg(int x) {
    switch (x) {
    case 1: std::cout << "Ботинки-вездеходы" << " "; break;
    case 2: std::cout << "Метла" << " "; break;
    case 3: std::cout << "Верблюд" << " "; break;
    case 4: std::cout << "Кентавр" << " "; break;
    case 5: std::cout << "Орёл" << " "; break;
    case 6: std::cout << "Верблюд-быстроход" << " "; break;
    case 7: std::cout << "Ковёр-самолет" << " "; break;

    }
}

void registration(int x, int type) {
    print_razdelitel();
    switch (x) {
    case 1:
        if (type == 1 || type == 3) { std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl; }
        //if (arr[x-1]!=0) { std::cout << "Ботинки-вездеходы уже зарегистрированы!" << std::endl; }
       // if (type == 2) {std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl;}
        break;
    case 2:
        if (type == 2 || type == 3) { std::cout << "Метла успешно зарегистрирован!" << std::endl; }
        //if (type == 1) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    case 3:
        if (type == 1 || type == 3) { std::cout << "Верблюд успешно зарегистрирован!" << std::endl; }
        //if (type == 2) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    case 4:
        if (type == 1 || type == 3) { std::cout << "Кентавр успешно зарегистрирован!" << std::endl; }
        // if (type == 2) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    case 5:
        if (type == 2 || type == 3) { std::cout << "Орел успешно зарегистрирован!" << std::endl; }
        // if (type == 1) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    case 6:
        if (type == 1 || type == 3) { std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl; }
        // if (type == 2) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    case 7:
        if (type == 2 || type == 3) { std::cout << "Ковёр-самолет успешно зарегистрирован!" << std::endl; }
        //if (type == 1) { std::cout << "Попытка зарегистрировать неправильный тип ТС!" << std::endl; }
        break;
    }
}
void reg_info(double* arr, int dist, int type){
    switch (type) {
    case 1: std::cout << "Гонка для наземного транспорта."; break;
    case 2: std::cout << "Гонка для воздушного транспорта."; break;
    case 3: std::cout << "Гонка для наземного и воздушного транспорта."; break;
    }
    
    std::cout << "Расстояние: " << dist << std::endl;
    std::cout << "Зарегистрированные транспортные средства: ";
        for (int i = 0; i < 7; i++) {
            if (arr[i] != 0) {
            zareg(arr[i]);
            }
        }
        std::cout << std::endl;
}

int quantity(double* arr) {
    int quant = 0;
    for (int i = 0; i < 7; i++) {
        if (arr[i] != 0) {
            quant++;
        }
        
    }
    return quant;
}
void clear_arr(double* arr) {
    for (int i = 0; i < 7; i++) {
        if (arr[i] != 0) {
            arr[i] = 0;
        }
    }
}

void enum_print(int x) {
    switch (x)
    {
    case static_cast<int>(months::Ботинки_вездеходы):
        std::cout << "Ботинки-вездеходы ";
        break;
    case static_cast<int>(months::Метла):
        std::cout << "Метла ";
        break;
    case static_cast<int>(months::Верблюд):
        std::cout << "Верблюд ";
        break;
    case static_cast<int>(months::Кентавр):
        std::cout << "Кентавр ";
        break;
    case static_cast<int>(months::Орёл):
        std::cout << "Орёл ";
        break;
    case static_cast<int>(months::Верблюд_быстроход):
        std::cout << "Верблюд-быстроход ";
        break;
    case static_cast<int>(months::Ковёр_самолет):
        std::cout << "Ковёр-самолет ";
        break;

    }
}


int resultat_gonki(int x, double dist) {

    Verblud verblud;
    Kover_samolet kover_samolet;
    Botinki_vezdehody botinki_vezdehody;
    Metla metla;
    Kentavr kentavr;
    Orel orel;
    Verblud_bystrohod verblud_bystrohod;
    switch (x) {
    case 0:
        return  botinki_vezdehody.result(dist);
    break;
    case 1:
       return   metla.result(dist);
    break;
    case 2:
       return  verblud.result(dist);
    break;
    case 3:
        return   kentavr.result(dist);
    break;
    case 4:
       return  orel.result(dist);
    break;
    case 5:
        return  verblud_bystrohod.result(dist);
    break;
    case 6:
        return  kover_samolet.result(dist);
    break;
    }
}

void gonka(double* arr, double dist,int q) {
    
    double** arr_result = new double* [q];

    for (int i = 0; i < q; i++) {
        arr_result[i] = new double[2];
    }

    int n = 0;
    for (int i = 0; i < 7; i++) {
        if (arr[i] != 0) {
            arr_result[n][0] = arr[i];
            arr_result[n][1] = resultat_gonki(i, dist);
            n++;
        }
    }

    double tmp1, tmp2;
    for (int k = 0; k < q-1; k++) {
        for (int i = 0; i < q - 1; i++) {
            if (arr_result[i + 1][1] < arr_result[i][1]) {
                tmp1 = arr_result[i + 1][1];
                tmp2 = arr_result[i + 1][0];
                arr_result[i + 1][1] = arr_result[i][1];
                arr_result[i + 1][0] = arr_result[i][0];
                arr_result[i][1] = tmp1;
                arr_result[i][0] = tmp2;
            }
        }
    }
    std::cout << "Результаты гонки:\n";
    int num = 1;
    for (int i = 0; i < q; i++) {
        std::cout << num << ". ";
        enum_print(arr_result[i][0]);
        std::cout << " " << arr_result[i][1];
        num++;
        std::cout << "\n";
    }
}
int main()
{

    setlocale(LC_ALL, "rus");

    

    std::cout << "Добро пожаловать в гоночный симулятор! \n";
    int type, distance, reg_yes,TS;
    int reg_or_gonka;
    int exit_or_gonka;
    double arr[7] = { 0,0,0,0,0,0,0 };
     do {
        start:
        std::cout << "1. Гонка для наземного транспорта.\n" << "2. Гонка для воздушного транспорта.\n" << "3. Гонка для наземного и воздушного транспорта.\n";
        std::cout << "Выберите тип гонки: ";
        type:
        std::cin >> type;
        if (type != 1 && type != 2 && type != 3) {goto type;}
        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        distance:
        std::cin >> distance;
        if (distance < 0) { 
            std::cout << "должна быть положительна" << std::endl;
            goto distance; }
        print_razdelitel();
        do
        {   std::cout << "Должно быть зарегестрировано минимум два ТС: \n1. Зарегистрировать ТС.\nВыберите действие: ";
            reg_yes:
            std::cin >> reg_yes;
            if (reg_yes != 1) { goto reg_yes; };
            print_razdelitel();
            do {reg:
                print_reg();
                std::cout << "Выберите ТС или 0 для окончания процесса регистрации. ";
                

                if (type == 1) {
                    std::cin >> TS;
                    if (TS == 2 || TS == 5 || TS == 7) {
                        print_razdelitel();
                        std::cout << "Попытка зарегистрировать неправильный тип ТС!\n";
                        goto registration;
                    }else  
                        if (arr[TS - 1] != 0) {
                            print_razdelitel();
                            enum_print(arr[TS - 1]);
                            
                            std::cout << "уже зарегистрирован!\n";
                            goto reg_info;
                        }
                        goto in_arr;
                }
                if (type == 2) {
                    std::cin >> TS;
                    if (TS == 1 || TS == 3 || TS == 4 || TS==6) {
                        print_razdelitel();
                        std::cout << "Попытка зарегистрировать неправильный тип ТС!\n";
                        goto registration;

                    }else  
                        if (arr[TS - 1] != 0) {
                            print_razdelitel();
                            enum_print(arr[TS - 1]);
                           
                            std::cout << "уже зарегистрирован!\n";
                            goto reg_info;
                        }
                        goto in_arr;
                }
                std::cin >> TS;
                in_arr:
                if (TS == 0) { break; print_razdelitel();};
               
                arr[TS - 1] = TS;
                registration:
                registration(TS, type);
                reg_info:
                reg_info(arr, distance, type);
               
                } while (TS != 0);
                print_razdelitel();
        } while (quantity(arr) < 2);
        
        do{
        std::cout << "1. Зарегистрировать ТС.\n2. Начать гонку\nВыберите действие:";
        std::cin >> reg_or_gonka;
        
            if (reg_or_gonka == 1) {
                 goto reg;
            }else if (reg_or_gonka == 2) {
                print_razdelitel();
                int q = quantity(arr);
                gonka(arr, distance,q);
                
            }
         } while (reg_or_gonka != 2);
        
      
     } while (reg_or_gonka != 2);
    do{
     std::cout << "\n1. Провести еще одну гонку.\n2. Выйти.\nВыберите действие:";
     
     std::cin >> exit_or_gonka;
     if (exit_or_gonka == 1) { 
         print_razdelitel();
         clear_arr(arr);
         goto start; 
     }
     else if (exit_or_gonka == 2) { break; }
      } while (exit_or_gonka != 2);
      print_razdelitel();
      std::cout << "До свидания!\n";
  
}


