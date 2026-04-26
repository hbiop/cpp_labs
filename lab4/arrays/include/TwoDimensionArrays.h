#pragma once
#include <string>

int **NewTwoDimensionArray(int rows, int columns);
double **NewTwoDimensionArrayDouble(int rows, int columns);
void DeleteTwoDimensionArray(int** array, int rows);
void DeleteTwoDimensionArray(double** array, int rows);
void FillTwoDimensionArrayWithNumbers(int** array, int rows, int columns, int min = 0, int max = 100);
void FillTwoDimensionArrayWithNumbersDouble(double **array, int rows, int columns, int min = 0, int max = 100);
void PrintTwoDimensionArray(int** array, int rows, int columns, const std::string &prefix = "");
void PrintTwoDimensionArray(double** array, int rows, int columns, const std::string &prefix = "");