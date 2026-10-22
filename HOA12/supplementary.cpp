#include <iostream>

const int M = 4;
const int N = 4;
int countPaths(int mtx[M][N], int i, int j, int cost);

int main() {
    int mtx[M][N] = {
        {4, 7, 1, 6},   
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int cost;
    std::cout << "Enter the target cost: ";
    std::cin >> cost;

    int result = countPaths(mtx, M - 1, N - 1, cost);
    std::cout << "Number of paths with cost " << cost << " is " << result << std::endl;
    
    return 0;
}

int countPaths(int mtx[M][N], int i, int j, int cost){
    if(cost < 0) return 0;
    if(i == 0 && j == 0){
        if(mtx[0][0] == cost){ 
            return 1;
        }
        return 0;
    }
    if(i == 0){
        return countPaths(mtx, i, j - 1, cost - mtx[i][j]);
    }
    if(j == 0) {
        return countPaths(mtx, i - 1, j, cost - mtx[i][j]);
    }
    return countPaths(mtx, i - 1, j, cost - mtx[i][j]) + countPaths(mtx, i, j - 1, cost - mtx[i][j]);
}

