template<class T>
	void BiTree<T>::CreateByPreMid(vector<T>& pre, vector<T>& mid)
	{
		int n = pre.size();
		root_ = CreateByPreMid(pre, mid, 0, 0, n);
	}
		template<class T>
	int BiTree<T>::MaxWidth()
	{
		vector<int> v;
		_CountWidth(root_,0,v);
		int ans = 0;
		for(auto x:v)
			ans = max(ans,x);
		return ans;
	}
		template<class T>
	bool BiTree<T>::IsCompleteBinaryTree()  
	{  
		queue<BiNode<T> *>q;  
		q.push(root_);  
		BiNode<T> *iter=q.front();  
		while (iter)  
		{  
			q.push(iter->_left);  
			q.push(iter->_right);  
			q.pop();  
			iter=q.front();  
		}  
		while(!q.empty())  
		{  
			if(q.front())  
				return false;  
			q.pop();  
		}  
		return true;  
	}  
		template<class T>
	void BiTree<T>::SwitchChild()
	{
		_SwitchChild(root_);
	}
		template<class T>
	int BiTree<T>::Height()
	{
		return _Height(root_);
	}
		template<class T>
	void BiTree<T>::_PreCreate(string& s,BiNode<T>** head,int& index)
	{
		if(index >= s.length())
			return ;
		char temp = s[index++];
		if(temp == '@' )
		{
			delete (*head);
			*head = nullptr;
			return ;
		}
		(*head)->data_ = temp;
		(*head)->lchild_ = new BiNode<T>();
		_PreCreate(s,&((*head)->lchild_),index);
		(*head)->rchild_ = new BiNode<T>();
		_PreCreate(s,&((*head)->rchild_),index);
	}
		template<class T>
	void BiTree<T>::_PreTraverse(BiNode<T> * head)
	{
		if(!head) return;
		cout << head->data_ << " ";
		_PreTraverse(head->lchild_);
		_PreTraverse(head->rchild_);
	}
		template<class T>
	void BiTree<T>::_InTraverse(BiNode<T> * head)
	{
		if(!head) return;
		_InTraverse(head->lchild_);
		cout << head->data_ << " ";
		_InTraverse(head->rchild_);
	}
		template<class T>
	void BiTree<T>::_PostTraverse(BiNode<T> * head)
	{
		if(!head) return;
		_PostTraverse(head->lchild_);
		_PostTraverse(head->rchild_);
		cout << head->data_ << " ";
	}
		template<class T>
	void BiTree<T>::_LineTraverse(BiNode<T> * head)
	{
		queue<BiNode<T> *> q;
		q.push(head);
		while(!q.empty())
		{
			BiNode<T> * temp = q.front();
			q.pop();
			if(temp)
			{
				cout << temp->data_ << " ";
				q.push(temp->lchild_);
				q.push(temp->rchild_);
			}
		}
	}
		template<class T>
	BiNode<T>* BiTree<T>::_CreateByPreMid(vector<T>& pre, vector<T>& mid, int ipre, int imid, int n)
	{
		{
			if (n == 0)
				return nullptr;
			BiNode<T>* head = new BiNode<T>;
			head->data = pre[ipre];
			int i;
			for (i = 0; i < n; i++)
				if (pre[ipre] == mid[imid + i])
					break;
			head->lchild_ = _CreateByPreMid(pre, mid, ipre + 1, imid, i);
			head->rchild_ = _CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
			return head;
		}
	}
		template<class T>
	int BiTree<T>::_CountDouble(BiNode<T> * head)
	{
		if(!head)
			return 0;
		return (head->lchild_ && head->lchild_) + _CountDouble(head->lchild_) + _CountDouble(head->rchild_);
	}
		template<class T>
	int BiTree<T>::_CountLeaf(BiNode<T> * head)
	{
		if(!head)
			return 0;
		return (!head->lchild_ && !head->lchild_) + _CountDouble(head->lchild_) + _CountDouble(head->rchild_);
	}
		template<class T>
	int BiTree<T>::_CountSingle(BiNode<T> * head)
	{
		if(!head)
			return 0;
		return (bool(head->lchild_) ^ bool(head->lchild_)) + _CountDouble(head->lchild_) + _CountDouble(head->rchild_);
	}
		template<class T>
	int BiTree<T>::_Height(BiNode<T>* head)
	{
		{
			if (head == nullptr)
				return 0;
			int left = _Height(head->lchild_);
			int right = _Height(head->rchild_);
			if (left > right)
				return left + 1;
			else return right + 1;
		}
	}
		template<class T>
	void BiTree<T>::_SwitchChild(BiNode<T>* head)
	{
		if (head == nullptr)
			return;
		_SwitchChild(head->lchild_);
		_SwitchChild(head->rchild_);
		swap(head->lchild_, head->rchild_);
	}
		template<class T>
	int BiTree<T>::_Balance(BiNode<T>* head)
	{

		if(!head) 
			return 0 ;
		int left = _Balance(head->lchild_) ;
		int right = _Balance(head->rchild_) ;
		head->balance_ = left-right ;    
		return max(left,right)+1 ;
	}
		template<class T>
	int BiTree<T>::_CountLeaf(BiNode<T> * head , int level, int k)                                         
	{
		if(!head || level>k) 
			return 0;
		if( level==k && !head->lchild_ && !head->rchild_)
			return 1;
		return _CountLeaf(head->lchild_, level+1, k)+_CountLeaf(head->rchild_, level+1, k);
	}
		template<class T>
	void BiTree<T>::_LeafPaths (BiNode<T>* head, vector<T>& path)
	{
		if(!head) return;
		path.push_back(head->data);
		if(!head->lchild_ && !head->rchild_)
		{
			for(auto X:path)
				cout << X << " ";
			cout << endl;
		}
		else{   
			_LeafPaths (head->lchild_, path);
			_LeafPaths (head->rchild_, path);
		}
		path.pop_back();

	}
		template<class T>
	BiNode<T>* BiTree<T>::_CommonAncestor (BiNode<T> *head, BiNode<T>*node1, BiNode<T>*node2)                                        
	{
		if(!head || head==node1 || head==node2)
			return head;
		BiNode<T>* left = _CommonAncestor(head->lchild_, node1, node2);
		BiNode<T>* right = _CommonAncestor(head->rchild_, node1, node2);
		if(!left)
			return right;
		if(!right) 
			return left;
		return head;
	}
		template<class T>
	void BiTree<T>::_FindXAncestors (BiNode<T>* head, vector<T>& path,T X,bool &find)
	{
		if(find || !head) return;
		if(head->data_ == X )
		{
			find=1;
			if(head->lchild_ || head->rchild_)
			{
				for(auto x:path)
					cout << x << " ";
				cout << endl;
			}
			return ;
		}
		path.push_back(head->data);
		_LeafPaths (head->lchild_, path,find);
		_LeafPaths (head->rchild_, path,find);
		path.pop_back();
	}
		template<class T>
	void BiTree<T>::_LinkLeaf(BiNode<T> *head,BiNode<T>** link_head,BiNode<T>** link_iter)
	{
		if(!head) return ;
		_LinkLeaf(head->lchild_,link_head,link_iter);
		if (!head->lchild_ && !head->rchild_) {
			if (*link_head==nullptr) {
				*link_head = *link_iter = head;
			}
			else {
				*link_iter = (*link_iter)->rchild_ = head;
			}
		}
		_LinkLeaf(head->rchild_,link_head,link_iter);
		(*link_iter)->rchild_ = nullptr;
	}
		template<class T>
	void BiTree<T>::_CountWidth(BiNode<T>* head,int level,vector<int> &v)
	{
		if(v.size() == level) v.push_back(0);
		v[level]++;
		_CountWidth(head->lchild_,level+1,v);
		_CountWidth(head->rchild_,level+1,v);
	}
		template<class T>
	BiTree<T>::BiTree()
	{
		root_ = new BiNode<T>();
	}
		template<class T>
	void BiTree<T>::PreCreateFromString(string s)
	{
		int index=0;
		_PreCreate(s,&root_,index);
	}
		template<class T>
	void BiTree<T>::PreTraverse()
	{
		_PreTraverse(root_);
	}
		template<class T>
	void BiTree<T>::InTraverse()
	{
		_InTraverse(root_);
	}
		template<class T>
	void BiTree<T>::PostTraverse()
	{
		_PostTraverse(root_);
	}
		template<class T>
	void BiTree<T>::LineTraverse()
	{
		_LineTraverse(root_);
	}
		template<class T>
	int BiTree<T>::CountDouble()
	{
		return _CountDouble(root_);
	}
		template<class T>
	int BiTree<T>::CountLeaf()
	{
		return CountLeaf(root_);
	}
		template<class T>
	int BiTree<T>::CountSingle()
	{
		return CountSingle(root_);
	}
