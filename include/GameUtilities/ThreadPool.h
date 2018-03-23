#ifndef GU_THREADPOOL_H
#define GU_THREADPOOL_H
#include "gameutilities_export.h"
#include <thread>
#include <future>
#include <vector>
#include <queue>

namespace GU
{

    class GAMEUTILITIES_EXPORT ThreadPool final
    {
        public:
            ThreadPool(const int newMaxThreads = std::thread::hardware_concurrency());
            template<typename Type, typename... Args>
            std::future<Type> push(Args&&... args);
        private:
            const int maxThreads;
            std::vector<std::thread> threads;
            std::queue<std::function<void ()>> jobQueue;
    };

    template<typename Type, typename... Args>
    std::future<Type> ThreadPool::push(Args&&... args)
    {
        return std::future<Type>();
    }
}
#endif // GU_THREADPOOL_H
