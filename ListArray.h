#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;

    static const int MINSIZE = 2;

    void resize(int newSize) {
        T* newArr = new T[newSize];

        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        max = newSize;
    }

public:
    ListArray() {
        max = MINSIZE;
        n = 0;
        arr = new T[max];
    }

    ~ListArray() override {
        delete[] arr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw out_of_range("Posicion invalida");
        }

        if (n == max) {
            resize(max * 2);
        }

        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
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

        T removed = arr[pos];

        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        if (n > 0 && n <= max / 4 && max > MINSIZE) {
            resize(max / 2);
        }

        return removed;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posicion invalida");
        }

        return arr[pos];
    }

    T operator[](int pos) {
        return get(pos);
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
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
    friend ostream& operator<<(ostream& out, const ListArray<U>& list);
};

template <typename T>
ostream& operator<<(ostream& out, const ListArray<T>& list) {
    out << "[";

    for (int i = 0; i < list.n; i++) {
        if (i > 0) {
            out << ", ";
        }

        out << list.arr[i];
    }

    out << "]";
    return out;
}

