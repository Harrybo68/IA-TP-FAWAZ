#include "../headers/tsdata.h"
#include <iostream>
#include <cmath>

using namespace std;

double TimeSeriesDataset::calculateMean(const vector<double>& series) const {
        double sum = 0;
        for (double val : series) {
            sum += val;
        }
        return sum / series.size();
    }

double TimeSeriesDataset::calculateStdDev(const vector<double>& series, double mean) const {
    double sum = 0;
    for (double val : series) {
        sum += (val - mean) * (val - mean);
    }
    return sqrt(sum / series.size());
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    vector<double> normalizedSeries = series;
    double mean = calculateMean(series);
    double stddev = calculateStdDev(series, mean);

    for (double& val : normalizedSeries) {
        val = (val - mean) / stddev;
    }

    data.push_back(normalizedSeries);
    labels.push_back(label);
}

const vector<vector<double>>& TimeSeriesDataset::getTimeSeriesData() const {
    return data;
}

double TimeSeriesDataset::euclidean_distance(const vector<double>& series1, const vector<double>& series2) {
    if (series1.size() != series2.size()) {
        cerr << "Erreur : Les séries temporelles doivent avoir la même taille pour calculer la distance euclidienne." << endl;
        throw invalid_argument("Tailles différentes des séries temporelles.");
    }

    double sum = 0;
    for (size_t i = 0; i < series1.size(); ++i) {
        double diff = series1[i] - series2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

void TimeSeriesDataset::printTimeSeriesDataset(const vector<vector<double>> data) {
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Time Series " << i + 1 << ": ";
        for (double value : data[i]) {
            cout << value << " ";
        }
        cout << endl << "Label: " << labels[i] << endl;
    }

    cout << endl;
}

const vector<int>& TimeSeriesDataset::getLabels() const {
    if (!hasLabels) {
        cerr << "Erreur : Ce dataset ne contient pas d'étiquettes." << endl;
        throw runtime_error("Pas d'étiquettes dans le dataset.");
    }
    return labels;
}


