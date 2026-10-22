#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

void display(int arr[]);
const int maxSize = 100;

int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100 + 1;
    }
    std::cout<<"random numbers: \n";
    display(unsortedArr);

    std::cout<<"bubble sort: \n";
    bubbleSort(unsortedArr, maxSize);
    display(unsortedArr);

    std::cout<<"insertion sort: \n";
    insertionSort(unsortedArr, maxSize);
    display(unsortedArr);

    std::cout<<"selection sort: \n";
    selectionSort(unsortedArr, maxSize);
    display(unsortedArr);


    return 0;
}

// FUNCTION DEFINITION/S
void display(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}