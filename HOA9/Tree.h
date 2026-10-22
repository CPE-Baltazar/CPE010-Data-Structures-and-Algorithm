#ifndef TREE_H
#define TREE_H

#include <iostream>

template<typename T>
class Tree{
private:
    T key;
    Tree<T>* firstChild;
    Tree<T>* nextSibling;

public:
    Tree(T value);
    void insertChild(T value);

    Tree<T>* getFirstChild();
    Tree<T>* getNextSibling();

    T getRootVal();
    void preOrder();
    void postOrder();
    void inOrder();
};

template<typename T>
Tree<T>::Tree(T value){
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template<typename T>
void Tree<T>::insertChild(T value){
    Tree<T>* newNode = new Tree<T>(value);

    if(firstChild == nullptr){
        firstChild = newNode;
    }else{
        Tree<T>* current = firstChild;

        while(current->nextSibling != nullptr){
            current = current->nextSibling;
        }
        current->nextSibling = newNode;
    }
}

template<typename T>
Tree<T>* Tree<T>::getFirstChild(){
    return firstChild;
}

template<typename T>
Tree<T>* Tree<T>::getNextSibling(){
    return nextSibling;
}

template<typename T>
T Tree<T>::getRootVal(){
    return key;
}

template<typename T>
void Tree<T>::preOrder(){
    std::cout << key << " ";
    Tree<T>* current = firstChild;
    while(current != nullptr){
        current->preOrder();
        current = current->nextSibling;
    }
}

template<typename T>
void Tree<T>::postOrder(){
    Tree<T>* current = firstChild;
    while(current != nullptr){
        current->postOrder();
        current = current->nextSibling;
    }

    std::cout << key << " ";
}

template<typename T>
void Tree<T>::inOrder(){
    if(firstChild != nullptr){
        firstChild->inOrder();
    }
    std::cout << key << " ";
    Tree<T>* current = nullptr;
    if(firstChild != nullptr){
        current = firstChild->nextSibling;
    }
    while(current != nullptr){
        current->inOrder();
        current = current->nextSibling;
    }
}

template<typename T>
bool findData(Tree<T>* root, int choice, T value){
    if(root == nullptr)
        return false;

    if(choice == 1){
        if(root->getRootVal() == value)
            return true;

        Tree<T>* current = root->getFirstChild();

        while(current != nullptr){
            if(findData(current, choice, value))
                return true;

            current = current->getNextSibling();
        }
    }else if(choice == 2){
        Tree<T>* current = root->getFirstChild();

        while(current != nullptr){
            if(findData(current, choice, value))
                return true;

            current = current->getNextSibling();
        }

        if(root->getRootVal() == value)
            return true;
    }else if(choice == 3){
        Tree<T>* current = root->getFirstChild();

        if(current != nullptr){
            if(findData(current, choice, value))
                return true;

            if(root->getRootVal() == value)
                return true;

            current = current->getNextSibling();

            while(current != nullptr){
                if(findData(current, choice, value))
                    return true;

                current = current->getNextSibling();
            }
        }else if(root->getRootVal() == value){
            return true;
        }
    }
    return false;
}

#endif