#include <iostream>


void delete_two_dim_array(double** matrix, int rows);

class Transport
{
protected:
    int type;
    int id;
    std::string name;
    double speed;
    double time_driving;
    double time_rest_1;
    double ratio_1;

public:
    void get_info_TS() {
       std::cout << id << ". " << name << std::endl;
    }
public:
    virtual
        void print_info() {
        this->get_info_TS();
    };
public:
    void get_info_type() {
        std::cout << type << ". " << name << std::endl;
    }
public:
    virtual
        void print_type() {
        this->get_info_type();
    };

};
class Zemlya :public Transport
{
public:
    Zemlya(){
        type = 1;
        name = "Гонка для наземного транспорта";
    }
    

};
class Vozduh :public Transport
{
public:
    Vozduh() {
        type = 2;
        name = "Гонка для воздушного транспорта";
    }

};
class Vozduh_Zemlya :public Transport
{
public:
    Vozduh_Zemlya() {
        type = 3;
        name = "Гонка для наземного и воздушного транспорта";
    }

};

class Botinki_vezdehody :public Zemlya
{
public:
    double time_rest_2;
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
        double time_not_rest, all_time;
        time_not_rest = static_cast<double>(dist) / speed;
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
    double time_rest_3;
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
        double time_not_rest, all_time;
        time_not_rest = static_cast<double>(dist) / speed;
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
    double time_rest_2;
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
        double time_not_rest, all_time;
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
    for (int i = 0; i < 7; i++) {
        std::cout << arr[i]<< " ";
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
        zareg(arr_result[i][0]);
        std::cout << " " << arr_result[i][1];
        num++;
        std::cout << "\n";
    }
    delete_two_dim_array(arr_result, q);
}

void print_info(Transport* f)
{
    f->print_info();
}
void print_type(Transport* f)
{
    f->print_type();
}
void delete_two_dim_array(double** matrix, int rows) {

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{

    setlocale(LC_ALL, "rus");
    Zemlya zemlya;
    Vozduh vozduh;
    Vozduh_Zemlya vozduh_Zemlya;
    Verblud verblud;
    Kover_samolet kover_samolet;
    Botinki_vezdehody botinki_vezdehody;
    Metla metla;
    Kentavr kentavr;
    Orel orel;
    Verblud_bystrohod verblud_bystrohod;

    

    std::cout << "Добро пожаловать в гоночный симулятор! \n";
    int type;
    double distance;
    int TS;
    int reg_yes;
    int reg_or_gonka;
    int exit_or_gonka;
    double arr[7] = { 0,0,0,0,0,0,0 };
     do {
        start:
        print_type(&zemlya);
        print_type(&vozduh);
        print_type(&vozduh_Zemlya);
        std::cout << "Выберите тип гонки: ";
        do {
            std::cin >> type;
            if (type != 1 && type != 2 && type != 3) {
                std::cout << "Введите 1, 2 или 3" << std::endl;
            }
        } while (type != 1 && type != 2 && type != 3);
        
        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        do {
            std::cin >> distance;
            if (distance < 0) {
                std::cout << "Должна быть положительна" << std::endl;
            }
        } while (distance < 0);
                   
        print_razdelitel();
        do
        {   std::cout << "Должно быть зарегестрировано минимум два ТС: \n1. Зарегистрировать ТС.\nВыберите действие: ";
    
        do {
            std::cin >> reg_yes;
            if (reg_yes != 1) {
                std::cout << "Введите 1" << std::endl;
            }
        } while (reg_yes != 1);
        print_razdelitel();
            do {
            reg:
           
            reg_info(arr, distance, type);

            print_info(&botinki_vezdehody);
            print_info(&metla);
            print_info(&verblud);
            print_info(&kentavr);
            print_info(&orel);
            print_info(&verblud_bystrohod);
            print_info(&kover_samolet);

                std::cout << "Выберите ТС или 0 для окончания процесса регистрации. ";

                if (type == 1) {
                    std::cin >> TS;
                    if (TS == 2 || TS == 5 || TS == 7) {
                        print_razdelitel();
                        std::cout << "Попытка зарегистрировать неправильный тип ТС!\n";
                    }else  
                        if (arr[TS - 1] != 0 && TS!=0) {
                            print_razdelitel();
                            zareg(arr[TS - 1]);
                            std::cout << "уже зарегистрирован!\n";
                        }
                        else if(TS == 1 || TS == 3 || TS == 4 || TS == 6){
                            arr[TS - 1] = TS;
                            print_razdelitel();
                            zareg(arr[TS - 1]);
                            std::cout << "успешно зарегистрирован!\n";
                            
                        }
                }
                else if (type == 2) {
                    std::cin >> TS;
                    if (TS == 1 || TS == 3 || TS == 4 || TS==6) {
                        print_razdelitel();
                        std::cout << "Попытка зарегистрировать неправильный тип ТС!\n";
                       
                    }else  
                        if (arr[TS - 1] != 0 && TS != 0) {
                            print_razdelitel();
                            zareg(arr[TS - 1]);
                            std::cout << "уже зарегистрирован!\n";
                        }
                        else if (TS == 2 || TS == 5 || TS == 7) {
                            arr[TS - 1] = TS;
                            print_razdelitel();
                            zareg(arr[TS - 1]);
                            std::cout << "успешно зарегистрирован!\n";
                            
                        }
                }
                else if (type == 3) {
                  
                        std::cin >> TS;
                        arr[TS - 1] = TS;
                        print_razdelitel();
                        zareg(arr[TS - 1]);
                        std::cout << "успешно зарегистрирован!\n";
                    
                }
                else if(TS == 0) { break; print_razdelitel(); };
                              
                } while (TS != 0);
                print_razdelitel();
        } while (quantity(arr) < 2);
        
        do{
        std::cout << "1. Зарегистрировать ТС.\n2. Начать гонку\nВыберите действие:";
        std::cin >> reg_or_gonka;
        
            if (reg_or_gonka == 1) {
                print_razdelitel();
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

      return 0;
  
}


