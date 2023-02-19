#pragma once
#include "head.h"

template <class T>
class SeqList
{
	T *data;
	int length;
	int maxLength;

public:
	SeqList();
	SeqList(T a[], int n);
	~SeqList();
	int ListLength() const;
	T &operator[](int index);
	int Locate(T item) const;
	void Insert(int index, T items);
	void Delete(int index);
	void Sort();
	void menu();
	friend ostream &operator<<(ostream &out, const SeqList<T> &s)
	{
		_for(i, 0, s.length) out << s.data[i] << " ";
		out << endl;
		return out;
	}
	friend void Merge(SeqList<T> &a, SeqList<T> &b)
	{
		T *data = new T[a.length + b.length + 1];
		int L = 0, R = 0, pt = 0;
		while (L < a.length || R < b.length)
		{
			if (L == a.length)
				data[pt++] = b[R++];
			else if (R == b.length)
				data[pt++] = a[L++];
			else if (a[L] < b[R])
				data[pt++] = a[L++];
			else
				data[pt++] = b[R++];
		}
		a.maxLength = a.length + b.length + 1;
		a.length = a.length + b.length;
		delete[] a.data;
		a.data = data;
	}
};

#include "SeqList.ipp"
