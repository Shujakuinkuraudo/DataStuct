#pragma once
#include "head.h"

void insertSort(vector<int> &arr, int n, int &moveCount);
void quickSort(vector<int> &arr, int low, int high, int &moveCount);
void heapSort(vector<int> &arr, int n, int &moveCount);
void mergeSort(vector<int> &arr, vector<int> &temp, int low, int high, int &moveCount);
void output(const vector<int> &sorted, const int &moveCount);

#include "sort.ipp"