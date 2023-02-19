bool Suffix::IsNum(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    return false;
}
int Suffix::Solve(string s)
{
    _for(i, 0, s.length())
    {
        char c = s[i];
        if (IsNum(c))
        {
            OPND.Push(c - '0');
        }
        else if (c == '@')
            return OPND.Top();
        else
        {
            int b = OPND.Pop();
            int a = OPND.Pop();
            OPND.Push(Operator(a, c, b));
        }
    }
    exit(1);
}
int Suffix::Operator(int a, char op, int b)
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