#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

//Classe que armazena os dados individuais de cada execução do benchmark
class Benchmark
{
private:
    //Armazena o número de comparações
    int compNumber;
    //Armazena o número de movimentações de chaves
    int movNumber;
    //Armazena o ponto de partida do algoritmo de ordenação
    chrono::time_point<chrono::high_resolution_clock> startTime;
    //Armazena o ponto de término do algoritmo de ordenação
    chrono::time_point<chrono::high_resolution_clock> endTime;
    //Armazena o tempo de execução do algoritmo
    double runtime;
    //Vector que armazena as chaves geradas para os testes
    vector<int> randomDataIndex;

public:
    /**
     * Construtor da classe, possui dois parâmetros, números dados aleatórios a serem selecionados (n) e 
     * o alcance de chaves a ser escolhida (dataSize)
     * 
     * @param int n
     * @param int dataSize
    */
    Benchmark(int n, int dataSize);
    /**
     * Destrutor da Classe
     * 
    */
    ~Benchmark();

    /**
     * Retorna o número de comparações
     * 
     * @return int
    */
    int getCompNumber();
    /**
     * Retorna o número de movimentações de chaves
     * 
     * @return int
    */
    int getMovNumber();
    /**
     * Retorna o ponto de partida do algoritmo
     * 
     * @return chrono::time_point<chrono::high_resolution_clock>
    */
    chrono::time_point<chrono::high_resolution_clock> getStartTime();
    /**
     * Retorna o ponto de término do algoritmo
     * 
     * @return chrono::time_point<chrono::high_resolution_clock>
    */
    chrono::time_point<chrono::high_resolution_clock> getEndTime();
    /**
     * Retorna o tempo de execução do algoritmo
     * 
     * @return double
    */
    double getRuntime();
    /**
     * Retorna o vector de chaves aleatórias
     * 
     * @return vector<int>
    */
    vector<int> getRandomDataIndex();

    /**
     * Define/Redefine o número de comparações
     * 
     * @param int compNumber
     * @return void
    */
    void setCompNumber(int compNumber);
    /**
     * Define/Redefine o número de movimentações de chaves
     * 
     * @param int movNumber
     * @return void
    */
    void setMovNumber(int movNumber);
    /**
     * Define/Redefine o ponto de partida do algoritmo
     * 
     * @param chrono::time_point<chrono::high_resolution_clock> startTime
     * @return void
    */
    void setStartTime(chrono::time_point<chrono::high_resolution_clock> startTime);
    /**
     * Define/Redefine o ponto de término do algoritmo
     * 
     * @param chrono::time_point<chrono::high_resolution_clock> endTime
     * @return void
    */
    void setEndTime(chrono::time_point<chrono::high_resolution_clock> endTime);
    /**
     * Define/Redefine o tempo de execução
     * 
     * @param double runtime
     * @return void
    */
    void setRuntime(double runtime);
    /**
     * Define/Redefine o vector de chaves aleatórias
     * 
     * @param vectot<int> randomDataIndex
     * @return void
    */
    void setRandomDataIndex(vector<int> randomDataIndex);

    /**
     * Incrementa em 1 o número de comparações
     * 
     * @return void
    */
    void incrementCompNumber();
    /**
     * Incrementa em 1 o número de movimentações de chaves
     * 
     * @return void
    */
    void incrementMovNumber();
    /**
     * Define ponto de partida do algoritmo para o momento em que esta função é chamada
     * 
     * @return void
    */
    void setStartTimeAsNow();
    /**
     * Define ponto de término do algoritmo para o momento em que esta função é chamada
     * 
     * @return void
    */
    void setEndTimeAsNow();
    /**
     * Gera o tempo de execução realizando a diferença do ponto partida e o ponto de término
     * 
     * @return void
    */
    void generateRuntime();
};

#endif