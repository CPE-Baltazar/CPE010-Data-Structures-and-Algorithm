#ifndef SINGLY_LL_H //header file name
#define SINGLY_LL_H // 

template <typename T>
class SingleList{
    public:
    T data;
    SingleList<T> *next = nullptr;
};

template <typename T>
void listTraversal(SingleList<T>* head){

    while(head != nullptr){
        std::cout<<head->data;

        //to check if the next line is not equal to null
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
    std::cout<<std::endl;
}

template <typename T>
void sllinsertHead(T newData, SingleList<T> ** currentHead){

    //Allocate memory for the new node
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    //Set next of the new node to point to the previous Head
    newNode->next = *currentHead;
    //reset head to point to the new node
    *currentHead = newNode;
}

template <typename T>
void sllGeneralinsertion(T newData, SingleList<T> * prevNode){
    //check if it is the head node (previous node is null)
    if(prevNode==nullptr){
        std::cout<<"The previous node cannot be null."<<std::endl;
        return;
    }

    SingleList<T>* newNode = new SingleList<T>;
    //store data in the new node
    newNode->data = newData;
    //point new node to the node prev node was pointing to
    newNode->next = prevNode->next;
    //point prev node to the new node
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head){
    //Allocate new node
    SingleList<T>* newNode = new SingleList<T>;
    //dereference to the head node
    SingleList<T>* currentNode = *head;
    //store data in new data
    newNode->data = newData;
    //point next of new node to null
    newNode->next = nullptr;
    //check if the list is empty
    if(currentNode == nullptr){
        currentNode == newNode;
        return;
    }
    //traverse the list until next of the node is null
    while(currentNode->next != nullptr){
        //iteration going to one node to another
        currentNode = currentNode->next; 
    }
    currentNode->next = newNode;
}

template <typename T>
void sllDelete(T findData, SingleList<T>** head){
    //check if there is a list
    if(*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    //Search for the node:
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    //if data is not found
    if (currNode == nullptr) return;

    //delete the head node(if the head ndode is the findData)
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template<typename T>

void sllDeleteList(SingleList<T>** head){
    SingleList<T>* currentNode = *head;

    while(currentNode != nullptr){
        SingleList<T>* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    *head = nullptr;
}

#endif