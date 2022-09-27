/*** 
 * @Date: 2022-09-26 08:13:13
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 09:29:34
 * @FilePath: /DSM/exp/exp2/include/SeqStack.hpp
 */
#pragma once
#include "head.h"
template<class T>
class SeqStack
{
    T* data;
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