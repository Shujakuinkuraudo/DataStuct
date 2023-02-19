template <class T>
GlistNode<T> *Glist<T>::__CreateFromString(string &s, int &idx)
{
    if (idx >= s.length())
        return nullptr;
    GlistNode<T> *temp = new GlistNode<T>;
    while (s[idx] == ' ' || s[idx] == ',')
        idx++;
    if (s[idx] == '(')
    {
        temp->type_ = LIST;
        temp->sublist_ = __CreateFromString(s, ++idx);
        temp->next_ = __CreateFromString(s, ++idx);
        return temp;
    }
    else if (s[idx] == ')')
    {
        idx++;
        return nullptr;
    }
    T t = s[idx];
    temp->type_ = ATOM;
    temp->data_ = t;
    temp->next_ = __CreateFromString(s, ++idx);
    return temp;
}
template <class T>
void Glist<T>::__Print(ostream &out, GlistNode<T> *start) const
{
    while (start)
    {
        if (start->type_ == LIST)
        {
            out << "(";
            __Print(out, start->sublist_);
            out << ")";
        }
        if (start->type_ == ATOM)
            out << start->data_;
        if (start->next_)
            out << ",";
        start = start->next_;
    }
}
template <class T>
int Glist<T>::__Depth(GlistNode<T> *head) const
{
    int max_depth = -1;
    while (head)
    {
        if (head->type_ == LIST)
            max_depth = max(max_depth, __Depth(head->sublist_));
        else
            max_depth = max(max_depth, 0);
        head = head->next_;
    }
    return max_depth + 1;
}
template <class T>
int Glist<T>::__Length(GlistNode<T> *head) const
{
    int res = 0;
    while (head)
    {
        res++;
        head = head->next_;
    }
    return res;
}
template <class T>
void Glist<T>::__Sub(T a, T target, GlistNode<T> *head)
{
    while (head)
    {
        if (head->type_ == LIST)
            __Sub(a, target, head->sublist_);
        else if (head->data_ == a)
            head->data_ = target;
        head = head->next_;
    }
}
template <class T>
GlistNode<T> *Glist<T>::__Del(T a, GlistNode<T> *head)
{
    GlistNode<T> *falsehead = new GlistNode<T>();
    falsehead->next_ = head;
    GlistNode<T> *front = falsehead->next_, *rear = falsehead;
    while (front)
    {
        if (front->type_ == LIST)
            front->sublist_ = __Del(a, front->sublist_);
        else if (front->data_ == a)
        {
            GlistNode<T> *temp = front;
            rear->next_ = front = front->next_;
            delete temp;
            temp = nullptr;
            continue;
        }
        front = front->next_;
        rear = rear->next_;
    }
    GlistNode<T> *res = falsehead->next_;
    delete falsehead;
    return res;
}
template <class T>
Glist<T>::Glist(string &s)
{
    int idx = 0;
    __head_ = __CreateFromString(s, idx);
};
template <class T>
int Glist<T>::Depth() const
{
    return __Depth(__head_) - 1;
}
template <class T>
int Glist<T>::Length()
{
    return __Length(__head_->sublist_);
}
template <class T>
void Glist<T>::Sub(T a, T target)
{
    __Sub(a, target, __head_);
}
template <class T>
void Glist<T>::Del(T a)
{
    __head_ = __Del(a, __head_);
}
template <class T>
bool Glist<T>::operator==(Glist<T> &t2)
{
    return __Equal(__head_, t2.__head_);
}
template <class T>
bool __Equal(GlistNode<T> *l1, GlistNode<T> *l2)
{
    if (!l1 || !l2)
    {
        if (l1 != l2)
            return false;
        else
            return true;
    }
    if (l1->type_ == ATOM || l2->type_ == ATOM)
    {
        if (l1->type_ != l2->type_)
            return false;
        if (l1->data_ != l2->data_)
            return false;
    }
    if (l1->type_ == LIST || l2->type_ == LIST)
        if (l1->type_ == l2->type_)
            return __Equal(l1->sublist_, l2->sublist_);
    if (!__Equal(l1->next_, l2->next_))
        return false;
    return true;
}