#include "../include/head.h"

int main()
{
	MGraph<int> m;
	vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0};
	vector<EdgeType<int>> e = {EdgeType<int>{0, 1, 2}, EdgeType<int>{1, 3, 2}, EdgeType<int>{2, 3, 1}, EdgeType<int>{3, 4, 2}, EdgeType<int>{3, 5, 4}, EdgeType<int>{4, 5, 1}, EdgeType<int>{4, 6, 5}, EdgeType<int>{5, 6, 2}, EdgeType<int>{5, 7, 1}, EdgeType<int>{6, 7, 1}};
	m.CreateGraph(UN, v, e);
	m.BFS();
	cout << endl;
	cout << "=====" << endl;
	m.DFS();
	cout << endl;
	cout << "=====" << endl;
	m.Prim(0);
	cout << endl;
	cout << "=====" << endl;
	m.Kruskal();
	cout << endl;
	cout << "=====" << endl;
	m.Floyd();
	cout << endl;
	cout << "=====" << endl;
	m.Dijkstra(1);
	cout << endl;
	cout << "=====" << endl;

	return 0;
}
