#pragma once
#include "head.h"
template <class T>
class Triple
{
public:
	int x, y;
	T data;
	Triple(int x, int y, T data) : x(x), y(y), data(data){};
	Triple(){};
	friend const bool operator<(const Triple &t1, const Triple &t2)
	{
		if (t1.x < t2.x)
			return true;
		else if (t1.x == t2.x && t1.y < t2.y)
			return true;
		return false;
	}
	Triple(const Triple<T> &t)
	{
		x = t.x;
		y = t.y;
		data = t.data;
	}
	friend ostream &operator<<(ostream &out, const Triple &t)
	{
		out << t.data;
		return out;
	}
};

template <class T>
class SparseMatrix
{
	vector<Triple<T>> matrix_;
	int n_, m_;

public:
	SparseMatrix(int n, int m) : n_(n), m_(m){};
	SparseMatrix(const SparseMatrix<T> &m);
	SparseMatrix(){};
	void PushBack(const Triple<T> data);
	void RowPushBack(const Triple<T> data);
	void IntTrans();
	SparseMatrix<T> ExtTrans() const;
	SparseMatrix<T> &operator=(const SparseMatrix<T> &m);
	Triple<T> &operator[](int idx);
	SparseMatrix<T> operator+(SparseMatrix<T> &m);
	SparseMatrix<T> operator-(const SparseMatrix<T> &m);
	void print();
	friend istream &operator>>(istream &in, SparseMatrix<T> &m)
	{
		Triple<T> temp;
		in >> temp.x >> temp.y >> temp.data;
		m.matrix_.push_back(temp);
		return in;
	}
};
#include "sparse_matrix.ipp"