#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "CovidData.h"
#include "Sorts.h"
#include "DataReader.h"

using namespace std;

void execMergeSortBenchmark(int nData) {
    DataReader reader;
    int comps[5];
    int movs[5];
    double runtimes[5];
    Sorts sort;
    vector<CovidData> data;

    ofstream intro("saidas.txt",ios::app);
    intro << "Merge Sort - N: " << nData << endl;
    intro << "Comparações,Movimentos,Tempo de execução" << endl;
    data = reader.readPreProcessedCovidDataFromFile("brazil_covid19_cities_processado.csv");
    intro.close();

    for(int i = 0; i < 5; i++)
    {
        srand(i);
        Benchmark *bench = new Benchmark(nData,data.size());
        vector<CovidData> benchData(nData);
        for(int j = 0; j < bench->getRandomIndexVectorSize();j++)
        {
            benchData[j] = data[bench->getRandomIndexFromVector(j)];
        }
        cout << "Executando Merge Sort " << "N: " << nData << " M: " << i + 1 << endl;
        bench->setStartTimeAsNow();
        sort.benchmarkMergeSortCovidData(benchData,0,benchData.size(),bench);
        bench->setEndTimeAsNow();
        cout << "Fim" << endl;
        bench->generateRuntime();
        reader.exportBenchmarkDataToFile(bench);

        comps[i] = bench->getCompNumber();
        movs[i] = bench->getMovNumber();
        runtimes[i] = bench->getRuntime();
        delete bench;
    }
    float compMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/5;
    float movMedia = (movs[0] + movs[1] + movs[2] + movs[3] + movs[4])/5;
    double runMedia = (runtimes[0] + runtimes[1] + runtimes[2] + runtimes[3] + runtimes[4])/5;
    ofstream endline("saidas.txt",ios::app);
    endline << "Médias: " << fixed << setprecision(2) << compMedia << "," << movMedia << "," << runMedia << endl << endl;
    endline.close();
}

void execQuickSortBenchmark(int nData) {
    DataReader reader;
    int comps[5];
    int movs[5];
    double runtimes[5];
    Sorts sort;
    vector<CovidData> data;

    ofstream intro("saidas.txt",ios::app);
    intro << "Quick Sort - N: " << nData << endl;
    intro << "Comparações,Movimentos,Tempo de execução" << endl;
    data = reader.readPreProcessedCovidDataFromFile("brazil_covid19_cities_processado.csv");
    intro.close();

    for(int i = 0; i < 5; i++)
    {
        srand(i);
        Benchmark *bench = new Benchmark(nData,data.size());
        vector<CovidData> benchData(nData);
        for(int j = 0; j < bench->getRandomIndexVectorSize();j++)
        {
            benchData[j] = data[bench->getRandomIndexFromVector(j)];
        }
        cout << "Executando Quick Sort " << "N: " << nData << " M: " << i + 1 << endl;
        bench->setStartTimeAsNow();
        sort.benchmarkQuickSortCovidData(benchData,0,benchData.size(),bench);
        bench->setEndTimeAsNow();
        cout << "Fim" << endl;
        bench->generateRuntime();
        reader.exportBenchmarkDataToFile(bench);

        comps[i] = bench->getCompNumber();
        movs[i] = bench->getMovNumber();
        runtimes[i] = bench->getRuntime();
        delete bench;
    }
    float compMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/5;
    float movMedia = (movs[0] + movs[1] + movs[2] + movs[3] + movs[4])/5;
    double runMedia = (runtimes[0] + runtimes[1] + runtimes[2] + runtimes[3] + runtimes[4])/5;
    ofstream endline("saidas.txt",ios::app);
    endline << "Médias: " << fixed << setprecision(2) << compMedia << "," << movMedia << "," << runMedia << endl << endl;
    endline.close();
}

void execCountingSortBenchmark(int nData) {
    DataReader reader;
    int comps[5];
    int movs[5];
    double runtimes[5];
    Sorts sort;
    vector<CovidData> data;

    ofstream intro("saidas.txt",ios::app);
    intro << "Counting Sort - N: " << nData << endl;
    intro << "Comparações,Movimentos,Tempo de execução" << endl;
    data = reader.readPreProcessedCovidDataFromFile("brazil_covid19_cities_processado.csv");
    intro.close();

    for(int i = 0; i < 5; i++)
    {
        srand(i);
        Benchmark *bench = new Benchmark(nData,data.size());
        vector<CovidData> benchData(nData);
        for(int j = 0; j < bench->getRandomIndexVectorSize();j++)
        {
            benchData[j] = data[bench->getRandomIndexFromVector(j)];
        }
        cout << "Executando Counting Sort " << "N: " << nData << " M: " << i + 1 << endl;
        bench->setStartTimeAsNow();
        sort.benchmarkCountingSortCovidData(benchData,bench);
        bench->setEndTimeAsNow();
        cout << "Fim" << endl;
        bench->generateRuntime();
        reader.exportBenchmarkDataToFile(bench);

        comps[i] = bench->getCompNumber();
        movs[i] = bench->getMovNumber();
        runtimes[i] = bench->getRuntime();
        delete bench;
    }
    float compMedia = (comps[0] + comps[1] + comps[2] + comps[3] + comps[4])/5;
    float movMedia = (movs[0] + movs[1] + movs[2] + movs[3] + movs[4])/5;
    double runMedia = (runtimes[0] + runtimes[1] + runtimes[2] + runtimes[3] + runtimes[4])/5;
    ofstream endline("saidas.txt",ios::app);
    endline << "Médias: " << fixed << setprecision(2) << compMedia << "," << movMedia << "," << runMedia << endl << endl;
    endline.close();
}

