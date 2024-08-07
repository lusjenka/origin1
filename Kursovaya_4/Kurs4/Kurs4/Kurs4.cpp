#include <iostream>
#include <chrono>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

std::mutex workQueueMutex; // мьютекс, которым будем делать очередь потокобезопасной
std::queue<std::function<void()>> workQueue; //не потокобезопасная очередь. Тип данных очереди - функция с сигнутурой void(). Будем складывать в очередь функции 
std::atomic<bool> flagDone{ false };// флаг. Потоки будут выполняться пока флагу не присвоить занчение тру

std::vector<std::thread> threadVector; //вектор потоков

void func1()
{
    std::this_thread::sleep_for(std::chrono::microseconds(200));
    std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}

void func2()
{
    std::this_thread::sleep_for(std::chrono::microseconds(200));
    std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}

void addFunc1ToPool()
{
    while (!flagDone)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard lockGuard{ workQueueMutex };  //для безопасности потока используем мьютекс
        std::cout << "Add func1" << std::endl;
        workQueue.push(func1); //каждые 500 милисекунд помещаем в нашу очередь функцию 1

    }

}

void addFunc2ToPool()
{
    while (!flagDone)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::lock_guard lockGuard{ workQueueMutex }; //для безопасности потока используем мьютекс
        std::cout << "Add func2" << std::endl;
        workQueue.push(func2);//каждые 1000 милисекунд помещаем в нашу очередь функцию 2

    }

}

void work()
{
    workQueueMutex.lock();
    std::cout << "Start working thread id: " << std::this_thread::get_id() << std::endl;
    workQueueMutex.unlock();

    while (!flagDone || !workQueue.empty())
    {
        std::lock_guard lockGuard{ workQueueMutex };
        if (!workQueue.empty())
        {
            auto task = workQueue.front();
            workQueue.pop();
            task();
        }
        else
        {
            std::this_thread::yield();
        }
    }
}

int main()
{
    std::thread addFunc1ToPoolThread{ addFunc1ToPool };//занесение функции в поток
    std::thread addFunc2ToPoolThread{ addFunc2ToPool };//занесение функции в поток

    const auto maxThreadCount{ std::thread::hardware_concurrency() }; //кол-во потоков

    for (int i = 0; i < maxThreadCount - 3; i++)//минус 3 - это минус main, addFunc1ToPoolThrea, addFunc2ToPoolThrea
    {
        threadVector.push_back(std::thread(work));
    }

    for (auto& thread : threadVector)
    {
        thread.join();
    }

    addFunc1ToPoolThread.join();
    addFunc2ToPoolThread.join();

    flagDone = true;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
