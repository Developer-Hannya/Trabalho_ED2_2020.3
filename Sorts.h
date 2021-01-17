#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include "CovidData.h"

class Sorts
{
private:
    void mergeSortCovidDatabyDate(vector<CovidData> &data,int init,int end);
    void auxMergeSortCovidDatabyDate(vector<CovidData> &data, int init,int mid, int end);

    void mergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int end);
    void auxMergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int mid,int end);

    void convertCumulativeToDiary(vector<CovidData> &data);

public:
    Sorts();
    ~Sorts();

    void preProcessCovidData(vector<CovidData> &data);
};

#endif