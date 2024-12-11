#include "../headers/ts.h"
#include <cstdlib>
#include <iostream>

TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed)
{
    srand(seed);
}

vector<double> TimeSeriesGenerator::generateTimeSeries(int length){
    vector<double> ts;
    for (int i = 0; i < length; i++)
    {
        ts.push_back(rand() % 100);
    }
    return ts;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> ts){
    for (int i = 0; i < ts.size(); i++)
    {
        cout << ts[i] << " ";
    }
    cout << endl;
}