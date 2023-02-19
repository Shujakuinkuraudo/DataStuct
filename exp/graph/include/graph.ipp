template <class T>
void MGraph<T>::__DFS(int v, vector<bool> &visited) const
{
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < vexnum_; i++)
		if (!visited[i] && edges_[v][i] == 1)
			__DFS(i, visited);
}
template <class T>
void MGraph<T>::CreateGraph(Gtype t, vector<T> &v, vector<EdgeType<T>> &e)
{
	vexnum_ = v.size();
	edgenum_ = e.size();
	type_ = t;

	vexs_.resize(vexnum_);
	edges_.resize(vexnum_);
	_for(i, 0, vexnum_) edges_[i].resize(vexnum_);
	_for(i, 0, vexnum_) vexs_[i] = v[i];
	switch (type_)
	{
	case (UG):
	case (DG):
	{
		for (auto &x : edges_)
			fill(x.begin(), x.end(), 0);
		switch (type_)
		{
		case (UG):
			for (auto E : e)
				edges_[E.head][E.tail] = edges_[E.tail][E.head] = 1;
			break;
		case (DG):
			for (auto E : e)
				edges_[E.head][E.tail] = 1;
			break;
		}
		break;
	}
	case (UN):
	case (DN):
	{
		for (auto &x : edges_)
			fill(x.begin(), x.end(), INF);
		_for(i, 0, vexnum_) edges_[i][i] = 0;
		switch (type_)
		{
		case (UN):
			for (auto E : e)
				edges_[E.head][E.tail] = edges_[E.tail][E.head] = E.cost;
			break;
		case (DN):
			for (auto E : e)
				edges_[E.head][E.tail] = E.cost;
			break;
		}
		break;
	}
	}
}

template <class T>
vector<pair<int, int>> MGraph<T>::Kruskal() const
{
	struct pqEdgeType
	{
		bool operator()(const EdgeType<T> &e1, const EdgeType<T> &e2)
		{
			return e1.cost > e2.cost;
		}
	};
	vector<pair<int, int>> tree;
	vector<EdgeType<T>> graph;
	int cnt = 0;
	vector<int> color(vexnum_, 0);
	priority_queue<EdgeType<T>, vector<EdgeType<T>>, pqEdgeType> pq;
	for (int i = 0; i < vexnum_; i++)
		for (int j = 0; j < vexnum_; j++)
			if (edges_[i][j] != 0 && edges_[i][j] != INF)
				pq.push(EdgeType<T>(i, j, edges_[i][j]));
	while (!pq.empty())
	{
		EdgeType<T> now = pq.top();
		pq.pop();
		if (color[now.head] == color[now.tail] && color[now.head] != 0)
			continue;
		int c1 = color[now.head], c2 = color[now.tail];
		int c = max(c1, c2);
		if (c)
		{
			if (c1 == 0)
				color[now.head] = c;
			else if (c2 == 0)
				color[now.tail] = c;
			else
				_for(i, 0, vexnum_) if (color[i] == c1 || color[i] == c2) color[i] = c;
		}
		else
			color[now.head] = color[now.tail] = ++cnt;
		if (now.head != now.tail)
			tree.push_back(make_pair(now.head, now.tail));
	}
	for (auto x : tree)
		cout << x.first << " " << x.second << endl;
	return tree;
}
template <class T>
void MGraph<T>::DFS() const
{
	vector<bool> visited(vexnum_, false);
	for (int i = 0; i < vexnum_; i++)
		if (!visited[i])
			__DFS(i, visited);
}
template <class T>
void MGraph<T>::BFS() const
{
	queue<int> q;
	vector<bool> visited(vexnum_, false);
	_for(i, 0, vexnum_)
	{
		if (!visited[i])
		{
			q.push(i);
			visited[i] = true;
			cout << i << " ";
			while (q.size())
			{
				int now = q.front();
				q.pop();
				_for(j, 0, vexnum_)
				{
					if (edges_[now][j] && edges_[now][j] != INF && !visited[j])
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
template <class T>
vector<pair<int, int>> MGraph<T>::Prim(int v) const
{
	struct Edge
	{
		int adjvex = -1;
		T lowcost = INF;
		const bool operator<(const Edge &other) const
		{
			return lowcost < other.lowcost;
		}
	};
	vector<bool> in_tree(vexnum_);
	vector<Edge> minedges(vexnum_);
	minedges[v].lowcost = 0;
	_for(i, 0, vexnum_)
	{
		int index = 0;
		int Emin = INF;
		_for(i, 0, vexnum_) if (minedges[i].lowcost < Emin && !in_tree[i])
		{
			index = i;
			Emin = minedges[i].lowcost;
		}
		in_tree[index] = true;
		_for(i, 0, vexnum_) if (edges_[index][i] && edges_[index][i] != INF && edges_[index][i] < minedges[i].lowcost)
		{
			minedges[i].adjvex = index;
			minedges[i].lowcost = edges_[index][i];
		}
	}
	vector<pair<int, int>> tree;
	_for(i, 0, vexnum_) if (minedges[i].adjvex != -1)
		tree.push_back(make_pair(minedges[i].adjvex, i));
	for (auto x : tree)
		cout << x.first << " " << x.second << endl;
	return tree;
}
template <class T>
pair<vector<int>, vector<pair<int, int>>> MGraph<T>::Dijkstra(int v) const
{
	struct Edge
	{
		int adjvex = -1;
		T lowcost = INF;
		const bool operator<(const Edge &other) const
		{
			return lowcost < other.lowcost;
		}
	};
	vector<bool> in_tree(vexnum_);
	vector<Edge> minedges(vexnum_);
	minedges[v].lowcost = 0;
	_for(i, 0, vexnum_)
	{
		int index = 0;
		int Emin = INF;
		_for(i, 0, vexnum_) if (minedges[i].lowcost < Emin && !in_tree[i])
		{
			index = i;
			Emin = minedges[i].lowcost;
		}
		in_tree[index] = true;
		_for(i, 0, vexnum_) if (edges_[index][i] && edges_[index][i] != INF && Emin + edges_[index][i] < minedges[i].lowcost)
		{
			minedges[i].adjvex = index;
			minedges[i].lowcost = Emin + edges_[index][i];
		}
	}
	vector<pair<int, int>> tree;
	vector<int> dist;
	_for(i, 0, vexnum_) if (minedges[i].adjvex != -1)
		tree.push_back(make_pair(minedges[i].adjvex, i));
	for (auto x : tree)
		cout << x.first << " " << x.second << endl;
	for (auto x : minedges)
	{
		dist.push_back(x.lowcost);
		cout << x.lowcost << " ";
	}
	return make_pair(dist, tree);
}
template <class T>
pair<vector<vector<int>>, vector<vector<int>>> MGraph<T>::Floyd() const
{
	vector<vector<int>> path(vexnum_), D(vexnum_);
	_for(i, 0, vexnum_)
		path[i] = D[i] = vector<int>(vexnum_);
	_for(i, 0, vexnum_)
		_for(j, 0, vexnum_)
	{
		D[i][j] = edges_[i][j];
		path[i][j] = D[i][j] != INF ? j : -1;
	}
	_for(k, 0, vexnum_)
		_for(i, 0, vexnum_)
			_for(j, 0, vexnum_) if (D[i][k] + D[k][j] < D[i][j])
	{
		D[i][j] = D[i][k] + D[k][j];
		path[i][j] = path[i][k];
	}
	cout << "path:" << endl;
	for (auto x : path)
	{
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}
	cout << "D:" << endl;
	for (auto x : D)
	{
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}
	return make_pair(path, D);
}