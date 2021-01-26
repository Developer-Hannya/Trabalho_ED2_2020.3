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

void Sorts::auxBenchmarkMergeSortCovidData(vector<CovidData> &data, int init, int mid, int end, Benchmark *bench)
{
    int i = init;
    int j = mid;
    vector<CovidData> aux;

    while(i < mid && j < end)
    {
        if(data[i].getCaseCount() < data[j].getCaseCount())
        {
            aux.push_back(data[i]);
            i++;
        }
        else
        {
            aux.push_back(data[j]);
            j++;
            bench->incrementMovNumber();
        }
        bench->incrementCompNumber();
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

void Sorts::benchmarkMergeSortCovidData(vector<CovidData> &data, int init, int end, Benchmark *bench)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        benchmarkMergeSortCovidData(data,init,mid,bench);
        benchmarkMergeSortCovidData(data,mid,end,bench);
        auxBenchmarkMergeSortCovidData(data,init,mid,end,bench);
    }
}