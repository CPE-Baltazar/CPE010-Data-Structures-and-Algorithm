#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

void display(int arr[]);
const int maxSize = 100;
const int numcrocodiles = 5;

void tallyVotes(int arr[], int maxSize, int voteCount[]);
int winnerchickndinner(int voteCount[]);

int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % numcrocodiles + 1;
    }
    std::cout << "All votes:\n";
    display(unsortedArr);

    int voteCount[numcrocodiles] ={0, 0, 0, 0, 0};
    std::string politician[numcrocodiles] ={
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };
    insertionSort(unsortedArr, maxSize);

    std::cout << "\nTallied votes:\n";
    display(unsortedArr);

    tallyVotes(unsortedArr, maxSize, voteCount);

    int winnerIndex = winnerchickndinner(voteCount);
    std::cout << "\nVote Tally: \n";
    for (int c = 0; c < numcrocodiles; c++) {
        std::cout << politician[c] <<": " << voteCount[c] << " votes\n";
    }
    std::cout << "\nWinner: "<< politician[winnerIndex]<<"\n";

    return 0;
}

void display(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void tallyVotes(int arr[], int maxSize, int voteCount[]) {
    for (int i = 0; i < maxSize; i++) {
        voteCount[arr[i] - 1]++;
    }
}

int winnerchickndinner(int voteCount[]) {
    int winner = 0;
    for (int c = 1; c < numcrocodiles; c++) {
        if (voteCount[c] > voteCount[winner]) {
            winner = c;
        }
    }
    return winner;
}