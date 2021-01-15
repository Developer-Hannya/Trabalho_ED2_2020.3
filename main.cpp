#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "CovidData.h"

using namespace std;

int main()
{
    ifstream file;
    file.open("brazil_covid19_cities.csv");
    string str;
    CovidData *data = new CovidData [1431490];
    getline(file,str);
    int i = 0;
    while(i < 1431490)
    {
        string date,stateInitials,cityName,cityCode,caseCount,deathCount;
        getline(file,date,',');
        getline(file,stateInitials,',');
        getline(file,cityName,',');
        getline(file,cityCode,',');
        getline(file,caseCount,',');
        getline(file,deathCount);
        data[i].setData(date,stateInitials,cityName,cityCode,atoi(caseCount.c_str()),atoi(deathCount.c_str()));
        i++;
    }
    delete [] data;
    return 0;
}