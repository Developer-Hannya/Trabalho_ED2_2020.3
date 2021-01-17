#ifndef DATAREADER_H
#define DATAREADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CovidData.h"

using namespace std;

class DataReader
{
private:
    
public:
    DataReader();
    ~DataReader();

    vector<CovidData> readCovidDatafromFile(string fileName);
    void exportPreProcessedCovidDataToFile(vector<CovidData> &data);
};

#endif