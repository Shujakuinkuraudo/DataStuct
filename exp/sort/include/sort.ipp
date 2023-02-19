void insertSort(vector<int> &arr, int n, int &moveCount)
{
    moveCount = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
            moveCount++;
        }
        arr[j + 1] = temp;
    }
}

void quickSort(vector<int> &arr, int low, int high, int &moveCount)
{
    if (low >= high)
    {
        return;
    }

    int i = low, j = high - 1;
    int pivot = arr[low];

    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
            moveCount++;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
        {
            i++;
            moveCount++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;

    quickSort(arr, low, i - 1, moveCount);
    quickSort(arr, i + 1, high, moveCount);
}

void heapSort(vector<int> &arr, int n, int &moveCount)
{
    moveCount = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
    {

        int parent = i;
        int child = 2 * parent + 1;
        while (child < n)
        {
            if (child + 1 < n && arr[child] < arr[child + 1])
            {
                child++;
            }
            if (arr[parent] < arr[child])
            {
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
                moveCount++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        moveCount++;

        int parent = 0;
        int child = 2 * parent + 1;
        while (child < i)
        {
            if (child + 1 < i && arr[child] < arr[child + 1])
            {
                child++;
            }
            if (arr[parent] < arr[child])
            {
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
                moveCount++;
            }
            else
            {
                break;
            }
        }
    }
}

void mergeSort(vector<int> &arr, vector<int> &temp, int low, int high, int &moveCount)
{
    high--;
    if (low >= high)
        return;

    int mid = low + high >> 1;
    mergeSort(arr, temp, low, mid + 1, moveCount);
    mergeSort(arr, temp, mid + 1, high + 1, moveCount);

    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
            moveCount++;
        }
        else
        {
            temp[k++] = arr[j++];
            moveCount++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
        moveCount++;
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
        moveCount++;
    }
    for (int l = low; l <= high; l++)
    {
        arr[l] = temp[l];
    }
}

void output(const vector<int> &sorted, const int &moveCount)
{
    for (int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << " ";
    cout << endl;
    cout << "数据移动次数：" << moveCount << endl;
}