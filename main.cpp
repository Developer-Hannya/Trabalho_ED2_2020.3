#include <iostream>
#include <string>
#include <vector>
#include "CovidData.h"
#include "Sorts.h"
#include "DataReader.h"
#include <chrono>


using namespace std;

int main()
{
    vector<CovidData> data;
    vector<CovidData> extractedData;
    DataReader reader;
    Sorts sort;
    bool run = true;
    cout << "Trabalho de Estrutura de Dados II" << endl;

    while(run)
    {
        int option;
        string fileName;
        cout << "Menu:" << endl << "2 - MergeSort por Numero de Casos "<< "1 - Pré-processamento de Dados do Covid-19" << endl << "0 - Fechar execução" << endl;
        cout << "Digite uma das opções do menu para execução do programa: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Digite o nome e/ou caminho do do arquivo a ser lido: ";
            cin >> fileName;
            cout << "Lendo arquivo..." << endl;
            data = reader.readCovidDatafromFile(fileName);
            cout << "Pré-processando dados..." << endl;
            sort.preProcessCovidData(data);
            cout << "Exportando dados..." << endl;
            reader.exportPreProcessedCovidDataToFile(data);
            cout << "Dados pré-processados e exportado para brazil_covid19_cities_processado.csv dentro da pasta do projeto." << endl << endl;
            break;
        case 2:
            cout << "Digite o nome e/ou caminho do do arquivo a ser lido: ";
            cin >> fileName;
            cout << "Lendo arquivo..." << endl;
            data = reader.readCovidDatafromFile(fileName);
            cout << "Executando mergeSort..." << endl;
            sort.mergeSortBenchmark(data, extractedData);
            cout << "Exportando dados..." << endl;
            reader.exportExtractedCovidDataToFile(data, extractedData);
        default:
            cout << "Encerrando execução..." << endl;
            run = false;
            break;
        }
    }
    
    return 0;
}