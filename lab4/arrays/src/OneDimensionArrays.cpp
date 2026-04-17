
#include "../include/OneDimensionArrays.h"

#include <iostream>

#include "../../generators/include/RandomNumberGenerators.h"

int *newOneDimensionArray(int N) {
    return new int[N];
}

double *newOneDimensionArrayDouble(int N) {
    return new double[N];
}

void fillOneDimensionArrayWithNumbers(int *array, int N, int min, int max) {
    for (int i = 0; i < N; i++) {
        array[i] = generateRandomNumber(min, max);
    }
}

void fillOneDimensionArrayWithNumbersDouble(double* array, int N, int min, int max) {
    for (int i = 0; i < N; i++) {
        array[i] = generateRandomNumber(min, max);
    }
}

void printOneDimensionArray(int *array, int N) {
    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
}

void printOneDimensionArray(double *array, int N) {
    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
}

double findMinElement(double *array, int N) {
    double min = array[0];
    for (int i = 1; i < N; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int findMaxNegativeNumber(int *array, int N) {
    int maxNegative = array[0];
    for (int i = 1; i < N; i++) {
        if (maxNegative >= 0 && array[i] < 0) {
            maxNegative = array[i];
        }
        if (array[i] > maxNegative && array[i] < 0) {
            maxNegative = array[i];
        }
    }
    if (maxNegative >= 0) {
        return 1;
    }
    return maxNegative;
}

void deleteElementFromArray(int *array, int N, int element) {
    for (int i = 0; i < N; i++) {
        if (array[i] == element) {
            for (int j = i; j < N - 1; j++) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}