/*** 
 * @Date: 2022-09-28 10:54:21
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-28 11:06:57
 * @FilePath: /DSM/exp/template/src/main.cpp
 */
/* ***********************************************
Created Time  :Mon 19 Sep 2022 10:30:17 AM CST
************************************************ */

#include "../include/head.h"

int main()
{
	string s1 = "(d,(a,a,(a,(a,a,(a,a,a,b),a,a),a,a,a),b,b),b,a,a,a,(a,(a,a,(a,(a,a,(a,a,a,a),a,a),a,a,a),a,a),a,a,a,a),a)";
	string s2 = "(d,(a,(a,(a,a,(a,a,a,b),a,a),a,a,a),b,b),b,a,a,a,(a,(a,a,(a,(a,a,(a,a,a,a),a,a),a,a,a),a,a),a,a,a,a),a)";
	auto temp = Glist<char>(s1);
	auto temp2 = Glist<char>(s2);
	cout << (temp==temp2) << endl;
	cout << temp << endl;
	temp.Sub('a','c');
	temp.Del('c');
	cout << temp << endl;
	cout << temp.Depth() << endl;
	cout << temp.Length() << endl;
    return 0;
}
