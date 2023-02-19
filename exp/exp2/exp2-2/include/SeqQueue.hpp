#pragma once
#include "head.h"
template <class T>
class SeqQueue
{
    T *data;
    int front, rear;
    int max_size;

public:
    SeqQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
    int Length() const;
    void Show();
};
#include "SeqQueue.ipp"