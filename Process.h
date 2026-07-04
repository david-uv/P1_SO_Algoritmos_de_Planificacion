
#ifndef PROCESS_H
#define PROCESS_H


#include <string>

class Process {


    private:
        //attributes of the processes
        std::string idProcess;
        int burstTime;
        int arrivalTime;
        int idQueue;
        int priority;
        //state of execution
        int remainingTime;
        bool started;


        //individual metrics
        double waitingTime;
        double turnaroundTime;
        double responseTime;
        double completionTime;
        

    public:
        //constructor
  Process(std::string idProcess,
            int burstTime,
            int arrivalTime,
            int idQueue,
            int priority);        

        // Getters
        std::string getIdProcess() const;
        int getBurstTime() const;
        int getArrivalTime() const;
        int getIdQueue() const;
        int getPriority() const;

        double getWaitingTime() const;
        double getTurnaroundTime() const;
        double getResponseTime() const;
        double getCompletionTime() const;
        int getRemainingTime() const;
        bool getStarted() const;

        
        // setters
        void setWaitingTime(double waitingTime);
        void setTurnaroundTime(double turnaroundTime);
        void setResponseTime(double responseTime);
        void setCompletionTime(double completionTime);
        void setRemainingTime(int remainingTime);
        void setStarted(bool started);

};

#endif