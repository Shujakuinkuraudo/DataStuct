/*
 * @Author: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @Date: 2022-11-28 10:23:12
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-11-29 21:11:47
 * @FilePath: /exp/exp8/src/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/head.h"

int main()
{
	MGraph<int> m;
	vector<int> v = {0,1,2};
	vector<EdgeType<int>> e = {EdgeType<int>{0,0,2},EdgeType<int>{0,1,2},EdgeType<int>{1,2,2}};
	m.CreateGraph(UNDG,v,e);
	m.BFS();
	cout << endl;
	cout << "=====" << endl;
	m.DFS();
	cout << endl;
	cout << "=====" << endl;
	m.Kruskal();
	cout << endl;
	cout << "=====" << endl;
	m.Prim(0);
	cout << endl;
	cout << "=====" << endl;
	m.Floyd(0,1);
	cout << endl;
	cout << "=====" << endl;
	m.Dijkstra(1);
	cout << endl;
	cout << "=====" << endl;
	

    return 0;
}
