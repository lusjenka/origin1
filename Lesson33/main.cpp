#include "swapData.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>
#include <mutex>


void swap_Lock(Data& d1, Data& d2)
{
    std::lock(d1.mutex_, d2.mutex_);
    
    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value2 = " << d2.getValue() << ";" << std::endl;

    d1.mutex_.unlock();
    d2.mutex_.unlock();
}

void swap_ScopedLock(Data& d1, Data& d2)
{
    std::scoped_lock lock(d1.mutex_, d2.mutex_);
    
    
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "Id: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value2 = " << d2.getValue() << ";" << std::endl;
}

void swap_UniqueLock(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> lock1(d1.mutex_, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.mutex_, std::defer_lock);
    lock1.lock();
    lock2.lock();
    
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "Id: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value2 = " << d2.getValue() << ";" << std::endl;
    lock1.unlock();
    lock2.unlock();
}

int main()
{
    
    Data d1(11);
    Data d2(22);

    std::cout << "\nbefore:\n";
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value2 = " << d2.getValue() << ";" << std::endl;

    std::thread thread1(swap_Lock, std::ref(d1), std::ref(d2));
    std::thread thread2(swap_ScopedLock, std::ref(d1), std::ref(d2));
    std::thread thread3(swap_UniqueLock, std::ref(d1), std::ref(d2));
    
    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "\nEND";
}