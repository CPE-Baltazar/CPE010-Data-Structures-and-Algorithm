#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo2.h"

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

    shellSort(unsortedArr, maxSize);
    std::cout << "\nShell Sort:\n";
    display(unsortedArr);

    mergeSort(unsortedArr, 0, maxSize - 1, maxSize);
    std::cout << "\nMerge Sort:\n";
    display(unsortedArr);

    quickSort(unsortedArr, 0, maxSize - 1);
    std::cout << "\nQuick Sort:\n";
    display(unsortedArr);

    return 0;
}

void display(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}