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
class List{
protected:
	LinkNode *first;
public:
	bool Insert(int i,T& x);
	bool Delete(int i,T& x);
	LinkNode* Locate(int i);
	void Output();
	void Input(T endtag);
	void MakeEmpty();
	List(){first=new LinkNode;}
	List(T &x){first=new LinkNode(x);}
};
void List::MakeEmpty(){
	LinkNode *del;
	while(first->link!=NULL){
		del=first->link;
		first->link=del->link;
		delete del;
	}
}
LinkNode* List::Locate(int i){
	if(i<0) return NULL;
	LinkNode *current=first;
	int k=0;
	while(current!=NULL&&k<i)
	{
		current=current->link;k++;
	}
	return current;
}
bool List::Insert(int i,T&x){
	LinkNode *current=Locate(i);
	if(current==NULL) return false;
	LinkNode *newNode=new LinkNode(x);
	if(newNode==NULL){cout<<"�洢�������!"<<endl;exit(1);}
	newNode->link=current->link;
	current->link=newNode;
	return true;
}
bool List::Delete(int i,T& x){
	LinkNode *current=Locate(i-1);
	if(current==NULL||current->link==NULL) return false;
	LinkNode *del=current->link;
	x=del->data;
	current->link=del->link;
	delete del;
	return true;
}
void List::Output(){
	LinkNode *current=first->link;
	while(current!=NULL){
		cout<<current->data<<endl;
		current=current->link;
	}
}
void List::Input(T endTag){
	LinkNode *newNode,*last;
	T d;
	MakeEmpty();
	cout<<"�����뵥����,����-1����"<<endl;
    cin>>d;
	last=first;
	while(d!=endTag){
		newNode=new LinkNode(d);
		if(newNode==NULL){cout<<"�洢�������"<<endl;exit(1);}
		last->link=newNode;
		last=newNode;
		cin>>d;
	}
	last->link=NULL;
}






	