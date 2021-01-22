#include <iostream>
#include <vector>
#include "CovidData.h"
#include <chrono>
#include <bits/stdc++.h> 
#include <cstdlib>
#include "Sorts.h"

class Benchmark {
  private: 

  public:

  void mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData, int n);

  vector<CovidData> extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n);

};
