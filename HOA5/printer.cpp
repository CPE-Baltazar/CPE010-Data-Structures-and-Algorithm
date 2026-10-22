#include <iostream>
#include <string>
#include "queueArr.h"

class Job {
    public:
        int id;
        std::string userName;
        int pageNum;
        //prototypes
        Job();
        Job(int jobId, std::string name, int pages);
};

class Printer {
    private:
        queueArr<Job>* jobb;

    public:
        //constructor
        Printer(int capacity){
            jobb = new queueArr<Job>(capacity);
        }
        //destructor
        ~Printer(){
            delete jobb;
        }
        //prototypes
        void add(Job addJob);
        void process();
};

int main() {
    Printer p(5); //The limit of what our printer can print at a time
    std::cout << "Zoro was about to send his file but he was too late\n\n";
    //          ID      NAME   PAGE
    p.add(Job(2515531, "Kenji", 6));
    p.add(Job(2345678, "Bakugo", 1));
    p.add(Job(2000123, "Shoto", 7));
    p.add(Job(2582791, "Might", 3));
    p.add(Job(2397208, "Deku", 5));
    p.add(Job(9999999, "Zoro", 4)); //Zoro cannot print because it is full
    p.process(); //now processing the jobs 

    std::cout << "\nNow Zoro was able to send his file this time\n\n";
    p.add(Job(9999999, "Zoro", 4)); //he can send his file again
    p.process();

    return 0;
}
//function to make a job but default
Job::Job(){
    id = 0;
    userName = "";
    pageNum = 0;
}
//function to create a job with parameters
Job::Job(int jobId, std::string name, int pages){
    id = jobId;
    userName = name;
    pageNum = pages;
}
//function to add job to our queue
void Printer::add(Job addJob){
    //checking if our queue is full or not
    if(jobb->Full()){ 
        std::cout << addJob.userName << " cannot print! Queue is full.\n";
        return;
    }
    //now we can add job to our queue
    jobb->Enqueue(addJob);
    std::cout << addJob.userName << " sent " << addJob.pageNum << " paged file.\n";
}
//function to process jobs to queue
void Printer::process(){
    //check if queue is empty or not
    if(jobb->Empty()){
        std::cout << "No jobs to process!\n";
        return;
    }
    //now we process the queue
    while(!jobb->Empty()){
        Job current = jobb->Front(); //we first get the front most job
        jobb->Dequeue(); //then we remove it from our queue to simulate processing
        std::cout << "Printing " << current.userName << "'s file" << "...done!\n";
    }
}