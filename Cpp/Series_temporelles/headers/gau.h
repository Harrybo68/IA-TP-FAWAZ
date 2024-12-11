#ifndef GAU_H
#define GAU_H

class GaussianGenerator : public TimeSeriesGenerator{
    private:
        double mean;
        double std;

    public:
        GaussianGenerator() {}
        GaussianGenerator(int seed, double mean, double std) : TimeSeriesGenerator(seed), mean(mean), std(std) {}
        ~GaussianGenerator() = default;
        vector<double> generateTimeSeries(int length) override;
};


#endif