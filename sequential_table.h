//
// Created by huang on 2024/7/10.
//
#include <iostream>
using namespace std;

#ifndef SEQUENTIAL_TABLE_H
#define SEQUENTIAL_TABLE_H

template<typename T>

class SequentialTable {
private:
    T *elements;
    int size{};
    int capacity{};

public:
    SequentialTable() {
        inititalize(10);
    }

    explicit SequentialTable(const int initCapacity) {
        inititalize(initCapacity);
    }

    void inititalize(int initCapacity) {
        if (initCapacity <= 0) {
            throw std::invalid_argument("the capacity is not valid");
        }
        this->elements = new T[initCapacity];
        this->capacity = initCapacity;
        this->size = 0;
    }

    ~SequentialTable() {
        if (elements != nullptr) {
            delete [] elements;
        }
        cout << "Destory successfully!" << endl;
    }

    void insert(int index, T element) {
        if (index < 0 || index > this->capacity) {
            throw std::invalid_argument("the index is not valid.");
        }

        if (this->capacity == this->size) {
            const int new_capacity = this->capacity * 2;
            auto new_elements = new T[new_capacity];
            for (int i = 0; i < this->size; i++) {
                new_elements[i] = this->elements[i];
            }
            if (elements != nullptr) {
                delete [] elements;
            }
            this->elements = new_elements;
            this->capacity = new_capacity;
        }
        for (int i = this->size; i > index; --i) {
            this->elements[i] = this->elements[i - 1];
        }
        this->elements[index] = element;
        ++this->size;
    }

    void remove(int index) {
        if (index < 0 || index > this->size) {
            throw std::invalid_argument("the index is not valid.");
        }
        for (int i = index; i < this->size; ++i) {
            this->elements[i] = this->elements[i + 1];
        }
        --this->size;
    }

    int indexOf(T element) {
        for (int i = 0; i < this->size; i++) {
            if (this->elements[i] == element) {
                return i;
            }
        }
        return -1;
    }

    T find(int index) {
        if (index < 0 || index > this->size) {
            throw std::invalid_argument("the index is not valid.");
        }
        return this->elements[index];
    }

    void update(int index, T element) {
        if (index < 0 || index > this->capacity) {
            throw std::invalid_argument("the index is not valid.");
        }
        this->elements[index] = element;
    }

    void display() {
        for (int i = 0; i < this->size; i++) {
            cout << this->elements[i] << " ";
        }
        cout << endl;
    }

    [[nodiscard]] int getSize() const {
        return this->size;
    }

    [[nodiscard]] int getCapacity() const {
        return this->capacity;
    }
};

inline void test_sequential_table() {
    cout << "the sequential table testing is starting..." << endl;
    SequentialTable<int> t;
    t.inititalize(10);
    int temp = 0;
    for (int i = 0; i < t.getCapacity(); i++) {
        temp = i * 10;
        t.insert(i, temp);
    }
    t.display();
    t.remove(3);
    t.display();
    t.update(3, 100);
    t.display();
    cout << t.find(3) << endl;
    cout << t.indexOf(40) << endl;
    cout << t.indexOf(50) << endl;
    cout << t.getCapacity() << endl;
    cout << t.getSize() << endl;
    cout << "the sequential table testing finished successfully!" << endl;
}

#endif //SEQUENTIAL_TABLE_H
