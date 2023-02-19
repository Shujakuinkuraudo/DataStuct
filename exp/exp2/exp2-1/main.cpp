#include "include/head.h"

int main()
{
	// SeqStack<int> a;
	// _for(i,0,20)
	// 	a.Push(i);
	// _for(i,0,20)
	// 	cout << a.Pop() <<" ";
	// cout << endl;
	string a = "1-9*(4+3)@";
	Infix sl;
	a = sl.ToSuffix(a);
	// cout << sl.Solve(a)<<endl;
	Suffix sl1;
	cout << sl1.Solve(a);
	return 0;
}