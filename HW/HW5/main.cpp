/*** 
 * @Date: 2022-09-20 18:04:16
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-26 09:48:51
 * @FilePath: /DSM/HW/HW2/main.cpp
 */
#include "include/head.h"
void Gennext(string t,int *next)
{
	int n = t.length();
	next[0] = -1;
	int i = 0;
	int j = -1 ;
	while(i<n)
	{
		if(j==-1 || t[i] == t[j])
		{
			++i,++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMPMatch(const string& s,const string& t)
{
	int n = s.length(),m=t.length();
	int i=-1,j=0,times=0;
	int next[m+1];
	Gennext(t,next);
	while(i<n)
	{
		j = -1;
		while(i<n && j<m)
		{
			if(j==-1 || s[i]==t[j])
			{
				i++;j++;
			}
			else
			{
				j = next[j];
			}
		}
		if(j>=m)
		{
			times++;
			i--;

		}
	}
	return times;
}
string KMPDel(string s,const string& t)
{
	int n = s.length(),m = t.length();
	int i=-1,j=0;
	int next[m+1];
	Gennext(t,next);
	while(i<n)
	{
		j = -1;
		while(i<n && j<m)
		{
			if(j==-1 || s[i]==t[j])
			{
				i++;j++;
			}
			else
			{
				j = next[j];
			}
		}
		if(j>=m)
		{
			_for(k,i-j,i)
			{
				s[k]=0;
			}
			i--;
		}
	}
	int head = -1,index = 0;
	while(++head<n)
	{
		if(s[head])
			s[index++] = s[head];
	}
	while(index<n)
		s[index++] = 0;
	return s;
}

pair<int,int> KMPMaxMatch(const string& s,const string& t)
{
	int n = s.length(),m = t.length();
	int i=-1,j=-1,len = 0,start_index = -1;
	int next[m+1];
	Gennext(t,next);
	while(i<n && j<m)
	{
		if(j==-1 || s[i]==t[j])
		{
			i++;j++;
			if (j>len)
			{
				len = j;
				start_index = i-j;
			}
		}
		else
		{
			j = next[j];
		}
	}
	return make_pair(len,start_index);
}

string InvertString(string s)
{
	int n = s.length();
	_for(i,0,n/2)
		swap(s[i],s[n-1-i]);
	int start_index	= -1;
	int i=0 ;
	for(;i<n;i++)
	{
		if(s[i] != ' ')
		{
			start_index = i;
			break;
		}
	for(;i<n;i++)
		if(s[i]==' ')
		{
			_for(j,0,i-start_index >> 1)
				swap(s[start_index+j],s[i-1-j]);
			start_index = i+1;
		}
	}
	_for(j,0,i-start_index >> 1)
		swap(s[start_index+j],s[i-1-j]);
	return s;
}
template <class T>
vector<pair<int,int>> SaddlePoint(vector< vector<T> > data)
{
	vector<pair<int,int>> ans; //m * n
	int m = data.size(),n = data[0].size();
	T row_min[m],col_max[n];
	_for(x,0,m)
		row_min[x] = data[x][0];
	_for(x,0,m)
		_for(y,0,n)
			row_min[x] = min(row_min[x],data[x][y]);
	_for(y,0,n)
		col_max[y] = data[0][y];
	_for(y,0,n)
		_for(x,0,m)
			col_max[y] = max(col_max[y],data[x][y]);
	_for(x,0,m)
		_for(y,0,n)
			if(data[x][y] == row_min[x] && data[x][y] == col_max[y])
				ans.push_back(make_pair(x,y));

	return ans;
}

template<class T>
struct MatrixTriple;

template<class T>
T AddDiagTriple(MatrixTriple<T> &data )
{
	T ans=0;
	_for(i,0,data.size())
	{
		if(data[i].x==data[i].y)
			ans += data[i].data;
	}
	return ans;

}


int main()
{
	int next[100];
	string s[7] ={"ABCDEFG","AAAAAAAA","BABBABAB","AAAAAAB","ABCABDAAABC","ABCABDABEABCABDABF","ABBACXY"};
	for(auto X:s)
	{
		Gennext(X,next);
		cout << X << " " ;
		_for(i,0,X.length())
		{
			cout << next[i] << " ";
		}
		cout << endl;
	}
	//string s= "Do    or do not, there is no try.    ",t= "a";
	////cout << KMPDel(s,t);
	//cout << InvertString(s);
	////pair<int,int> lenAndStart = KMPMaxMatch(s,t);
	////_for(i,0,lenAndStart.first)
	////{
		////cout << s[lenAndStart.second+i];
	////}

    return 0;
}
