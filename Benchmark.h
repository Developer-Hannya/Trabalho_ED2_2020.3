#include <iostream>
#include <vector>
#include "CovidData.h"
#include <chrono>
#include <bits/stdc++.h> 
#include <cstdlib>
#include "Sorts.h"

class Benchmark {
  private: 

  double mediaRuntime;
  double mediaComp;
  double mediaMov;
  double time_taken;

// Extrai N linhas randomicas do arquivo processado
  vector<CovidData> extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n);

  public:
// Calcula runtime de um mergesort em um conjunto de tamanho N 
  void mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData, int n);
  
  double getMediaRuntime();

  void setMediaRuntime(double mediaRuntime);

  double getMediaComp();

  void setMediaComp(double mediaComp);

  double getMediaMov();
  
  void setMediaMov(double mediaMov);

  double getTimeTaken();

  void setTimeTaken(double time_taken);

   /**
     * Construtor da Classe
     * 
    */
    Benchmark();
    /**
     * Destrutor da Classe
     * 
    */
    ~Benchmark();


};
