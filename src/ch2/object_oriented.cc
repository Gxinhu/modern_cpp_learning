#include <fmt/core.h>

#include <iostream>
class Base {
   public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() {
        value2 = value;
    }
    virtual void foo() {
        std::cout << "This Base::foo" << std::endl;
    }
    virtual void foo_final() final {
        std::cout << "This is final function, can not be override" << std::endl;
    }
};
class Base2 : public Base {
   public:
    using Base::Base;
    virtual void foo() override {
        std::cout << "This Base2::foo" << std::endl;
    }
};
int main() {
    Base *a = new Base2();
    a->foo();
    Base2 b(2);
    fmt::print("value1={},value={}\n", b.value1, b.value2);
    return 0;
}