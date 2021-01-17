#include "CovidData.h"

CovidData::CovidData()
{
    this->date = "";
    this->stateInitials = "";
    this->cityName = "";
    this->cityCode = "";
    this->caseCount = 0;
    this->deathCount = 0;
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

void CovidData::setDate(string date)
{
    this->date = date;
}

void CovidData::setStateInitials(string stateInitials)
{
    this->stateInitials = stateInitials;
}

void CovidData::setCityName(string cityName)
{
    this->cityName = cityName;
}

void CovidData::setCityCode(string cityCode)
{
    this->cityCode = cityCode;
}

void CovidData::setCaseCount(int caseCount)
{
    this->caseCount = caseCount;
}

void CovidData::setDeathCount(int deathCount)
{
    this->deathCount = deathCount;
}

void CovidData::setData(string date,string stateInitials,string cityName,string cityCode,int caseCount,int deathCount)
{
    this->date = date;
    this->stateInitials = stateInitials;
    this->cityName = cityName;
    this->cityCode = cityCode;
    this->caseCount = caseCount;
    this->deathCount = deathCount;   
}