/**
 * @file NNClassifier.cpp
 * @brief Implementation of NNClassifier class methods
 * @author Your Name
 * @date 2025
 */

#include "../include/NNClassifier.h"

/**
 * @brief Stores training data for classification
 * @param trainingData Vector of labeled Points for training
 */
void NNClassifier::train(const std::vector<Point>& trainingData) {
    this->trainingData = trainingData;
}

/**
 * @brief Calculates Euclidean distance between two points
 * @param a First point
 * @param b Second point
 * @return Calculated distance
 */
float NNClassifier::euclideanDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

/**
 * @brief Predicts label for unknown point using nearest neighbor
 * @param unknown Point to classify
 * @return Predicted label (1-6)
 */
int NNClassifier::predict(const Point& unknown) {
    float minDist = INFINITY;
    int predictedLabel = -1;

    for (const auto& trainPoint : trainingData) {
        float dist = euclideanDistance(unknown, trainPoint);
        if (dist < minDist) {
            minDist = dist;
            predictedLabel = trainPoint.label;
        }
    }
    return predictedLabel;
}

/**
 * @brief Maps numeric labels to orientation strings
 * @param label Numeric orientation label (1-6)
 * @return Corresponding orientation description
 */
std::string NNClassifier::getOrientation(int label) {
    static const std::map<int, std::string> orientations = {
            {1, "Face up"}, {2, "Face down"}, {3, "Portrait"},
            {4, "Portrait upside down"}, {5, "Landscape left"},
            {6, "Landscape right"}
    };
    return orientations.at(label);
}
