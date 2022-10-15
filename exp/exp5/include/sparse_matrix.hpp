#pragma once
#include "head.h"
template<class T>
class Triple
{
	public:
	int x,y;
	T data;
	Triple(int x,int y,T data):x(x),y(y),data(data){};
	Triple(){};
	friend const bool operator<(const Triple& t1,const Triple& t2){
		if(t1.x<t2.x)
			return true;
		else if(t1.x==t2.x && t1.y<t2.y)
			return true;
		return false;
	}
	Triple(const Triple<T>& t)
	{
		x = t.x;
		y = t.y;
		data = t.data;
	}
	friend ostream& operator<<(ostream& out,const Triple& t)
	{
		out << t.data;
		return out;
	}
};

template<class T>
class SparseMatrix
{
	vector<Triple<T> > matrix_;
	int n_,m_;
	public:
	SparseMatrix(int n,int m):n_(n),m_(m){};
	SparseMatrix(const SparseMatrix<T>& m){
		matrix_ = m.matrix_;
		m_ = m.m_;
		n_ = m.n_;
	};
	SparseMatrix(){};
	friend istream& operator>>(istream &in,SparseMatrix<T>& m)
	{
		Triple<T> temp;
		in >> temp.x >> temp.y >> temp.data;
		m.matrix_.push_back(temp);
		return in;
	}
	void PushBack(const Triple<T>  data)
	{
		matrix_.push_back(data);
	}
	void RowPushBack(const Triple<T> data)
	{
		Triple<T> last = matrix_[matrix_.size()-1];
		bool allow = 1;
		if(data.x<last.x)
			allow = 0;
		if(data.x==last.x && data.x<=last.x)
			allow = 0;
		if(!allow)
		{
			cerr << "not row prior" << endl;
			exit(1);
		}
		matrix_.push_back(data);
	}
	void IntTrans()
	{
		_for(i,0,matrix_.size())
			swap(matrix_[i].x,matrix_[i].y);
	}
	SparseMatrix<T> ExtTrans() const
	{
		SparseMatrix<T> res = *this;
		_for(i,0,res.matrix_.size())
			swap(res[i].x,res[i].y);
		return res;
	}
	SparseMatrix<T>& operator=(const SparseMatrix<T>& m)
	{
		matrix_ = m.matrix_;n_ = m.n_;m_ = m.m_;
		return *this;
	}
	Triple<T>& operator[](const int idx) 
	{
		return matrix_[idx];
	}
	SparseMatrix<T> operator+(const SparseMatrix<T>& m)
	{
		sort(matrix_.begin(),matrix_.end());
		SparseMatrix res = *this;
		int length = matrix_.size();
		_for(i,0,m.matrix_.size())
		{
			bool push = 1;
			_for(j,0,length)
			{
				if(res[j].x > m[i].x)
					break;
				if(res[j].x == m[i].x && res[j].y == m[i].y )
				{
					T data = res[j].data+m[i].data;
					res[j].data = data;
					push = 0;
					break;
				}
			}
			if(push)
				res.PushBack(m[i]);
		}
		return res;
	}
	SparseMatrix<T> operator-(const SparseMatrix<T>& m)
	{
		SparseMatrix<T> negative = m;
		_for(i,0,negative.matrix_.size())
			negative[i].data = -negative[i].data;
		return *this+negative;
	}
	void print()
	{
		sort(matrix_.begin(),matrix_.end());
		int idx = 0;
		_for(x,0,m_)
		{
			_for(y,0,n_)
			{
				if(idx >= matrix_.size())
					cout << "0" << " ";
				else if(x !=  matrix_[idx].x || y!= matrix_[idx].y )
					cout << "0" << " ";
				else 
					cout << matrix_[idx++] << " ";
			}
			cout << endl;

		}
	}
};
