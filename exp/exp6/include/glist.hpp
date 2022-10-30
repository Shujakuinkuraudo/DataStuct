#pragma once
#include "head.h"
enum GlistNodeType {ATOM,LIST};
template<class T>
class GlistNode;
template <class T>
bool _Equal(GlistNode<T>* l1,GlistNode<T>* l2) 
{
	if(l1==nullptr || l2==nullptr){
		if(l1!=l2)
			return false;
		else
			return true;
	}
	if(l1->type_ == ATOM || l2->type_ == ATOM)
	{
		if(l1->type_ != l2->type_)
			return false;
		if(l1->data_ != l2->data_) 
			return false;
	}
	if(l1->type_ == LIST || l2->type_ == LIST)
		if(l1->type_ == l2->type_)
			return _Equal(l1->sublist_,l2->sublist_);
	if(!_Equal(l1->next_,l2->next_)) return false;
	return true;

}
template<class T>
class GlistNode
{
	public:
		GlistNodeType type_;
		union
		{
			T data_;
			GlistNode<T> * sublist_;
		};
		GlistNode<T> * next_;
		GlistNode(){};
		GlistNode(GlistNodeType type):type_(type){};
};

template <class T>
class Glist{
	GlistNode<T> * head_;

	GlistNode<T> * CreateFromString(string& s,int &idx)
	{
		if(idx>=s.length()) return nullptr;
		GlistNode<T> * temp = new GlistNode<T>;
		while(s[idx] == ' ' || s[idx] == ',') idx++;
		if(s[idx]=='(')
		{
			temp->type_ = LIST;
			temp->sublist_ = CreateFromString(s,++idx);
			temp->next_ = CreateFromString(s,++idx);
			return temp;
		}
		else if(s[idx]==')')
		{
			idx++;
			return nullptr;
		}
		T t = s[idx];
		temp->type_ = ATOM;
		temp->data_ = t;
		temp->next_ = CreateFromString(s,++idx);
		return temp;
	}
	void print(ostream& out,GlistNode<T> * start) const
	{
		while(start)
		{
			if (start->type_ == LIST)
			{
				out << "(";
				print(out,start->sublist_);
				out << ")";
			}
			if(start-> type_ == ATOM)
				out << start->data_;
			if(start->next_)
				out << ",";
			start = start->next_;
		}
	}
	int _Depth(GlistNode<T> * head) const
	{
		int max_depth=-1;
		while(head)
		{
			if(head->type_==LIST)
				max_depth = max(max_depth,_Depth(head->sublist_));
			else
				max_depth=max(max_depth,0);
			head = head->next_;
		}
		return max_depth+1;
	}
	int _Length(GlistNode<T> * head) const
	{
		int res=0;
		while(head)
		{
			res++;
			head = head->next_;
		}
		return res;
	}
	void _Sub(T a,T target,GlistNode<T> * head)
	{
		while(head)
		{
			if(head->type_ == LIST)
				_Sub(a,target,head->sublist_);
			else if(head->data_ == a)
					head -> data_ = target;
			head = head -> next_;
		}
	}
	//GlistNode<T> *  _Del(T a,GlistNode<T> * head)
	//{
		//auto start = head;
		//while(start && start->type_ == ATOM && start->data_ == a)
		//{
			//auto temp = start;
			//start = start->next_;
			//delete temp;
		//}
		//if(start->type_ == LIST)
			//start->sublist_ = _Del(a,start->sublist_);
		//auto front = start, rear = start;
		//if(! front -> next_)
			//return start;
		//front = front->next_;
		//while(front)
		//{
			//if(front->type_==LIST)
				//front->sublist_ = _Del(a,front->sublist_);
			//if(front->data_ == a)
			//{
				//auto temp = front;
				//rear -> next_ = front -> next_;
				//front = front ->next_;
				//delete temp;
			//}
			//if(front)
				//front = front -> next_;
			//rear = rear -> next_;

		//}
		//return start;
	//}
	GlistNode<T> *  _Del(T a,GlistNode<T> * head)
	{
		GlistNode<T> *  falsehead = new GlistNode<T>();
		falsehead -> next_ = head;
		GlistNode<T> * front = falsehead->next_,rear = falsehead;
		while(front)
		{
			if(front->type_ == LIST )
				front->sublist_ = _Del(a,front->sublist_);
			else if(front->data_ == a)
			{
				GlistNode<T> *  temp = front;
				rear -> next_ = front = front -> next_;
				delete temp;
				continue;
			}
			front = front->next_;
			rear = rear->next_;
		}
		GlistNode<T> *  res = falsehead->next_;
		delete falsehead;
		return res;
	}

	public:
	Glist(string &s){
		int idx = 0;
		head_ = CreateFromString(s,idx);
	};
	friend ostream& operator<<(ostream& out,const Glist<T>& g)
	{
		g.print(out,g.head_);
		return out;
	}
	int Depth() const
	{
		return _Depth(head_)-1;
	}
	int Length()
	{
		return _Length(head_->sublist_);
	}
	void Sub(T a,T target)
	{
		_Sub(a,target,head_);
	}
	void Del(T a)
	{
		head_ = _Del(a,head_);
	}
	template<class U>
	friend	bool _Equal(Glist<U>* l1,Glist<U>* l2);
	//{
		//if(l1==nullptr || l2==nullptr){
			//if(l1!=l2)
				//return false;
			//else
				//return true;
		//}
		//if(l1->type_ == ATOM || l2->type_ == ATOM)
		//{
			//if(l1->type_ != l2->type_)
				//return false;
			//if(l1->data_ != l2->data_) 
				//return false;
		//}
		//if(l1->type_ == LIST || l2->type_ == LIST)
			//if(l1->type_ == l2->type_)
				//return _Equal(l1->sublist_,l2->sublist_);
		//if(!_Equal(l1->next_,l2->next_)) return false;
		//return true;

	//}
	bool operator==(Glist<T>& t2)
	{
		return _Equal<T>(head_,t2.head_);
	}
};
