#include <iostream>
#include "singly_LL.h"
#include "double_LL.h"

int main(){
    //'C' 'P' 'E'
    //CREATION OF 
    doubleList<char>* head = new_node('E');
    //CREATIN OF OTHER NODES:
    doubleList<char>* second = new_node('N');
    doubleList<char>* third = new_node('J');

    //LINK THE NODES
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout<<"initial Traversal"<<std::endl;
    dllTraverse(head);

    std::cout<<"inserting at the head"<<std::endl;
    dllInsertHead('K', &head);
    dllTraverse(head);

    std::cout<<"inserting at the end"<<std::endl;
    dllInsertEnd('I', head);
    dllTraverse(head);

    std::cout<<"inserting at any node"<<std::endl;
    doubleList<char>* current = head;
    while(current != nullptr && current->data != 'N'){
        current = current->next;
    }

    if(current != nullptr){
        dllInsertAny('X', current);
    }
    dllTraverse(head);

    std::cout<<"Delete node"<<std::endl;
    dllDelete('I', &head);
    dllTraverse(head); 

    return 0;
}