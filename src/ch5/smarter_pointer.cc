#include <iostream>
#include <memory>
void foo(std::shared_ptr<int>& i) {
    (*i)++;
};
void share_pointer();
void unique_pointer();
void no_destory_pointer();

struct Foo {
    Foo() {
        std::cout << "Foo::Foo" << std::endl;
    }
    // 析构函数 对象所在的函数调用完毕后，会自动执行析构函数
    ~Foo() {
        std::cout << "Foo::~Foo" << std::endl;
    }
    static void foo() {
        std::cout << "Foo::foo" << std::endl;
    }
};
void f(const Foo& /*unused*/) {
    std::cout << "f(const Foo)" << std::endl;
}

struct B;
struct A {
    std::weak_ptr<B> pointer;
    ~A() {
        std::cout << "A 被销毁" << std::endl;
    }
};
struct B {
    std::weak_ptr<A> pointer;
    ~B() {
        std::cout << "B 被销毁" << std::endl;
    }
};
int main() {
    share_pointer();
    unique_pointer();
    no_destory_pointer();
    return 0;
}

void share_pointer() {

    // auto pointer  = new int(10);
    // std::make_shared 是一种智能指针，会记录被多少对象指着，当计数为零之后就自动删除
    auto pointer = std::make_shared<int>(10);
    foo(pointer);
    std::cout << *pointer << std::endl;

    auto pointer2 = pointer;
    auto pointer3 = pointer;
    std::cout << pointer.use_count() << std::endl;
    std::cout << pointer2.use_count() << std::endl;
    std::cout << pointer3.use_count() << std::endl;
    pointer2.reset();
    std::cout << "reset pointer2" << std::endl;
    std::cout << pointer.use_count() << std::endl;
    std::cout << pointer2.use_count() << std::endl;
    std::cout << pointer3.use_count() << std::endl;
    pointer3.reset();
    std::cout << "reset pointer3" << std::endl;
    std::cout << pointer.use_count() << std::endl;
    std::cout << pointer2.use_count() << std::endl;
    std::cout << pointer3.use_count() << std::endl;
}
// unique_pointer 是一种独占的指针，禁止其他智能指针共享
void unique_pointer() {
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    if (p1) {
        p1->foo();
    }
    std::unique_ptr<Foo> p2(std::move(p1));
    f(*p2);

    if (p2) {
        p2->foo();
    }
    if (p1) {
        p1->foo();
    }
    p1 = std::move(p2);
    if (p2) {
        p2->foo();
    } else {
        std::cout << "p2 被销毁" << std::endl;
    }
    auto* p = new Foo();
}
void no_destory_pointer() {
    // 弱引用不会引起引用计数增加
    auto a     = std::make_shared<A>();
    auto b     = std::make_shared<B>();
    b->pointer = a;
    a->pointer = b;
    std::cout << a->pointer.use_count() << std::endl;
    std::cout << b->pointer.use_count() << std::endl;
}