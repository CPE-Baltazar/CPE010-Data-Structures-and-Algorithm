#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

bool algo_uniqueA(const std::vector<int>& A){
    int n = A.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

void search_test(int size) {
    std::vector<int> A;

    for(auto i = 0; i < size; i++){
        A.push_back(i);
    }

    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();
    bool search_result = algo_uniqueA(A);

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken to search = " <<
        std::chrono::duration_cast<std::chrono::microseconds>
        (end - begin).count() << " microseconds" << std::endl;
    if(search_result)
        std::cout << "Array of size " << size << " is unique." << std::endl;
    else
        std::cout << "Array of size " << size << " is not unique." << std::endl;
}

int main(){
    search_test(1000);
    search_test(12000);
    search_test(26700);
    return 0;
}