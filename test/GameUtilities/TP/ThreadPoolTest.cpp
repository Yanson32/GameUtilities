#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <GameUtilities/TP/ThreadPool.h>
#include <GameUtilities/TP/ThreadTask.h>
#include <memory>

class Task: public GU::Thread::ThreadPoolTask
{
    public:
        void run() {}
};

TEST_CASE("ThreadPool::ThreadPool single argument constructor") 
{
    GU::Thread::ThreadPool tp(std::thread::hardware_concurrency() - 1);

    SECTION("Test default number of threads")
    {
        REQUIRE( tp.size() == std::thread::hardware_concurrency() - 1);
    }

    tp.execute();
}

TEST_CASE("ThreadPool::add Add a task to the threadPool") 
{
    GU::Thread::ThreadPool tp(std::thread::hardware_concurrency() - 1);
    std::unique_ptr<GU::Thread::ThreadPoolTask> task(new Task());

    SECTION("Test adding a single task to the threadPool")
    {
        REQUIRE_NOTHROW(tp.add(std::move(task)));
    }

    tp.execute();
}

TEST_CASE("ThreadPool::execute test the execute method") 
{
    GU::Thread::ThreadPool tp(std::thread::hardware_concurrency() - 1);
    std::unique_ptr<GU::Thread::ThreadPoolTask> task(new Task());
    tp.add(std::move(task));

    SECTION("Test execute method")
    {
        REQUIRE_NOTHROW(tp.execute());
    }
}
