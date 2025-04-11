/**
 * @file UserInterface.h
 * @brief Provides user interaction for the orientation detection system
 * @author Your Name
 * @date 2025
 */

#pragma once
#include "NNClassifier.h"
#include "DataHandler.h"

/**
 * @class UserInterface
 * @brief Handles all user interactions and program flow
 */
class UserInterface {
public:
    /**
     * @brief Main program loop
     */
    void run();

    /**
     * @brief Handles manual point input from user
     * @param classifier Reference to NNClassifier instance
     */
    void handleManualInput(NNClassifier& classifier);

    /**
     * @brief Handles file-based input processing
     * @param classifier Reference to NNClassifier instance
     * @param dataHandler Reference to DataHandler instance
     */
    void handleFileInput(NNClassifier& classifier, DataHandler& dataHandler);
};
