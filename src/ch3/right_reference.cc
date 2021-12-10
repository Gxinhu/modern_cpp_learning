// 左值、右值的纯右值、将亡值、右值
// 这个还有一些地方不是很明白，等以后实际项目在了解

#include <iostream>
#include <string>

void reference(std::string& str) {
    std::cout << " 左值" << std::endl;
}
void reference(std::string&& str) {
    std::cout << "右值" << std::endl;
}

int main() {
    std::string lv1 = "string";
    reference(lv1);
    // std::string&& r1 = lv1;
    std::string&& rv1 = std::move(lv1);
    std::cout << rv1 << std::endl;

    const std::string& lv2 = lv1 + lv1;
    // lv2 += "test";
    std::cout << lv2 << std::endl;

    std::string&& rv2 = lv1 + lv2;
    rv2 += "Test";
    std::cout << rv2 << std::endl;

    return 0;
}