#ifndef TS_H
#define TS_H
#include <vector>

using namespace std;

class TimeSeriesGenerator
{
private:
    int seed;

public:
    TimeSeriesGenerator() = default;
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator() = default;

    virtual vector<double> generateTimeSeries(int length);
    static void printTimeSeries(const vector<double> ts);
};

#endif