#ifndef MLQSCHEDULER_H
#define MLQSCHEDULER_H

#include <queue>
#include <vector>
#include "Process.h"

class MLQScheduler{
private:

    std::vector<Process> processes;

    std::queue<Process*> queue1;
    std::queue<Process*> queue2;
    std::queue<Process*> queue3;

    int currentTime;

    double averageWaitingTime;
    double averageTurnaroundTime;
    double averageResponseTime;
    double averageCompletionTime;

    void calculateMetrics(Process* process);


public:

    MLQScheduler(std::vector<Process> processes);

    void initializeQueues();

    void execute();

    void runRoundRobin(std::queue<Process*>& queue, int quantum);

    void runSJF(std::queue<Process*>& queue);

    void calculateAverages();

    std::vector<Process> getProcesses();
};

#endif