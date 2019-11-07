//
// Created by Sulav on 11/6/2019.
//

#include <string>
#include <vector>
#include <queue>
#include "FileHandler.cpp"

using namespace std;

class FileMerger
{
private:

    /*Comparator for constructing min-heap*/
    struct Comp
    {
        bool operator()(const pair<string,int>& first, const pair<string,int>& second)
        {
            int numFirst = stoi(first.first);
            int numSecond = stoi(second.first);
            return numFirst > numSecond;
        }
    };

    static const int CHUNK_SIZE = 500; /* Loads 500 lines of input from File in a batch*/
    int numberOfFiles;
    vector<FileHandler*> fileHandles;
    std::string outputFileName;
    priority_queue<pair<string,int>,vector<pair<string,int>>, Comp> queue;

public:

    FileMerger()
    {
        numberOfFiles = 0;
        outputFileName = "DefaultOut.txt";
    }

    /*Read the list of files to merge in sorted order*/
    void loadFiles(vector<string> fileNames)
    {
        numberOfFiles = fileNames.size();
        for(string file : fileNames)
        {
            FileHandler* handler = new FileHandler(CHUNK_SIZE);
            handler->loadFile(file);
            fileHandles.push_back(handler);
        }
    }

    void setOutputFileName(string fileName)
    {
        outputFileName = fileName;
    }

    void generateSortedFile()
    {
        fstream outputFile(outputFileName,fstream::out);
        for(int i=0;i<numberOfFiles;i++)
        {
            if(fileHandles[i]->hasNext())
            {
                queue.push(make_pair(fileHandles[i]->next(), i));
            }
        }
        while(!queue.empty())
        {
            auto lineHandlePair = queue.top();queue.pop();
            outputFile<<lineHandlePair.first<<endl;
            if(fileHandles[lineHandlePair.second]->hasNext())
            {
                queue.push(make_pair(fileHandles[lineHandlePair.second]->next(), lineHandlePair.second));
            }
        }
        outputFile.close();
    }

    ~FileMerger()
    {
        for(int i=0;i<numberOfFiles;i++)
        {
            delete fileHandles[i];
        }
    }
};