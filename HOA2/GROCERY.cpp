#include <iostream>
#include <string>

class Fruit {
private:
    std::string fruitName;
    float moneyEach;
    int howManyPls;
 
public:
    //makes a new fruit thingy
    Fruit(std::string n = "SomeFruit", double p = 0, int q = 0) {
        fruitName = n;
        moneyEach = p;
        howManyPls = q;
        std::cout << "New Fruit Constructed!" << std::endl;
    }
    //removes the fruit
    ~Fruit() {
        std::cout << "Deconstructed." << std::endl;
    }
    //this one copies the fruit  
    Fruit(Fruit& other) {
        fruitName = other.fruitName;
        moneyEach = other.moneyEach;
        howManyPls = other.howManyPls;
        std::cout << "Copied the fruit." << std::endl;
    }
    //copies it again but different
    Fruit& operator=(Fruit& other) {
        std::cout << "= copied the fruit again" << std::endl;
        if (this != &other) {
            fruitName = other.fruitName;
            moneyEach = other.moneyEach;
            howManyPls = other.howManyPls;
        }
        return *this;
    }
 
    double doMath(){
        return moneyEach * howManyPls; // price times how many 
    }

    std::string whatsMyName(){
        return fruitName;
    }

    void showMe(){
        std::cout << "[Fruit] " << fruitName << " - PHP " << moneyEach
                  << " x " << howManyPls << " = PHP " << doMath() << std::endl;
    }
};
 
class Vegetable {
private:
    std::string veggieName;
    float moneyEach;
    int howManyPls;
 
public:
    Vegetable(std::string n = "SomeVeggie", double p = 0, int q = 0) {
        veggieName = n;
        moneyEach = p;
        howManyPls = q;
        std::cout << "New Veggie Constructed!" << std::endl;
    }
    ~Vegetable() {
        std::cout << "Deconstructed." << std::endl;
    }
    Vegetable(const Vegetable& other) {
        veggieName = other.veggieName;
        moneyEach = other.moneyEach;
        howManyPls = other.howManyPls;
        std::cout << "Copied the veggie." << std::endl;
    }
    Vegetable& operator=(Vegetable& other) {
        std::cout << "= copied the veggie again" << std::endl;
        if (this != &other) {
            veggieName = other.veggieName;
            moneyEach = other.moneyEach;
            howManyPls = other.howManyPls;
        }
        return *this;
    }
 
    double doMath(){
        return moneyEach * howManyPls;
    }
    std::string whatsMyName(){ 
        return veggieName; 
    }
 
    void showMe(){
        std::cout << "[Veggie] " << veggieName << " - PHP " << moneyEach
                  << " x " << howManyPls << " = PHP " << doMath() << std::endl;
    }
};
 
// adds up everything, fruits and veggies together
double TotalSum(Fruit** myFruits, int fruitCount, Vegetable** myVeggies, int veggieCount) {
    double bigTotal = 0;
    for (int i = 0; i < fruitCount; i++) {
        bigTotal = bigTotal + myFruits[i]->doMath();
    }
    for (int j = 0; j < veggieCount; j++) {
        bigTotal = bigTotal + myVeggies[j]->doMath();
    }
    return bigTotal;
}
 
int main() {
    int fruitCount = 2;
    Fruit** fruitBasket = new Fruit*[fruitCount];
    fruitBasket[0] = new Fruit("Apple", 10, 7);
    fruitBasket[1] = new Fruit("Banana", 10, 8);
 
    int veggieCount = 2;
    Vegetable** veggieBasket = new Vegetable*[veggieCount];
    veggieBasket[0] = new Vegetable("Broccoli", 60, 12);
    veggieBasket[1] = new Vegetable("Lettuce", 50, 10);
 
    std::cout << "\nGrocery List" << std::endl;
    for (int i = 0; i < fruitCount; i++) {
        fruitBasket[i]->showMe();
    }
    for (int i = 0; i < veggieCount; i++) {
        veggieBasket[i]->showMe();
    }
 
    double moneyNeeded = TotalSum(fruitBasket, fruitCount, veggieBasket, veggieCount);
    std::cout << "\nTotal Sum: PHP " << moneyNeeded << std::endl;
 
    int byeIndex = -1;
    for (int i = 0; i < veggieCount; i++) {
        if (veggieBasket[i]->whatsMyName() == "Lettuce") {
            byeIndex = i;
            break;
        }
    }
 
    if (byeIndex != -1) {
        delete veggieBasket[byeIndex]; // free the memory
 
        Vegetable** smolerBasket = new Vegetable*[veggieCount - 1];
        int k = 0;
        for (int i = 0; i < veggieCount; i++) {
            if (i != byeIndex) {
                smolerBasket[k] = veggieBasket[i];
                k++;
            }
        }
        delete[] veggieBasket;
        veggieBasket = smolerBasket;
        veggieCount = veggieCount - 1;
    }
 
    double newMoneyNeeded = TotalSum(fruitBasket, fruitCount, veggieBasket, veggieCount);
    std::cout << "\nUpdated Total Sum: PHP " << newMoneyNeeded << std::endl;
 
    // clean up everything 
    for (int i = 0; i < fruitCount; i++) {
        delete fruitBasket[i];
    }
    delete[] fruitBasket;
 
    for (int i = 0; i < veggieCount; i++) {
        delete veggieBasket[i];
    }
    delete[] veggieBasket;
 
    return 0;
}