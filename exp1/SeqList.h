// #include <iostream>
// #ifndef HEADER_SeqList
// #define HEADER_SeqList
#pragma once
#include "head.h"

template<class T>
class SeqList
{
	T* data;
	int length;
	int maxLength;
public:
	SeqList()
	{
		length = 0;
		maxLength = 10;
		data = new T[10];
	}
	SeqList(T a[],int n)
	{
		length = n;
		maxLength = n+1;
		data = new T[maxLength];
		_for(i,0,n)
			data[i] = a[i];
	}
	~SeqList()
	{
		delete [] data;
	}
	int ListLength() const
	{
		return length;
	}
	T& operator [](int index) 
	{
		if(index <0 || index >length) {cerr << "越界" ; exit(1);}
		return data[index];
	}
	int Locate(T item) const
	{
		_for(i,0,length)
			if (data[i]==item)
				return i;
		return -1;
	}
	friend ostream& operator << (ostream& out,const SeqList& s)
	{
		_for(i,0,s.length) out << s.data[i]  << " ";
		out << endl;
		return out;
	}
	void Insert(int index,T items)
	{
		if(index <0 || index>length) {cerr << "越界"; exit(1);}
		if(length >= maxLength-2)
		{
			maxLength *= 2;
			T* newData = new T[maxLength];
			_for(i,0,index)
				newData[i] = data[i];
			newData[index] = items;
			_for(i,index,length)
				newData[i+1] = data[i];
			delete [] data;
			data = newData;
		}
		else
		{
			for(int i=length;i>index;i--)
				data[i] = data[i-1];
			data[index] = items;
		}
		length += 1;
	}
	void Delete(int index)
	{
		if (index<0 || index>length-1){cerr << "越界" ; exit(1);}
		_for(i,index,length-1)
		{
			data[i] = data[i+1];
		}

		length -=1;
	}
	friend void Merge(SeqList<T>& a,SeqList<T> &b)
	{
		T* data = new T[a.length+b.length+1];
		int L=0,R=0,pt=0;
		while(L< a.length || R < b.length)
		{
			// cout << L << " " << R << " " << pt << endl;
			// cout <<  << endl;
			if(L==a.length) 
				data[pt++] = b[R++];
			else if(R==b.length) 
				data[pt++] = a[L++];
			else if(a[L] < b[R])
				data[pt++] = a[L++];
			else
				data[pt++] = b[R++];
		}
		a.maxLength = a.length+b.length+1;
		a.length = a.length+b.length;
		delete [] a.data;
		a.data = data;
		
	}
	void Sort()
	{
		for (int i = 1; i < length; i++)
		{
			cout << i << endl;
			T key = data[i];
			int j = i - 1;
			while ((j >= 0) && (key < data[j])   )
			{
				data[j + 1] = data[j];
				j--;
			}
			data[j + 1] = key;
		}
	}
	void menu()
	{
		cout << "选择功能 1.插入(index,item) 2.排序 3.查找(item) 4.序数(index) 5.删除(index) 6.显示" << endl;
		int op ;
		cin >> op;
		int index;
		T item;
		switch (op)
		{
		case 1:
			cin >> index >> item;
			Insert(index,item);
			break;
		case 2:
			Sort();
			break;
		case 3:
			cin >> index;
			cout << Locate(index);
			break;
		case 4:
			cin >> index;
			cout << data[index];
			break;
		case 5:
			cin >> index;
			Delete(index);
			break;
		case 6:
			_for(i,0,length)
				cout << data[i]  << " ";
			cout << endl;
			break;
		default:
			break;
		}	
		menu();

	}
};


// #endif
