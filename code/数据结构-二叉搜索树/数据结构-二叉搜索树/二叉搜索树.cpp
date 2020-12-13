#include"stdafx.h"
#include<iostream>
using namespace std;
typedef int T;
struct BstNode{
	T data;
	BstNode *left,*right;
	BstNode(T d):data(d){}
	BstNode():left(NULL),right(NULL){}
	BstNode(const T d,BstNode *l,BstNode *r):data(d),left(l),right(r){}
	~BstNode(){}
	void setData(T d){data=d;}
	T getData(){return data;}
};
class BST{
public:
	BST():root(NULL){}
	BST(T value);
	~BST(){}
	bool Search(const T x){return Serach(x,root)!=NULL?true:false;}
	BST& operator=(const BST&R);
	void makeEmpty(){makeEmpty(root);root=NULL;}
	void disPlay()const{disPlay(root);}
	T Min(){return Min(root)->data;}
	T Max(){return Max(root)->data;}
	bool Insert(const T&e){return Insert(e,root);}
	bool Remove(const T x){return Remove(x,root);}
private:
	BstNode *root;
	T endTag;
    BstNode* Serach(const T x,BstNode *r);
	void makeEmpty(BstNode *&r);
	void disPlay(BstNode *r)const;
	BstNode* Min(BstNode *r)const;
	BstNode* Max(BstNode *r)const;
	bool Insert(const T&e,BstNode *&r);
	bool Remove(const T&e,BstNode *&r);
};
BstNode* BST::Serach(const T x,BstNode *p){
	if(p==NULL) return NULL;
	else if(x<p->data) Serach(x,p->left);
	else if(x>p->data) Serach(x,p->right);
	else return p;
}
bool BST::Insert(const T&e,BstNode *&p){
	if(p==NULL){
		p=new BstNode(e);
		if(p==NULL){cerr<<"´æ´¢·ÖÅäÊ§°Ü"<<endl;exit(1);}
		return true;
	}
	else if(e<p->data) Insert(e,p->left);
	else if(e>p->data) Insert(e,p->right);
	else return false;
}
BST::BST(T value){
	T x;
	root=NULL;
	endTag=value;
	cin>>x;
	while(x!=endTag){
		Insert(x,root);
		cin>>x;
	}
}
bool BST::Remove(const T &x,BstNode *&p){
	BstNode *temp;
	if(p!=NULL){
		if(x<p->data) Remove(x,p->left);
		else if(x>p->data) Remove(x,p->right);
		else if(p->left!=NULL&&p->right!=NULL){
			temp=p->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			p->data=temp->data;
			Remove(p->data,p->right);
		}
		else{
			temp=p;
			if(p->left==NULL) p=p->right;
			else p=p->right;
			delete temp;
			return true;
		}
	}
	return false;
}









