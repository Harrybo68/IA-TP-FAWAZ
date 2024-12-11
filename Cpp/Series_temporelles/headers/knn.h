#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <numeric>
#include "../headers/dtw.h"

using namespace std;

class KNN {
private:
    int k;
    string similarity_measure;

    double euclidean_distance(const std::vector<double>& series1, const std::vector<double>& series2) const;
public:
    KNN(int _k, const string& _similarity_measure)
        : k(_k), similarity_measure(_similarity_measure) {}

    int predict(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<double>& testSeries) const;

    double evaluate(const std::vector<std::vector<double>>& trainData, const std::vector<std::vector<double>>& testData, const std::vector<int>& groundTruth) const;
};
