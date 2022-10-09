/*** 
 * @Date: 2022-09-22 08:08:48
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 11:08:08
 * @FilePath: /DSM/exp/exp2/main.cpp
 */
#include "head.h"

//#tag 1
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