// array is diffident with vector, the former one is constant, and later one is
// dynamic

#include <algorithm>
#include <array>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <iostream>
#include <utility>
#include <vector>

void learn_array();
void learn_vector();
int main() {
    learn_vector();
    learn_array();
    return 0;
}
void foo(int* p, int len) {}
void learn_array() {
    std::array<int, 4> arrays = {1, 2, 3, 4};
    int arr1[]                = {1, 2, 3, 4};
    fmt::print("Arrays is empty: {}\n", arrays.empty());
    fmt::print("The size of the arrays: {}\n", arrays.size());
    for (auto& i : arrays) {
        i += 1;
    }
    fmt::print("Arrays: {}\n", arrays);
    for (auto i : arrays) {
        i += 1;
    }
    fmt::print("Arrays: {}\n", arrays);
    std::sort(arrays.begin(), arrays.end(), [](int x, int y) { return x > y; });
    std::sort(&arr1[0], &arr1[4], [](int x, int y) { return x > y; });
    fmt::print("Arrays: {}, Arrays in C: {}\n", arrays, arr1);

    // constexpr 是常量表达式，表示后面返回的会是一个常数
    constexpr int len        = 4;
    std::array<int, len> arr = {1, 2, 45, 6};
    // foo(arr, arr.size());
    // 传统 C 数组会隐式转换
    foo(arr1, sizeof(arr1) / sizeof(arr1[0]));
    foo(arr.data(), arr.size());
}
void learn_vector() {
    std::vector<int> v;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity :" << v.capacity() << std::endl;

    v.push_back(4);
    v.push_back(5);
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity :" << v.capacity() << std::endl;

    // 这里清空了元素，容量还是没有返还，需要采用下面的 shrink to fit 才返还
    v.clear();
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity :" << v.capacity() << std::endl;
    v.shrink_to_fit();
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity :" << v.capacity() << std::endl;
}