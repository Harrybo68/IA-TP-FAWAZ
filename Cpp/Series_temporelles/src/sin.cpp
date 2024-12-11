#include "../headers/sin.h"
#include <cmath>

vector<double> SinWaveGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries(length);
        for (int i = 0; i < length; ++i) {
            timeSeries[i] = amplitude * sin(2 * M_PI * frequency * i / length + phase);
        }
        return timeSeries;
}