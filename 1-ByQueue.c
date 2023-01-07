/*
    Submitted By: Krishna Kanhaiya
    Submitted To: Dr. Aditi Sharan
    Course: M.Tech. Data Science (Semester-1)
    Subject: Data Structures & Algorithms
    Timestamp: January 06, 2023 17.38.05 IST
    Help: Julfikaraehmad
    Objective: Assignment
*/

#include<stdio.h>
#include<stdlib.h>

//Definition of the node of the queue named as Process
struct Process{
    int processID;
    int burstTime;
    int arrivalTime;
    struct Process * nextProcess;
};

struct Process * front = NULL, * rear = NULL;

int print() {
    if(front != NULL){
        struct Process * currProcess;
        currProcess = front;
        printf("Process ID\tBurst Time\tArrivalTime\n");
        while(currProcess -> nextProcess != NULL){
            printf("%d\t\t%d\t\t%d\n", currProcess -> processID, currProcess -> burstTime, currProcess -> arrivalTime);
            currProcess = currProcess -> nextProcess;
        }
        printf("%d\t\t%d\t\t%d\n", currProcess -> processID, currProcess -> burstTime, currProcess -> arrivalTime);
    }
    return 0;
}

int insertA(int processList[][2], int numberOfProcesses){
    int i;
    struct Process * currProcess = NULL;
    for(i = 0; i < numberOfProcesses; i++){
        currProcess = (struct Process *) malloc(sizeof(struct Process *));
        currProcess -> processID = i;
        currProcess -> burstTime = processList[i][0];
        currProcess -> arrivalTime = processList[i][1];
        currProcess -> nextProcess = NULL;
        if(i > 0){
            rear -> nextProcess = currProcess;
        } else if(i == 0){
            front = currProcess;
        }
        rear = currProcess;
        currProcess = NULL;
        free(currProcess);
    }
    rear -> nextProcess = NULL;
    return 0;
}

int insertB(int processList[][2], int numberOfProcesses){
    int i, j, elapsedTime = 0, timeDifference, tempElapsedTime, minProcessBurstTime;
    struct Process * currProcess = NULL, * prevProcess = NULL, *nextProcess = NULL, *minProcess = NULL;
    prevProcess = front;
    for(i = 0; i < numberOfProcesses; i++){
        currProcess = (struct Process *) malloc(sizeof(struct Process *));
        currProcess -> processID = i;
        currProcess -> burstTime = processList[i][0];
        currProcess -> arrivalTime = processList[i][1];
        currProcess -> nextProcess = NULL;
        if(i > 0){
            timeDifferece = (currProcess -> arrivalTime) - elapsedTime;
            if(timeDifference < 0){
                prevProcess = front;
                nextProcess = front;
                while(prevProcess != rear){
                    timeDifference = 
                }
            } else {
                rear -> nextProcess = currProcess;
                rear = currProcess;
                elapsedTime += timeDifference + currProcess -> burstTime;
            }
        } else {
            front = currProcess;
            rear = currProcess;
            elapsedTime = (currProcess -> arrivalTime) + (currProcess -> burstTime);
            minProcessBurstTime = currProcess -> burstTime;
        }
        currProcess = NULL;
        free(currProcess);
    }
}

int deleteA(){
    int minProcessBurstTime, elapsedTime = 0, minProcessArrivalTime, currProcessArrivalTime;
    struct Process * minProcess = NULL, * prevProcess = NULL, * currProcess = NULL, * nextProcess = NULL;
    while(front != NULL){
        print();
        minProcess = front;
        minProcessBurstTime = minProcess -> burstTime;
        if(front -> nextProcess != NULL){
            prevProcess = front;
            currProcess = front;
            minProcess = currProcess;
            minProcessArrivalTime = minProcess -> arrivalTime;
            currProcessArrivalTime = minProcessArrivalTime;
            while(currProcessArrivalTime > elapsedTime){
                //currProcess != rear
                if(currProcess -> nextProcess != NULL){
                    if(currProcess != minProcess){
                        prevProcess = currProcess;
                    }
                    currProcess = currProcess -> nextProcess;
                    currProcessArrivalTime = currProcess -> arrivalTime;
                } else {
                    printf("No min process at time %d.\n", elapsedTime);
                    elapsedTime = minProcessArrivalTime;
                    currProcessArrivalTime = minProcessArrivalTime;
                    printf("Time elapsed: %d\n**************************************\n", elapsedTime);
                    print();
                }
                if(currProcessArrivalTime < minProcessArrivalTime){
                    minProcess = currProcess;
                    minProcessArrivalTime = currProcessArrivalTime;
                }
            }
            currProcess = minProcess;
            minProcessBurstTime = minProcess -> burstTime;
            //currProcess != rear
            while(currProcess -> nextProcess != NULL){
                nextProcess = currProcess -> nextProcess;
                if((nextProcess -> arrivalTime <= elapsedTime) && (nextProcess -> burstTime <= minProcessBurstTime)){
                    prevProcess = currProcess;
                    minProcess = nextProcess;
                    minProcessBurstTime = minProcess -> burstTime;
                }
                currProcess = nextProcess;
            }
            if(minProcess != front){
                //added newly
                if(minProcess == rear){
                    rear = prevProcess;
                }
                prevProcess -> nextProcess = minProcess -> nextProcess;
            } else {
                front = front -> nextProcess;
            }
            minProcess -> nextProcess = NULL;
        } else {
            front = NULL;
            rear = NULL;
        }
        elapsedTime += minProcess -> burstTime;
        printf("Min process: {%d, %d, %d}\n", minProcess -> processID, minProcessBurstTime, minProcess -> arrivalTime);
        printf("Time elapsed: %d\n**************************************\n", elapsedTime);
        minProcess = NULL;
    }
    printf("There are no more processes available.\n");
    return 0;
}

int main(){
    //List of processes is given as an array
    int processList[5][2] = {
        //{BurstTime, ArrivalTime}
        //Array index is treated as a Process ID
        {2, 0},
        {5, 5},
        {10, 0},
        {2, 3},
        {4, 6}
    };
    //insertA(processList, 5);
    //deleteA();
    insertB(processList, 5);
    print();
    return 0;
}