#include "CovidData.h"
#include <iostream>
#include<sstream>
#include<fstream>

using namespace std;

CovidData::CovidData(string date,string stateInitials,string cityName,string cityCode,int caseCount,int deathCount)
{
    this->date = date;
    this->stateInitials = stateInitials;
    this->cityName = cityName;
    this->cityCode = cityCode;
    this->caseCount = caseCount;
    this->deathCount = deathCount;
}

CovidData::~CovidData(){}

string CovidData::getDate()
{
    return this->date;
}

string CovidData::getStateInitials()
{
    return this->stateInitials;
}

string CovidData::getCityName()
{
    return this->cityName;
}

string CovidData::getCityCode()
{
    return this->cityCode;
}

int CovidData::getCaseCount()
{
    return this->caseCount;
}

int CovidData::getDeathCount()
{
    return this->deathCount;
}
