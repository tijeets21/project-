/**
 * @file NNClassifier.h
 * @brief Implements Nearest Neighbor classification for phone orientation detection
 * @author Your Name
 * @date 2025
 */

#pragma once
#include "DataHandler.h"
#include <cmath>
#include <map>

/**
 * @class NNClassifier
 * @brief Provides nearest neighbor classification functionality
 */
class NNClassifier {
public:
    /**
     * @brief Trains the classifier with reference data
     * @param trainingData Vector of labeled Points for training
     */
    void train(const std::vector<Point>& trainingData);

    /**
     * @brief Predicts orientation for an unknown point
     * @param unknown Point to classify
     * @return Predicted label (1-6)
     */
    int predict(const Point& unknown);

    /**
     * @brief Gets orientation description for a given label
     * @param label Numeric orientation label (1-6)
     * @return String description of the orientation
     */
    std::string getOrientation(int label);

private:
    std::vector<Point> trainingData;  ///< Storage for training data

    /**
     * @brief Calculates Euclidean distance between two points
     * @param a First point
     * @param b Second point
     * @return Calculated distance
     */
    float euclideanDistance(const Point& a, const Point& b);
};
