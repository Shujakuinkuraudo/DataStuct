#include "include/head.h"

int main()
{
	char *s = "aabb", *t = "ab";
	// cout << BFMatch(s,t);
	KMPMatch a;
	cout << a(s, t, 4, 2);
}
