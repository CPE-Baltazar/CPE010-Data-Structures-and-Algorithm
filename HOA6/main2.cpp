#include <iostream>
#include "nodes.h"
#include "searchingAlgo.h"
#include "supplementary.h"

int main(){
    int array1[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int num1 = 10;
    std::cout << "Linear Search for Array result: "; 
    linearSearchArr2(array1, num1, 18);

    Node<int> *head1 = new_node(array1[0]);
    Node<int> *temp1 = head1;
    for(int i = 1; i < num1; i++){ 
        temp1->next = new_node(array1[i]); 
        temp1 = temp1->next; 
    }
    std::cout << "Linear Search for Linked List result: "; 
    linearSearchLL2(head1, 18);

    std::cout << "Array Count result: "; 
    countArr(array1, num1, 18);
    std::cout << "Linked List Count result: "; 
    countLL(head1, 18);

    int array3[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int num3 = 10;
    std::cout << "Binary Search for Array result: "; 
    binarySearchArr(array3, num3, 8);

    int c2_greentea = 0;
    std::cout << "Recursive Binary Search for Array result: "; 
    BinarySearchArr2(array3, 0, num3-1, 8, c2_greentea);

    return 0;
}