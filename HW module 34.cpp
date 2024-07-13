#include <type_traits>
#include <string>

template <typename T>
concept ComplexConcept = requires(T t) {
    { t.hash() } -> std::convertible_to<long>;
    { t.toString() } -> std::convertible_to<std::string>;
        requires !std::is_polymorphic_v<T>;
};

class MyComplexType1 {
public:
    long hash() { return 42; }
    std::string toString() { return "MyComplexType1"; }
};

class MyComplexType2 {
public:
    long hash() { return 87; }
    std::string toString() { return "MyComplexType2"; }
    virtual ~MyComplexType2() = default;
};

int main() {
    static_assert(ComplexConcept<MyComplexType1>, "MyComplexType1 не удовлетворяет ComplexConcept");
    return 0;
}