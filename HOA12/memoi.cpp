#include <iostream>

int memo[1001];
int getMinSteps(int n);

int main() {
    int n;
        std::cout << "Input 1 to 1000: ";
        std::cin >> n;
        if(n >= 1 && n <= 1000){
            for(int i = 0; i <= n; i++) {
                memo[i] = -1;
            }
            std::cout << "Minimum steps: " << getMinSteps(n) << std::endl;
        }else{ 
            std::cout << "Invalid input" << std::endl;
        }
    return 0;
}

int getMinSteps(int n) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    int r = 1 + getMinSteps(n - 1);
    if (n%2 == 0) r = std::min(r, 1 + getMinSteps(n/2));
    if (n%3 == 0) r = std::min(r, 1 + getMinSteps(n/3));
    memo[n] = r;
    return r;
}