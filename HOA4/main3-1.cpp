#include <iostream>
#include "stackList.h"

bool isBalanced(char exp[]);

int main(){
    char* exprsn[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"};

    for (int i = 0; i < 4; i++){
        char*exp= exprsn[i];
        std::cout<< "\nExpression:"<<exp<<std::endl;
        if (isBalanced(exp) == true){
            std::cout<< "Valid?: YES\n";
        }
        else{
            std::cout <<"Valid?: NO\n";
        }
    }
    return 0;
}

int length(char exp[]){
    int count = 0;
    for(int i = 0; exp[i] != 0; i++){
        count++;
    }
    return count;
}
// function to check if balanced or nah
bool isBalanced(char exp[]){
    while (!isEmpty<char>())
        pop<char>(); // we need to clear stack to not reuse data from prev expression

    int len = length(exp);
    for(int i = 0; i < len; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
 
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty<char>()){
                std::cout<<"Error! no opening symbol for " <<exp[i]<<std::endl;
                return false;
            }
            char top = pop<char>(); 

            if(exp[i] == ')' && top != '('){
                std::cout <<"Error! "<<top<< " does not match " <<exp[i]<<std::endl;
                return false;
            }
            if(exp[i] == '}' && top != '{'){
                std::cout <<"Error! "<<top<< "does not match " <<exp[i]<<std::endl;
                return false;
            }
            if(exp[i] == ']'&& top != '['){
                std::cout <<"Error! "<<top<< " does not match " << exp[i]<<std::endl;
                return false;
            }
        }
    }
    if (!isEmpty<char>()){
        std::cout << "Error! No closing symbol!\n";
        return false;
    }
    return true;
}