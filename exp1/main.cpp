/* ***********************************************
Created Time  :Mon 19 Sep 2022 10:30:17 AM CST
************************************************ */

#include "head.h"

int main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	SeqList<int> a;
	//a.menu();
	Goods b;
	int c[4] = {0,1,2,3};
	LinkList<int> d(c,4);
	LinkList<int> f(c,4);
	Merge(d,f);
	d.Menu();
    return 0;
}
