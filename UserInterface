/**
 * @file UserInterface.cpp
 * @brief Implementation of UserInterface class methods
 * @author Your Name
 * @date 2025
 */

#include "../include/UserInterface.h"
#include <iostream>

/**
 * @brief Main program loop and menu system
 */
void UserInterface::run() {
    DataHandler dataHandler;
    NNClassifier classifier;
    auto trainingData = dataHandler.readCSV("trainingData.txt", true);
    classifier.train(trainingData);

    std::cout << "Choose a classifier:\n1. NNClassifier\n2. AnotherClassifier\n3. KNNClassifier\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Enter input method:\n1. Manual entry\n2. File input\n";
            int method;
            std::cin >> method;
            if (method == 1) handleManualInput(classifier);
            else handleFileInput(classifier, dataHandler);
            break;
        case 2:
        case 3:
            std::cout << "Classifier not implemented yet!\n";
            break;
        default:
            std::cerr << "Invalid choice!\n";
    }
}

/**
 * @brief Handles manual point input from user
 * @param classifier Reference to trained NNClassifier
 */
void UserInterface::handleManualInput(NNClassifier& classifier) {
    Point p;
    std::cout << "Enter x,y,z: ";
    char comma;
    std::cin >> p.x >> comma >> p.y >> comma >> p.z;
    int label = classifier.predict(p);
    std::cout << "Predicted orientation: " << classifier.getOrientation(label) << "\n";
}

/**
 * @brief Processes input file and saves predictions
 * @param classifier Reference to trained NNClassifier
 * @param dataHandler Reference to DataHandler instance
 */
void UserInterface::handleFileInput(NNClassifier& classifier, DataHandler& dataHandler) {
    std::string filename;
    std::cout << "Enter filename (e.g., unknownData-3.txt): ";
    std::cin >> filename;
    auto unknownData = dataHandler.readCSV(filename, false);
    std::vector<Point> predictions;

    for (auto& p : unknownData) {
        p.label = classifier.predict(p);
        p.orientation = classifier.getOrientation(p.label);
        predictions.push_back(p);
    }

    dataHandler.writeResults("result.txt", predictions);
    std::cout << "Predictions saved to data/result.txt\n";
}

