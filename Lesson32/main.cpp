#include "progressBar.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::once_flag flag;//Ёкземпл€ры класса std::once_flag используютс€ совместно с шаблоном функции std::call_once дл€ гарантии того, что нека€ функци€ будет вызвала ровно один раз, даже если ее могут вызывать одновременно несколько потоков.
std::mutex m1;
std::mutex m2;
std::mutex m3;
std::mutex m4;

static void tableHeader() { std::cout << "#\t" << "id\t" << "Progress Bar\t" << "Time" << std::endl; }//выполнение функции ровно один раз 

static void progressBar(int numberThreadsNow)
{
    //координаты
    int progressBar_c = 16;
    int total = 30;
    int PositionForTime = 32;
    
    std::call_once(flag, tableHeader);//выполнение функции ровно один раз с помощью конкурирующих потоков
        
    m2.lock();//захват потока
    Timer t1;//создаем объект класса Timer 
    consol_parameter d1;//создаем объект класса consol_parameter 
    m2.unlock();//освободили поток

    m4.lock();//захват потока
    d1.SetPosition(0, numberThreadsNow + 1);//переход к следующей координате
    std::cout << numberThreadsNow << "\t" << std::this_thread::get_id() << "\t";//вывод номера и id
    m4.unlock();//освободили поток
   
    while (progressBar_c < total)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));//засыпает
        
        m1.lock();//захват потока
        d1.SetPosition(progressBar_c, numberThreadsNow + 1);//переход к следующей координате
        std::cout << char(176);//символ белый квадрат
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));//засыпает
        
        ++progressBar_c;//увеличение координаты начала прогрессбара
        m1.unlock();//освободили поток
    }
   
    std::this_thread::sleep_for(std::chrono::milliseconds(300));//засыпает
    
    m3.lock();
    d1.SetPosition(PositionForTime, numberThreadsNow + 1);
    t1.print();
    m3.unlock();
}

int main()
{
    int countThreads = 5;//кол-во потоков
    std::vector<std::thread> vectorThreads(countThreads);// вектор vectorThreads состоит из 5 чисел, каждое число равно 0
    
    for (size_t i = 0; i < countThreads; i++)
    {
        vectorThreads[i] = std::thread(progressBar, i);//вызываем функцию progressBar с параметром i
    }
    for (auto& i : vectorThreads)
    {
        i.join();
    }
    std::cout << "\nEND";
    
}