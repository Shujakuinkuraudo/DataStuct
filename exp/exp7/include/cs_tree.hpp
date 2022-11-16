#pragma once
#include "head.h"
using namespace std;

struct Couple
{
	char parent, child;
};
template<class T>
struct CSNode
{
	T data_;
	CSNode<T>* firstchild_, * nextsibling_;
	int degree_;
};
template<class T>
class CSTree
{
	CSNode<T>* root_;
	void _Insert(Couple &head);
	CSNode<T>* _Search(CSNode<T>* head, T e);
	void _Free(CSNode<T>* head);
	void _TraverseByPre(CSNode<T>* head);
	void _TraverseByLst(CSNode<T>* head);
	void _degree(CSNode<T>* head);
	int _Height(CSNode<T>* head);
	void rootLeafPath(CSNode<T>* head, vector<T>& path);
	public:
	CSTree(vector<Couple>& ps);
	~CSTree();
	void TraverseByPre();
	void TraverseByLst();
	void Degree();
	int Height();
	void rootLeafPath();
};
#include "cs_tree.ipp"
