#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Process.h"

class FileManager
{
public:

    std::vector<Process> readFile(const std::string& fileName);

    void writeFile(const std::string& fileName,
                   const std::vector<Process>& processes);

};

#endif