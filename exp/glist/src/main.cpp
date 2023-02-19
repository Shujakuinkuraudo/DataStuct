#include "../include/head.h"

int main()
{
	string s1 = "(d,(a,a,(a,(a,a,(a,a,a,b),a,a),a,a,a),b,b),b,a,a,a,(a,(a,a,(a,(a,a,(a,a,a,a),a,a),a,a,a),a,a),a,a,a,a),a)";
	string s2 = "(d,(a,(a,(a,a,(a,a,a,b),a,a),a,a,a),b,b),b,a,a,a,(a,(a,a,(a,(a,a,(a,a,a,a),a,a),a,a,a),a,a),a,a,a,a),a)";
	auto temp = Glist<char>(s1);
	auto temp2 = Glist<char>(s2);
	cout << (temp == temp2) << endl;
	cout << temp << endl;
	temp.Sub('a', 'c');
	temp.Del('c');
	cout << temp << endl;
	cout << temp.Depth() << endl;
	cout << temp.Length() << endl;
	return 0;
}
