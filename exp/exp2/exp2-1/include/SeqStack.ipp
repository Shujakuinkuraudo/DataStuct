template <class T>
SeqStack<T>::SeqStack()
{
    data = new T[10];
    max_length = 10;
    top = -1;
}
template <class T>
SeqStack<T>::~SeqStack()
{
    delete[] data;
}
template <class T>
void SeqStack<T>::Push(T x)
{
    if (top == max_length - 1)
    {
        T *new_data = new T[max_length * 2];
        _for(i, 0, max_length)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        max_length *= 2;
    }
    data[++top] = x;
}
template <class T>
T SeqStack<T>::Pop()
{
    if (top == -1)
    {
        cerr << "栈空" << endl;
        exit(1);
    }
    return data[top--];
}
template <class T>
T SeqStack<T>::Top()
{
    return data[top];
}
template <class T>
bool SeqStack<T>::Empty()
{
    return top == -1;
}