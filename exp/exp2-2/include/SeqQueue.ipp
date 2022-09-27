
template <class T>
bool SeqQueue<T>::Empty()
{
    return rear == front;
}
template <class T>
T SeqQueue<T>::GetQueue()
{
    return data[front + 1];
}
template <class T>
T SeqQueue<T>::DeQueue()
{
    return data[++front];
}

template <class T>
void SeqQueue<T>::EnQueue(T x)
{
    if (rear + 1 == max_size)
    {
        T *new_data = new T[max_size * 2];
        _for(i, front + 1, max_size)
            new_data[i - (front + 1)] = data[i];
        rear = max_size - (front + 1) - 1;
        front = -1;
        delete[] data;
        data = new_data;
        max_size *= 2;
    }
    data[++rear] = x;
    // Show();
}
template <class T>
SeqQueue<T>::SeqQueue()
{
    data = new T[5];
    max_size = 5;
    front = rear = -1;
}
// template <class T>
// void SeqQueue<T>::Show()
// {
//     _for(i, 0, max_size)
//             cout
//         << data[i] << " ";
//     cout << endl;
// }