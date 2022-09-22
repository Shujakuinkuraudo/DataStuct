#include "head.h"

// template<class T>
// T DeleteMin(SeqList<T>& l)
// {
//     if(l.length == 0)
//     {
//         cerr << "长度为0" ; exit(1);
//     }
//     T _T_min = l[0];
//     for(int i=0;i<l.length;i++)
//         if (_T_min<l[i])
//             _T_min = l[i]
//     for(int i=0;i<l.length;i++)
//         if (_T_min==l[i])
//             l[i] = l[l.length-1];
//     return _T_min;
// }

// template<class T>
// void Delete(SeqList<T>& l,T& x)
// {
//     int pt = 0;
//     while(pt < l.length)
//     {
//         if (l[pt]==x)
//         {
//             for(int j=pt;j<l.length-1;j++)
//                 l[j]=l[j+1];
//             l.length--;
//         }
//         else 
//             pt++;
//     }
// }

// template<class T>
// void Delete(SeqList<T>& l,T& s,T& t)
// {
//     if (s >= t) {cerr<"范围错误"; exit(1);}

//     int pt = 0;
//     while(pt < l.length)
//     {
//         if (l[pt]>=s && l[pt] <=t)
//         {
//             for(int j=pt;j<l.length-1;j++)
//                 l[j] = l[j+1];
//             l.length--;
//         }
//         else 
//             pt++;
//     }
// }

// template<class T>
// void DeleteRepeat(SeqList<T>& l)
// {
//     map<T,int> m;
//     int pt=0;
//     while(pt<l.length){
//         if(m[l[pt]])
//         {
//             for(int j=pt;j<l.length-1;j++)
//                 l[j] = l[j+1];
//             l.length--;
//         }
//         else 
//         {
//             m[l[pt]] = 1;
//             pt++;
//         }
//     }
// }

// template<class T>
// void OrderedInsert(T arr[],int n,T item){
//     for(int i =0;i<n;i++)
//     {
//         if(item < arr[i]) // 2 3 5 
//         {
//             for(int j=n;j>i;j--)
//             {
//                 arr[j] = arr[j-1];
//             }
//             arr[i] = item;
//             return ;
//         }
//     }
// }

template <class T>
class Node
{
    public:
    T data;
    Node<T>* next = nullptr;
    Node(){};
    Node(T a):data(a){};
};

template<class T>
void Copy(Node<T>* now,Node<T>* other)
{
    now -> data = other->data;
    Node<T>* Oahead = other->next;
    Node<T>* Nahead = now;
    while(Oahead)
    {
        Node<T>* temp =new Node<T>(Oahead->data);
        Nahead->next = temp;
        Nahead = Nahead->next;
        Oahead = Oahead -> next;
    }
}

template<class T>
void show(Node<T>* now)
{
    while(now)
    {
        cout << now->data << " ";
        now = now->next;
    }
    cout << endl;
}

int main(){
    Node<int> a[5] = {1,2,3,4,5};
    a[0].next = a+1;
    a[1].next = a+2;
    Copy<int>(a+4,a);
    show(a);
    show(a+4);

    return 0;
}