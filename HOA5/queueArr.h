#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

//Array-Based Circular Queue
template <typename T>
class queueArr{
    private:
        //create a pointer array:
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;
    public:
    //prototype
    queueArr(size_t capacity);
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    ~queueArr();

    //taskss
    queueArr(const queueArr& other);
    queueArr& operator = (const queueArr& other);
};

//constructor
template <typename T> 
queueArr<T>::queueArr(size_t capacity){
    //capacity
    q_capacity = capacity;
    //current size
    q_size = 0;
    //initial front & back index
    q_front = 0;
    q_back = -1;
    //newly allocated array
    q_array = new T[q_capacity];
    std::cout<<"constructor class was called\n";
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other){
    //copy 
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    //allocate a new memory for array
    q_array = new T[q_capacity];

    //copy the elements from the other array to this brand new array
    for(size_t i = 0; i < q_size; ++i){
        size_t index = (q_front + i) % q_capacity;
        q_array[index] = other.q_array[index];
    }
    std::cout<<"copy constructor was called\n";
}

//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    //check if curr object is not the same the other one
    if(this != &other){
        delete [] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        //allocate again
        q_array = new T[q_capacity];

        //copy again
        for(size_t i = 0; i < q_size; ++i){
            size_t index = (q_front + i) % q_capacity;
            q_array[index] = other.q_array[index];
        }
        std::cout<<"copy assignment operator was called\n";
    }
    return *this;
}

//destructor()
template <typename T>
queueArr<T>::~queueArr(){
    delete [] q_array;
    std::cout<<"destructor was called\n";
}

//empty()
template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

//full()
template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

//clear()
template <typename T>
void queueArr<T>::Clear(){
    q_front = 0;
    q_back = -1;
    q_size = 0;
}

//front()
template <typename T>
T queueArr<T>::Front(){
    //check  & display if the q is empty
    if(Empty()){
        std::cout<<"The queue is empty\n";
        return T{}; //std::optional
    }
    //return the front item
    return q_array[q_front];
}

//back()
template <typename T>
T queueArr<T>::Back(){
    //check  & display if the q is empty
    if(Empty()){
        std::cout<<"The queue is empty\n";
        return T{}; //std::optional
    }
    //return the back item
    return q_array[q_back];
}

//enqueue()
template <typename T>
void queueArr<T>::Enqueue(T newData){
    //check if the queue is full
    if(Full()){
        std::cout << "Queue is full" << std::endl;
        return;
    }
    //compute for the q_back to move it circularly
    q_back = (q_back + 1) % q_capacity;

    //assign the new value to the back of the queue array
    q_array[q_back] = newData;
    //increment the q_size
    q_size++;
}

//dequeue()
template <typename T>
void queueArr<T>::Dequeue(){
    //check if its empty
    if(Empty()){
        std::cout<<"The queue is empty\n";
        return;
    }
    //compute for q_front to move it circulary
    q_front = (q_front + 1) % q_capacity;

    //decrement the q_size
    q_size--;
}

template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

#endif //QUEUEARR_H