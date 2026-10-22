#include <iostream>

//function prototype 
void swappa(int &a, int &b); 

int main() {
    int n1, n2;

    std::cout << "Enter first number: "; //asks user to input 1st num 
    std::cin >> n1;
    std::cout << "Enter second number: ";//asks user to input 2nd num
    std::cin >> n2;

    std::cout << "\nBefore swapping: " << n1 << " and " << n2 << std::endl; //outputs the num before swap 
    swappa(n1, n2); //calls for the function
    std::cout << "After swapping: " << n1 << " and " << n2 << std::endl; //outputs the swapped numbers

    return 0;
}
//function definition
void swappa(int &a, int &b) { 
    int temp = a; //stores value of a in temp
    a = b; //assigns value of b to a
    b = temp; //assigns value of temp to b
}
