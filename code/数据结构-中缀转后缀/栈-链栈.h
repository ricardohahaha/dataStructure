#include"stdafx.h"
#include<iostream>
using namespace std;
typedef char DataType;
class StackNode
{
public:
	DataType data;
	StackNode *next;
	StackNode()
	{
		next=NULL;
	};
};
class LinkStack
{
private:
	StackNode*top;
public:
	LinkStack()
    { top=NULL;
	};
	~LinkStack()
	{
		StackNode*p;
		while(top)
		{
			p=top;
			top=top->next;
			delete p;
		}
		top=NULL;
	};
	bool IsEmpty();
	int Push(DataType a);
	int Pop(DataType &a);
	int GetTop(DataType &a);
};
bool LinkStack::IsEmpty()
{
	if(top)
	{
		return 1;
	}
	else return 0;
}
int LinkStack::Push(DataType a)
{
	{
	StackNode*p=new StackNode;
	if(p)
	{
	p->data=a;
	p->next=top;
	top=p;
	return 1;
	}
	else return 0;
	}
}
int LinkStack::Pop(DataType &a)
{
	StackNode*p;
	if(IsEmpty())
	{
		p=top;
		a=top->data;
		top=top->next;
		delete p;
		return 1;
	}
	else return 0;
}
int LinkStack::GetTop(DataType &a)
{
	if(IsEmpty())
	{
		a=top->data;
		return a;
	}
	else return 0;
}



