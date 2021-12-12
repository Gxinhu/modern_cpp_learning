#include <iostream>
#include <vector>
template <typename T> class Magic {
public:
  std::vector<T> vec;
  Magic(std::initializer_list<T> list) {
    for (const auto *it = list.begin(); it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};
template <typename T0, typename... T> void printf1(T0 t0, T... t) {
  std::cout << t0 << std::endl;
  if constexpr (sizeof...(t) > 0) {
    printf1(t...);
  }
};
template <typename... T> auto sum(T... t) { return (t + ...); };
template <typename T, auto Bufsize> class BufferT {
public:
  T &alloc();
  void free(T &item);
};
int main() {
  Magic<int> magic = {1, 2, 3, 4};
  std::cout << magic.vec[0] << std::endl;
  printf1(1, 2, 3, "4343");
  std::cout << sum(1, 2, 3, 4, 5) << std::endl;
  BufferT<int, 10> buffer;
  return 0;
}