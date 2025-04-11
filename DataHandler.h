/**
 * @file DataHandler.h
 * @brief Handles reading and writing of point data for phone orientation detection
 * @author Your Name
 * @date 2025
 */

#pragma once
#include <vector>
#include <string>
#include <fstream>

/**
 * @struct Point
 * @brief Represents a 3D point with gravity vector and orientation information
 */
struct Point {
    float x;        ///< X-axis gravity value (normalized between -1 and 1)
    float y;        ///< Y-axis gravity value (normalized between -1 and 1)
    float z;        ///< Z-axis gravity value (normalized between -1 and 1)
    int label;      ///< Numeric label representing phone orientation (1-6)
    std::string orientation;  ///< Human-readable orientation description
};

/**
 * @class DataHandler
 * @brief Manages data input/output operations for the orientation detection system
 */
class DataHandler {
public:
    /**
     * @brief Reads point data from a CSV file
     * @param filename Name of the file to read
     * @param hasLabels Flag indicating if the file contains labels
     * @return Vector of Point objects containing the read data
     */
    std::vector<Point> readCSV(const std::string& filename, bool hasLabels);

    /**
     * @brief Writes prediction results to a CSV file
     * @param filename Name of the output file
     * @param predictions Vector of Points with prediction results
     */
    void writeResults(const std::string& filename, const std::vector<Point>& predictions);
};

