#include <iostream>
#include "queuell.h"
#include "queueArr.h"

int main() {

    queueArr<int> q(6);
    q.Enqueue(1);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(2);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(3);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(4);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(5);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(6);
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(6);
    q.Dequeue();
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Dequeue();
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Dequeue();
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Dequeue();
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Dequeue();
    std::cout<<"q.front: " << q.Front() << " q_back: " << q.Back() << std::endl;
    q.Enqueue(1);

    q.Clear();
    std::cout<< q.Front() << "\n" << q.Back();
    std::cout<<"\n";

    //for copy constructor
    queueArr<int> q2=q;
    
    //for assignment operator
    queueArr<int> q3(5);
    q3 = q;

    return 0;
}