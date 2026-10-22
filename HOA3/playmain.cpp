#include <iostream>
#include "playlist_LL.h"

int main(){
    kantaNode<std::string>* head = nullptr;
    kantaNode<std::string>* current = nullptr;

    playlistInsert<std::string>("Bahay Kubo", &head);
    playlistInsert<std::string>("Girl in the Mirror", &head);
    playlistInsert<std::string>("Shinunoga E-wa", &head);
    current = head;

    std::cout << "Play all:" << std::endl;
    playlisttraverse(head);

    std::cout << std::endl << "Next:" << std::endl;
    playlistNext<std::string>(&current);
    std::cout << std::endl << "Previous:" << std::endl;
    playlistPrev<std::string>(&current);

    std::cout << std::endl << "Remove Girl in the Mirror:" << std::endl;
    playlistDelete<std::string>("Girl in the Mirror", &head);
    playlisttraverse(head);

    return 0;
}