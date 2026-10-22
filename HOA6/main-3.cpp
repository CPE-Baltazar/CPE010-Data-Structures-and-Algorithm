#include <iostream>
#include <cstdlib>
#include <time.h>
#include "nodes.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main(){
    int dataset[max_size];
    srand(time(0));
    for(int i=0; i<max_size;i++){
        dataset[i] = rand();
    }
    for(int i=0; i<max_size;i++){
        std::cout<<dataset[i]<<" ";
    }   
    std::cout<<"\n";

    //user input to ask what value to find
    int toFind;
    std::cout<<"what value you want to search? ";
    std::cin>>toFind;

    linearSearchArr(dataset, max_size, toFind);

    Node<char>* name1  = new_node('K');
    Node<char>* name2  = new_node('E');
    Node<char>* name3  = new_node('N');
    Node<char>* name4  = new_node('J');
    Node<char>* name5  = new_node('I');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;

    std::cout<<"Linear Search for Linked List result: \n";
    linearSearchLL(name1, 'J');
    std::cout<<"Linear Search for Linked List result: \n";
    linearSearchLL(name1, 'x');
    std::cout<<"Binary Search for Linked List result: \n";
    binarySearchLL(name5, 'I');

    std::cout<<"\n";
    int toFind2;
    std::cout<<"what value you want to search? ";
    std::cin>>toFind2;
    binarySearchArr(dataset, max_size, toFind2);


return 0;
}