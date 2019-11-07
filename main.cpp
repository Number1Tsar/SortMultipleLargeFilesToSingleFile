#include <iostream>
#include <vector>
#include "FileMerger.cpp"

using namespace std;

/*
 * This is a driver program to simulate sorting large sorted files into a single file.
 * The FileMerger class takes a list of sorted files and generated the combined sorted list in the output file.
 * Designed in C++ 11
 */
int main()
{
    FileMerger* merger = new FileMerger();
    vector<string> files = {"C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\TestFiles\\File1.txt",
                            "C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\TestFiles\\File2.txt",
                            "C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\TestFiles\\File3.txt",
                            "C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\TestFiles\\File4.txt",
                            "C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\TestFiles\\File5.txt"};
    merger->loadFiles(files);
    merger->setOutputFileName("C:\\Users\\Sulav\\ClionProjects\\SortLargeFiles\\Outputs\\SortedOutput.txt");
    cout<<"Sorting files"<<endl;
    merger->generateSortedFile();
    cout<<"Sorting ended"<<endl;
    return 0;

}