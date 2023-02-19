#pragma once
#include "head.h"
using namespace std;

template <class T>
struct Couple
{
	T parent, child;
};
template <class T>
struct CSNode
{
	T index_;
	CSNode<T> *firstchild_ = nullptr, *nextsibling_ = nullptr;
	int degree_ = 0;
};
template <class T>
class CSTree
{
	CSNode<T> *__root_ = nullptr;
	void __Insert(Couple<T> &root);
	CSNode<T> *__Search(CSNode<T> *root, T index);
	void __DeleteNode(CSNode<T> *&root);
	void __PreTraverse(CSNode<T> *root);
	void __PostTraverse(CSNode<T> *root);
	void __SetDegree(CSNode<T> *root);
	int __Height(CSNode<T> *root);
	void __RootLeafPath(CSNode<T> *root, vector<T> &path);

public:
	CSTree(vector<Couple<T>> &ps);
	~CSTree();
	void PreTraverse();
	void PostTraverse();
	void SetDegree();
	int Height();
	void RootLeafPath();
};