#include "include/head.h"
template<class T>
struct Node
{
	T data;
	Node<T*> next;
};

template<class T>
class CircularLinkQueue
{
	Node<T> *rear_;
	public:
	CircularLinkQueue(Node<T> *rear):rear_(rear){};
	CircularLinkQueue()
	{
		rear_ = new Node<T>;
		rear_ -> next = rear_;
	}
	void ClearLinkList()
	{
		if (rear_->next == rear_)
			return ;
		Node<T>* front = rear_->next;
		Node<T>* pre = rear_->next;
		rear_ -> next = rear_;
		while(front != rear_)
		{
			front = front -> next;
			delete pre;
			pre = front;
		}
	}
	void Push(T x)
	{
		Node<T>* temp = new Node<T>(x);
		temp -> next = rear_ -> next;
		rear_ -> next = temp;
		rear_ = temp;
	}
	T Pop()
	{
		if(rear_ -> next == rear_ )
		{
			cerr << "underflow" << endl;
			exit(1);

		}
		Node<T>* head = rear_->next;
		if(head -> next == rear_ )
		{
			T ans = rear_ -> data;
			head -> next = head;
			delete rear_;
			rear_ = head;
			return ans;
		}
		T ans = head -> next -> data;
		Node<T>* temp = head -> next;
		head -> next = temp -> next;
		delete temp;
		return ans;
	}
};

template<class T,int m>
class CircularArrayQueueFlag
{
	T data_[m];
	bool flag_;
	int front_;
	int rear_;
	public:
	CircularArrayQueueFlag(){
		flag_ = 0;
		front_ = 0;
		rear_ = 0;
	}
	void Push(T x)
	{
		if(flag_)
		{
			cerr << "overflow" << endl;
			exit(1);
		}
		data_[rear_++] = x;
		rear_ %= m;
		if (rear_ == front_)
			flag_ = 1;
	}
	T Pop()
	{
		if (!flag_ && front_==rear_)
		{
			cerr << "underflow" << endl;
			exit(1);
		}
		T ans = data_[front_++];
		front_ %= m;
		flag_ = 0;
		return ans;
	}
};

template<class T,int m>
class CircularArrayQueueNum
{
	T data_[m];
	int length_;
	int front_;
	int rear_;
	public:
	CircularArrayQueueNum(){
		length_ = 0;
		front_ = 0;
		rear_ = 0;
	}
	void Push(T x)
	{
		if(length_ == m)
		{
			cerr << "overflow" << endl;
			exit(1);
		}
		data_[rear_++] = x;
		rear_ %= m;
		length_++;
	}
	T Pop()
	{
		if (length_ == 0)
		{
			cerr << "underflow" << endl;
			exit(1);
		}
		T ans = data_[front_++];
		front_ %= m;
		length_--;
		return ans;
	}
};

template <class T,int m>
class Stack{};

template<class T,int m>
class CircularArrayQueueTwoStack
{
	Stack<T,m> in_s1_;
	Stack<T,m> out_s2_;
	bool in_;

	public:
	CircularArrayQueueTwoStack(){
		in_ = 1;
	}
	void Push(T x)
	{
		if(in_)
		{
			if(in_s1_.Size() == m)
			{
				cerr << "overflow" << endl;
				exit(1);
			}
			in_s1_.Push(x);
		}
		else if(! in_)
		{
			while(!out_s2_.Empty())
				in_s1_.Push(out_s2_.Pop());
			in_ = true;
			Push(x);
		}

	}
	T Pop()
	{
		if(! in_)
		{
			if(out_s2_.Empty())
			{
				cerr << "underflow" << endl;
				exit(1);
			}
			return out_s2_.Pop();
		}
		else if(in_)
		{
			while(!in_s1_.Empty())
				out_s2_.Push(in_s1_.Pop());
			in_ = false;
			Pop();
		}
	}
};

int main()
{
	return 0;
}
