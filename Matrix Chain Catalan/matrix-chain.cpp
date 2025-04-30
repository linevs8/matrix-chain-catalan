#include <iostream>
#include <vector>
#include <climits>

// Function to calculate Catalan numbers
unsigned long int catalanNumber(unsigned int n) {
    std::vector<unsigned long int> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for (unsigned int i = 2; i <= n; ++i) {
        for (unsigned int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

// Recursive function to add up all multiplication work
unsigned long int matrixChainTotalWork(const std::vector<int>& p, int i, int j) {
    if (i == j)
        return 0;

    unsigned long int totalWork = 0;

    for (int k = i; k < j; k++) {
        totalWork += matrixChainTotalWork(p, i, k)
                   + matrixChainTotalWork(p, k + 1, j)
                   + p[i - 1] * p[k] * p[j];
    }

    return totalWork;
}

// Function to find the average work for multiplying a chain of matrices
double averageMatrixChainMultiplication(const std::vector<int>& p) {
    int n = p.size() - 1;

    unsigned long int totalWork = matrixChainTotalWork(p, 1, n);
    unsigned long int catalan = catalanNumber(n - 1);

    double averageWork = static_cast<double>(totalWork) / static_cast<double>(catalan);
    return averageWork;
}

int main() {
    std::vector<int> p1 = {10, 100, 5, 50, 1};
    double averageWork1 = averageMatrixChainMultiplication(p1);
    std::cout << "The average work for the matrix chain {10, 100, 5} is: " 
              << averageWork1 << std::endl;

    std::vector<int> p2 = {10, 20, 30};
    double averageWork2 = averageMatrixChainMultiplication(p2);
    std::cout << "The average work for the matrix chain {10, 20, 30} is: " 
              << averageWork2 << std::endl;

    return 0;
}