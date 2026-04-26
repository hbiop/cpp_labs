#pragma once

int *NewOneDimensionArray(int array_size);
double *NewOneDimensionArrayDouble(int array_size);
void FillOneDimensionArrayWithNumbers(int* array, int array_size, int min = 0, int max = 100);
void FillOneDimensionArrayWithNumbersWithPointerArithmetic(int* array, int array_size, int min = 0, int max = 100);
void FillOneDimensionArrayWithNumbersDouble(double* array, int array_size, int min = 0, int max = 100);
void PrintOneDimensionArray(int* array, int array_size);
void PrintOneDimensionArray(double* array, int array_size);
double FindMinElement(double *array, int array_size);
int FindMaxNegativeNumber(int *array, int array_size);
void DeleteElementFromArray(int* &array, int &array_size, int element);