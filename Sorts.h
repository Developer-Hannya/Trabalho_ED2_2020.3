#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include "CovidData.h"
#include <chrono>
#include <bits/stdc++.h> 
#include <cstdlib>

//Classe com as funções de ordenação de dados
class Sorts
{
private:
    /**
     * Ordenação primária do pré-processamento, um merge sort que ordena as datas 
     * em ordem decrescente
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int end
     * @return void
    */
    void mergeSortCovidDatabyDate(vector<CovidData> &data,int init,int end);
    /**
     * Função auxiliar do merge sort de datas do pré processamento
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int mid
     * @param int end
     * @return void
    */
    void auxMergeSortCovidDatabyDate(vector<CovidData> &data, int init,int mid, int end);

    /**
     * Ordenação secundária do pré-processamento, um merge sort que ordena os pares de estados e cidades 
     * em ordem alfabética, por consequência, inverte a ordem de datas, fazendo a ordenação final divida por 
     * pares de estados e cidades e cada par ordenado por data 
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int end
     * @return void
    */
    void mergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int end);
    /**
     * Função auxiliar do merge sort de pares de estado e cidade do pré processamento
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int mid
     * @param int end
     * @return void
    */
    void auxMergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int mid,int end);

    /**
     * Converte os dados do vector de casos/mortes cumulativas para totais diários, 
     * fazendo uma iteração em todos os dados e subtraindo os casos/mortes a partir do segundo dia 
     * com o cumulativo do dia anterior
     * 
     * @param vector<CovidData> data
     * @return void
    */
    void convertCumulativeToDiary(vector<CovidData> &data);

    /**
     * Função de intercalação para o algoritmo MergeSort
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int mid
     * @param int end
     * @return void
    */
   void merge (vector<CovidData> &data, int init, int mid, int end);

    /**
     * Função recursiva do algoritmo MergeSort pós-processamento, que ordena M vezes um conjunto de N linhas do arquivo 
     * brazil_covid19_cities_processado utilizando como chave de ordenação o numero de casos.
     * 
     * @param vector<CovidData> data
     * @param int init
     * @param int end
     * @return void
    */
   void mergeSort(vector<CovidData> &data, int init, int end);
    
    

public:
    /**
     * Construtor da Classe
     * 
    */
    Sorts();
    /**
     * Destrutor da Classe
     * 
    */
    ~Sorts();

    /**
     * Realiza o pré-processamento dos dados como pedido na Fase 1. Os dados são ordenados por pares (estado,cidade) e 
     * cada par é ordenado por data. Após isso os totais cumulativos (casos e mortes) são convertidos para totais diários.
     * 
     * @param vector<CovidData> data
     * @return void
    */
    void preProcessCovidData(vector<CovidData> &data);

    /**
     * Função que calcula o tempo de execução do mergeSort
     * @return auto
    */
   void mergeSortBenchmark(vector<CovidData> &data, vector<CovidData> &extractedData);
//
   vector<CovidData> extractNfromFile(vector<CovidData> &data, vector<CovidData> &extractedData, int n);
};

#endif