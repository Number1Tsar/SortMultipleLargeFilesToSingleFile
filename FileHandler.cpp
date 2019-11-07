//
// Created by Sulav on 11/6/2019.
//
#include <fstream>
#include <string>
#include <vector>

/*
 * File Handler is a class that manages individual files.
 * Reads inputs line by line from file in chunks of size capacity, defined at construction.
 * */
class FileHandler
{
private:
    std::fstream fileHandle;
    int totalBufferCapacity;
    int iterator;
    int bufferSize;
    std::vector<std::string> buffer;

    /*  Loads next batch of lines from Disk to Memory */
    void loadDataFromDisk()
    {
        int i = 0;
        std::string line;
        for(;i<totalBufferCapacity && getline(fileHandle,line);i++) buffer[i] = line;
        bufferSize = i;
        iterator = 0;
    }

public:
        FileHandler(int capacity)
        {
            totalBufferCapacity = capacity;
            iterator = 0;
            bufferSize = 0;
            buffer.resize(capacity);
        }

        /*Finds and Opens file in read only mode*/
        void loadFile(std::string fileName)
        {
            fileHandle.open(fileName, std::fstream::in);
        }

        /*Checks if file has any more line left*/
        bool hasNext()
        {
            return (iterator < bufferSize || !fileHandle.eof());
        }

        /*Returns next line*/
        std::string next()
        {
            if(!hasNext()) return "";
            if(iterator >= bufferSize) loadDataFromDisk();
            return buffer[iterator++];
        }

        ~FileHandler()
        {
            fileHandle.close();
        }
};
