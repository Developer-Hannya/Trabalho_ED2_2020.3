#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Benchmark
{
private:
    int compNumber;
    int movNumber;
    chrono::time_point<chrono::high_resolution_clock> startTime;
    chrono::time_point<chrono::high_resolution_clock> endTime;
    double runtime;
    vector<int> randomDataIndex;

public:
    Benchmark(int n, int dataSize);
    ~Benchmark();

    int getCompNumber();
    int getMovNumber();
    chrono::time_point<chrono::high_resolution_clock> getStartTime();
    chrono::time_point<chrono::high_resolution_clock> getEndTime();
    double getRuntime();
    vector<int> getRandomDataIndex();

    void setCompNumber(int compNumber);
    void setMovNumber(int movNumber);
    void setStartTime(chrono::time_point<chrono::high_resolution_clock> startTime);
    void setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime);
    void setRuntime(double runtime);
    void setRandomDataIndex(vector<int> randomDataIndex);

    void incrementCompNumber();
    void incrementMovNumber();
    void setStartTimeAsNow();
    void setEndTimeAsNow();
    void generateRuntime();
};

#endif