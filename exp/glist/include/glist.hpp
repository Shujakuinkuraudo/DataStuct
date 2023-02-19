#pragma once
#include "head.h"
enum GlistNodeType
{
	ATOM,
	LIST
};
template <class T>
class GlistNode
{
public:
	GlistNodeType type_;
	union
	{
		T data_;
		GlistNode<T> *sublist_;
	};
	GlistNode<T> *next_;
	GlistNode(){};
	GlistNode(GlistNodeType type) : type_(type){};
};

template <class T>
class Glist
{
	GlistNode<T> *__head_;
	GlistNode<T> *__CreateFromString(string &s, int &idx);
	void __Print(ostream &out, GlistNode<T> *start) const;
	int __Depth(GlistNode<T> *head) const;
	int __Length(GlistNode<T> *head) const;
	void __Sub(T a, T target, GlistNode<T> *head);
	GlistNode<T> *__Del(T a, GlistNode<T> *head);
	template <class U>
	friend bool __Equal(Glist<U> *l1, Glist<U> *l2);

public:
	Glist(string &s);
	int Depth() const;
	int Length();
	void Sub(T a, T target);
	void Del(T a);
	bool operator==(Glist<T> &t2);
	friend ostream &operator<<(ostream &out, const Glist<T> &g)
	{
		g.__Print(out, g.__head_);
		return out;
	}
};

#include "glist.ipp"