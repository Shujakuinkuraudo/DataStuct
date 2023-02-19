#include "../include/head.h"

int main()
{
    srand(time(0));

    const int n = 1000;
    vector<int> origin(n);

    for (int i = 0; i < n; i++)
        origin[i] = rand() % 10000;

    cout << "排序前的数组：";
    for (int i = 0; i < n; i++)
        cout << origin[i] << " ";
    cout << endl;

    int moveCount = 0;
    vector<int> sorted(origin);
    insertSort(sorted, n, moveCount);
    cout << "插入排序后的数组：";
    output(sorted, moveCount);

    moveCount = 0;
    sorted = origin;
    quickSort(sorted, 0, n, moveCount);
    cout << "快速排序后的数组：";
    output(sorted, moveCount);

    moveCount = 0;
    sorted = origin;
    heapSort(sorted, n, moveCount);
    cout << "堆排序后的数组：";
    output(sorted, moveCount);

    vector<int> temp(n);
    moveCount = 0;
    sorted = origin;
    mergeSort(sorted, temp, 0, n, moveCount);
    cout << "归并排序后的数组：";
    output(sorted, moveCount);

    return 0;
}