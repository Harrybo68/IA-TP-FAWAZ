#ifndef SIN_H
#define SIN_H
#include <vector>

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator {
    private:
        double amplitude;
        double frequency;
        double phase;
    
    public:
        SinWaveGenerator() : amplitude(1.0), frequency(1.0), phase(0.0) {}
        SinWaveGenerator(double amplitude, double frequency, double phase)
        : amplitude(amplitude), frequency(frequency), phase(phase) {}
        ~SinWaveGenerator() = default;

        vector<double> generateTimeSeries(int length) override;

};

#endif