#ifndef COVIDDATA_H
#define COVIDDATA_H

#include <iostream>
#include <string>

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
    CovidData();
    ~CovidData();

    string getDate();
    string getStateInitials();
    string getCityName();
    string getCityCode();
    int getCaseCount();
    int getDeathCount();
    
    void setDate(string date);
    void setStateInitials(string stateInitials);
    void setCityName(string cityName);
    void setCityCode(string cityCode);
    void setCaseCount(int caseCount);
    void setDeathCount(int deathCount);

    void setData(string date,string stateInitials,string cityName,string cityCode,int caseCount,int deathCount);
};

#endif