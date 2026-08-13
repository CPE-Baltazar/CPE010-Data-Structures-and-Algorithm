#include <iostream>
#ifndef STACK_LIST_H // header file name
#define STACK_LIST_H

template <typename T>
class Node{
    public:
    T data;     // VALUE THAT WE NEED TO STORE
    Node* next; // POINTER TO THE NEXT NODE


};

// Global pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;


//## Operations for the stack

// ISEMPTY
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// PUSH
template <typename T>
void push(T newData){
    // Create a new node and assign the newData
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    // New node points to current top, then becomes the new top 
    newNode->next = head<T>;
    head<T> = newNode;
}

// POP
template <typename T>
T pop() {
    if (isEmpty<T>()) {
        std::cout << "Stack underflow!\n";
        return T{};
    }

    // Save the current top node
    Node<T>* temp = head<T>;

    // Store its data
    T tempVal = temp->data;

    // Move the head to the next node
    head<T> = head<T>->next;

    // Free the removed node
    delete temp;

    // return the removed value
    return tempVal;
}

// TOP
template <typename T>
void Top(){
    // Error Catching
    if (isEmpty<T>()) {
        std::cout << "Stack underflow!\n";
        return;
    }
    // Display the top node
    std::cout << "Top of Stack:  " << head<T>->data << std::endl;
}


// DISPLAY ALL
template <typename T>
void displayAll(){
    if (isEmpty<T>()) {
        std::cout << "Stack underflow!\n";
        return;
    }

    std::cout << "Stack (top to bottom): ";
    Node<T>* tempVal = head<T>;
    while (tempVal != nullptr) {
        std::cout << tempVal->data;
        if (tempVal->next != nullptr) std::cout << " -> ";
        tempVal = tempVal->next;
    }
    std::cout << std::endl;
}

// CLEAR (had to add this after answers didn't match and realized I had to clear the stack after every call)
template <typename T>
void clear() {
    while (!isEmpty<T>()) {
        pop<T>();
    }
}

// COMPARATOR
bool comparator(char openSymbol, char closeSymbol){
    // checkes for all three types of brackets, parentheses, and braces
    return (openSymbol == '(' && closeSymbol == ')') || (openSymbol == '{' && closeSymbol == '}') || (openSymbol == '[' && closeSymbol == ']');
}

// DELIMITERS
bool isOpen(char i){ return i == '(' || i == '{' || i == '['; }
bool isClose(char j){ return j == ')' || j == '}' || j == ']'; }

// PARSER
bool parser(const std::string& expressions){
    clear<char>(); // clear stack at every validation call

    for (char k : expressions){
        if (!isOpen(k) && !isClose(k)) {
            continue; // a) if not balancing continue
        }

        if (isOpen(k)) {
            push<char>(k); // b) if opening symbol, we push em
        }
        else { // c) if closing symbol
            if (isEmpty<char>()) { // c.i) stack empty check 
                std::cout << "Err! '" << k << "' has no matching opening symbol.\n";
                return false;
            }
            char sym = pop<char>(); // c.ii) pop the stack if stack not empty
            if (!comparator(sym, k)) { // if popped symbol isn't the same, error em!
                std::cout << "Err! '" << sym << "' does not match '" << k << "'.\n";
                return false;
            }
        }
    }

    if (!isEmpty<char>()) { // 3. if stack is not empty, show error!
        std::cout << "Err! Stack is not empty (perhaps there is an unmatched opening symbol).\n";
        return false;
    }

    return true;
}

#endif