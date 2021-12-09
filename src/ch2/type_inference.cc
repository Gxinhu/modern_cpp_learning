#include <fmt/core.h>

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <vector>

template <typename T, typename U>
auto add(T x, U y) {
    return x + y;
};
std::tuple<int, double, std::string> tuple_bind();
class MagicFoo {
   public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }
    }
};
void for_loop();

int main() {
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    auto [a, b, c] = tuple_bind();
    fmt::print("{},{},{}\n", a, b, c);
    auto w = add<int, double>(1, 2.3);
    fmt::print("{}", w);
    for_loop();
    return 0;
}

std::tuple<int, double, std::string> tuple_bind() {
    return std::make_tuple(1, 2.3, "fdf");
}

void for_loop() {
    std::vector vec = {1, 2, 3, 4, 5};
    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) {
        *itr = 4;
    }
    for (auto element : vec) {
        std::cout << element << std::endl;
    }
    for (auto &element : vec) {
        element += 1;
        std::cout << element << std::endl;
    }
}