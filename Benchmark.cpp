#include "Benchmark.h"

Benchmark::Benchmark(int n, int dataSize)
{
    this->compNumber = 0;
    this->movNumber = 0;
    this->runtime = 0;
    for(int i = 0;i < n;i++)
    {
        this->randomDataIndex.push_back(rand() % dataSize);   
    }
}

Benchmark::~Benchmark(){}

int Benchmark::getCompNumber()
{
    return this->compNumber;
}

int Benchmark::getMovNumber()
{
    return this->movNumber;
}

chrono::time_point<chrono::high_resolution_clock> Benchmark::getStartTime()
{
    return this->startTime;
}

chrono::time_point<chrono::high_resolution_clock> Benchmark::getEndTime()
{
    return this->endTime;
}

double Benchmark::getRuntime()
{
    return this->runtime;
}

vector<int> Benchmark::getRandomDataIndex()
{
    return this->randomDataIndex;
}

void Benchmark::setCompNumber(int compNumber)
{
    this->compNumber = compNumber;
}

void Benchmark::setMovNumber(int movNumber)
{
    this->movNumber = movNumber;
}

void Benchmark::setStartTime(chrono::time_point<chrono::high_resolution_clock> startTime)
{
    this->startTime = startTime;
}

void Benchmark::setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime)
{
    this->endTime = endTime;
}

void Benchmark::setRuntime(double runtime)
{
    this->runtime = runtime;
}

void Benchmark::setRandomDataIndex(vector<int> randomDataIndex)
{
    this->randomDataIndex = randomDataIndex;
}

void Benchmark::incrementCompNumber()
{
    this->compNumber++;
}

void Benchmark::incrementMovNumber()
{
    this->movNumber++;
}

void Benchmark::setStartTimeAsNow()
{
    this->startTime = chrono::high_resolution_clock::now();
}

void Benchmark::setEndTimeAsNow()
{
    this->endTime = chrono::high_resolution_clock::now();
}

void Benchmark::generateRuntime()
{
    this->runtime = chrono::duration_cast<chrono::nanoseconds>(this->endTime - this->startTime).count()*1e-9;
}