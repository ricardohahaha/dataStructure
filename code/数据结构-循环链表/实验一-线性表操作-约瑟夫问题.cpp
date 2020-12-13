#include"stdafx.h"
#include<iostream>
using namespace std;
struct Node{
	int number;
	Node *next;
};
class List{
private:
	Node *head;
	int length;
public:
	List(){
		head=NULL;
		length=0;
	}
	List(int n){
		int i;
		Node *p=new Node;
		Node *temp;
		head=p;
		head->number=1;
		for(i=2;i<=n;i++)
		{
			Node *temp=new Node;
			p->next=temp;
			p=p->next;
			p->number=i;
		}
		p->next=head;
	}
	int Answer(int,int);
};
int List::Answer(int sign,int first)
{
	Node *q,*t,*m;
	int i;
	q=head;
	while(q->next->number!=first)
	{
	   q=q->next;
	}

	while(q->next!=q)
	{
	for(i=1;i<sign;i++)
	{
		q=q->next;
	}
	t=q->next;
	q->next=q->next->next;
	delete t;
	}
	return q->number;
}
int main()
{
	List list(9);
	cout<<list.Answer(5,1);
	return 0;
}