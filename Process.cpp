#include "Process.h"

Process::Process(std::string idProcess, int burstTime, int arrivalTime, int idQueue)
{
    this->idProcess = idProcess;
    this->burstTime = burstTime;
    this->arrivalTime = arrivalTime;
    this->idQueue = idQueue;
}

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