/*
 * @Author: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @Date: 2022-11-16 22:25:54
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-11-29 21:12:28
 * @FilePath: /exp/exp7/include/bi_tree.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include "head.h"
template<class T>
class BiTree;
template<class T>
class BiNode
{
	public:
		BiNode<T> * lchild_,* rchild_;
		T data_;
		BiNode(T data):data_(data){
			lchild_ = rchild_ = nullptr;

		};
		BiNode(){
			lchild_ = rchild_ = nullptr;
		};
};
template<class T>
class BiTree
{
	BiNode<T>* root_;
	void _PreCreate(string& s,BiNode<T>** head,int& index);
	void _PreTraverse(BiNode<T> * head);
	void _InTraverse(BiNode<T> * head);
	void _PostTraverse(BiNode<T> * head);
	void _LineTraverse(BiNode<T> * head);
	BiNode<T>* _CreateByPreMid(vector<T>& pre, vector<T>& mid, int ipre, int imid, int n);
	int _CountDouble(BiNode<T> * head);
	int _CountLeaf(BiNode<T> * head);
	int _CountSingle(BiNode<T> * head);
	int _Height(BiNode<T>* head);
	void _SwitchChild(BiNode<T>* head);
	int _Balance(BiNode<T>* head);
	int _CountLeaf(BiNode<T> * head , int level, int k);
	void _LeafPaths (BiNode<T>* head, vector<T>& path);	
	BiNode<T>* _CommonAncestor (BiNode<T> *head, BiNode<T>*node1, BiNode<T>*node2);
	void _FindXAncestors (BiNode<T>* head, vector<T>& path,T X,bool &find);
	void _LinkLeaf(BiNode<T> *head,BiNode<T>** link_head,BiNode<T>** link_iter);
	void _CountWidth(BiNode<T>* head,int level,vector<int> &v);
	public:
	BiTree();
	void PreCreateFromString(string s);
	void PreTraverse();
	void InTraverse();
	void PostTraverse();
	void LineTraverse();
	int CountDouble();
	int CountLeaf();
	int CountSingle();
	void SwitchChild();
	int Height();
	bool IsCompleteBinaryTree();
	int MaxWidth();
	void CreateByPreMid(vector<T>& pre, vector<T>& mid);

};
#include "bi_tree.ipp"
