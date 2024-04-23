#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utils.hpp"

int main() {
    double S;
    int n;
    double* w;
    double* r;

    readData("data.csv", S, n, w, r);

    std::ofstream outputFile("result.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create result.txt file." << std::endl;
        return EXIT_FAILURE;
    }

    // Print to console
    std::cout << "S = " << std::fixed << std::setprecision(2) << S << ", n = " << n << std::endl;
    std::cout << "w = [ ";
    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << w[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "r = [ ";
    for (int i = 0; i < n; ++i) {
        std::cout << std::fixed << std::setprecision(2) << r[i] << " ";
    }
    std::cout << "]" << std::endl;

    double portfolioReturn = calculatePortfolioReturn(S, n, w, r);
    double finalValue = calculateFinalPortfolioValue(S, portfolioReturn);

    std::cout << "Rate of return of the portfolio: " << std::fixed << std::setprecision(4) << portfolioReturn << std::endl;
    std::cout << "V: " << std::fixed << std::setprecision(2) << finalValue << std::endl;

    // Print to file
    outputFile << "S = " << std::fixed << std::setprecision(2) << S << ", n = " << n << std::endl;
    outputFile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << std::fixed << std::setprecision(2) << w[i] << " ";
    }
    outputFile << "]" << std::endl;
    outputFile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << std::fixed << std::setprecision(2) << r[i] << " ";
    }
    outputFile << "]" << std::endl;

    outputFile << "Rate of return of the portfolio: " << std::fixed << std::setprecision(4) << portfolioReturn << std::endl;
    outputFile << "V: " << std::fixed << std::setprecision(2) << finalValue << std::endl;

    outputFile.close();

    delete[] w;
    delete[] r;

    return 0;
}
