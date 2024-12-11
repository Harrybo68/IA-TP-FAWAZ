#ifndef DTW_H
#define DTW_H
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

class DTW {
public:
    double compute(const vector<double>& x, const vector<double>& y);
};

#endif