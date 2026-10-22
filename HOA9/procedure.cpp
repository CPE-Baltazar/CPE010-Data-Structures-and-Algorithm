#include <iostream>
#include "tree.h"

int main(){
    Tree<char>* root = new Tree<char>('A');

    //under A
    root->insertChild('B');
    root->insertChild('C');
    root->insertChild('D');
    root->insertChild('E');
    root->insertChild('F');
    root->insertChild('G');

    //children D
    Tree<char>* D = root->getFirstChild()->getNextSibling()->getNextSibling();

    D->insertChild('H');

    //children E
    Tree<char>* E = D->getNextSibling();

    E->insertChild('I');
    E->insertChild('J');

    //children J
    Tree<char>* J = E->getFirstChild()->getNextSibling();

    J->insertChild('P');
    J->insertChild('Q');

    //children F
    Tree<char>* F = E->getNextSibling();

    F->insertChild('K');
    F->insertChild('L');
    F->insertChild('M');

    //children G
    Tree<char>* G = F->getNextSibling();
    G->insertChild('N');
    G->insertChild('O');

    std::cout << "Pre-order: ";
    root->preOrder();

    std::cout << "\nPost-order: ";
    root->postOrder();

    std::cout << "\nIn-order: ";
    root->inOrder();
    
    if(findData(root, 1, 'K'))
        std::cout << "K was found!" << std::endl;

    if(findData(root, 2, 'E'))
        std::cout << "E was found!" << std::endl;

    if(findData(root, 3, 'N'))
        std::cout << "N was found!" << std::endl;

    if(findData(root, 3, 'O'))
        std::cout << "O was found!" << std::endl;
}