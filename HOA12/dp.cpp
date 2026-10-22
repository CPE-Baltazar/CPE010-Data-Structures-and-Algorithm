#include <iostream>
#include <algorithm>

int getMinSteps(int n);

int main() {
    int n;
    std::cout << "BOTTOM UP DP" << std::endl;
    do {
        std::cout << "Enter n from 1 to 1000, or 0 to stop: ";
        std::cin >> n;
        if (n >= 1 && n <= 1000) {
            std::cout << "Minimum steps to reach 1 is " << getMinSteps(n) << std::endl;
        } else if (n != 0) {
            std::cout << "Invalid input" << std::endl;
        }
    } while (n != 0);
    return 0;
}   

int getMinSteps(int n) {
    int dp[1001];
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}