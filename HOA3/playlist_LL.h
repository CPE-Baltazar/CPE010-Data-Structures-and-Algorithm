#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>

template <typename T>
class kantaNode{
    public:
        T data;
        kantaNode<T>* next = nullptr;
        kantaNode<T>* prev = nullptr;
};

//====================
//creating a node
//====================
template <typename T>
kantaNode<T>* new_song(T newData){
    //dynamically allocate memory for a new node
    kantaNode<T>* newNode = new kantaNode<T>;
    //store the data in the node:
    newNode->data = newData;
    //since its a new node, it will point to null for now
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//====================
//Traversal
//====================
template <typename T>
void playlisttraverse(kantaNode<T>* currentHead){
    if(currentHead == nullptr){
        std::cout << "Playlist is empty.\n";
        return;
    }
    kantaNode<T>* currentNode = currentHead;
    do{
        std::cout << currentNode->data << std::endl;
        currentNode = currentNode->next;
    } while(currentNode != currentHead);
}

//====================
//move to the next song
//====================
template <typename T>
void playlistNext(kantaNode<T>** current){
    if(*current == nullptr) return;
    *current = (*current)->next;
    std::cout << "Now playing: " << (*current)->data << std::endl;
}

//====================
//move to the previous song
//====================
template <typename T>
void playlistPrev(kantaNode<T>** current){
    if(*current == nullptr) return;
    *current = (*current)->prev;
    std::cout << "Now playing: " << (*current)->data << std::endl;
}

//====================
//insertion at the end
//====================
template <typename T>
void playlistInsert(T newData, kantaNode<T>** currentHead){
    //create a new node
    kantaNode<T>* newNode = new_song(newData);
    //if the playlist is empty, the new node points to itself
    if(*currentHead == nullptr){
        newNode->next = newNode;
        newNode->prev = newNode;
        *currentHead = newNode;
        return;
    }
    //the last node is the one before the head
    kantaNode<T>* last = (*currentHead)->prev;
    //connect the last node to the new node
    last->next = newNode;
    newNode->prev = last;
    //connect new node back to the head
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;
}

//====================
//deletion
//====================
template <typename T>
void playlistDelete(T findData, kantaNode<T>** currentHead){
    if(*currentHead == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    //traverse the circle until node is found or we go back to head
    kantaNode<T>* currentNode = *currentHead;
    do{
        if(currentNode->data == findData) break;
        currentNode = currentNode->next;
    } while(currentNode != *currentHead);
    if(currentNode->data != findData){ //if didn't find it
        std::cout << "Song not found." << std::endl;
        return;
    }
    if(currentNode->next == currentNode){ //only song left in the playlist
        *currentHead = nullptr;
    } else {
        //connect the previous node to the next node and vice versa
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;

        if(*currentHead == currentNode){ //if we deleted the head, move the currenthead to the next
            *currentHead = currentNode->next;
        }
    }

    //delete the node
    delete currentNode;
}

#endif