#include"StdAfx.h"
#include<iostream>
#include"������.h"
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
		cout<<"û���ҵ�"<<endl;
		return -1;
	}
	while(p!=NULL&&p->data!=x){
		p=p->link;
		i++;
	}
	if(p!=NULL){
		cout<<"�ҵ���,��"<<i<<"��Ԫ��"<<endl;
		return i;
	}
	else
	{
	cout<<"û���ҵ�"<<endl;
	return -1;
	}
}
int main(){
	searchList list(-1);
	list.SeqSearch(35);
	return 0;
}
