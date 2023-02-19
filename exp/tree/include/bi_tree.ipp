//===============
template <class T>
BiNode<T> *BiTree<T>::__CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n)
{
	if (!n)
		return nullptr;
	BiNode<T> *root = new BiNode<T>;
	root->data = pre[ipre];
	int i;
	for (i = 0; i < n; i++)
		if (pre[ipre] == mid[imid + i])
			break;
	root->lchild_ = __CreateByPreMid(pre, mid, ipre + 1, imid, i);
	root->rchild_ = __CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
	return root;
}
template <class T>
void BiTree<T>::CreateByPreMid(vector<T> &pre, vector<T> &mid)
{
	int n = pre.size();
	__root_ = __CreateByPreMid(pre, mid, 0, 0, n);
}
//===============
template <class T>
void BiTree<T>::__CountWidth(BiNode<T> *root, int level, vector<int> &v)
{
	if (v.size() == level)
		v.push_back(0);
	v[level]++;
	__CountWidth(root->lchild_, level + 1, v);
	__CountWidth(root->rchild_, level + 1, v);
}
template <class T>
int BiTree<T>::MaxWidth()
{
	vector<int> v;
	__CountWidth(__root_, 0, v);
	int ans = 0;
	for (auto x : v)
		ans = max(ans, x);
	return ans;
}
//===============
template <class T>
bool BiTree<T>::IsCompleteBinaryTree()
{
	queue<BiNode<T> *> q;
	q.push(__root_);
	BiNode<T> *iter = q.front();
	while (iter)
	{
		q.push(iter->_left);
		q.push(iter->_right);
		q.pop();
		iter = q.front();
	}
	while (!q.empty())
	{
		if (q.front())
			return false;
		q.pop();
	}
	return true;
}
//===============
template <class T>
void BiTree<T>::__SwitchChild(BiNode<T> *root)
{
	if (!root)
		return;
	__SwitchChild(root->lchild_);
	__SwitchChild(root->rchild_);
	swap(root->lchild_, root->rchild_);
}
template <class T>
void BiTree<T>::SwitchChild()
{
	__SwitchChild(__root_);
}
//===============
template <class T>
int BiTree<T>::__Height(BiNode<T> *root)
{
	if (!root)
		return 0;
	return max(__Height(root->lchild_), __Height(root->rchild_)) + 1;
}
template <class T>
int BiTree<T>::Height()
{
	return __Height(__root_);
}
//===============
template <class T>
int BiTree<T>::__Balance(BiNode<T> *root)
{

	if (!root)
		return 0;
	int left = __Balance(root->lchild_);
	int right = __Balance(root->rchild_);
	root->balance_ = left - right;
	return max(left, right) + 1;
}
//===============
template <class T>
void BiTree<T>::__LeafPaths(BiNode<T> *root, vector<T> &path)
{
	if (!root)
		return;
	path.push_back(root->data);
	if (!root->lchild_ && !root->rchild_)
	{
		for (auto X : path)
			cout << X << " ";
		cout << endl;
	}
	else
	{
		__LeafPaths(root->lchild_, path);
		__LeafPaths(root->rchild_, path);
	}
	path.pop_back();
}
//===============
template <class T>
BiNode<T> *BiTree<T>::__CommonAncestor(BiNode<T> *root, BiNode<T> *node1, BiNode<T> *node2)
{
	if (!root || root == node1 || root == node2)
		return root;
	BiNode<T> *left = __CommonAncestor(root->lchild_, node1, node2);
	BiNode<T> *right = __CommonAncestor(root->rchild_, node1, node2);
	if (!left)
		return right;
	if (!right)
		return left;
	return root;
}
//===============
template <class T>
void BiTree<T>::__FindXAncestors(BiNode<T> *root, vector<T> &path, T X, bool &find)
{
	if (find || !root)
		return;
	if (root->data_ == X)
	{
		find = 1;
		if (root->lchild_ || root->rchild_)
		{
			for (auto x : path)
				cout << x << " ";
			cout << endl;
		}
		return;
	}
	path.push_back(root->data);
	__LeafPaths(root->lchild_, path, find);
	__LeafPaths(root->rchild_, path, find);
	path.pop_back();
}
//===============
template <class T>
void BiTree<T>::__LinkLeaf(BiNode<T> *root, BiNode<T> *&link_root, BiNode<T> *&link_iter)
{
	if (!root)
		return;
	__LinkLeaf(root->lchild_, link_root, link_iter);
	if (!root->lchild_ && !root->rchild_)
	{
		if (link_root == nullptr)
			link_root = link_iter = root;
		else
			link_iter = link_iter->rchild_ = root;
	}
	__LinkLeaf(root->rchild_, link_root, link_iter);
	link_iter->rchild_ = nullptr;
}
//===============
template <class T>
BiTree<T>::BiTree()
{
	__root_ = new BiNode<T>();
}
//===============
template <class T>
void BiTree<T>::__DeleteNode(BiNode<T> *&root)
{
	if (!root)
		return;
	__DeleteNode(root->lchild_);
	__DeleteNode(root->rchild_);
	delete root;
	root = nullptr;
}
template <class T>
BiTree<T>::~BiTree()
{
	__DeleteNode(__root_);
}
//===============
template <class T>
void BiTree<T>::__PreCreate(string &s, BiNode<T> *&root, int &index)
{
	if (index >= s.length())
		return;
	char temp = s[index++];
	if (temp == '@')
	{
		delete root;
		root = nullptr;
		return;
	}
	root->data_ = temp;
	root->lchild_ = new BiNode<T>();
	__PreCreate(s, root->lchild_, index);
	root->rchild_ = new BiNode<T>();
	__PreCreate(s, root->rchild_, index);
}
template <class T>
void BiTree<T>::PreCreate(string s)
{
	int index = 0;
	__PreCreate(s, __root_, index);
}
//===============
template <class T>
void BiTree<T>::__PreTraverse(BiNode<T> *root)
{
	if (!root)
		return;
	cout << root->data_ << " ";
	__PreTraverse(root->lchild_);
	__PreTraverse(root->rchild_);
}
template <class T>
void BiTree<T>::PreTraverse()
{
	__PreTraverse(__root_);
}
//===============
template <class T>
void BiTree<T>::__InTraverse(BiNode<T> *root)
{
	if (!root)
		return;
	__InTraverse(root->lchild_);
	cout << root->data_ << " ";
	__InTraverse(root->rchild_);
}
template <class T>
void BiTree<T>::InTraverse()
{
	__InTraverse(__root_);
}
//===============
template <class T>
void BiTree<T>::__PostTraverse(BiNode<T> *root)
{
	if (!root)
		return;
	__PostTraverse(root->lchild_);
	__PostTraverse(root->rchild_);
	cout << root->data_ << " ";
}
template <class T>
void BiTree<T>::PostTraverse()
{
	__PostTraverse(__root_);
}
//===============
template <class T>
void BiTree<T>::__LineTraverse(BiNode<T> *root)
{
	queue<BiNode<T> *> q;
	q.push(root);
	while (!q.empty())
	{
		BiNode<T> *temp = q.front();
		q.pop();
		if (temp)
		{
			cout << temp->data_ << " ";
			q.push(temp->lchild_);
			q.push(temp->rchild_);
		}
	}
}
template <class T>
void BiTree<T>::LineTraverse()
{
	__LineTraverse(__root_);
}
//===============
template <class T>
int BiTree<T>::__CountDouble(BiNode<T> *root)
{
	if (!root)
		return 0;
	return (root->lchild_ && root->lchild_) + __CountDouble(root->lchild_) + __CountDouble(root->rchild_);
}
template <class T>
int BiTree<T>::CountDouble()
{
	return __CountDouble(__root_);
}

//===============
template <class T>
int BiTree<T>::__CountLeaf(BiNode<T> *root)
{
	if (!root)
		return 0;
	return (!root->lchild_ && !root->lchild_) + __CountLeaf(root->lchild_) + __CountLeaf(root->rchild_);
}
template <class T>
int BiTree<T>::CountLeaf()
{
	return __CountLeaf(__root_);
}
//===============
template <class T>
int BiTree<T>::__CountLeafK(BiNode<T> *root, int level, int k)
{
	if (!root || level > k)
		return 0;
	if (level == k && !root->lchild_ && !root->rchild_)
		return 1;
	return __CountLeafK(root->lchild_, level + 1, k) + __CountLeafK(root->rchild_, level + 1, k);
}
//===============
template <class T>
int BiTree<T>::__CountSingle(BiNode<T> *root)
{
	if (!root)
		return 0;
	return (bool(root->lchild_) ^ bool(root->lchild_)) + __CountSingle(root->lchild_) + __CountSingle(root->rchild_);
}
template <class T>
int BiTree<T>::CountSingle()
{
	return __CountSingle(__root_);
}