int main(int argc,char const *argv[])
{
    if(argc != 2)
    {
        cout << "ERRO: Esperando seguintes parâmetros: ./<nome do executável> <modo de execução>" << endl;
        cout << "0 - Modo de testes" << endl << "1 - Modo de Benchmark" << endl;
        return 0;
    }

    if(atoi(argv[1]) == 0)
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
            cout << "Menu:" << endl << "1 - Pré-processamento de Dados do Covid-19" << endl << "2 - Testar Merge Sort" << endl << "3 - Testar Quick Sort" << endl << "4 - Testar Counting Sort" << endl << "0 - Fechar execução" << endl;
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
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkMergeSortCovidData(benchmarkData,0,benchmarkData.size(),bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
                    for(int i = 0; i < benchmarkData.size();i++)
                    {
                        cout << benchmarkData[i].getDate() << "," << benchmarkData[i].getStateInitials() << "," << benchmarkData[i].getCityName() << "," << benchmarkData[i].getCityCode() << "," << benchmarkData[i].getCaseCount() << "," << benchmarkData[i].getDeathCount() << endl;
                    }
                    cout << "Número de comparações: " << bench->getCompNumber() << endl;
                    cout << "Número de Movimentos: " << bench->getMovNumber() << endl;
                    cout << "Tempo de execução: " << bench->getRuntime() << endl;
                    delete bench;
                    break;
                
                case 2:
                    cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                    cin >> fileName;
                    data = reader.readPreProcessedCovidDataFromFile(fileName);
                    bench = new Benchmark(100,data.size());
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkMergeSortCovidData(benchmarkData,0,benchmarkData.size(),bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
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
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkQuickSortCovidData(benchmarkData,0,benchmarkData.size() - 1,bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
                    for(int i = 0; i < benchmarkData.size();i++)
                    {
                        cout << benchmarkData[i].getDate() << "," << benchmarkData[i].getStateInitials() << "," << benchmarkData[i].getCityName() << "," << benchmarkData[i].getCityCode() << "," << benchmarkData[i].getCaseCount() << "," << benchmarkData[i].getDeathCount() << endl;
                    }
                    cout << "Número de comparações: " << bench->getCompNumber() << endl;
                    cout << "Número de Movimentos: " << bench->getMovNumber() << endl;
                    cout << "Tempo de execução: " << bench->getRuntime() << endl;
                    delete bench;
                    break;
                
                case 2:
                    cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                    cin >> fileName;
                    data = reader.readPreProcessedCovidDataFromFile(fileName);
                    bench = new Benchmark(100,data.size());
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkQuickSortCovidData(benchmarkData,0,benchmarkData.size() - 1,bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
                    reader.exportTestedDataToFile(benchmarkData);
                    reader.exportBenchmarkDataToFile(bench);
                    delete bench;
                    break;
                
                default:
                    cout << "Opção inválida!" << endl;
                    break;
                }
                break;

            case 4:
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
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkCountingSortCovidData(benchmarkData,bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
                    for(int i = 0; i < benchmarkData.size();i++)
                    {
                        cout << benchmarkData[i].getDate() << "," << benchmarkData[i].getStateInitials() << "," << benchmarkData[i].getCityName() << "," << benchmarkData[i].getCityCode() << "," << benchmarkData[i].getCaseCount() << "," << benchmarkData[i].getDeathCount() << endl;
                    }
                    cout << "Número de comparações: " << bench->getCompNumber() << endl;
                    cout << "Número de Movimentos: " << bench->getMovNumber() << endl;
                    cout << "Tempo de execução: " << bench->getRuntime() << endl;
                    delete bench;
                    break;
                
                case 2:
                    cout << "Digite o nome e/ou caminho do arquivo pré-processado a ser lido: ";
                    cin >> fileName;
                    data = reader.readPreProcessedCovidDataFromFile(fileName);
                    bench = new Benchmark(100,data.size());
                    for(int i = 0;i < bench->getRandomIndexVectorSize();i++)
                    {
                        benchmarkData.push_back(data[bench->getRandomIndexFromVector(i)]);
                    }
                    bench->setStartTimeAsNow();
                    sort.benchmarkCountingSortCovidData(benchmarkData,bench);
                    bench->setEndTimeAsNow();
                    bench->generateRuntime();
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
    }
    else if(atoi(argv[1]) == 1)
    {
        execMergeSortBenchmark(10000);
        execMergeSortBenchmark(50000);
        execMergeSortBenchmark(100000);
        execMergeSortBenchmark(500000);
        execMergeSortBenchmark(1000000);

        execQuickSortBenchmark(10000);
        execQuickSortBenchmark(50000);
        execQuickSortBenchmark(100000);
        execQuickSortBenchmark(500000);
        execQuickSortBenchmark(1000000);

        execCountingSortBenchmark(10000);
        execCountingSortBenchmark(50000);
        execCountingSortBenchmark(100000);
        execCountingSortBenchmark(500000);
        execCountingSortBenchmark(1000000);  
    }
    else
    {
        cout << "Modo de execução inválido!" << endl;
    }
    
    return 0;
}