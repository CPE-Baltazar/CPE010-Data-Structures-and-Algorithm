#include <iostream>
#ifndef QUEUEARR_H
#define QUEUEARR_H

template <typename T>
class queueArr{
private:
    T* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // CONSTRUCTOR
    queueArr(int max = 7) { // Capacity to match the 7 elements in the lab manual as default parameter
        q_capacity = (max > 0) ? max : 7; // Ternary operator (makes sure capacity is not set to 0)
        q_array = new T[q_capacity];
        Clear();
    }

    // DESTRUCTOR
    ~queueArr() {
        delete[] q_array;
    }

    // COPY CONSTRUCTOR
    queueArr(const queueArr<T>& other) {
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];

        for (int i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }

// COPY ASSIGNMENT
    queueArr<T>& operator=(const queueArr<T>& other) {
        if (this != &other) {
            delete[] q_array;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new T[q_capacity];

            for (int i = 0; i < q_capacity; ++i) {
                q_array[i] = other.q_array[i];
            }
        }
        return *this;
    }

    // DECLARATIONS
    bool Empty() const;
    int Size() const;
    void Clear();
    T Front();
    const T& Front() const;
    T Back();
    const T& Back() const;
    void Enqueue(const T& val);
    void Dequeue();
    void Display() const;
};

// EMPTY
template <typename T>
bool queueArr<T>::Empty() const {
    return q_size == 0;
}

// SIZE
template <typename T>
int queueArr<T>::Size() const {
    return q_size;
}

// CLEAR
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = q_capacity - 1;
}

// FRONT
template <typename T>
T queueArr<T>::Front() {
    if (Empty()) {
        std::cout<<"The queue is empty!";
        return T{};
    }
    return q_array[q_front];
}

// BACK
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        std::cout<<"The queue is empty!";
        return T{};
    }
    return q_array[q_back];
}

// ENQUEUE
template <typename T>
void queueArr<T>::Enqueue(const T& val) {
    if (q_size == q_capacity) {
        std::cout<<"The queue is full!";
        return;
    }
    q_back = (q_back + 1) % q_capacity;
    q_array[q_back] = val;
    q_size++;
}

// DEQUEUE
template <typename T>
void queueArr<T>::Dequeue() {
    if (Empty()) {
        std::cout<<"The queue is empty!";
        return;
    }
    q_front = (q_front + 1) % q_capacity;
    q_size--;
}

// DISPLAY
template <typename T>
void queueArr<T>::Display() const {
    if (Empty()) {
        std::cout<<"The queue is empty!";
        return;
    }
    for (int i = 0; i < q_size; ++i) {
        int indexNum = (q_front + i) % q_capacity;
        std::cout << q_array[indexNum] << " ";
    }
}

#endif