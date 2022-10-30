#pragma once
#include "head.h"
template<class T>
class BiTree;
template<class T>
class BiNode
{
	public:
	BiNode<T> * lchild_,* rchild_;
	T data_;
	BiNode(T data):data_(data){};
};
template<class T>
class BiTree
{
	BiNode<T>* root_;
	void _PreCreate(string s,BiNode<T>* head)
	{

	}
	void _PreTraverse(BiNode<T> * head)
	{
		if(!head) return;
		cout << head->data_ << " ";
		_PreTraverse(head->lchild_);
		_PreTraverse(head->rchild_);
	}
	void _InTraverse(BiNode<T> * head)
	{
		if(!head) return;
		_InTraverse(head->lchild_);
		cout << head->data_ << " ";
		_InTraverse(head->rchild_);
	}
	void _PostTraverse(BiNode<T> * head)
	{
		if(!head) return;
		_PostTraverse(head->lchild_);
		_PostTraverse(head->rchild_);
		cout << head->data_ << " ";
	}
	void _LineTraverse(BiNode<T> * head)
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
	public:
	BiTree()
	{
		root_ = new BiNode<T>();
	}
	void PreCreateFromString(string s)
	{
		_PreCreate(s,root_);
	}
	void PreTraverse()
	{
		_PreTraverse(root_);
	}
	void InTraverse()
	{
		_InTraverse(root_);
	}
	void PostTraverse()
	{
		_PostTraverse(root_);
	}
	void LineTraverse()
	{
		_LineTraverse(root_);
	}

};
