#include "../include/RandomNumberGenerators.h"

#include <cstdlib>

int GenerateRandomNumber(const int min, const int max) {
    return std::rand() % (max - min + 1) + min;
}

double GenerateRandomNumber(const double min, const double max) {
    const double f = std::rand() / (0.1 * RAND_MAX);
    return min + f * (max - min);
}