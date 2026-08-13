#include <iostream>
#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode{
    public:
    T data;
    qNode *next;
};

// creating a new node
template <typename T>
qNode<T> *new_node(T newData){
    qNode<T>* newNodePtr = new qNode<T>;
    newNodePtr->data = newData;
    newNodePtr->next = nullptr;
    return newNodePtr;
}


//ENQUEUE
template<typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){
    // create a new node
    qNode<T> *newNodePtr = new_node(newData);

    //inserting to an empty queue
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNodePtr;
        (*backPtr) = newNodePtr;
    }
    //inserting an item into a non empty queue
    else {
        (*backPtr)-> next = newNodePtr;
        (*backPtr) = newNodePtr;
    }
}


//DEQUEUE
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    // create a temporary node to store the node to be deleted
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    // check if the queue is only one node
    if((*frontPtr)->next==nullptr && (*backPtr)->next==nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    // deleting of a node
    (*frontPtr)=deleteNode->next;
    delete deleteNode;
}

// DISPLAY - display all elements in the queue
template <typename T>
void display(qNode<T>* frontPtr) {
    qNode<T>* currentHead = frontPtr;
    while (currentHead != nullptr) {
        std::cout << currentHead->data << " -> ";
        currentHead = currentHead->next;
    }
    std::cout << "nullptr" << std::endl;
}

// FRONT - return the front element of the queue
template <typename T>
T frontFind(qNode<T>* frontPtr) {
    return frontPtr->data;
}

#endif