#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class BinaryTree{
    private:
        //data
        T key;
        //left
        BinaryTree* leftChild;
        //right
        BinaryTree* rightChild;
    public:

    //Constructor
    BinaryTree(T rootObj);

    //insert children
    void insertLeft(T newNode);
    void insertRight(T newNode);

    //accessing the child nodes:
    BinaryTree* getLeftChild();
    BinaryTree* getRightChild();

    //get and set node value
    void setRootVal(T obj);
    T getRootVal();

    //checker if the node is a leaf
    bool isLeaf();
};
//Constructor:
template<typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    //add a value to the key
    key = rootObj;
    //set your left and right child to nullptr
    leftChild = nullptr;
    rightChild = nullptr;
}
//Inserting left:
template<typename T>
void BinaryTree<T>::insertLeft(T newNode){
 
    if(leftChild == nullptr){
        //CREATE A NEW NODE
        leftChild= new BinaryTree<T>(newNode);
        return;
    }
    else{
        BinaryTree<T>* newChild= new BinaryTree<T>(newNode);

        //Moves the existing left child below the new node
        newChild->leftChild = leftChild;

        //Make the new node the left child
        leftChild = newChild;
    }   
}


template<typename T>
void BinaryTree<T>::insertRight(T newNode){
    if(rightChild == nullptr){
        rightChild= new BinaryTree<T>(newNode);
        return;
    }
    else{
        BinaryTree<T>* newChild= new BinaryTree<T>(newNode);
        newChild->rightChild = rightChild;
        rightChild = newChild;
    }   
} 

template<typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
    return rightChild;
}

//get and set node value
template<typename T>
void BinaryTree<T>::setRootVal(T obj){
    key = obj;
}

template<typename T>
T BinaryTree<T>::getRootVal(){
    return key;
}

//if leaf
template<typename T>
bool BinaryTree<T>::isLeaf(){
    return (leftChild == nullptr && rightChild == nullptr);
}
#endif