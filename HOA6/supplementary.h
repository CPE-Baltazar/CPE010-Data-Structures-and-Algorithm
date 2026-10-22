#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H
#include "nodes.h"
#include "searchingAlgo.h"

template <typename T>
int linearSearchArr2(T data[], int arrSize, T dataFind){
    for(int i = 0; i < arrSize; i++){
        if(dataFind == data[i]){
            std::cout << "the search is a success with " << i + 1 << " comparisons\n";
            return i + 1;
        }
    }
    std::cout << "The element is not found\n";
    return arrSize;
}

template <typename T>
int linearSearchLL2(Node<T> *node, T dataFind){
    int ll = 0;
    while(node){
        ll++;
        if(dataFind == node->data){
            std::cout << "the search is a success with " << ll << " comparisons\n";
            return ll;
        }
        node = node->next;
    }
    std::cout << "The element is not found\n";
    return ll;
}

template <typename T>
int countArr(T data[], int arrSize, T dataFind){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(data[i] == dataFind){
            count++;
        }
    }
    std::cout << count << " repeat\n";
    return count;
}

template <typename T>
int countLL(Node<T> *node, T dataFind){
    int count = 0;
    while(node){
        if(node->data == dataFind){ 
            count++;
        }
        node = node->next;
    }
    std::cout << count << " repeat\n";
    return count;
}

template <typename T>
T BinarySearchArr2(T data[], int start, int last, T findData, int &cbnry){
    if(start > last){
        std::cout << "not found (" << cbnry << " comparisons)\n";
        return T();
    }
    int midol = (start + last) / 2;
    cbnry++;
    if(data[midol] == findData){
        std::cout << cbnry << " comparisons\n";
        return data[midol];
    }
    if(findData < data[midol]){
        return BinarySearchArr2(data, start, midol-1, findData, cbnry);
    }

    return BinarySearchArr2(data, midol+1, last, findData, cbnry);
}

#endif