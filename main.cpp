#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
#include <cstdlib>
#include "CovidData.h"
#include "Sorts.h"
#include "DataReader.h"

using namespace std;

int main()
{
    DataReader reader;
    Sorts sort;
    Benchmark *bench;
    bool run = true;
    cout << "Trabalho de Estrutura de Dados II" << endl;

    while(run)
    {
        vector<CovidData> data;
        vector<CovidData> benchmarkData;
        int option;
        string fileName;
        int viewOption;
        cout << "Menu:" << endl << "1 - Pré-processamento de Dados do Covid-19" << endl << "2 - Testar Merge Sort" << endl << "3 - Testar Quick Sort" << endl << "0 - Fechar execução" << endl;
        cout << "Digite uma das opções do menu para execução do programa: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Digite o nome e/ou caminho do arquivo a ser lido: ";
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
            cout << "1 - Saída em console" << endl << "2 - Saída em arquivo" << endl;
            cout << "Selecione o tipo de saída: ";
            cin >> viewOption;
            switch (viewOption)
            {
            case 1:
                cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                cin >> fileName;
                data = reader.readPreProcessedCovidDataFromFile(fileName);
                bench = new Benchmark(10,data.size());
                for(int i = 0;i < bench->getRandomDataIndex().size();i++)
                {
                    benchmarkData.push_back(data[bench->getRandomDataIndex()[i]]);
                }
                bench->setStartTimeAsNow();
                sort.benchmarkMergeSortCovidData(benchmarkData,0,benchmarkData.size(),bench);
                bench->setEndTimeAsNow();
                for(int i = 0; i < benchmarkData.size();i++)
                {
                    cout << benchmarkData[i].getDate() << "," << benchmarkData[i].getStateInitials() << "," << benchmarkData[i].getCityName() << "," << benchmarkData[i].getCityCode() << "," << benchmarkData[i].getCaseCount() << "," << benchmarkData[i].getDeathCount() << endl;
                }
                cout << "Número de comparações: " << bench->getCompNumber() << endl;
                cout << "Número de Movimentos: " << bench->getMovNumber() << endl;
                cout << "Tempo de execução: " << fixed << bench->getRuntime() << setprecision(9) << endl;
                delete bench;
                break;
            
            case 2:
                cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                cin >> fileName;
                data = reader.readPreProcessedCovidDataFromFile(fileName);
                bench = new Benchmark(100,data.size());
                for(int i = 0;i < bench->getRandomDataIndex().size();i++)
                {
                    benchmarkData.push_back(data[bench->getRandomDataIndex()[i]]);
                }
                bench->setStartTimeAsNow();
                sort.benchmarkMergeSortCovidData(benchmarkData,0,benchmarkData.size(),bench);
                bench->setEndTimeAsNow();
                reader.exportTestedDataToFile(benchmarkData);
                reader.exportBenchmarkDataToFile(bench);
                delete bench;
                break;
            
            default:
                cout << "Opção inválida!" << endl;
                break;
            }
            break;
        
        case 3:
            cout << "1 - Saída em console" << endl << "2 - Saída em arquivo" << endl;
            cout << "Selecione o tipo de saída: ";
            cin >> viewOption;
            switch (viewOption)
            {
            case 1:
                cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                cin >> fileName;
                data = reader.readPreProcessedCovidDataFromFile(fileName);
                bench = new Benchmark(10,data.size());
                for(int i = 0;i < bench->getRandomDataIndex().size();i++)
                {
                    benchmarkData.push_back(data[bench->getRandomDataIndex()[i]]);
                }
                bench->setStartTimeAsNow();
                sort.benchmarkQuickSortCovidData(benchmarkData,0,benchmarkData.size() - 1,bench);
                bench->setEndTimeAsNow();
                for(int i = 0; i < benchmarkData.size();i++)
                {
                    cout << benchmarkData[i].getDate() << "," << benchmarkData[i].getStateInitials() << "," << benchmarkData[i].getCityName() << "," << benchmarkData[i].getCityCode() << "," << benchmarkData[i].getCaseCount() << "," << benchmarkData[i].getDeathCount() << endl;
                }
                cout << "Número de comparações: " << bench->getCompNumber() << endl;
                cout << "Número de Movimentos: " << bench->getMovNumber() << endl;
                cout << "Tempo de execução: " << fixed << bench->getRuntime() << setprecision(9) << endl;
                delete bench;
                break;
            
            case 2:
                cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                cin >> fileName;
                data = reader.readPreProcessedCovidDataFromFile(fileName);
                bench = new Benchmark(100,data.size());
                for(int i = 0;i < bench->getRandomDataIndex().size();i++)
                {
                    benchmarkData.push_back(data[bench->getRandomDataIndex()[i]]);
                }
                bench->setStartTimeAsNow();
                sort.benchmarkQuickSortCovidData(benchmarkData,0,benchmarkData.size() - 1,bench);
                bench->setEndTimeAsNow();
                reader.exportTestedDataToFile(benchmarkData);
                reader.exportBenchmarkDataToFile(bench);
                delete bench;
                break;
            
            default:
                cout << "Opção inválida!" << endl;
                break;
            }
            break;

        default:
            cout << "Encerrando execução..." << endl;
            run = false;
            break;
        }
    }
    
    return 0;
}