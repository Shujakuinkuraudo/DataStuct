#pragma once
#include "head.h"
template <class T>
class SeqStack
{
    T *data;
    int top;
    int max_length;

public:
    SeqStack();
    ~SeqStack();
    void Push(T x);
    T Pop();
    T Top();
    bool Empty();
};

#include "SeqStack.ipp"