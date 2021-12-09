#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end()) {
        *itr2 = 4;
    }

    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element) {
        std::cout << *element << std::endl;
    }

    std::vector<int> vector = {1, 2, 3, 4};
    if (const std::vector<int>::iterator iterator = std::find(vector.begin(), vector.end(), 2); iterator != vector.end()) {
        *iterator = 3;
    }
    if (const std::vector<int>::iterator iterator = std::find(vector.begin(), vector.end(), 3); iterator != vector.end()) {
        *iterator = 3;
    }
    for (std::vector<int>::iterator element = vector.begin(); element != vector.end(); ++element) {
        std::cout << *element << std::endl;
    }
    double table[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; ++i) {
        auto row = table[i];
        for (int j = 0; j < 3; ++j) {
            auto value = &row[j];
            std::cout << *value;
        }
    }
}
