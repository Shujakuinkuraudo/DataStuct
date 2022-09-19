template <class T>
SeqList<T>::SeqList()
{
    length = 0;
    maxLength = 10;
    data = new T[10];
}
template <class T>
SeqList<T>::SeqList(T a[], int n)
{
    length = n;
    maxLength = n + 1;
    data = new T[maxLength];
    _for(i, 0, n)
        data[i] = a[i];
}
template <class T>
SeqList<T>::~SeqList()
{
    delete[] data;
}
template <class T>
int SeqList<T>::ListLength() const
{
    return length;
}

template <class T>
T &SeqList<T>::operator[](int index)
{
    if (index < 0 || index > length)
    {
        cerr << "越界";
        exit(1);
    }
    return data[index];
}
template <class T>
int SeqList<T>::Locate(T item) const
{
    _for(i, 0, length) if (data[i] == item) return i;
    return -1;
}

template <class T>
void SeqList<T>::Insert(int index, T items)
{
    if (index < 0 || index > length)
    {
        cerr << "越界";
        exit(1);
    }
    if (length >= maxLength - 2)
    {
        maxLength *= 2;
        T *newData = new T[maxLength];
        _for(i, 0, index)
            newData[i] = data[i];
        newData[index] = items;
        _for(i, index, length)
            newData[i + 1] = data[i];
        delete[] data;
        data = newData;
    }
    else
    {
        for (int i = length; i > index; i--)
            data[i] = data[i - 1];
        data[index] = items;
    }
    length += 1;
}
template <class T>
void SeqList<T>::Delete(int index)
{
    if (index < 0 || index > length - 1)
    {
        cerr << "越界";
        exit(1);
    }
    _for(i, index, length - 1)
    {
        data[i] = data[i + 1];
    }

    length -= 1;
}
template <class T>
void SeqList<T>::Sort()
{
    for (int i = 1; i < length; i++)
    {
        cout << i << endl;
        T key = data[i];
        int j = i - 1;
        while ((j >= 0) && (key < data[j]))
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

template <class T>
void SeqList<T>::menu()
{
    cout << "选择功能 1.插入(index,item) 2.排序 3.查找(item) 4.序数(index) 5.删除(index) 6.显示" << endl;
    int op;
    cin >> op;
    int index;
    T item;
    switch (op)
    {
    case 1:
        cin >> index >> item;
        Insert(index, item);
        break;
    case 2:
        Sort();
        break;
    case 3:
        cin >> index;
        cout << Locate(index);
        break;
    case 4:
        cin >> index;
        cout << (*this)[index];
        break;
    case 5:
        cin >> index;
        Delete(index);
        break;
    case 6:
        cout << *this;
        break;
    default:
        break;
    }
    menu();
}