#ifndef UTILS_HPP
#define UTILS_HPP

void readData(const char* filename, double& S, int& n, double*& w, double*& r);
double calculatePortfolioReturn(double S, int n, double* w, double* r);
double calculateFinalPortfolioValue(double S, double portfolioReturn);

#endif // UTILS_HPP
