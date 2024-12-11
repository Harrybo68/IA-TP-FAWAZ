#ifndef TS_DATA_H
#define TS_DATA_H
#include <vector>

using namespace std;

class TimeSeriesDataset {
    private:
        bool znormalize;
        bool isTrain;
        bool hasLabels;
        vector<vector<double>> data;
        vector<int> labels;
        int maxLength;
        int numberOfSamples;

        double calculateMean(const vector<double>& series) const;
        double calculateStdDev(const vector<double>& series, double mean) const;

    public:
        TimeSeriesDataset() {}
        TimeSeriesDataset(bool normalized, bool trained)
            : znormalize(normalized), isTrain(trained), maxLength(0), numberOfSamples(0) {}
        ~TimeSeriesDataset() = default;
        const vector<vector<double>>& getTimeSeriesData() const;
        const vector<int>& getLabels() const;
        void addTimeSeries(const vector<double>& series, int label = -1);
        static double euclidean_distance(const vector<double>& series1, const vector<double>& series2);
        void printTimeSeriesDataset(const vector<vector<double>> data);
};

#endif