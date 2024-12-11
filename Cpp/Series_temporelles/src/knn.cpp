#include "../headers/knn.h"
#include "../headers/dtw.h"


int KNN::predict(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<double>& testSeries) const {
    std::vector<std::pair<double, int>> distances;

    for (size_t i = 0; i < trainData.size(); ++i) {
        double distance = 0.0;
        if (similarity_measure == "euclidean_distance") {
            distance = euclidean_distance(trainData[i], testSeries);
        } else if (similarity_measure == "dtw") {
            DTW dtw;
            distance = dtw.compute(trainData[i], testSeries);
        distances.emplace_back(distance, trainLabels[i]);
    }

    std::sort(distances.begin(), distances.end());

    std::vector<int> kNearestLabels(k);
    for (int i = 0; i < k; ++i) {
        kNearestLabels[i] = distances[i].second;
    }

    int predictedLabel = std::accumulate(kNearestLabels.begin(), kNearestLabels.end(), 0) / k;
    return predictedLabel;
}

// Fonction pour évaluer le modèle
double KNN::evaluate(const std::vector<std::vector<double>>& trainData, const std::vector<std::vector<double>>& testData, const std::vector<int>& groundTruth) const {
    int correctPredictions = 0;
    for (size_t i = 0; i < testData.size(); ++i) {
        int predictedLabel = predict(trainData, trainLabels, testData[i]);
        if (predictedLabel == groundTruth[i]) {
            ++correctPredictions;
        }
    }
    return static_cast<double>(correctPredictions) / groundTruth.size();
}