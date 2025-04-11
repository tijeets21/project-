/**
 * @file DataHandler.cpp
 * @brief Implementation of DataHandler class methods
 * @author Your Name
 * @date 2025
 */

#include "../include/DataHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Reads point data from CSV file
 * @param filename Name of the file to read
 * @param hasLabels Flag indicating if file contains labels
 * @return Vector of parsed Point objects
 */
std::vector<Point> DataHandler::readCSV(const std::string& filename, bool hasLabels) {
    std::vector<Point> points;
    std::ifstream file("../data/" + filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return points;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Point p;
        char comma;
        ss >> p.x >> comma >> p.y >> comma >> p.z;
        if (hasLabels) ss >> comma >> p.label;
        points.push_back(p);
    }
    return points;
}

/**
 * @brief Writes prediction results to CSV file
 * @param filename Name of the output file
 * @param predictions Vector of Points with prediction results
 */
void DataHandler::writeResults(const std::string& filename, const std::vector<Point>& predictions) {
    std::ofstream outFile("../data/" + filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    for (const auto& p : predictions) {
        outFile << p.x << "," << p.y << "," << p.z << ","
                << p.label << "," << p.orientation << "\n";
    }
}

/**
 * @file DataHandler.cpp
 * @brief Implementation of DataHandler class methods
 * @author Your Name
 * @date 2025
 */

#include "../include/DataHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Reads point data from CSV file
 * @param filename Name of the file to read
 * @param hasLabels Flag indicating if file contains labels
 * @return Vector of parsed Point objects
 */
std::vector<Point> DataHandler::readCSV(const std::string& filename, bool hasLabels) {
    std::vector<Point> points;
    std::ifstream file("../data/" + filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return points;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Point p;
        char comma;
        ss >> p.x >> comma >> p.y >> comma >> p.z;
        if (hasLabels) ss >> comma >> p.label;
        points.push_back(p);
    }
    return points;
}

/**
 * @brief Writes prediction results to CSV file
 * @param filename Name of the output file
 * @param predictions Vector of Points with prediction results
 */
void DataHandler::writeResults(const std::string& filename, const std::vector<Point>& predictions) {
    std::ofstream outFile("../data/" + filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    for (const auto& p : predictions) {
        outFile << p.x << "," << p.y << "," << p.z << ","
                << p.label << "," << p.orientation << "\n";
    }
}

