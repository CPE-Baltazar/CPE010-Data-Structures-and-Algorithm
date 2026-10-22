#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList{
    public:
        T data;
        doubleList<T>* next = nullptr;
        doubleList<T>* prev = nullptr;
};

//====================
//creating a node
//====================
template <typename T>
doubleList<T>* new_node(T newData){
    //dynamically allocate memory for a new node
    doubleList<T>* newNode = new doubleList<T>;
    //store data in the node:
    newNode->data = newData;
    //since its a new node, it will point to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//====================
//traversal 
//====================
template <typename T>
void dllTraverse(doubleList<T>* currentNode){
    doubleList<T>* tail = nullptr;
    while(currentNode != nullptr){
        //prints the data
        std::cout << currentNode->data << " ";
        //save the current node as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    //reverse traversal
    std::cout << "Reverse Traversal: ";

    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

//====================
//insertion at the head
//====================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead){
    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //SET THE new node to point to the current head
    newNode->next = *currentHead;

    //current head will be pointed to the new node
    if(*currentHead != nullptr){
        (*currentHead)->prev = newNode;
    }
    //update the head pointer
    *currentHead = newNode;
}

//====================
//general insertion
//====================
template <typename T>
void dllInsertAny(T newData, doubleList<T>* prevNode){
    //cannot insert after a null (prevNode cannot be null -> return)
    if (prevNode == nullptr) {
        std::cout << "The previous node cannot be null." << std::endl;
        return;
    }

    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //new node points to the new node after the prevNode
    newNode->next = prevNode->next;

    //newNode previous mustbe pointed to the prevNode
    newNode->prev = prevNode;

    //if there is a node after the prevNode, make it point back to the new node
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    //prevNode will be pointed to the new node
    prevNode->next = newNode;
}


//====================
//insertion at the end
//====================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead){
    //create a new node
    doubleList<T>* newNode = new_node(newData);
    //traverse until the last node
    doubleList<T>* currentNode = currentHead;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    //connect the last node to the new node
    currentNode->next = newNode;

    //connect the prev node to the new node
    newNode->prev = currentNode;
}

//====================
//deletion
//====================
template <typename T>
void dllDelete(T findData, doubleList<T>** currentHead){
    //traverse until the node that we want to delete is found
    doubleList<T>* currentNode = *currentHead;
    while(currentNode != nullptr && currentNode->data != findData){   
        currentNode = currentNode->next; 
    }

    if(currentNode == nullptr){ //so when we reach the end of the list which is null, we will return
        std::cout << "Node not found" << std::endl;
        return;
    }

    if(currentNode == *currentHead){ //if the node to be deleted is the head node
        *currentHead = currentNode->next; //update the head pointer to the next node
        if(*currentHead != nullptr){
            (*currentHead)->prev = nullptr; //set the prev pointer of the new head to null
        }
   } else {
        /*this one if the node to be deleted is not the head node, we connect the previous node 
        to th next node and the next node to the previous node*/
        currentNode->prev->next = currentNode->next;
        if(currentNode->next != nullptr){
            currentNode->next->prev = currentNode->prev;
        }
    }

    //delete the node
    delete currentNode;
}

#endif