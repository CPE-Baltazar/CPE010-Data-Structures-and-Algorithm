#include <iostream>
#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H



template <typename T>
class doubleList{
    public:
        T data;
        doubleList<T>* next = nullptr;
        doubleList<T>* prev = nullptr;
};


// creating a node
template <typename T>
doubleList<T>* newNode(T newData){
    //dynamically allocate memory for a new node
    doubleList<T>* newNode = new doubleList<T>;

    //Store data in the node:
    newNode->data = newData;

    //since its a new node, it will point to null
    newNode->next = nullptr;
    newNode->prev=nullptr;

    return newNode;
}


// Traversal
template <typename T>
void dllTraverse(doubleList<T>* currentNode){
    doubleList<T>* tail = nullptr;
    //traversal to the end
    std::cout << "Forward traversal \n";
    while(currentNode!= nullptr){
        //prints the data
        std::cout<< currentNode->data<<" ";
        //save the current node as the last visited node
        tail = currentNode;
        // move to the next node
        currentNode = currentNode->next;
    }

    std::cout<<std::endl;
    //reverse traversal
    std::cout << "Reverse Traversal\n";
    while(tail != nullptr){
        std::cout << tail->data<<" ";
        tail = tail->prev;
    }
    std::cout << std::endl << std::endl;
};


// Insetion at the head
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {

    // create a new node
    doubleList<T>* newNodePtr = newNode(newData);

    // SET THE new node to point to the current head
    newNodePtr->next = *currentHead;

    // Update previous pointer of old head (verifies)
    if (*currentHead != nullptr){
        (*currentHead)->prev = newNodePtr;
    }

    // Change head pointer to point to new node
    *currentHead = newNodePtr;
}


// General Insertion
template <typename T>
void dllGeneralInsertion(T newData, doubleList<T>* prevNode){
    // prev node cannot be null check
    if(prevNode==nullptr){
        std::cout << "The previous node cannot be null!\n";
        return;
    }

    // new node
    doubleList<T>* newNodePtr = newNode(newData);

    // update pointers
    newNodePtr->next = prevNode->next;
    newNodePtr->prev = prevNode;

    // middle insertion
    if(prevNode->next != nullptr){
        prevNode->next->prev = newNodePtr;
    }

    // update previous node
    prevNode->next = newNodePtr;
}


// Insertion at the end
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead) {

    // create a new node
    doubleList<T>* newNodePtr = newNode(newData);

    // traverse until the last node
    while (currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    // connect the last node to the new node
    currentHead->next = newNodePtr;

    // connect the prev node to the new node
    newNodePtr->prev = currentHead;
}

// delete
template <typename T>
void dllDelete(T findData, doubleList<T>** head){

    // list check
    if(*head == nullptr)
        return;

    // finding specified to delete
    doubleList<T>* current = *head;
    while(current != nullptr && current->data != findData){
        current = current->next;
    }

    // if not found
    if(current == nullptr)
        return;

    // head deletion handling and else
    if(current->prev == nullptr){
        *head = current->next;

        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    } else {
        current->prev->next = current->next;

        if(current->next != nullptr){
            current->next->prev = current->prev;
        }
    }

    delete current;
}
#endif