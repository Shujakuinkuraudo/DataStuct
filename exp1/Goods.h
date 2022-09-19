#pragma once
#include "head.h"
class Goods;
class Good
{
    // 商品代码、商品名称、价格、库存量
    string code = "";
    string name = "";
    float price = 0;
    int store = 0;
    friend Goods;
    public:
	Good(){};
	Good(string code,string name,float price,int store):code(code),name(name),price(price),store(store){};
        friend ostream& operator << (ostream& out,const Good& item)
        {
            out << "code:" << item.code << " name:" << item.name << "price:" << item.price << "store:"  << item.store << endl;
            return out;
        }
	bool operator < (const Good& other) const
	{
		return code<other.code;
	}
	Good& operator = (const Good& other)
	{
		name = other.name;
		code = other.code;
		price = other.price;
		store = other.store;
		return *this;
	}
};
class Goods
{
    SeqList<Good> data ;
    public:
    friend ostream& operator << (ostream& out,const Goods& item)
    {
        out << item.data << endl;
        return out;
    }
	int Locate(string code)
	{
		_for(i,0,data.ListLength())
			if(data[i].code == code)
				return i;
		return -1;
	}
	void change(string code)
	{
		if (Locate(code) == -1)
		{
			string name;
			int store;
			float price;
			cout << "name price store" << endl;
			cin >> name >> price >> store;
			Good temp(code,name,price,store);
			data.Insert(data.ListLength(),temp);
		}
		else
		{
			int delta;
			cout << "delta"  << endl;
			cin >> delta;
			data[Locate(code)].store+=delta;
		}
	}
	void Delete( string code)
	{
		if(Locate(code) != -1)
		{
			data.Delete(Locate(code));
		}
	}
	void Sort()
	{
		data.Sort();
	}
	void menu()
	{
		int op;
		cout << "1.显示 2.修改库存(code) 3.删除记录(code) 4.排序" << endl;
		cin >> op;
		string temp;
		switch(op)
		{
			case 1:
				cout << data << endl;
				break;
			case 2:
				cin >> temp;
				change(temp);
				break;
			case 3:
				cin >> temp;
				Delete(temp);
				break;
			case 4:
				Sort();
				break;
		}
		menu();
	}

};
