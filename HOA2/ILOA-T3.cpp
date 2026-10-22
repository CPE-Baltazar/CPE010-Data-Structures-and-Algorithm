#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
        //Constructor
        Student(std::string newName = "John Doe", int newAge = 18) {
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor was called" << std::endl;
        }
        //Deconstructor
        ~Student(){
            std::cout <<"Destructor was called" <<std::endl;
        }
        
        //Copy Constructor
        Student (const Student &copyStudent){
            std::cout << "Copy Constructor Called" << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        //Display Attributes
        void printDetails(){
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }

    };

int main() {
    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] = {"Acelajado", "Aguila", "Alvarez", "Baltazar", "Cabangon"};
    int ageList[j] = {21, 18, 19, 19, 20};

    for(int i=0; i<j; i++){ //LOOP A
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for(int i=0; i<j; i++){ //LOOP B
        studentList[i].printDetails();
    }

    return 0;
}