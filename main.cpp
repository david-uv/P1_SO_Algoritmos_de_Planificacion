#include <iostream>
#include <vector>

#include "Process.h"
#include "FileManager.h"
#include "MLQScheduler.h"

int main()
{
    FileManager fileManager;

    // read proccesses from the file
    std::vector<Process> processes = fileManager.readFile("mlq_David.txt");
    std::cout << "Procesos leidos: " << processes.size() << std::endl;

    MLQScheduler scheduler(processes);

    scheduler.initializeQueues();

    // executing MLQ algorithm
    scheduler.execute();

    // getting the results with the calculated metrics  
    std::vector<Process> results = scheduler.getProcesses();
std::cout << "Procesos en results: " << results.size() << std::endl;
    fileManager.writeFile("output.txt", results);

    std::cout << "Simulation finished successfully!" << std::endl;
    std::cout << "Results saved in output.txt" << std::endl;

    return 0;
}