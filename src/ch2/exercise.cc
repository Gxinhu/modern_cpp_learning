#include <iostream>
#include <map>
#include <string>
#include <vector>
template <typename... T>
double average(T... t) {
    return (t + ...) / sizeof...(t);
};
template <typename T, typename... Ts>
void recursion(T t0, Ts... args) {
    auto a = average(args...);
    std::cout << a << std::endl;
};

int main() {
    std::cout << average(1, 2, 3, 4, 5) << std::endl;
    recursion(1, 2.1, 3, 45);
    return 0;
}