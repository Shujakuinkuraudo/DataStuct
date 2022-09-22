template <class T>
LinkList<T>::LinkList()
{

}
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
    Node<T> *rear = head;
    _for(i, 0, n)
    {
        Node<T> *temp = new Node<T>(a[i]);
        rear->next = temp;
        rear = rear->next;
    }
}
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *ahead = head;
    while (ahead)
    {
        ahead = ahead->next;
        delete head;
        head = ahead;
    }
}

template <class T>
int LinkList<T>::ListLength() const
{
    return length;
}
template <class T>
T &LinkList<T>::Get(int index) 
{
    int count = -1;
    auto ahead = head;
    while (ahead)
    {
        ahead = ahead->next;
        count++;
        if (count == index)
            return ahead->data;
    }
    return head->data;
}
template <class T>
T &LinkList<T>::operator[](int index) 
{
    return Get(index);
}

template <class T>
int LinkList<T>::Locate(T item)
{
    int count = -1;
    auto ahead = head;
    while (ahead->next)
    {
        ahead = ahead->next;
        count++;
        if (ahead->data == item)
        {
            return count;
        }
    }
    return -1;
}
template <class T>
void LinkList<T>::Insert(int index, T item)
{
    Node<T> *temp = new Node<T>(item);
    int count = -1;
    auto ahead = head;
    while (ahead)
    {
        if (count == index - 1)
        {
            temp->next = ahead->next;
            ahead->next = temp;
            length++;
            return;
        }
        else
        {
            ahead = ahead->next;
            count++;
        }
    }
}
template <class T>
T LinkList<T>::Delete(int index)
{
    int count = -1;
    auto ahead = head;
    while (ahead->next)
    {
        if (count == index - 1)
        {
            auto temp = ahead->next;
            ahead->next = ahead->next->next;
            T r = temp->data;
            delete temp;
            return r;
        }
        else
        {
            ahead = ahead->next;
            count++;
        }
    }
    length--;
    return head->data;
}
template <class T>
void LinkList<T>::Reverse()
{
    Node<T> *now, *ahead, *prev = nullptr;
    now = ahead = head->next;
    while (ahead->next)
    {
        ahead = ahead->next;
        now->next = prev;
        prev = now;
        now = ahead;
    }
    head->next = ahead;
    ahead->next = prev;
}
template <class T>
void LinkList<T>::Menu()
{
    int op;
    cout << "1.长度 2.序号(index) 3.查找(item)"
            << "4.插入(index,item) 5.删除(index)"
            <<"6.反转 7.显示" << endl;

    int index;
    T item;
    cin >> op;
    switch(op)
    {
        case 1:
            cout << ListLength() << endl;
            break;
        case 2:
            cin >> index;
            cout << (*this)[index]<<endl;
            break;
        case 3:
            cin >> item;
            cout << Locate(item) << endl;
            break;
        case 4:
            cin >> index >> item;
            Insert(index,item);
            break;
        case 5:
            cin >> index;
            Delete(index);
            break;
        case 6:
            Reverse();
            break;
        case 7:
            cout << *this;
            break;
    }
    Menu();
}
