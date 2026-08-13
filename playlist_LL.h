#include <iostream>
#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H



template <typename T>
class playList{
    public:
        T data;
        playList<T>* next = nullptr;
        playList<T>* prev = nullptr;
};


// creating a node
template <typename T>
playList<T>* newNode(T newData){
    //dynamically allocate memory for a new node
    playList<T>* newNodePtr = new playList<T>;

    //Store data in the node:
    newNodePtr->data = newData;

    //since its a new node, it will point to null
    newNodePtr->next = nullptr;
    newNodePtr->prev = nullptr;

    return newNodePtr;
}


// Insertion at end of playlist (before head)
template <typename T>
void pllInsertEnd(T newData, playList<T>** currentHead) {

    // create a new node
    playList<T>* newNodePtr = newNode(newData);

    // if playlist is empty
    if(*currentHead == nullptr){
        *currentHead = newNodePtr;

        newNodePtr->next = newNodePtr;
        newNodePtr->prev = newNodePtr;

        return;
    }

    playList<T>* head = *currentHead;
    playList<T>* tail = head->prev; // Loop back from head

    // connects newNodePtr between tail and head
    tail->next = newNodePtr;
    newNodePtr->prev = tail;
    newNodePtr->next = head;
    head->prev = newNodePtr;
}


// Insertion at head (new node is new head)
template <typename T>
void pllInsertHead(T newData, playList<T>** currentHead){

    // reuse insert end
    pllInsertEnd(newData, currentHead);

    // make new head the new head (haha)
    *currentHead = (*currentHead)->prev;
}


// General Insertion
template <typename T>
void pllGeneralInsertion(T newData, playList<T>* prevNode){
    // prev node cannot be null check
    if(prevNode==nullptr){
        std::cout << "The previous node cannot be null!\n";
        return;
    }

    // new node
    playList<T>* newNodePtr = newNode(newData);

    // update pointers
    newNodePtr->next = prevNode->next;
    newNodePtr->prev = prevNode;

    prevNode->next->prev = newNodePtr;
    prevNode->next = newNodePtr;
}


// Delete
template <typename T>
void pllDelete(T findData, playList<T>** currentHead){

    // list check if empty
    if(*currentHead == nullptr)
        return;

    // finding specified to delete
    playList<T>* head = *currentHead;
    playList<T>* current = head;
    bool found = false;

    // Finding what node is needed
    do{
        if(current->data == findData){
            found = true;
            break;
        }
        current = current->next;
    } while(current != head);

    if(!found)
        return;

    // if there is only one node in the list
    if(current->next == current){
        *currentHead = nullptr;
        delete current;
        return;
    }

    // update
    current->prev->next = current->next;
    current->next->prev = current->prev;

    // if head isdeleted, change head to next node
    if(current == head){
        *currentHead = current->next;
    }

    delete current;
}


// Traverse to next song
template <typename T>
playList<T>* pllNext(playList<T>* current){
    if(current == nullptr)
        return nullptr;
    return current->next;
}


// Traverse to previous song
template <typename T>
playList<T>* pllPrev(playList<T>* current){
    if(current == nullptr)
        return nullptr;
    return current->prev;
}


// Traversal (all songs)
template <typename T>
void pllTraverse(playList<T>* head){
    if(head == nullptr){
        std::cout << "Playlist is empty!\n";
        return;
    }

    std::cout << "Playing songs:\n";
    playList<T>* current = head;
    do{
        std::cout << current->data << "\n";
        current = current -> next;
    } while(current != head);
    std::cout << "\n(back to \"" << head -> data << "\")\n\n";
}

#endif