#include <string>

class Process {


    private:
        //attributes of the processes
        std::string idProcess;
        int burstTime;
        int arrivalTime;
        int idQueue;
        int priority;

        //individual metrics
        double waitingTime;
        double turnaroundTime;
        double responseTime;
        double completionTime;

    public:
        //constructor
        Process(std::string idProcess, int burstTime, int arrivalTime, int idQueue);
        //setters
        void setWaitingTime(double waitingTime);
        void setTurnaroundTime(double turnaroundTime);
        void setResponseTime(double responseTime);
        void setCompletionTime(double completionTime);

        
};