#pragma once

int *newOneDimensionArray(int N);
double *newOneDimensionArrayDouble(int N);
void fillOneDimensionArrayWithNumbers(int* array, int N, int min = 0, int max = 100);
void fillOneDimensionArrayWithNumbersDouble(double* array, int N, int min = 0, int max = 100);
void printOneDimensionArray(int* array, int N);
void printOneDimensionArray(double* array, int N);
double findMinElement(double *array, int N);
int findMaxNegativeNumber(int *array, int N);
void deleteElementFromArray(int *array, int N, int element);