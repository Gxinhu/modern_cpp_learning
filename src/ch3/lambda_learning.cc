// 基本 Lambda 表达式的语法为：

// \[捕获列表\](参数列表) mutable(可选) 异常属性 -> 返回类型

#include <fmt/core.h>

#include <iostream>
#include <memory>
#include <utility>
void lambda_value_capture();
void lambda_reference_capture();
void lambda_hidden_capture();
void lambda_expression_capture();
void lambda_generic();
int main() {
    lambda_value_capture();
    lambda_reference_capture();
    lambda_hidden_capture();
    lambda_expression_capture();
    lambda_generic();
    return 0;
}
// 值捕获
void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    fmt::print("lambda value capture:\n stored value ={}, value = {}\n", stored_value, value);
}

// 引用捕获
void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] { return value; };
    value = 100;
    auto stored_value = copy_value();
    fmt::print("lambda reference capture:\n stored value ={}, value = {}\n", stored_value, value);
}

// 隐式捕获
void lambda_hidden_capture() {
    int value = 1;
    auto copy_value = [=] { return value; };
    value = 100;
    auto stored_value = copy_value();
    fmt::print("lambda hidden value capture:\n stored value ={}, value = {}\n", stored_value, value);
    auto copy_reference_value = [&] { return value; };
    value = 200;
    auto stored_reference_value = copy_reference_value();
    fmt::print("lambda hidden reference capture:\n stored value ={}, value = {}\n", stored_reference_value, value);
}

//表达式捕获 学习了右值引用和智能指针再回来看看
void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(1, 2) << std::endl;
}
// 泛型 Lambda
void lambda_generic() {
    auto add = [](auto x, auto y) {
        return x + y;
    };
    std::cout << add(1, 2) << " " << add(1.1, 2.2) << std::endl;
}