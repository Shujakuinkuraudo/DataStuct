#include "../include/head.h"

int main()
{
	BiTree<char> a;
	string s = "12@@@";
	a.PreCreateFromString(s);
	a.InTraverse();
	a.CountDouble();
	cout << endl;
	
    return 0;
}
