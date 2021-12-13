#include <chrono>
#include <fmt/core.h>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>


int v     = 1;
double vv = 1.0;
void critical_section(int change_v) {
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    v = change_v;
}
void critical_section_double(double change_v) {
    static std::mutex mutex;
    std::unique_lock<std::mutex> lock(mutex);
    vv = change_v;
    std::cout << vv << std::endl;
    fmt::print("第一次{}\n", vv);
    lock.unlock();
    lock.lock();
    vv += 1;
    fmt::print("第二次{}\n", vv);
}
// future 主要是处理异步任务的结果
void future() {
    std::packaged_task<int()> task([]() { return 7; });
    std::future<int> result = task.get_future();
    std::thread(std::move(task)).detach();
    std::cout << "waiting..."<<std::endl;
    result.wait();
    std::cout << "done" << std::endl << "future result is " << result.get() << std::endl;
}


int main() {
    std::thread t([]() { std::cout << "Testing" << std::endl; });
    t.join();
    std::thread t1(critical_section, 2);
    std::thread t2(critical_section, 3);
    t1.join();
    t2.join();
    std::cout << v << std::endl;

    std::thread tt1(critical_section_double, 1.1);
    std::thread tt2(critical_section_double, 2.2);
    tt1.join();
    tt2.join();
    future();
    return 0;
}
