# SortMultipleLargeFilesToSingleFile
An C++ implementation of merging large sorted input files to a single output file. An effort to practice Algorithm and System desing problem. Exceptions not handled.

FileMerger class takes file locations and outputs the sorted result into output file. Sample sorted input files are provided in the project directory. The program can be used to sort very large single file as well. First split the files into consumable pieces, sort them individually and then pass them to FileMerger.
