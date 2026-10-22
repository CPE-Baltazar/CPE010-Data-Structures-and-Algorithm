#include <iostream>
#include <cmath>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();

    //NEWLY ADDED
    double compArea(double a, double b, double c); //func prot. for computing area
    double compPmeter(double a, double b, double c); //func prot. for computing perimeter
    std::string whataTriangle(); //func prot. for finding what kind of angle
};

//the original functions in here was transferred after the int main

int main() {
    // driver code
    Triangle set1(40, 30, 110);
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    //NEW ADDITIONS
    std::cout << "Area: " << set1.compArea(6, 7, 11) << std::endl; //The 6, 7, 11 are the different sides to compute the area
    std::cout << "Perimeter: " << set1.compPmeter(6, 9, 11) << std::endl; //The 6, 9, 11 are the sides to compute perimeter
    std::cout << "What angle: " << set1.whataTriangle() << std::endl; //outputs the function for what kind of angle is the triangle

    return 0;
}

//The function definitions
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

//NEW function definitions
double Triangle::compArea(double a, double b, double c) { //func def. for computing area
    double s = (a+b+c)/2;   
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double Triangle::compPmeter(double a, double b, double c) { //func def. for computing perimeter
    return a + b + c;
}

std::string Triangle::whataTriangle() { //func def. for finding what kind of angle
    if (angleA<90 && angleB<90 && angleC<90) { //acute means less than 90, even if one is 90, it is not acute
        return "acute-angled";
    } else if (angleA>90 || angleB>90 || angleC>90) { //obtuse means greater than 90, if one is 90, it is not obtuse
        return "obtuse-angled";
    } else {
        return "others..."; //others are just others.. like right triangle and stuff
    }
}
