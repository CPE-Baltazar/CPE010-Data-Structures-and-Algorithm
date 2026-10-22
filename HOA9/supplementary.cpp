#include <iostream>
#include "BST.h"

int main(){
    BinarySearchTree<int> tree(2);

    std::cout<<"Pre Order: ";
    tree.insert(2);
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    tree.preOrder();
    std::cout<<"\nIn Order: ";
    tree.inOrder();
    std::cout<<"\nPost Order: ";
    tree.postOrder();

    return 0;
}