#pragma once
class Suffix
{
    SeqStack<int> OPND;
    bool IsNum(char c);
    int Operator(int a, char op, int b);
    public:
    int Solve(string s);
};
#include "Suffix.ipp"