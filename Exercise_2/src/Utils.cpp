#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept> // Add this for std::invalid_argument

void readData(const char* filename, double& S, int& n, double*& w, double*& r) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    getline(file, line); // Read the first line (S;1000)
    S = std::stod(line.substr(2));

    getline(file, line); // Read the second line (n;8)
    n = std::stoi(line.substr(2));

    // Skip the third line which contains column names
    getline(file, line);

    w = new double[n];
    r = new double[n];

    for (int i = 0; i < n; ++i) {
        getline(file, line); // Read the weights and rates of return
        try {
            size_t pos = line.find(';');
            w[i] = std::stod(line.substr(0, pos));
            r[i] = std::stod(line.substr(pos + 1));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting w[" << i << "] or r[" << i << "] to double: " << e.what() << std::endl;
            std::cerr << "Problematic line: " << line << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    file.close();
}



double calculatePortfolioReturn(double S, int n, double* w, double* r) {
    double portfolioReturn = 0.0;
    for (int i = 0; i < n; ++i) {
        portfolioReturn += w[i] * r[i];
    }
    return portfolioReturn;
}

double calculateFinalPortfolioValue(double S, double portfolioReturn) {
    return S * (1 + portfolioReturn);
}
