#include"StdAfx.h"
#include<iostream>
#include<queue>
using namespace std;
typedef char T;
struct BinTreeNode{
	T data;
	BinTreeNode *leftchild,*rightchild;
	BinTreeNode(T d,BinTreeNode *l=NULL,BinTreeNode *r=NULL):leftchild(l),rightchild(r),data(d){};
	BinTreeNode():leftchild(NULL),rightchild(NULL){};
};
class BinaryTree{
public:
	BinTreeNode *root;
	char endTag;
	BinaryTree():root(NULL){};
	BinaryTree(T value):endTag(value),root(NULL){};
	~BinaryTree(){destroy(root);}
	void CreateBinTree(BinTreeNode* &subTree);
	void destroy(BinTreeNode* &subTree);
	BinTreeNode* Parent(BinTreeNode* current);
	void Traverse(BinTreeNode* subTree);
	void PreOrder(BinTreeNode* subTree);
	void InOrder(BinTreeNode* subTree);
	void PostOrder(BinTreeNode* subTree);
	int Size(BinTreeNode* subTree);
	int Height(BinTreeNode* subTree);
	void LevelOrder(BinTreeNode* subTree);
	void visit(BinTreeNode* subTree);
    bool Find(BinTreeNode* &subTree,const T &data);
	BinTreeNode* Root(){return root;}
};
void BinaryTree::LevelOrder(BinTreeNode* p){
	std::queue<BinTreeNode*>q;
	q.push(p);
	while(!q.empty()){
		p=q.front();q.pop();visit(p);
		if(p->leftchild!=NULL) {q.push(p->leftchild);}
		if(p->rightchild!=NULL) {q.push(p->rightchild);}
	}
}
bool BinaryTree::Find(BinTreeNode* &subTree,const T &Data){
	if(subTree==NULL||subTree->data!=Data) return 0;
	else if(subTree->data==Data) return 1;
	else{
		Find(subTree->leftchild,Data);
		Find(subTree->rightchild,Data);
	}
}
int BinaryTree::Size(BinTreeNode* subTree){
	if(subTree==NULL) return 0;
	else return 1+Size(subTree->leftchild)+Size(subTree->rightchild);
}
int BinaryTree::Height(BinTreeNode* subTree){
	if(subTree==NULL) return 0;
	else{
		int i=Height(subTree->leftchild);
		int j=Height(subTree->rightchild);
		return(i>j)?i+1:j+1;
	}
}
void BinaryTree::destroy(BinTreeNode* &subTree){
	if(subTree!=NULL){
		destroy(subTree->leftchild);
		destroy(subTree->rightchild);
		cout<<"析构"<<subTree->data<<endl;
		delete subTree;
	}
}
void BinaryTree::CreateBinTree(BinTreeNode* &subTree){
	T item;
	cin>>item;
	if(item!=endTag){
		subTree=new BinTreeNode(item);
		CreateBinTree(subTree->leftchild);
		CreateBinTree(subTree->rightchild);
	}
	else subTree=NULL;
}
void BinaryTree::visit(BinTreeNode* subTree){
	cout<<subTree->data;
}
void BinaryTree::PostOrder(BinTreeNode* subTree){
	if(subTree!=NULL){
		PostOrder(subTree->leftchild);
		PostOrder(subTree->rightchild);
		visit(subTree);
	}
}
void BinaryTree::PreOrder(BinTreeNode* subTree){
	if(subTree!=NULL){
		visit(subTree);
		PreOrder(subTree->leftchild);
		PreOrder(subTree->rightchild);
	}
}
void BinaryTree::InOrder(BinTreeNode* subTree){
	if(subTree!=NULL){
		InOrder(subTree->leftchild);
		visit(subTree);
		InOrder(subTree->rightchild);
	}
}
int main(){
	BinTreeNode* r;
	BinaryTree myTree('#');
	r=myTree.Root();
	myTree.CreateBinTree(r);
	myTree.PreOrder(r);
	cout<<"此二叉树的高度"<<myTree.Height(r)<<endl;
	cout<<"此二叉树的结点个数"<<myTree.Size(r)<<endl;
	myTree.LevelOrder(r);
	return 0;
}