#pragma once
#include "head.h"

template <class T>
class Node
{
    public:
    T data;
    Node<T>* next=nullptr;
    Node(){}
    Node(T data):data(data){};
};
template <class T>
class LinkList
{
    Node <T> *head =new Node<T>(0); 
    public:
    LinkList();
    LinkList(T a[],int n);
    ~LinkList();
    int ListLength();
    T& Get(int index) const;
    T& operator[](int index) const;
    int Locate(T item);
    void Insert(int index, T item);
    T Delete(int index);
    void Reverse();
    void Menu();
    friend ostream& operator<<(ostream& out,const LinkList<T>& L)
    {
        auto pt = L.head;
        while(pt->next)
        {
            pt = pt->next;
            out << pt->data << " ";
        }
        return out;
    }
    friend void Merge(LinkList<T>& l1,const LinkList<T>& l2)
    {
        auto L = l1.head->next; auto R = l2.head->next;
        Node<T> *head = new Node<T>;
        auto ahead = head;
        while(L || R)
        {
            if(!L) 
            {
                ahead ->next =new Node<T>(R->data);
                R = R->next;
            }
            else if(!R)
            {
                ahead ->next = new Node<T>(L->data);
                L = L->next;
            }
            else if(L->data < R->data)
            {
                ahead -> next = new Node<T>(L->data);
                L = L->next;
            }
            else{
                ahead ->next = new Node<T>(R->data);
                R = R->next;
            }
            ahead = ahead->next;
        }
        l1.head = head;
    }
};
#include "LinkList.ipp"