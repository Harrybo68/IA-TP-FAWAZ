#include "../headers/stp.h"
#include <cstdlib>

vector<double> StepGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries(length);
    timeSeries[0] = 0;

    for (int i = 1; i < length; ++i) {
        if (rand() % 2 == 0) {
            timeSeries[i] = timeSeries[i - 1];
        } else {
            timeSeries[i] = rand() % 101;
        }
    }

    return timeSeries;
}