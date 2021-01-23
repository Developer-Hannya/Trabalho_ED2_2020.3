#include "Benchmark.h"
#include "Sorts.h"
#include "DataReader.h"

Benchmark::Benchmark() {
 
  double time_taken = 0;
  double compNum = 0;
  double movNum = 0;

  double mediaRuntime = 0;
  double mediaComp = 0;
  double mediaMov = 0;
  
}

Benchmark::~Benchmark() {}

void Benchmark::exec() {
  vector<CovidData> data;
  vector<CovidData> extractedData;
  vector<double> runtime;
  DataReader reader;
  string fileName;

  cout << "Digite o nome e/ou caminho do do arquivo a ser lido: ";
  cin >> fileName;
  cout << "Lendo arquivo..." << endl;
  data = reader.readCovidDatafromFile(fileName);
  cout << "Executando benchmark..." << endl;

  mergeSortBenchmark(data, extractedData, 100, runtime);
  mergeSortBenchmark(data, extractedData, 500, runtime);
  mergeSortBenchmark(data, extractedData, 1000, runtime);

  calculaMedias(runtime);
  exportMetricsToTxt(runtime);
}

void Benchmark::exportExtractedCovidDataToFile(vector<CovidData> &data, vector<CovidData> &extractedData)
{
    ofstream outfile("brazil_covid19_cities_extracted.csv");
    for(int i = 0;i < extractedData.size();i++)
    {
        outfile << extractedData[i].getDate() << "," << extractedData[i].getStateInitials() << "," << extractedData[i].getCityName() << "," << extractedData[i].getCityCode() << "," << extractedData[i].getCaseCount() << "," << extractedData[i].getDeathCount() << endl;
    }
    outfile.close();
}

void Benchmark::mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData, int n, vector<double> &runtime)
{
   Sorts sort;
    // n = {10k, 50k, 100k, 500k, 1kk}
    extractedData = extractNfromFile(data, extractedData, n);

    auto start = chrono::high_resolution_clock::now();
    sort.mergeSort(extractedData, 0, extractedData.size() -1);
    auto end = chrono::high_resolution_clock::now();
    setTimeTaken((chrono::duration_cast<chrono::nanoseconds>(end - start).count())* 1e-9);
    cout << "O tempo de execução do MergeSort para N = " << extractedData.size() -1 << "é de: " << fixed
         << getTimeTaken() << setprecision(9);
    cout << " seg" << endl;
    exportExtractedCovidDataToFile(data, extractedData);
    runtime.push_back(getTimeTaken());
}

 vector<CovidData> Benchmark::extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n){
    int index; 
    for (int i =0; i < n; i++) {
        index = rand() % (data.size() + 1 - 0) + 0;
        extractedData.push_back( data[index]);
    }

    return extractedData;
 }

void Benchmark:: calculaMedias(vector<double> runtime) {
  double t;
  
  for (int i = 0; i < runtime.size(); i++) {
    t = runtime[i];
  }

  setMediaRuntime(t/runtime.size());

} 

void Benchmark::exportMetricsToTxt(vector<double> runtime) {
 
  ofstream outfile("saidas.txt");
  for (int i=0; i < runtime.size(); i++) {
    outfile << "Tempo exec nº " << i << ": " << runtime[i] << endl;
  }
  outfile << getMediaRuntime() << endl;

  outfile.close();

}

double Benchmark::getTimeTaken() {
  return this->time_taken;
}

void Benchmark::setTimeTaken(double time_taken) {
  this->time_taken = time_taken;
}

double Benchmark::getCompNum() {
    return this->compNum;
  }

void Benchmark::setCompNum(double compNum) {
    this->compNum = compNum;
  }

double Benchmark::getMovNum() {
   return this->movNum;
  }

void Benchmark::setMovNum(double movNum) {
  this->movNum = movNum;
}

double Benchmark::getMediaRuntime() {
  return this->mediaRuntime;
}

void Benchmark::setMediaRuntime(double mediaRuntime){
  this->mediaRuntime = mediaRuntime;
}

double Benchmark::getMediaComp(){
  return this->mediaComp;
}

void Benchmark::setMediaComp(double mediaComp){
  this->mediaComp = mediaComp;
}

double Benchmark::getMediaMov(){
  return this->mediaMov;
}
  
void Benchmark::setMediaMov(double mediaMov){
  this->mediaMov = mediaMov;
}