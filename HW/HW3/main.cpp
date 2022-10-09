/*** 
 * @Date: 2022-09-20 18:04:16
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-27 19:08:28
 * @FilePath: /DSM/HW/HW3/main.cpp
 */
#include "head.h"

//template <class T>
//int CountCircularLinkList(Node<T>* head)
//{
	//Node<T> *pt = head;
	//int count = 1;
	//while(pt->next!=head)
	//{
		//pt = pt->next;
		//count++;
	//}
	//return count;
//}

template<class T>
void Swap(T& a,T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<class T>
void SplitArr(T* arr,int n) //快排
{
	int v = arr[0];
	int l=0,r=n-1;
	while(l<r)
	{
		while(l<r && arr[r]>=v)
			r--;
		arr[l]=arr[r];
		while(l<r && arr[l]<=v)
			l++;
		arr[r]=arr[l];
	}
	arr[l] = v;
}

void StackOrder(char* arr,int n,int index,string now,stack<char> s,vector<string>& ans)
{
	if (s.empty() && index == n)
	{
		ans.push_back(now);
		return;
	}
	if(index < n)
	{
		s.push(arr[index]);
		StackOrder(arr,n,index+1,now,s,ans);
		s.pop();
	}
	if(!s.empty())
	{
		now += s.top();
		s.pop();
		StackOrder(arr,n,index,now,s,ans);
	}
}
//利用栈实现把十进制整数转换为二至十六之间的任一进制数输出的功能。

//void  TransferDigit(int i,int digit)
//{
    //char* table = "0123456789ABCDEF";
    //stack<int> s;
    //while(i)
    //{
        //s.push(i%digit);
        //i /= digit;
    //}
    //string ans;
    //while(!s.empty())
        //{
            //ans += table[s.top()]; s.pop();
        //}
    //cout << ans;
//}

//// 设有一维数组stack[StackMaxSize]
//// ，分配给两个栈S1和S2使用，如何分配数组空间，使得对任何一个栈，当且仅当数组空间全满时才不能插入。
//// 试说明你的分配方法。并分别给出两个栈各自的入栈和出栈算法。
//template<class T,int StackMaxSize>
//class DStack
//{
    //T data[StackMaxSize];
    //int l=-1,r=StackMaxSize;
    //public:
    //void S1push(T item)
    //{
        //if(l+1==r)
        //{
            //cerr << "size error" << endl;
            //exit(1);
        //}
        //data[++l] = item;
    //}
    //void S2push(T item)
    //{
        //if(l==r-1)
        //{
            //cerr << "size error" << endl;
            //exit(1);
        //}
        //data[--r] = item;

    //}
    //T S1pop()
    //{
        //if(l==-1)
        //{
            //cerr << "size error" << endl;
            //exit(1);
        //}
        //return data[l--];

    //}
    //T S2pop()
    //{
        //if(r==StackMaxSize)
        //{

        //}
        //return data[r++];
    //}
//};
//// 假设表达式中允许包含3种括号：圆括号、方括号和大括号。
//// 试编写一个算法，检查表达式中括号是否配对，若能够全部配对则返回1，否则返回0。
//bool Check(string& s)
//{
    //stack<char> pa;
    //_for(i,0,s.length()){
        //if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            //pa.push(s[i]);
        //if(s[i] == ')')
            //{
                //if(pa.empty() || pa.top() != '(') return 0;
                //pa.pop();
            //}
        //if(s[i] == ']')
            //{
                //if(pa.empty() ||pa.top() != '[') return 0;
                //pa.pop();
            //}
        //if(s[i] == '}')
            //{
                //if(pa.empty() ||pa.top() != '{') return 0;
                //pa.pop();
            //}
    //}
    //if(pa.empty()) return 1;
    //return 0;
//}


int main(){
	int a[30] = {456,45,4,684,9,0215,1,56,46,04,654,4065,4,604,65,406,84,64,61,65,46,501,65,1065,106,81,8};
	SplitArr<int>(a,30);
	_for(i,0,30)
		cout << a[i] << " ";


    return 0;
}
