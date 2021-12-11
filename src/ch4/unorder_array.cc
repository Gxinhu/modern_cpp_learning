// 无序 map 会在 存储时，对比  map set 的时间复杂度更低
#include <fmt/core.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
int main(int argc, const char** argv) {
    std::unordered_map<int, std::string> u = {
        {1, "1"},
        {3, "3"},
        {2, "2"}};
    std::map<int, std::string> v = {
        {1, "1"},
        {3, "3"},
        {2, "2"}};
    fmt::print("unordered map: \n");
    for (auto m : u) {
        fmt::print(" Key [{}] Value [{}]\n", m.first, m.second);
    }

    fmt::print("map: \n");
    for (auto m : v) {
        fmt::print(" Key [{}] Value [{}]\n", m.first, m.second);
    }
    return 0;
}