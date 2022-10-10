#include "include/head.h"

int BFMatch(char* s,char* t)
{
	int i=1,j=1,times=0;
	int n=s[0]-'0',m=t[0]-'0';
	while(i<=n)
	{
		j = 1;
		while(i<=n && j<=m)
		{
			if(s[i]==t[j])
			{
				i++;j++;
			}
			else
			{
				i = i-j+2;
				j=1;
			}
		}
		if(j>m) times++;
	}
	return times;
}



class KMPMatch
{
	int *next_;
	int *nextval_;
	void Gennext(char *t,int n)
	{
		next_[0] = -1;
		int i = 0;
		int j = -1 ;
		while(i<n)
		{
			cout << i << " " << j << endl;
			if(j==-1 || t[i] == t[j])
			{
				++i,++j;
				next_[i] = j;
			}
			else
			{
				j = next_[j];
			}
		}
	}
	void Gennextval(char *t,int n)
	{
		nextval_[0] = -1;
		int i = 0;
		int j = -1 ;
		while(i<n)
		{
			cout << i << " " << j << endl;
			if(j==-1 || t[i] == t[j])
			{
				++i,++j;
				nextval_[i] = j;
				if(t[i] == t[j])
					nextval_[i]=nextval_[j];
			}
			else
			{
				j = nextval_[j];
			}
		}
	}
	int KMP(char *s,char *t ,int n1 ,int n2)
	{
		Gennext(t,n2);
		Gennextval(t,n2);
		_for(i,0,n2)
			cout << next_[i] << " " << endl;
		_for(i,0,n2)
			cout << nextval_[i] << " " << endl;
		int i =0,j=0;
		while(i<n1 && j< n2)
		{
			if(j==-1 || s[i] == t[j])
			{
				i++;j++;
			}
			else
			{
				j = nextval_[j];
			}
		}
		//cout << "1:" <<  j <<" "<<  i << endl;
		return i-j;
	}
	public:
	int operator()(char *s,char *t,int n1,int n2)
	{
		next_ = new int[n2];
		nextval_ = new int[n2];
		return KMP(s,t,n1,n2);
	}
};

int main()
{
	char *s="aabb",*t="ab";
	//cout << BFMatch(s,t);
	KMPMatch a;
	cout << a(s,t,4,2);
}
