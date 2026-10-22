#include <iostream>

float kToF(float kelvin); //function prototype 

int main() {
    float kelvin;

    std::cout << "Enter temp in Kelvin: "; //asks user to input temp in Kelvin
    std::cin >> kelvin;

    float fahren = kToF(kelvin); //calls for the function to convert K to F

    std::cout << kelvin << " K = " << fahren << " F" << std::endl; //outputs the converted temp

    return 0;
}

float kToF(float kelvin) { //function definition
    return (kelvin - 273.15) * 9.0 / 5.0 + 32; //converts K to F
}
