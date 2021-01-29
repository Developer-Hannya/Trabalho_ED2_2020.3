#include "Sorts.h"

Sorts::Sorts(){}

Sorts::~Sorts(){}

void Sorts::auxMergeSortCovidDatabyDate(vector<CovidData> &data, int init,int mid, int end)
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

void Sorts::mergeSortCovidDatabyDate(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        mergeSortCovidDatabyDate(data,init,mid);
        mergeSortCovidDatabyDate(data,mid,end);
        auxMergeSortCovidDatabyDate(data,init,mid,end);
    }
}

void Sorts::auxMergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int mid,int end)
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

void Sorts::mergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        mergeSortCovidDatabyCityStatePair(data,init,mid);
        mergeSortCovidDatabyCityStatePair(data,mid,end);
        auxMergeSortCovidDatabyCityStatePair(data,init,mid,end);
    }
}

void Sorts::convertCumulativeToDiary(vector<CovidData> &data)
{
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
}

void Sorts::preProcessCovidData(vector<CovidData> &data)
{
    mergeSortCovidDatabyDate(data,0,data.size() - 1);
    mergeSortCovidDatabyCityStatePair(data,0,data.size() - 1);
    convertCumulativeToDiary(data);
}

// aqui para baixo são as funções do Counting Sort

void countSort(vector<CovidData> &data){
    int ma = data[0].getCaseCount(), mi = data[0].getCaseCount();
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getCaseCount() > ma) {
            ma = data[i].getCaseCount();
        }
        if(data[i].getCaseCount() < mi) {
            ma = data[i].getCaseCount();
        }
    }

    int *cont = new int [ma - mi + 1];

    for(int i = 0; i < data[i].getCaseCount() + 1; i++) {
        cont[i] = 0;
    }

    for (int i = 0; i < data.size(); i++) {
        cont[data[i].getCaseCount()]++;
    }

    for(int i = 1; cont[i] < data[i].getCaseCount() + 1; i++) {
        cont[i] += cont[i - 1];
    }
    
    vector<CovidData> ordem(data.size());
    
    for(int i = data.size(); i >= 0; i--) {
        ordem[cont[data[i]] - 1] = data[i];
        cont[data[i]]--;
    }
    // Output data: 1, 1, 2, 2, 4, 5, 7
}