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
  vector<double> runtime;
  vector<double> comp;
  vector<double> mov;


// Extrai N linhas randomicas do arquivo processado
  vector<CovidData> extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n);

  void calculaMedias(vector<double> runtime);
  
  void exportExtractedCovidDataToFile(vector<CovidData> &data, vector<CovidData> &extractedData);

  void exportMetricsToTxt(vector<double> runtime); 

  void mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData, int n, vector<double> &runtime);
 
  public:
// Calcula runtime de um mergesort em um conjunto de tamanho N 
  void exec();

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
