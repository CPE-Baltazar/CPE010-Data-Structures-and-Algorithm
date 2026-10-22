#include <iostream>
#include <cmath>   

float compD(float d1, float dd1, float d2, float dd2); //function prototype

int main() {
    float d1, dd1, d2, dd2;

    std::cout << "Enter d1 and dd1: "; //asks user to input d1 and dd1
    std::cin >> d1 >> dd1;
    std::cout << "Enter d2 and dd2: "; //asks user to input d2 and dd2
    std::cin >> d2 >> dd2;

    float distance = compD(d1, dd1, d2, dd2); //calls the function and store it in the variable distance

    std::cout << "The distance is: " << distance << std::endl; //outputs the distance

    return 0;
}

float compD(float d1, float dd1, float d2, float dd2) {
    return sqrt((d2-d1)*(d2-d1) + (dd2-dd1)*(dd2-dd1)); //calculates the distance
}
