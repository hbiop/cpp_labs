#pragma once

int ***NewThreeDimensionArray(int depth, int rows, int columns);
void DeleteThreeDimensionArray(int*** array, int depth, int rows);
void FillThreeDimensionArrayWithNumbers(int*** array, int depth,int rows, int columns, int min = 0, int max = 100);