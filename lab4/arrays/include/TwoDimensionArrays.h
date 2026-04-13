#pragma once
#include <string>

int **newTwoDimensionArray(int M, int N);
double **newTwoDimensionArrayDouble(int M, int N);
void deleteTwoDimensionArray(int** array, int M);
void deleteTwoDimensionArray(double** array, int M);
void fillTwoDimensionArrayWithNumbers(int** array, int M, int N, int min = 0, int max = 100);
void fillTwoDimensionArrayWithNumbersDouble(double **array, int M, int N, int min = 0, int max = 100);
void printTwoDimensionArray(int** array, int M, int N, std::string prefix = "");
void printTwoDimensionArray(double** array, int M, int N, std::string prefix = "");