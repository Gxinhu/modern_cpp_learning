// 关于函数对象包装器( 函数的容器 )的学习

#include <fmt/core.h>

#include <functional>
#include <iostream>
using foo = void(int);
void functional(foo f) { f(1); }
int foo1(int parameter) { return parameter; }
int foo3(int a, int b, int c) { return a + c + b; }
int main() {
  // lambda 表达式的本质就是一个闭包对象
  auto f = [](int value) { std::cout << value << std::endl; };
  // 传递闭包对象
  functional(f);
  // 直接使用 lambda 表达式调用
  f(1);

  // C++11 之后
  std::function<int(int)> func = foo1;
  int important = 10;
  std::function<int(int)> func2 = [&](int value) -> int {
    return 1 + value + important;
  };

  auto binFoo = std::bind(foo3, std::placeholders::_1, 1, 2);
  std::cout << binFoo(1) << std::endl;
  return 0;
}