/***
 * @Date: 2022-09-26 10:33:37
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 10:40:25
 * @FilePath: /DSM/exp/exp2/include/Infix.ipp
 */

char Infix::CompareOp(char c, char pre_op) // a<=b    char Infix::CompareOp(char c,char pre_op) // a<=b
{
    switch (c)
    {
    case '+':
    case '-':
        switch (pre_op)
        {
        case '(':
        case '@':
            return '<';
        default:
            return '>';
        }
    case '*':
    case '/':
        switch (pre_op)
        {
        case '*':
        case '/':
        case ')':
            return '>';
        default:
            return '<';
        }
    case '(':
        return '<';
    case ')':
        switch (pre_op)
        {
        case '(':
            return '=';
        default:
            return '>';
        }
    case '@':
        switch (pre_op)
        {
        case '@':
            return '=';
        default:
            return '>';
        }
    }
    cerr << "CompareOp error" << endl;
    exit(1);
}
bool Infix::IsNum(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    return false;
}
int Infix::Operator(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    cerr << "operator error" << endl;
    exit(1);
}
int Infix::Solve(string prefix_expression)
{
    OPTR.Push('@');
    _for(i, 0, prefix_expression.length())
    {
        char c = prefix_expression[i];
        if (IsNum(c))
            OPND.Push(c - '0');
        else
        {
            if (c == ' ')
                continue;
            switch (CompareOp(c, OPTR.Top()))
            {
            case '<':
                OPTR.Push(c);
                break;
            case '=':
                OPTR.Pop();
                break;
            case '>':
                int b = OPND.Pop();
                int a = OPND.Pop();
                char op = OPTR.Pop();
                OPND.Push(Operator(a, op, b));
                i--;
            }
        }
    }
    return OPND.Top();
}
int Infix::SolveEnhanced(string prefix_expression)
{
    OPTR.Push('@');
    _for(i, 0, prefix_expression.length())
    {
        char c = prefix_expression[i];
        if (IsNum(c))
        {
            int t = c - '0';
            while (IsNum(prefix_expression[++i]))
            {
                t *= 10;
                t += prefix_expression[i] - '0';
            }
            i--;
            OPND.Push(t);
        }
        else
        {
            if (c == ' ')
                continue;
            switch (CompareOp(c, OPTR.Top()))
            {
            case '<':
                OPTR.Push(c);
                break;
            case '=':
                OPTR.Pop();
                break;
            case '>':
                int b = OPND.Pop();
                int a = OPND.Pop();
                char op = OPTR.Pop();
                OPND.Push(Operator(a, op, b));
                i--;
            }
        }
    }
    return OPND.Top();
}
string Infix::ToSuffix(string prefix_expression)
{
    string suffix = "";
    OPTR.Push('@');
    _for(i,0,prefix_expression.length())
    {
        // cout << OPTR.Top();
        char c = prefix_expression[i];
        if(c=='@')
        {
            while(!OPTR.Empty())
                suffix += OPTR.Pop();
        }
        else if(IsNum(c))
            {suffix+=c;}
        else if(c=='(')
            OPTR.Push(c);
        else if(c==')')
        {
            while(OPTR.Top()!='(')
                {suffix+=OPTR.Pop();}
            OPTR.Pop();
        }
        else
        {
            switch(CompareOp(c,OPTR.Top()))
            {
                case '<':
                    OPTR.Push(c);
                    break;
                case '>':
                case '=':
                    suffix+=OPTR.Pop();
                    i--;
            }
        }
    }
    return suffix;

}