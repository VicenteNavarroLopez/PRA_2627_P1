
#ifndef LISTLINKED_H
#define LISTLINKED_H
#include "List.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {
    }

    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first;
            first = first->next;
            delete aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw out_of_range("Posicion invalida");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;

            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            aux->next = new Node<T>(e, aux->next);
        }

        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion invalida");
        }

        Node<T>* aux;
        T removed;

        if (pos == 0) {
            aux = first;
            removed = aux->data;
            first = first->next;
        } else {
            Node<T>* prev = first;

            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }

            aux = prev->next;
            removed = aux->data;
            prev->next = aux->next;
        }

        delete aux;
        n--;

        return removed;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion invalida");
        }

        Node<T>* aux = first;

        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    T operator[](int pos) {
        return get(pos);
    }

    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;

        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }

            aux = aux->next;
            pos++;
        }

        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    template <typename U>
    friend ostream& operator<<(ostream& out, const ListLinked<U>& list);
};

template <typename T>
ostream& operator<<(ostream& out, const ListLinked<T>& list) {
    out << "[";
    Node<T>* aux = list.first;

    while (aux != nullptr) {
        out << aux->data;

        if (aux->next != nullptr) {
            out << ", ";
        }

        aux = aux->next;
    }

    out << "]";
    return out;
}

