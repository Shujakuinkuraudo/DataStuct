template<class T>
void CSTree<T>::_Insert(Couple &head)
{
	CSNode<T>* child = new CSNode<T>;
	child->data_ = head.child;
	child->firstchild_ = child->nextsibling_ = nullptr;
	CSNode <T>* parent = _Search(root_, head.parent);
	if (parent->firstchild_ == nullptr)
		parent->firstchild_ = child;
	else
	{
		for (parent = parent->firstchild_; parent->nextsibling_; parent = parent->nextsibling_);
		parent->nextsibling_ = child;
	}
}
	template<class T>
CSNode<T>* CSTree<T>::_Search(CSNode<T>* head, T e)
{
	if (head == nullptr)
		return nullptr;
	if (head->data_ == e)
		return head;
	CSNode<T>* q = _Search(head->firstchild_, e);
	if (q)return q;
	return _Search(head->nextsibling_, e);
}
	template<class T>
void CSTree<T>::_Free(CSNode<T>* head)
{
	if (head == nullptr)
		return;
	_Free(head->firstchild_);
	_Free(head->nextsibling_);
	delete head;
}
	template<class T>
void CSTree<T>::_TraverseByPre(CSNode<T>* head)
{
	if (head == nullptr)
		return;
	cout << head->data_ << " ";
	_TraverseByPre(head->firstchild_);
	_TraverseByPre(head->nextsibling_);
}
	template<class T>
void CSTree<T>::_TraverseByLst(CSNode<T>* head)
{
	if (head == nullptr)
		return;
	_TraverseByPre(head->firstchild_);
	cout << head->data_ << " ";
	_TraverseByPre(head->nextsibling_);
}
	template<class T>
void CSTree<T>::_degree(CSNode<T>* head)
{
	if (head == nullptr)
		return;
	head->degree_ = 0;
	CSNode<T>* child = head->firstchild_;
	for (; child; child = child->nextsibling_)
		head->degree_++;
	_degree(head->firstchild_);
	_degree(head->nextsibling_);
}
	template<class T>
int CSTree<T>::_Height(CSNode<T>* head)
{
	if (head == nullptr)
		return 0;
	int max = 0;
	for (head = head->firstchild_; head; head = head->nextsibling_)
	{
		int height = _Height(head);
		if (height > max)
			max = height;
	}
	return ++max;
}
	template<class T>
void CSTree<T>::rootLeafPath(CSNode<T>* head, vector<T>& path)
{
	while (head)
	{
		path.push_back(head->data_);
		if (head->firstchild_)
			root_LeafPath(head->firstchild_, path);
		else
		{
			for (vector<char>::iterator iter = path.begin(); iter != path.end(); iter++)
				cout << *iter << " ";
			cout << endl;
		}
		path.pop_back();
		head = head->nextsibling_;
	}
}
	template<class T>
CSTree<T>::CSTree(vector<Couple>& ps)
{
	if (ps.empty())
	{
		root_ = nullptr;
		return;
	}
	root_ = new CSNode<T>;
	root_->data_ = ps[0].parent;
	root_->firstchild_ = root_->nextsibling_ = nullptr;
	int len = ps.size();
	for (int i = 0; i < len; i++)
		_Insert(ps[i]);
}
	template<class T>
CSTree<T>::~CSTree()
{
	_Free(root_);
}
	template<class T>
void CSTree<T>::TraverseByPre()
{
	_TraverseByPre(root_);
}
	template<class T>
void CSTree<T>::TraverseByLst()
{
	_TraverseByLst(root_);
}
	template<class T>
void CSTree<T>::Degree()
{
	Degree(root_);
}
	template<class T>
int CSTree<T>::Height()
{
	return Height(root_);
}
	template<class T>
void CSTree<T>::rootLeafPath()
{
	vector<T> path;
	root_LeafPath(root_, path);
}
