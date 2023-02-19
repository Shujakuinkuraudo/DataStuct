#pragma once
#include "head.h"
class Infix
{
    SeqStack<char> OPTR;
    SeqStack<int> OPND;
    char CompareOp(char c, char pre_op);

    bool IsNum(char c);
    int Operator(int a, char op, int b);

public:
    int Solve(string prefix_expression);
    int SolveEnhanced(string prefix_expression);
    string ToSuffix(string prefix_expression);
};

#include "Infix.ipp"