#include"StdAfx.h"
#include<iostream>
using namespace std;
typedef int T;
struct LinkNode{
	T data;
	LinkNode *link;
	LinkNode(LinkNode *ptr=NULL){link=ptr;}
	LinkNode(T d,LinkNode *ptr=NULL){data=d;link=ptr;}
};
class Queue{
public:
	Queue(){};
	~Queue(){};
	virtual void EnQueue(const T &x)=0;
	virtual bool DeQueue(T& x)=0;
	virtual bool IsEmpty()const=0;
	virtual bool Getfront(T &x)const=0;
	virtual void Input(T &endTag)=0;
	virtual void MakeEmpty()=0;
	virtual void Output()const=0;
};
class SeqQueue:public Queue{
	LinkNode *first;
	LinkNode *rear;
public:
	SeqQueue(){first=new LinkNode;first->link=first;rear=first;}
	//~SeqQueue();
	 void EnQueue(const T &x);
	 bool Getfront(T &x)const{if(IsEmpty()) return false;else {x=first->link->data;return true;}}
	 bool DeQueue(T& x);
	 bool IsEmpty()const{return(first->link==first)?true:false;}
	 void Input(T &endTag);
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
void SeqQueue::Input(T &endTag){
	LinkNode *newNode,*last;
	T d;
	MakeEmpty();
    cin>>d;
	last=first;
	while(d!=endTag){
		newNode=new LinkNode(d);
		if(newNode==NULL){cout<<"存储分配错误！"<<endl;exit(1);}
		last->link=newNode;
		last=newNode;
		cin>>d;
	}
	rear=last;
	last->link=first;
}
void SeqQueue::Output()const{
	LinkNode *current=first->link;
	while(current->link!=first->link){
		cout<<current->data<<endl;
		current=current->link;
	}
}
void SeqQueue::EnQueue(const T &x){
	LinkNode *p=new LinkNode(x);
	rear->link=p;
	p->link=first;
	rear=p;
}
bool SeqQueue::DeQueue(T& x){
	if(IsEmpty()) return false;
	LinkNode *del=first->link;
	first->link=del->link;
	x=del->data;
	delete del;
	return true;
}
int main(){
	int x=5;
	SeqQueue my;
	cout<<"请输入队列"<<endl;
	my.Input(x);
	my.Output();
	my.Getfront(x);
	cout<<"队首元素"<<x<<endl;
	my.EnQueue(9);
	my.EnQueue(10);
	my.EnQueue(0);
	cout<<"进队后的队列"<<endl;
	my.Output();
	my.DeQueue(x);
	cout<<"出队元素为"<<x<<endl;
	my.MakeEmpty();
	my.EnQueue(666);
	cout<<"置队空后再入队"<<endl;
	my.Output();
    return 0;
}








