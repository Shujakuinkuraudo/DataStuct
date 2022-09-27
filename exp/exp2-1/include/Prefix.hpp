/*** 
 * @Date: 2022-09-26 08:48:02
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 11:07:45
 * @FilePath: /DSM/exp/exp2/include/Prefix.hpp
 */
#pragma once
#include "head.h"
class Prefix
{
    SeqStack<char> OPTR;
    SeqStack<int> OPND;
    char CompareOp(char c,char pre_op) ;

    bool IsNum(char c);
    int Operator(int a,char op,int b);
public:
    int Solve(string prefix_expression);
    int SolveEnhanced(string prefix_expression);
    string ToSuffix(string prefix_expression);

};

#include "Prefix.ipp"