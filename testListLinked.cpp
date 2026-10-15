
#include <iostream>
#include "ListLinked.h"

int main() {
    std::cout << std::boolalpha;

    ListLinked<int> list;

    std::cout << list << std::endl;
    std::cout << "size(): " << list.size() << std::endl;
    std::cout << "empty(): " << list.empty() << std::endl;

    list.insert(0, 0);
    list.insert(1, 10);
    list.insert(0, -5);
    list.insert(2, 5);

    std::cout << list << std::endl;

    std::cout << "size(): " << list.size() << std::endl;
    std::cout << "empty(): " << list.empty() << std::endl;

    std::cout << "list.get(0): " << list.get(0) << std::endl;
    std::cout << "list[0]: " << list[0] << std::endl;

    std::cout << "list.remove(3): "
              << list.remove(3) << std::endl;

    std::cout << "list.remove(1): "
              << list.remove(1) << std::endl;

    list.append(14);
    list.prepend(33);

    std::cout << list << std::endl;

    std::cout << "search(14): "
              << list.search(14) << std::endl;

    std::cout << "search(55): "
              << list.search(55) << std::endl;

    try {
        list.get(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "Excepcion: " << e.what() << std::endl;
    }

    return 0;
}
