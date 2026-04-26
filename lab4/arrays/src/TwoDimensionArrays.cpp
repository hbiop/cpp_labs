

#include "../include/TwoDimensionArrays.h"

#include <iostream>

#include "../include/OneDimensionArrays.h"

int **NewTwoDimensionArray(const int rows, const int columns) {
    auto array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = NewOneDimensionArray(columns);
    }
    return array;
}

double **NewTwoDimensionArrayDouble(const int rows, const int columns) {
    auto array = new double*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = NewOneDimensionArrayDouble(columns);
    }
    return array;
}

void DeleteTwoDimensionArray(int** array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void DeleteTwoDimensionArray(double** array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void FillTwoDimensionArrayWithNumbers(int **array, const int rows, const int columns, const int min, const int max) {
    for (int i = 0; i < rows; i++) {
        FillOneDimensionArrayWithNumbers(array[i], columns, min, max);
    }
}

void FillTwoDimensionArrayWithNumbersDouble(double **array, const int rows, const int columns, const int min, const int max) {
    for (int i = 0; i < rows; i++) {
        FillOneDimensionArrayWithNumbersDouble(array[i], columns, min, max);
    }
}

void PrintTwoDimensionArray(int **array, const int rows, const int columns, const std::string &prefix) {
    for (int i = 0; i < rows; i++) {
        std::cout << prefix << " ";
        PrintOneDimensionArray(array[i],columns);
        std::cout << std::endl;
    }
}


void PrintTwoDimensionArray(double **array, const int rows, const int columns, const std::string &prefix) {
    for (int i = 0; i < rows; i++) {
        std::cout << prefix << " ";
        PrintOneDimensionArray(array[i],columns);
        std::cout << std::endl;
    }
}
