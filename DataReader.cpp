#include "DataReader.h"

DataReader::DataReader(){}

DataReader::~DataReader(){}

vector<CovidData> DataReader::readCovidDatafromFile(string fileName)
{
    ifstream file;
    string line;
    vector<CovidData> data;
    
    file.open(fileName);
    getline(file,line);

    if(file.is_open())
    {
        while(getline(file,line))
        {
            if(line == "")
            {
                continue;
            }
            else
            {
                istringstream dataFromLine(line);
                string date,stateInitials,cityName,cityCode,caseCount,deathCount;
                getline(dataFromLine,date,',');
                getline(dataFromLine,stateInitials,',');
                getline(dataFromLine,cityName,',');
                getline(dataFromLine,cityCode,',');
                getline(dataFromLine,caseCount,',');
                getline(dataFromLine,deathCount,',');
                CovidData element;
                element.setData(date,stateInitials,cityName,cityCode,atoi(caseCount.c_str()),atoi(deathCount.c_str()));
                data.push_back(element);    
            }
        }
        file.close();
    }
    else
    {
        cout << "Arquivo não aberto, retornando vector vazio!" << endl;
    }

    return data;
}

void DataReader::exportPreProcessedCovidDataToFile(vector<CovidData> &data)
{
    ofstream outfile("brazil_covid19_cities_processado.csv");
    for(int i = 0;i < data.size();i++)
    {
        outfile << data[i].getDate() << "," << data[i].getStateInitials() << "," << data[i].getCityName() << "," << data[i].getCityCode() << "," << data[i].getCaseCount() << "," << data[i].getDeathCount() << endl;
    }
    outfile.close();
}

void DataReader::exportExtractedCovidDataToFile(vector<CovidData> &data, vector<CovidData> &extractedData)
{
    ofstream outfile("brazil_covid19_cities_extracted.csv");
    for(int i = 0;i < extractedData.size();i++)
    {
        outfile << extractedData[i].getDate() << "," << extractedData[i].getStateInitials() << "," << extractedData[i].getCityName() << "," << extractedData[i].getCityCode() << "," << extractedData[i].getCaseCount() << "," << extractedData[i].getDeathCount() << endl;
    }
    outfile.close();
}

