#ifndef COVIDDATA_H
#define COVIDDATA_H

#include <iostream>
#include <string>

using namespace std;

//Classe que armazena os dados de cada linha do arquivo do Covid-19
class CovidData
{
private:
    //Data de ocorrência do relatório
    string date;
    //Iniciais do Estado
    string stateInitials;
    //Nome da Cidade
    string cityName;
    //Código da Cidade
    string cityCode;
    //Número de casos
    int caseCount;
    //Número de Óbitos
    int deathCount;

public:
    /**
     * Construtor da Classe
     * 
    */
    CovidData();
    /**
     * Destrutor da Classe
     * 
    */
    ~CovidData();

    /**
     * Retorna a data de ocorrência do relatório
     * 
     * @return string
    */
    string getDate();
    /**
     * Retorna as iniciais do estado
     * 
     * @return string
    */
    string getStateInitials();
    /**
     * Retorna o nome da cidade
     * 
     * @return string
    */
    string getCityName();
    /**
     * Retorna o código da cidade
     * 
     * @return string
    */
    string getCityCode();
    /**
     * Retorna o número de casos
     * 
     * @return int
    */
    int getCaseCount();
    /**
     * Retorna o número de óbitos
     * 
     * @return string
    */
    int getDeathCount();
    
    /**
     * Define/Redefine a data de ocorrência do relatório
     * 
     * @param string date
     * @return void
    */
    void setDate(string date);
    /**
     * Define/Redefine as iniciais do estado
     * 
     * @param string stateInitials
     * @return void
    */
    void setStateInitials(string stateInitials);
    /**
     * Define/Redefine o nome da cidade
     * 
     * @param string cityName
     * @return void
    */
    void setCityName(string cityName);
    /**
     * Define/Redefine o código da cidade
     * 
     * @param string cityCode
     * @return void
    */
    void setCityCode(string cityCode);
    /**
     * Define/Redefine o número de casos
     * 
     * @param int caseCount
     * @return void
    */
    void setCaseCount(int caseCount);
    /**
     * Define/Redefine o número de óbitos
     * 
     * @param int deathCount
     * @return void
    */
    void setDeathCount(int deathCount);

    /**
     * Define/Redefine todo o conjunto de dados de uma vez só
     * 
     * @param string date
     * @param string stateInitials
     * @param string cityName
     * @param string cityCode
     * @param int caseCount
     * @param int deathCount
     * @return void
    */
    void setData(string date,string stateInitials,string cityName,string cityCode,int caseCount,int deathCount);
};

#endif