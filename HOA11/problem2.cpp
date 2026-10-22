#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

int rpower(int x, int n){
    if(n == 0) return 1;
    else return x * rpower(x, n - 1);
}

int brpower(int x, int n){
    int y;
    if(n == 0) return 1;
    if(n % 2 == 1){
        y = brpower(x, (n - 1)/2);
        return x * y * y;
    }
    else{
        y = brpower(x, n/2);
        return y * y;
    }
}

void power_test(int n){
    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();
    int searchr_result = rpower(1, n);

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "n = " << n << std::endl;
    std::cout << "rpower: Time taken = " <<
        std::chrono::duration_cast<std::chrono::microseconds>
        (end - begin).count() << " microseconds" << std::endl;

    begin = std::chrono::steady_clock::now();
    int searchbr_result = brpower(1, n);
    end = std::chrono::steady_clock::now();
    std::cout << "brpower: Time taken = " <<
        std::chrono::duration_cast<std::chrono::microseconds>
        (end - begin).count() << " microseconds" << std::endl;
}

int main() {
    power_test(1000);
    power_test(12000);
    power_test(26700);
    return 0;
}