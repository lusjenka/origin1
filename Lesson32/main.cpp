#include "progressBar.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::once_flag flag;//���������� ������ std::once_flag ������������ ��������� � �������� ������� std::call_once ��� �������� ����, ��� ����� ������� ����� ������� ����� ���� ���, ���� ���� �� ����� �������� ������������ ��������� �������.
std::mutex m1;
std::mutex m2;
std::mutex m3;
std::mutex m4;

static void tableHeader() { std::cout << "#\t" << "id\t" << "Progress Bar\t" << "Time" << std::endl; }//���������� ������� ����� ���� ��� 

static void progressBar(int numberThreadsNow)
{
    //����������
    int progressBar_c = 16;
    int total = 30;
    int PositionForTime = 32;
    
    std::call_once(flag, tableHeader);//���������� ������� ����� ���� ��� � ������� ������������� �������
        
    m2.lock();//������ ������
    Timer t1;//������� ������ ������ Timer 
    consol_parameter d1;//������� ������ ������ consol_parameter 
    m2.unlock();//���������� �����

    m4.lock();//������ ������
    d1.SetPosition(0, numberThreadsNow + 1);//������� � ��������� ����������
    std::cout << numberThreadsNow << "\t" << std::this_thread::get_id() << "\t";//����� ������ � id
    m4.unlock();//���������� �����
   
    while (progressBar_c < total)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));//��������
        
        m1.lock();//������ ������
        d1.SetPosition(progressBar_c, numberThreadsNow + 1);//������� � ��������� ����������
        std::cout << char(176);//������ ����� �������
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));//��������
        
        ++progressBar_c;//���������� ���������� ������ ������������
        m1.unlock();//���������� �����
    }
   
    std::this_thread::sleep_for(std::chrono::milliseconds(300));//��������
    
    m3.lock();
    d1.SetPosition(PositionForTime, numberThreadsNow + 1);
    t1.print();
    m3.unlock();
}

int main()
{
    int countThreads = 5;//���-�� �������
    std::vector<std::thread> vectorThreads(countThreads);// ������ vectorThreads ������� �� 5 �����, ������ ����� ����� 0
    
    for (size_t i = 0; i < countThreads; i++)
    {
        vectorThreads[i] = std::thread(progressBar, i);//�������� ������� progressBar � ���������� i
    }
    for (auto& i : vectorThreads)
    {
        i.join();
    }
    std::cout << "\nEND";
    
}