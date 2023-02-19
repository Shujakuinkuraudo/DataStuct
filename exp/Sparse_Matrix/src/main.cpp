#include "../include/head.h"
int main()
{
	SparseMatrix<int> m(5, 5);
	Triple<int> a1(0, 0, 1);
	Triple<int> a2(0, 1, 1);
	Triple<int> a3(1, 0, 1);
	Triple<int> a4(1, 1, 1);
	SparseMatrix<int> m2(5, 5);
	m.PushBack(a1);
	m.PushBack(a2);
	m2.PushBack(a1);
	m2.PushBack(a2);
	m2.PushBack(a3);
	m2.PushBack(a4);
	SparseMatrix<int> temp;
	temp = m + m2;
	temp.print();
	return 0;
}
