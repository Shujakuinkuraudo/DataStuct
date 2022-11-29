#pragma once
#include "head.h"
const int INF = 0x3f3f3f3f;
using namespace std;
enum Gtype {UNDG,DG,UNDN,DN};

template<class T>
struct EdgeType
{
	int  head, tail;
	T cost;
	friend bool operator<(const EdgeType<T>& cmp1, const EdgeType<T>& cmp2)
	{
		return cmp1.cost < cmp2.cost;
	}
};
template<class T>
struct Edge
{
	int adjvex;
	T lowcost;
};
template<class T>
class MGraph
{
	int vexnum_, edgenum_;
	Gtype type;
	vector<vector<int>> edges_;
	vector<T> vexs_;
	void DFS(int v, vector<bool>& visited)
	{
		visited[v] = true;
		cout << v << " ";
		for (int i = 0; i < vexnum_; i++)
			if (!visited[i] && edges_[v][i] == 1)
				DFS(i, visited);
		//visited[v] = false;
	}
	void Kruskal(vector<EdgeType<T>>& tree)
	{
		vector<EdgeType<T>> graph;
		for(int i=0;i<vexnum_;i++)
			for(int j=0;j<vexnum_;j++)
				if (edges_[i][j] != 0 && edges_[i][j] != INF)
				{
					EdgeType<T> tmp;
					tmp.head = i;
					tmp.tail = j;
					tmp.cost = edges_[i][j];
					graph.push_back(tmp);
				}
		sort(graph.begin(), graph.end());
		tree.resize(vexnum_ - 1);
		vector<int> components(edgenum_);
		for (int i = 0; i < vexnum_; i++)
			components[i] = i;
		int k = 0, j = 0;
		while (k < vexnum_ - 1)
		{
			int h1 = graph[j].head;
			int t1 = graph[j].tail;
			int h2 = components[h1];
			int t2 = components[t1];
			if (h2 != t2)
			{
				tree[k].head = h1;
				tree[k].tail = t1;
				tree[k].cost = graph[j].cost;
				k++;
				for (int i = 0; i < vexnum_; i++)
					if (components[i] == t2)
						components[i] = h2;
			}
			j++;
		}
	}
	void Dijkstra(int v, vector<int>& path, vector<int>& dist)
	{
		vector<bool> visited(vexnum_, false);
		for (int i = 0; i < vexnum_; i++)
		{
			dist[i] = edges_[v][i];
			if ((i == v || dist[i] < INF))
				path[i] = v;
			else path[i] = -1;
		}
		dist[v] = 0;
		visited[v] = true;
		for (int i = 1; i < vexnum_; i++)
		{
			int k = 0;
			int min = INF;
			for (int j = 0; j < vexnum_; j++)
				if (!visited[j] && dist[j] < min)
				{
					min = dist[j];
					k = j;
				}
			visited[k] = true;
			for (int j = 0; j < vexnum_; j++)
				if (!visited[j])
					if (edges_[k][j] != 0 && edges_[k][j] != INF)
						if (edges_[k][j] + dist[k] < dist[j])
						{
							dist[j] = dist[k] + edges_[k][j];
							path[j] = k;
						}
		}
	}
	void Floyd(vector<vector<int>>& path, vector<vector<int>>& D)
	{
		for(int i=0;i<vexnum_;i++)
			for (int j = 0; j < vexnum_; j++)
			{
				if (i == j)
					D[i][j] = 0;
				else D[i][j] = edges_[i][j];
				if (D[i][j] < INF)
					path[i][j] = j;
				else path[i][j] = -1;
			}
		for(int k=0;k<vexnum_;k++)
			for(int i=0;i<vexnum_;i++)
				for(int j=0;j<vexnum_;j++)
					if (D[i][k] + D[k][j] < D[i][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						path[i][j] = path[i][k];
					}
	}
	public:
	MGraph()
	{
		vexnum_ = edgenum_ = 0;
		type = UNDG;
	}
	void CreateGraph(Gtype t, vector<T>& v, vector<EdgeType<T>>& e)
	{
		vexnum_ = v.size();
		edgenum_ = e.size();
		int& vn = vexnum_, & en = edgenum_;
		type = t;
		vexs_.resize(vn);
		edges_.resize(vn);
		for (int i = 0; i < vn; i++)
			vexs_[i] = v[i];
		for (int i = 0; i < vn; i++)
			edges_[i].resize(vn);
		for (int i = 0; i < vn; i++)
			for (int j = 0; j < vn; j++)
				if (i == j)
					edges_[i][j] = 0;
				else edges_[i][j] = INF;
		for (int i = 0; i < en; i++)
		{
			switch (type)
			{
				case UNDG:
					edges_[ e[i].head ][ e[i].tail ] = edges_[ e[i].tail ][ e[i].head ] = 1;
					break;
				case DG:
					edges_[ e[i].head ][ e[i].tail ] = 1;
					break;
				case UNDN:
					edges_[ e[i].head ][ e[i].tail ] = edges_[ e[i].tail ][ e[i].head ] = e[i].cost;
					break;
				case DN:
					edges_[ e[i].head ][ e[i].tail ] = e[i].cost;
					break;
			}
		}
	}
	~MGraph()
	{
	}
	void DFS()
	{
		vector<bool> visited(vexnum_, false);
		for (int i = 0; i < vexnum_; i++)
			if (!visited[i])
			{
				cout << i <<  ":";
				DFS(i, visited);
			}
	}
	void BFS()
	{
		queue<int> q;
		vector<bool> visited(vexnum_, false);
		for (int i = 0; i < vexnum_; i++)
		{
			if (!visited[i])
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
				while(q.size())
				{
					int u = q.front();
					q.pop();
					for (int j = 0; j < vexnum_; j++)
					{
						if (edges_[u][j] == 1 && !visited[j])
						{
							visited[j] = true;
							cout << j << " ";
							q.push(j);
						}
					}
				}
			}
		}
	}
	void Prim(int v)
	{
		vector<Edge<T>> miniedges(vexnum_);//建立该点邻接点的数组，记录到达所需权值
		for (int i = 0; i < vexnum_; i++)
		{
			miniedges[i].adjvex = v;
			miniedges[i].lowcost = edges_[v][i];
		}
		miniedges[v].lowcost = 0;//理论上可略去，因edges_[v][v]==0
		for (int i = 1; i < vexnum_; i++)
		{
			int k = 0;
			int min = INF;
			for (int j = 0; j < vexnum_; j++)
				if (miniedges[j].lowcost < min && miniedges[j].lowcost != 0)//注意!=0
				{
					min = miniedges[j].lowcost;
					k = j;
				}
			cout << miniedges[k].adjvex << "," << k << endl;
			miniedges[k].lowcost = 0;//此处排除已进入的点
			for (int j = 0; j < vexnum_; j++)
				if (edges_[k][j] < miniedges[j].lowcost && miniedges[j].lowcost != 0 && edges_[k][j] != 0)//注意!=0
				{
					miniedges[j].adjvex = k;
					miniedges[j].lowcost = edges_[k][j];
				}
		}
	}
	void Kruskal()
	{
		vector<EdgeType<T>> tree;
		Kruskal(tree);
		for (int i = 0; i < tree.size(); i++)
			cout << tree[i].head << "," << tree[i].tail << endl;
	}
	void Dijkstra(int v)
	{
		vector<int> path(vexnum_);
		vector<int> dist(vexnum_);
		Dijkstra(v, path, dist);
		int n = path.size() - 1;
		vector<int> print;
		print.push_back(n);
		while (n != v && n > 0)
		{
			n = path[n];
			print.push_back(n);
		}
		for (int i = print.size() - 1; i > 0; i--)
			cout << print[i] << "->";
		cout << print[0];
	}
	void Floyd(int i, int j)
	{
		vector<vector<int>> path(vexnum_);
		vector<vector<int>> D(vexnum_);
		for (int k = 0; k < vexnum_; k++)
			path[k].resize(vexnum_), D[k].resize(vexnum_);
		Floyd(path, D);
		cout << i << "->";
		int k = path[i][j];
		while (k != -1 && k != j)
		{
			cout << k << "->";
			k = path[k][j];
		}
		cout << j;
	}
};
