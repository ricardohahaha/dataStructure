#include"StdAfx.h"
#include<iostream>
using namespace std;
typedef char T;
struct LinkNode{
	BinTreeNode *data;
	LinkNode *link;
	LinkNode(LinkNode *ptr=NULL){link=ptr;}
	LinkNode(BinTreeNode* d,LinkNode *ptr=NULL){data=d;link=ptr;}
};
class Queue{
public:
	Queue(){};
	~Queue(){};
	virtual void EnQueue(BinTreeNode *x)=0;
	virtual bool DeQueue(BinTreeNode* x)=0;
	virtual bool IsEmpty()const=0;
	virtual bool Getfront(BinTreeNode* x)const=0;
	virtual void Input(BinTreeNode* &endTag)=0;
	virtual void MakeEmpty()=0;
	virtual void Output()const=0;
};
class SeqQueue:public Queue{
	LinkNode *first;
	LinkNode *rear;
public:
	SeqQueue(){first=new LinkNode;first->link=first;rear=first;}
	//~SeqQueue();
	 void EnQueue(BinTreeNode* x);
	 bool Getfront(BinTreeNode* x)const{if(IsEmpty()) return false;else {x=first->link->data;return true;}}
	 bool DeQueue(BinTreeNode* x);
	 bool IsEmpty()const{return(first->link==first)?true:false;}
	 void Input(BinTreeNode* &endTag);
	 void MakeEmpty();
	 void Output()const;
};
void SeqQueue::MakeEmpty(){
	LinkNode *del;
	while(first->link!=first){
		LinkNode *del=first->link;
		first->link=del->link;
		delete del;
	}
	rear=first;
}
/*void SeqQueue::Input(BinTreeNode* &endTag){
	LinkNode *newNode,*last;
	T d;
	MakeEmpty();
    cin>>d;
	last=first;
	while(d!=endTag){
		newNode=new LinkNode(d);
		if(newNode==NULL){cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;exit(1);}
		last->link=newNode;
		last=newNode;
		cin>>d;
	}
	rear=last;
	last->link=first;
}*/
/*void SeqQueue::Output()const{
	LinkNode *current=first->link;
	while(current->link!=first->link){
		cout<<current->data<<endl;
		current=current->link;
	}
}*/
void SeqQueue::EnQueue(BinTreeNode* x){
	LinkNode *p=new LinkNode(x);
	rear->link=p;
	p->link=first;
	rear=p;
}
bool SeqQueue::DeQueue(BinTreeNode* x){
	if(IsEmpty()) return false;
	LinkNode *del=first->link;
	first->link=del->link;
	x=del->data;
	delete del;
	return true;
}
