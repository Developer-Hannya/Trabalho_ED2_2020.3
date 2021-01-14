#ifndef COVIDDATA_H
#define COVIDDATA_H

#include <iostream>
#include<sstream>
#include<fstream>

using namespace std;

class CovidData
{
private:
    string date;
    string stateInitials;
    string cityName;
    string cityCode;
    int caseCount;
    int deathCount;

public:
    CovidData(string date,string stateInitials,string cityName,string cityCode,int caseCount,int deathCount);
    ~CovidData();

    string getDate();
    string getStateInitials();
    string getCityName();
    string getCityCode();
    int getCaseCount();
    int getDeathCount();
};

#endif