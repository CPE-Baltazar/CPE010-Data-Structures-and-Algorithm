#include "nodes.h"
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H
#include <iostream>

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    int i = 0;
    while(i <= arrSize){
        if(dataFind == data[i]){
            std::cout<<"the search is a success\n";
            return;
        }
        i++;
    }
    std::cout<<"The element is not found\n";
    return;
}

template <typename T>
void linearSearchLL(Node<T> *node, T dataFind){
    while(node != nullptr){
        if(dataFind == node->data){
            std::cout<<"the search is a success\n";
            return;
        }
        node = node->next;
    }
    std::cout<<"The element is not found\n";
    return;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
1. Start node is set to head of the list and the last node is set to NULL.
2. Middle element is calculated using the two pointers approach discussed above.
3. If the middle element is same as the key to be searched, we return it.
4. Else if middle element is greater than the key to be searched, we have to search is the
right side of the singly linked list. So, we set start pointer to the next of middle
element.
5. Else if middle element is less than the key to be searched, we have to search is the left
side of the singly linked list. So, we set last pointer to the middle element.
6. If the key is found or the entire linked list gets traversed, we break the loop.
*/
template <typename T>
void binarySearchLL(Node<T>* start, T findData){
    Node<T>* last = nullptr;

    while(start != last){
        Node<T>* middle = getMiddle(start, last);
        if(middle == nullptr) 
        break;

        if(findData == middle->data){
            std::cout << "the search is a success\n";
            return;
        } else if(findData < middle->data){
            last = middle;         
        } else{
            start = middle->next;   
        }
    }
    std::cout << "The element is not found\n";
}

//create a binary search using an array : getmiddle and binarySearchArr
template <typename T>
T binarySearchArr(T data[], int arrSize, T findData){
    int start = 0;
    int last = arrSize - 1;
    while(start <= last){
        T middle = data[(start + last) / 2];
        if(middle == findData){
            std::cout << "the search is a success\n";
            return middle;
        } else if(findData < middle){
            last = (start + last) / 2 - 1;
        } else{
            start = (start + last) / 2 + 1;
        }
    }
    std::cout << "The element is not found\n";
    return T();
}
#endif
