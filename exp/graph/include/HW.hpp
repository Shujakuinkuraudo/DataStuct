#include "head.h"
template <class T>
class ALGraph
{
	struct EdgeNode
	{
		int adjvex;
		EdgeNode *nextedge;
	};
	struct VexNode
	{
		T data;
		EdgeNode *firstedge;
	};
	vector<VexNode> adjlist;
	int vexnum;

	void DFS(int now, vector<int> &visited)
	{
		cout << adjlist[now].data << " ";
		visited[now] = true;
		for (EdgeNode *to = adjlist[now].firstedge; to; to = to->nextedge)
			if (!visited[to->adjvex])
				DFS(to->adjvex, visited);
	}
	bool BFS(int i, int j)
	{
		queue<int> q;
		vector<bool> visited(vexnum, false);
		q.push(i);
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			if (now == j)
				return true;
			visited[now] = true;
			for (EdgeNode *to = adjlist[now].firstedge; to; to = to->nextedge)
				if (!visited[to->adjvex])
					q.push(to->adjvex);
		}
		return false;
	}
	void __BackTrack_Lenk(bool &find, int now, vector<int> &visited, int now_length, int k, int i, int j)
	{
		if (now == j && now_length == k)
			find = true;
		if (find || now_length >= k)
			return;

		visited[now] = true;
		for (EdgeNode *to = adjlist[now].firstedge; to; to = to->nextedge)
			if (!visited[to->adjvex])
				BackTrack_Lenk_(find, to->adjvex, visited, now_length + 1, k, i, j);
		visited[now] = false;
	}
	bool Lenk(int k, int i, int j)
	{
		bool ans = false;
		vector<bool> visited(vexnum, false);
		__BackTrack_Lenk(ans, i, visited, 0, k, i, j);
		return ans;
	}
};
template <class T>
class MGraph
{
	vector<vector<T>> edges;
	vector<T> vexs;
	int vexnum;
	void __DFS_DGFindloop(bool &find, stack<int> &vex_S, vector<int> &visit_state, int now, vector<int> &v)
	{
		// unvisited = -1 visiting = 0 visited = 1 loop_start = 2
		if (visit_state[now] == 0)
		{
			find = 1;
			visit_state[i] = 2;
			return;
		}
		if (find || visit_state[now] == 1)
			return;
		visit_state[now] = 0;
		v[now] = 1;
		vex_S.push(now);
		for (int i = 0; i < vexnum; i++)
			if (edges[now][i])
				__DFS_DGFindloop(find, vex_S, visit_state, i, v);
		vex_S.pop();
		visit_state[now] = 1;
	}
	bool DFS_DGFindloop()
	{
		bool find = false;
		stack<int> vex_S;
		vector<int> v(vexnum, 0);
		for (int i = 0; i < vexnum; i++)
		{
			if (v[i])
				continue;
			vector<int> visit_state(vexnum, -1);
			__DFS_DGFindloop(find, vex_S, visit_state, i, v);
			if (find)
			{
				while (visit_state[vex_S.top()] != 2)
				{
					cout << vex_S.top() << " ";
					vex_S.pop();
				}
				cout << vex_S.top();
				break;
			}
		}
		return find;
	}

	void __DFS_UGFindloop(bool &find, stack<int> &vex_S, vector<int> &visit_state, int now, vector<int> &v, int father)
	{
		// unvisited = -1 visiting = 0 visited = 1 loop_start = 2
		if (visit_state[now] == 0)
		{
			find = 1;
			visit_state[i] = 2;
			return;
		}
		if (find || visit_state[now] == 1 || now == father)
			return;
		visit_state[now] = 0;
		v[now] = 1;
		vex_S.push(now);
		for (int i = 0; i < vexnum; i++)
			if (edges[now][i])
				__DFS_UGFindloop(find, vex_S, visit_state, i, v, now);
		vex_S.pop();
		visit_state[now] = 1;
	}
	bool DFS_UGFindloop()
	{
		bool find = false;
		stack<int> vex_S;
		vector<int> v(vexnum, 0);
		for (int i = 0; i < vexnum; i++)
		{
			if (v[i])
				continue;
			vector<int> visit_state(vexnum, -1);
			__DFS_UGFindloop(find, vex_S, visit_state, i, v, -1);
			if (find)
			{
				while (visit_state[vex_S.top()] != 2)
				{
					cout << vex_S.top() << " ";
					vex_S.pop();
				}
				cout << vex_S.top();
				break;
			}
		}
		return find;
	}
};