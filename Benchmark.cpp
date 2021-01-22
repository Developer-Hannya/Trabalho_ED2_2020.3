#include "Benchmark.h"
#include "Sorts.h"

void Benchmark::mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData, int n)
{
  Sorts sort;
    // n = {10k, 50k, 100k, 500k, 1kk}
    extractedData = extractNfromFile(data, extractedData, n);
    auto start = chrono::high_resolution_clock::now();
    sort.mergeSort(extractedData, 0, extractedData.size() -1);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "O tempo de execução do MergeSort para N = " << extractedData.size() -1 << "é de: " << fixed
         << time_taken << setprecision(9);
    cout << " seg" << endl;
}

 vector<CovidData> Benchmark::extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n){
    int index; 
    for (int i =0; i < n; i++) {
        index = rand() % (data.size() + 1 - 0) + 0;
        extractedData.push_back( data[index]);
    }

    return extractedData;
 }