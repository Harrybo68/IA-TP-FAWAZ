#ifndef STP_H
#define STP_H
#include <vector>
#include "../headers/ts.h"

using namespace std;

class StepGenerator : public TimeSeriesGenerator {
    private:
        double step;
        double noise;

    public:
        StepGenerator() {}
        StepGenerator(int seed, double step, double noise) : TimeSeriesGenerator(seed), step(step), noise(noise) {}
        ~StepGenerator() = default;
        vector<double> generateTimeSeries(int length) override;
};

#endif