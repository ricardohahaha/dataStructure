#include"stdafx.h"
#include<iostream>
using namespace std;
typedef int T;
struct LinkNode{
	LinkNode *next;
	T Data;
};
class List{
public:
	bool Insert(int i,T &x);
	bool Delete(int j,T &y);
	bool Find(T data);
	List(T data);
	List(){head=NULL;}
private:
	LinkNode *head;
};
List::List(T data)
{
	head->Data=data;
}
bool List::Insert(int i,T &a)
{

		LinkNode *p=new LinkNode;
        LinkNode *current=head->next;
		if(!p)
		{cout<<"�ڴ治��!����"<<endl;
		  return false;
		}
		else
		{
			p->Data=a;
			for(int k=1;k<i;k++)
			{
				if(current==NULL)
				{cout<<"����λ�ò��Ϸ�"<<endl;
				 return false;
				}
				else
				{
					current=current->next;
				}
			}