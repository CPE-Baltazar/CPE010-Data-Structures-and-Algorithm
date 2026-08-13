#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include "queueArr.h"


class Job {
private:
    int jobID;
    std::string username;
    int numOfPages;

public:
    // DEFAULT CONSTRUCTOR & CONSTRUCTOR
    Job()
    {
        jobID = 0;
        username = "";
        numOfPages = 0;
    }

    Job(int id, std::string name, int pages) {
        jobID = id;
        username = name;
        numOfPages = pages;
    }

    // GETTERS 
    int getJobID() {
        return jobID;
    }

    std::string getName() {
        return username;
    }

    int getNumOfPages() {
        return numOfPages;
    }

    // DISPLAY
    void displayJob() {
        std::cout << "[ #" << jobID << " - User: " << username << " - Pages: " << numOfPages << " ]";
    }
};


// PRINTER CLASS 
class Printer {
private:
    queueArr<Job> jobsList;

public:
    // CONSTRUCTOR (using member initializer)
    Printer(int max = 10): jobsList(max){}

    // REQUEST A JOB
    void addJob(int jobID, std::string username, int numOfPages){
        Job newJob(jobID, username, numOfPages);

        jobsList.Enqueue(newJob);

        std::cout << "New Request: ";
        newJob.displayJob();
        std::cout << " added to queue." << std::endl;
    }

    // PROCESS JOB (oldest)
    void processNext()
    {
        if (jobsList.Empty())
        {
            std::cout << "Idle... No pending jobs to print.\n";
            return;
        }

        Job currentJob = jobsList.Front();

        std::cout << "Printing: ";
        currentJob.displayJob();
        std::cout << " -> Printing complete!\n";

        jobsList.Dequeue();
    }

    // DO ALL
    void processAll()
    {
        std::cout << "\n-- Remaining Jobs --\n";

        while (!jobsList.Empty()) {
            processNext();
        }

        std::cout << "-- All jobs completed. --\n\n";
    }

    // Returns the number of jobs waiting
    int getPendingCount()
    {
        return jobsList.Size();
    }
};

#endif