#include <iostream>
#include <chrono>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>


template<class T>
class SafeQueue {
    public:
        void push(T work) {
            std::unique_lock<std::mutex> lockMutex(queueMutex);
            queueOfWorks.push(work);
        };
        T pop() {
            std::unique_lock<std::mutex> lockMutex(queueMutex);
            T work = std::move(queueOfWorks.front());
            queueOfWorks.pop();
            return work;
        };
        bool empty() {
            std::unique_lock<std::mutex> lock(queueMutex);
            return queueOfWorks.empty();
        }

        void front() {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueOfWorks.front()();
        };

    private:
        std::queue<T> queueOfWorks;
        std::mutex queueMutex;
};


class Threadpool {
    public:
        Threadpool(int cores)
        {
	        for (int i = 0; i < cores; ++i) {
		    vectorOfThreads.push_back(std::thread(&Threadpool::work, this));
	        }
        }
        ~Threadpool()
         {
            for (auto& thread : vectorOfThreads) {
            thread.join();
        }
}
        void work()
        {
	    while (!isSubmit) {
		std::unique_lock<std::mutex> lockMutex(threadMutex);
		if (!safeQueueOfWorks.empty()) {
            std::cout << "\nStart working thread id: " << std::this_thread::get_id() << std::endl;
			safeQueueOfWorks.front();
			safeQueueOfWorks.pop();
		}
		else {
			std::this_thread::yield();
		}
		lockMutex.unlock();
	}
}

        void submit (std::vector<std::function<void()>> vectorFunctions, int countSubmits) {
            for (int i = 0; i < countSubmits; ++i) {
                for (size_t j = 0; j < vectorFunctions.size(); ++j) {
                    safeQueueOfWorks.push(vectorFunctions.at(j));
                }
                std::this_thread::sleep_for(std::chrono::microseconds(200));
            }
            isSubmit = true;
        }

    private:
        std::mutex threadMutex;
        std::vector<std::thread> vectorOfThreads;
        SafeQueue<std::function<void()>> safeQueueOfWorks;
        bool isSubmit = false;
};

void func1()
{
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}

void func2()
{
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}
    int main(int argc, char** argv) {

        const int maxThreadCount = std::thread::hardware_concurrency() - 3;
        std::vector<std::function<void()>> threadVector{ func1, func2 };
        int countSubmits = 5;
        
        Threadpool threadpool{ maxThreadCount };
        
        std::thread thread1(&Threadpool::submit, &threadpool, threadVector, countSubmits);

        thread1.join();
        return 0;
    }
