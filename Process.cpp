#include "Process.h"

Process::Process(std::string idProcess,
                 int burstTime,
                 int arrivalTime,
                 int idQueue,
                 int priority)
{
    this->idProcess = idProcess;

    this->burstTime = burstTime;
    this->remainingTime = burstTime;

    this->arrivalTime = arrivalTime;
    this->idQueue = idQueue;
    this->priority = priority;

    started = false;

    waitingTime = 0;
    turnaroundTime = 0;
    responseTime = 0;
    completionTime = 0;
}


// getters
std::string Process::getIdProcess() const
{
    return idProcess;
}

int Process::getBurstTime() const
{
    return burstTime;
}

int Process::getArrivalTime() const
{
    return arrivalTime;
}

int Process::getRemainingTime() const
{
    return remainingTime;
}

int Process::getIdQueue() const
{
    return idQueue;
}

int Process::getPriority() const
{
    return priority;
}

double Process::getWaitingTime() const
{
    return waitingTime;
}

double Process::getTurnaroundTime() const
{
    return turnaroundTime;
}

double Process::getResponseTime() const
{
    return responseTime;
}

double Process::getCompletionTime() const
{
    return completionTime;
}

bool Process::getStarted() const
{
    return started;
}


//setters
void Process::setWaitingTime(double waitingTime)
{
    this->waitingTime = waitingTime;
}

void Process::setTurnaroundTime(double turnaroundTime)
{
    this->turnaroundTime = turnaroundTime;
}

void Process::setResponseTime(double responseTime)
{
    this->responseTime = responseTime;
}

void Process::setCompletionTime(double completionTime)
{
    this->completionTime = completionTime;
}

void Process::setRemainingTime(int remainingTime)
{
    this->remainingTime = remainingTime;
}

void Process::setStarted(bool started)
{
    this->started = started;
}

