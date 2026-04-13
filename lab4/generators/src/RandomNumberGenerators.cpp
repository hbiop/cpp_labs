#include "../include/RandomNumberGenerators.h"

#include <cstdlib>

int generateRandomNumber(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}

double generateRandomNumber(double min, double max) {
    double f = std::rand() / (0.1 * RAND_MAX);
    return min + f * (max - min);
}