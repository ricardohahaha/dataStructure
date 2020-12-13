#include"StdAfx.h"
#include<iostream>
#include"单链表.h"
using namespace std;
const int defaultSize=100;
typedef int T;
class searchList:public List{
public:
	searchList(T endTag):List(){Input(endTag);};
	searchList();
	int SeqSearch(const T x)const;
};
int searchList::SeqSearch(const T x)const{
	LinkNode *p;
	p=first;
	int i=0;
	if(p==NULL||p->link==NULL){
		cout<<"没有找到"<<endl;
		return -1;
	}
	while(p!=NULL&&p->data!=x){
		p=p->link;
		i++;
	}
	if(p!=NULL){
		cout<<"找到了,第"<<i<<"个元素"<<endl;
		return i;
	}
	else
	{
	cout<<"没有找到"<<endl;
	return -1;
	}
}
int main(){
	searchList list(-1);
	list.SeqSearch(35);
	return 0;
}
