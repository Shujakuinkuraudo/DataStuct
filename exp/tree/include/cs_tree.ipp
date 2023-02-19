
// ##############
template <class T>
void CSTree<T>::__RootLeafPath(CSNode<T> *root, vector<T> &path)
{
	if (!root->firstchild_)
	{
		for (auto p : path)
			cout << p << " ";
		cout << endl;
		return;
	}
	path.push_back(root->index_);
	for (auto iter = root->firstchild_; iter; iter = iter->nextsibling_)
		__RootLeafPath(iter, path);
	path.pop_back();
}
template <class T>
void CSTree<T>::RootLeafPath()
{
	vector<T> path;
	__RootLeafPath(__root_, path);
}
// ##################
template <class T>
CSTree<T>::CSTree(vector<Couple<T>> &ps)
{
	if (ps.empty())
	{
		__root_ = nullptr;
		return;
	}
	__root_ = new CSNode<T>;
	__root_->index_ = ps[0].parent;
	_for(i, 0, ps.size())
		__Insert(ps[i]);
}
template <class T>
void CSTree<T>::__Insert(Couple<T> &pc)
{
	CSNode<T> *temp = new CSNode<T>;
	temp->index_ = pc.child;
	CSNode<T> *parent = __Search(__root_, pc.parent);
	if (!parent->firstchild_)
		parent->firstchild_ = temp;
	else
	{
		auto iter = parent->firstchild_;
		while (iter->nextsibling_)
			iter = iter->nextsibling_;
		iter->nextsibling_ = temp;
	}
}
template <class T>
CSNode<T> *CSTree<T>::__Search(CSNode<T> *root, T index)
{
	if (!root)
		return nullptr;
	if (root->index_ == index)
		return root;
	auto p = __Search(root->firstchild_, index);
	if (p)
		return p;
	return __Search(root->nextsibling_, index);
}
// ##################
template <class T>
void CSTree<T>::__DeleteNode(CSNode<T> *&root)
{
	if (!root)
		return;
	__DeleteNode(root->firstchild_);
	__DeleteNode(root->nextsibling_);
	delete root;
	root = nullptr;
}
template <class T>
CSTree<T>::~CSTree()
{
	__DeleteNode(__root_);
}
// ##############
template <class T>
void CSTree<T>::__PreTraverse(CSNode<T> *root)
{
	if (!root)
		return;
	cout << root->index_ << " ";
	__PreTraverse(root->firstchild_);
	__PreTraverse(root->nextsibling_);
}
template <class T>
void CSTree<T>::PreTraverse()
{
	__PreTraverse(__root_);
}
// ##############
template <class T>
void CSTree<T>::__PostTraverse(CSNode<T> *root)
{
	if (!root)
		return;
	__PostTraverse(root->firstchild_);
	cout << root->index_ << " ";
	__PostTraverse(root->nextsibling_);
}
template <class T>
void CSTree<T>::PostTraverse()
{
	__PostTraverse(__root_);
}
// ##############
template <class T>
void CSTree<T>::__SetDegree(CSNode<T> *root)
{
	if (!root)
		return;
	root->degree_ = 0;
	for (auto iter = root->firstchild_; iter; iter = iter->nextsibling_)
	{
		root->degree_++;
		__SetDegree(iter);
	}
}
template <class T>
void CSTree<T>::SetDegree()
{
	__SetDegree(__root_);
}
// ##############
template <class T>
int CSTree<T>::__Height(CSNode<T> *root)
{
	if (!root)
		return 0;
	int max_height = 0;
	for (root = root->firstchild_; root; root = root->nextsibling_)
		max_height = max(max_height, __Height(root));
	return ++max_height;
}
template <class T>
int CSTree<T>::Height()
{
	return __Height(__root_);
}