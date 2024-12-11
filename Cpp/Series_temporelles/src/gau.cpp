#include "../headers/gau.h"
#include <cmath>
#include <random>
using namespace std;


vector<double> GaussianGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries;
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < length; i += 2) {
        double u1 = dist(rng);
        double u2 = dist(rng);

        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

        timeSeries.push_back(z0);
    }

    return timeSeries;
}