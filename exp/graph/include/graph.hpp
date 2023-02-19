#pragma once
#include "head.h"
const int INF = 0x3f3f3f3f;
using namespace std;
enum Gtype
{
	UG,
	DG,
	UN,
	DN
};

template <class T>
struct EdgeType
{
	int head, tail;
	T cost;
	bool operator<(const EdgeType<T> &other) const
	{
		return cost < other.cost;
	}
	EdgeType()
	{
	}
	EdgeType(int head, int tail, T cost) : head(head), tail(tail), cost(cost){};
};
template <class T>
class MGraph
{
	int vexnum_, edgenum_;
	Gtype type_;
	vector<vector<T>> edges_;
	vector<T> vexs_;
	void __DFS(int v, vector<bool> &visited) const;

public:
	MGraph()
	{
		vexnum_ = edgenum_ = 0;
	}
	void CreateGraph(Gtype t, vector<T> &v, vector<EdgeType<T>> &e);
	void DFS() const;
	void BFS() const;
	vector<pair<int, int>> Kruskal() const;
	vector<pair<int, int>> Prim(int v) const;
	pair<vector<int>, vector<pair<int, int>>> Dijkstra(int v) const;
	pair<vector<vector<int>>, vector<vector<int>>> Floyd() const;
};

#include "graph.ipp"