#include "MLQScheduler.h"
#include <algorithm>

void MLQScheduler::calculateMetrics(Process* process)
{
    process->setCompletionTime(currentTime);

    process->setTurnaroundTime(
        process->getCompletionTime() - process->getArrivalTime());

    process->setWaitingTime(
        process->getTurnaroundTime() - process->getBurstTime());
}


MLQScheduler::MLQScheduler(std::vector<Process> processes)
{
    this->processes = processes;
    this->currentTime = 0;

    averageWaitingTime = 0;
    averageTurnaroundTime = 0;
    averageResponseTime = 0;
    averageCompletionTime = 0;
}

void MLQScheduler::initializeQueues()
{
    for (Process& process : processes)
    {
        switch (process.getIdQueue())
        {
            case 1:
                queue1.push(&process);
                break;

            case 2:
                queue2.push(&process);
                break;

            case 3:
                queue3.push(&process);
                break;
        }
    }
}

void MLQScheduler::execute()
{
    runRoundRobin(queue1,1);

    runRoundRobin(queue2,3);

    runSJF(queue3);

    calculateAverages();
}

void MLQScheduler::runRoundRobin(std::queue<Process*>& queue, int quantum)
{
    while(!queue.empty())
    {
        Process* current = queue.front();
        queue.pop();

        if(!current->getStarted())
        {
            current->setResponseTime(
                currentTime - current->getArrivalTime());

            current->setStarted(true);
        }

        if(current->getRemainingTime() <= quantum)
        {
            currentTime += current->getRemainingTime();

            current->setRemainingTime(0);

            calculateMetrics(current);
        }
        else
        {
            current->setRemainingTime(
                current->getRemainingTime() - quantum);

            currentTime += quantum;

            queue.push(current);
        }
    }
}

void MLQScheduler::runSJF(std::queue<Process*>& queue)
{
    std::vector<Process*> temp;

    while(!queue.empty())
    {
        temp.push_back(queue.front());
        queue.pop();
    }

    std::sort(temp.begin(), temp.end(),
        [](Process* a, Process* b)
        {
            return a->getBurstTime() < b->getBurstTime();
        });

    for(Process* process : temp)
    {
        if(!process->getStarted())
        {
            process->setResponseTime(
                currentTime - process->getArrivalTime());

            process->setStarted(true);
        }

        currentTime += process->getRemainingTime();

        process->setRemainingTime(0);

        calculateMetrics(process);
    }
}

void MLQScheduler::calculateAverages()
{
    averageWaitingTime = 0;
    averageTurnaroundTime = 0;
    averageResponseTime = 0;
    averageCompletionTime = 0;

    for(Process& process : processes)
    {
        averageWaitingTime += process.getWaitingTime();
        averageTurnaroundTime += process.getTurnaroundTime();
        averageResponseTime += process.getResponseTime();
        averageCompletionTime += process.getCompletionTime();
    }

    int n = processes.size();

    if(n > 0)
    {
        averageWaitingTime /= n;
        averageTurnaroundTime /= n;
        averageResponseTime /= n;
        averageCompletionTime /= n;
    }
}

std::vector<Process> MLQScheduler::getProcesses()
{
    return processes;
}


double MLQScheduler::getAverageWaitingTime()
{
    return averageWaitingTime;
}

double MLQScheduler::getAverageTurnaroundTime()
{
    return averageTurnaroundTime;
}

double MLQScheduler::getAverageResponseTime()
{
    return averageResponseTime;
}

double MLQScheduler::getAverageCompletionTime()
{
    return averageCompletionTime;
}