#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>

using namespace std;

class DataFile
{
    const string FILE_NAME;
public:
    DataFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
};

#endif // DATAFILE_H
