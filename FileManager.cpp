#include "FileManager.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Process> FileManager::readFile(const std::string& fileName)
{
    std::vector<Process> processes;

    std::ifstream file(fileName);

    if(!file.is_open())
    {
        std::cout << "Error opening file.\n";
        return processes;
    }

    std::string line;

    while(std::getline(file,line))
    {
        // Ignorar comentarios y líneas vacías
        if(line.empty() || line[0]=='#')
            continue;

        std::stringstream ss(line);

        std::string id;
        std::string temp;

        int bt;
        int at;
        int queue;
        int priority;

        std::getline(ss,id,';');

        std::getline(ss,temp,';');
        bt = std::stoi(temp);

        std::getline(ss,temp,';');
        at = std::stoi(temp);

        std::getline(ss,temp,';');
        queue = std::stoi(temp);

        std::getline(ss,temp,';');
        priority = std::stoi(temp);

        Process process(id,bt,at,queue,priority);

        processes.push_back(process);
    }

    file.close();

    return processes;
}

void FileManager::writeFile(const std::string& fileName,
                            const std::vector<Process>& processes)
{
    std::ofstream file(fileName);

    if(!file.is_open())
    {
        std::cout << "Error creating file.\n";
        return;
    }

    file << "ID\tBT\tAT\tQ\tPriority\tWT\tTAT\tRT\tCT\n";

    for(const Process& p : processes)
    {
        file << p.getIdProcess() << "\t"
             << p.getBurstTime() << "\t"
             << p.getArrivalTime() << "\t"
             << p.getIdQueue() << "\t"
             << p.getPriority() << "\t"
             << p.getWaitingTime() << "\t"
             << p.getTurnaroundTime() << "\t"
             << p.getResponseTime() << "\t"
             << p.getCompletionTime()
             << "\n";
    }

    file.close();
}