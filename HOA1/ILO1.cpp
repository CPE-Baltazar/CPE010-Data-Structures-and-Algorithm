#include <iostream>

// Function prototypes
int getSum(int a, int b);
void compare(int a, int b);
void logic(bool c, bool d);

int main() {
    int a, b;
    bool c, d;
    int choice;

    do {
        std::cout << "Input first num: ";
        std::cin >> a;

        std::cout << "Input second num: ";
        std::cin >> b;

        std::cout << "Input a boolean value: ";
        std::cin >> c;

        std::cout << "Input a second boolean value: ";
        std::cin >> d;

        std::cout << "\nThe sum of the two numbers is " << getSum(a, b) << std::endl; // display sum
        compare(a, b); // display whether a is greater than b

        logic(c, d); // displays all logical operations

        std::cout << "\nPress any key to redo, otherwise press any num: ";
        std::cin >> choice;

    } while (choice == 1); // loop to redo (enter 1 to redo, any other number to exit)

    return 0;
}

int getSum(int a, int b) {
    int sum = 0;
    sum = a + b;
    return sum;
}

void compare(int a, int b) {
    if (a > b) {
        std::cout << a << " is greater than " << b;
    } else {
        std::cout << a << " is not greater than " << b;
    }
    return;
}

void logic(bool c, bool d) {
    std::cout << "\n\n>>>LOGICAL OPERATION<<<" << std::endl;
    std::cout << "c && d = " << (c && d) << std::endl;
    std::cout << "c || d = " << (c || d) << std::endl;
    std::cout << "!c = " << (!c) << std::endl;
    std::cout << "!d = " << (!d) << std::endl;

    return;
}