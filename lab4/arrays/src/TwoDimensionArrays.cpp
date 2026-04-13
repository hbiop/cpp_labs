

#include "../include/TwoDimensionArrays.h"

#include <iostream>

#include "../include/OneDimensionArrays.h"

int **newTwoDimensionArray(int M, int N) {
    auto array = new int*[M];
    for (int i = 0; i < M; i++) {
        array[i] = newOneDimensionArray(N);
    }
    return array;
}

double **newTwoDimensionArrayDouble(int M, int N) {
    auto array = new double*[M];
    for (int i = 0; i < M; i++) {
        array[i] = newOneDimensionArrayDouble(N);
    }
    return array;
}

void deleteTwoDimensionArray(int** array, int M) {
    for (int i = 0; i < M; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void deleteTwoDimensionArray(double** array, int M) {
    for (int i = 0; i < M; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void fillTwoDimensionArrayWithNumbers(int **array, int M, int N, int min, int max) {
    for (int i = 0; i < M; i++) {
        fillOneDimensionArrayWithNumbers(array[i], N, min, max);
    }
}

void fillTwoDimensionArrayWithNumbersDouble(double **array, int M, int N, int min, int max) {
    for (int i = 0; i < M; i++) {
        fillOneDimensionArrayWithNumbersDouble(array[i], N, min, max);
    }
}

void printTwoDimensionArray(int **array, int M, int N, std::string prefix) {
    for (int i = 0; i < M; i++) {
        std::cout << prefix << " ";
        printOneDimensionArray(array[i],N);
        std::cout << std::endl;
    }
}


void printTwoDimensionArray(double **array, int M, int N, std::string prefix) {
    for (int i = 0; i < M; i++) {
        std::cout << prefix << " ";
        printOneDimensionArray(array[i],N);
        std::cout << std::endl;
    }
}
