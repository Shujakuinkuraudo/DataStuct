#pragma once
#include "head.h"
template <class T>
class BiTree;
template <class T>
class BiNode
{
public:
	BiNode<T> *lchild_ = nullptr, *rchild_ = nullptr;
	T data_;
	BiNode(T data) : data_(data){};
	BiNode(){};
};
template <class T>
class BiTree
{
	BiNode<T> *__root_;
	void __PreCreate(string &s, BiNode<T> *&root, int &index);
	void __PreTraverse(BiNode<T> *root);
	void __InTraverse(BiNode<T> *root);
	void __PostTraverse(BiNode<T> *root);
	void __LineTraverse(BiNode<T> *root);
	BiNode<T> *__CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);
	int __CountDouble(BiNode<T> *root);
	int __CountLeaf(BiNode<T> *root);
	int __CountSingle(BiNode<T> *root);
	int __Height(BiNode<T> *root);
	void __SwitchChild(BiNode<T> *root);
	int __Balance(BiNode<T> *root);
	int __CountLeafK(BiNode<T> *root, int level, int k);
	void __LeafPaths(BiNode<T> *root, vector<T> &path);
	BiNode<T> *__CommonAncestor(BiNode<T> *root, BiNode<T> *node1, BiNode<T> *node2);
	void __FindXAncestors(BiNode<T> *root, vector<T> &path, T X, bool &find);
	void __LinkLeaf(BiNode<T> *root, BiNode<T> *&link_root, BiNode<T> *&link_iter);
	void __CountWidth(BiNode<T> *root, int level, vector<int> &v);
	void __DeleteNode(BiNode<T> *&root);

public:
	BiTree();
	~BiTree();
	void PreCreate(string s);
	void PreTraverse();
	void InTraverse();
	void PostTraverse();
	void LineTraverse();
	int CountDouble();
	int CountLeaf();
	int CountSingle();
	void SwitchChild();
	int Height();
	bool IsCompleteBinaryTree();
	int MaxWidth();
	void CreateByPreMid(vector<T> &pre, vector<T> &mid);
};
#include "bi_tree.ipp"
