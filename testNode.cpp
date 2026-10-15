#include <iostream>
#include "Node.h"

int main() {
    Node<char>* first = new Node<char>('a');
    first->next = new Node<char>('b');
    first->next->next = new Node<char>('c');

    Node<char>* aux = first;

    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }

    std::cout << std::endl;

    while (first != nullptr) {
        aux = first;
        first = first->next;
        delete aux;
    }

    return 0;
}
