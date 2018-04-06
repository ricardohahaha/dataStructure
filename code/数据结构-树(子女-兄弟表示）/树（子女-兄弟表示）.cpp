#include"StdAfx.h"
#include<iostream>
using namespace std;
typedef char T;
struct TreeNode{
	T data;
	TreeNode *firstChild,*nextSibling;
	TreeNode(T value=0,TreeNode *fc=NULL,TreeNode *ns=NULL):data(value),firstChild(fc),nextSibling(ns){};
};
class Tree{
private:
	T endTag;
	TreeNode *root,*current;
	bool Find(TreeNode *p,T value);
	void RemovesubTree(TreeNode *p);
	bool FindParent(TreeNode *t,TreeNode *p);
public:
	Tree(T value){root=current=NULL;endTag=value;}
    bool Root();
	bool IsEmpty(){if(root==NULL) return true;}
	bool FirstChild();
	bool NextSibling();
	bool Parent();
	bool Find(T target);
	void CreateTree(TreeNode* &subTree);
	TreeNode* ReturnRoot(){return root;}
	void PreOrder(TreeNode* subTree);
	void PostOrder(TreeNode* subTree);
};
void Tree::CreateTree(TreeNode* &subTree){
	T item;
	cin>>item;
	if(item!=endTag){
		subTree=new TreeNode(item);
		CreateTree(subTree->firstChild);
		CreateTree(subTree->nextSibling);
	}
	else subTree=NULL;
}
bool Tree::Root(){
	if(root==NULL){current=NULL;return false;}
	else{current=root;return true;}
}
bool Tree::Parent(){
	TreeNode *p=current;
	if(current==NULL||current==root){current=NULL;return false;}
	return FindParent(root,p);
}
bool Tree::FindParent(TreeNode *t,TreeNode *p){
	TreeNode *q=t->firstChild;
	//bool succ;
	while(q!=NULL&&q!=p){
		if(FindParent(q,p)){ return true;}
		q=q->nextSibling;
	}
	if(q!=NULL&&q==p){current=t;return true;}
	else{current=NULL;return false;}
}
bool Tree::FirstChild(){
	if(current!=NULL&&current->firstChild!=NULL){current=current->firstChild;return true;}
	else{
		current=NULL;
		return false;
	}
}
bool Tree::NextSibling(){
	if(current!=NULL&&current->nextSibling!=NULL){
		current=current->nextSibling;return true;
	}
	else{
		current=NULL;return false;
	}
}
bool Tree::Find(T value){
	if(IsEmpty()) return false;
	return Find(root,value);
}
bool Tree::Find(TreeNode *p,T value){
	if(p->data==value){current=p;return true;}
	else{
		TreeNode *q=p->firstChild;
		while(q!=NULL&&!(Find(q,value))){
			q=q->nextSibling;
		}
	}
}
void Tree::PreOrder(TreeNode* p){
	if(p!=NULL){
		cout<<p->data;
		p=p->firstChild;
		while(p!=NULL){
			PreOrder(p);
			p=p->nextSibling;
		}
	}
}
void Tree::PostOrder(TreeNode* p){
	if(p!=NULL){
		TreeNode *q=p->firstChild;
		while(q!=NULL){
			PostOrder(q);
			q=q->nextSibling;
		}
	}
	cout<<p->data;
}
int main(){
	Tree MyTree('#');
	TreeNode *r=MyTree.ReturnRoot();
	MyTree.CreateTree(r);
	MyTree.PostOrder(r);
	MyTree.Find('H');
	return 0;
}

