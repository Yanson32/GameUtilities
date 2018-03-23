#include "GameUtilities/ThreadPool.h"
namespace GU
{
    ThreadPool::ThreadPool(const int newMaxThreads):
    maxThreads(newMaxThreads),
    threads(maxThreads)
    {
        //ctor
    }

}
