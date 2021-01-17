#ifndef DATAREADER_H
#define DATAREADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CovidData.h"

using namespace std;

//Classe com as funções de leitura e exportação de dados em arquivos
class DataReader
{
private:
    
public:
    /**
     * Construtor da Classe
     * 
    */
    DataReader();
    /**
     * Destrutor da Classe
     * 
    */
    ~DataReader();

    /**
     * Retorna um vector com os dados lidos de cada linha do arquivo do Covid-19, a função lê o arquivo ignorando a primeira linha 
     * (que representa somente a legenda das linhas) e ignora as linhas vazias do arquivo.
     * 
     * @param string fileName
     * @return vector<CovidData>
    */
    vector<CovidData> readCovidDatafromFile(string fileName);
    /**
     * Exporta os dados armazenados no vector do Covid-19 para o arquivo "brazil_covid19_cities_processado.csv"
     * 
     * @param vector<CodvidData> data
     * @return void
    */
    void exportPreProcessedCovidDataToFile(vector<CovidData> &data);
};

#endif