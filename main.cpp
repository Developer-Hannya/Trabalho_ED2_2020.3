#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CovidData.h"

using namespace std;

vector<CovidData> readCovidDatafromFile(string fileName)
{
    ifstream file;
    string line;
    vector<CovidData> data;
    
    file.open(fileName);
    getline(file,line);

    if(file.is_open())
    {
        while(getline(file,line))
        {
            if(line == "")
            {
                continue;
            }
            else
            {
                istringstream dataFromLine(line);
                string date,stateInitials,cityName,cityCode,caseCount,deathCount;
                getline(dataFromLine,date,',');
                getline(dataFromLine,stateInitials,',');
                getline(dataFromLine,cityName,',');
                getline(dataFromLine,cityCode,',');
                getline(dataFromLine,caseCount,',');
                getline(dataFromLine,deathCount,',');
                CovidData element;
                element.setData(date,stateInitials,cityName,cityCode,atoi(caseCount.c_str()),atoi(deathCount.c_str()));
                data.push_back(element);    
            }
        }
        file.close();
    }
    else
    {
        cout << "Arquivo não aberto, retornando vector vazio!" << endl;
    }

    return data;
}

void mergeDate(vector<CovidData> &data,int init,int mid,int end)
{
    int i = init;
    int j = mid;
    vector<CovidData> aux;

    while(i < mid && j < end)
    {
        if(data[i].getDate() > data[j].getDate())
        {
            aux.push_back(data[i]);
            i++;
        }
        else
        {
            aux.push_back(data[j]);
            j++;
        }
    }

    while (i < mid)
    {
        aux.push_back(data[i]);
        i++;
    }
    while (j < end)
    {
        aux.push_back(data[j]);
        j++;
    }
    
    for(int k = init; k < end;k++)
    {
        data[k] = aux[k - init];
    }
}

void sortCovidDataByDate(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        sortCovidDataByDate(data,init,mid);
        sortCovidDataByDate(data,mid,end);
        mergeDate(data,init,mid,end);
    }
}

void mergeStateCityPair(vector<CovidData> &data,int init,int mid,int end)
{
    int i = init;
    int j = mid;
    vector<CovidData> aux;

    while(i < mid && j < end)
    {
        if(data[i].getStateInitials() + data[i].getCityName() < data[j].getStateInitials() + data[j].getCityName())
        {
            aux.push_back(data[i]);
            i++;
        }
        else
        {
            aux.push_back(data[j]);
            j++;
        }
    }

    while (i < mid)
    {
        aux.push_back(data[i]);
        i++;
    }
    while (j < end)
    {
        aux.push_back(data[j]);
        j++;
    }
    
    for(int k = init; k < end;k++)
    {
        data[k] = aux[k - init];
    }
}

void sortCovidDataByStateCityPair(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        sortCovidDataByStateCityPair(data,init,mid);
        sortCovidDataByStateCityPair(data,mid,end);
        mergeStateCityPair(data,init,mid,end);
    }
}

int main()
{
    vector<CovidData> data = readCovidDatafromFile("brazil_covid19_cities.csv");
    sortCovidDataByDate(data,0,data.size() - 1);
    sortCovidDataByStateCityPair(data,0,data.size() - 1);
    
    int previousCaseCount = data[0].getCaseCount();
    int previousDeathCount = data[0].getDeathCount();
    for(int i = 1;i < data.size();i++)
    {
        int auxCase = previousCaseCount;
        int auxDeath = previousDeathCount;
        previousCaseCount = data[i].getCaseCount();
        previousDeathCount = data[i].getDeathCount();

        if(data[i - 1].getCityCode() == data[i].getCityCode())
        {
            data[i].setCaseCount(data[i].getCaseCount() - auxCase);
            data[i].setDeathCount(data[i].getDeathCount() - auxDeath);
        }
        else
        {
            continue;
        }   
    }

    ofstream outfile("brazil_covid19_cities_processado.csv");
    for(int i = 0;i < data.size();i++)
    {
        outfile << data[i].getDate() << "," << data[i].getStateInitials() << "," << data[i].getCityName() << "," << data[i].getCityCode() << "," << data[i].getCaseCount() << "," << data[i].getDeathCount() << endl;
    }
    outfile.close();

    return 0;
}