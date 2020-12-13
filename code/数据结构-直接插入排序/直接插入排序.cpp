#include"StdAfx.h"
#include<iostream>
#include"数据结构-排序表.h"
using namespace std;
void dataList::createList(int number){
	cout<<"请输入"<<number<<"个数据"<<endl;
	for(int i=0;i<number;i++)
	{
		currentSize++;
		cin>>Vector[i].key>>Vector[i].otherdata;
	}
};
void dataList::disPlay(){
	for(int i=0;i<currentSize;i++){
		cout<<Vector[i].key<<endl;
	}
}

void InserSort(dataList &L,const int left,const int right){
	Element temp;
	int i,j;
	for(i=left+1;i<=right;i++){
		if(L[i]<L[i-1]){
			temp=L[i];
			j=i-1;
			do{
				L[j+1]=L[j];
				j--;
			}while(j>=left&&temp<L[j]);
			L[j+1]=temp;
		}
	}
};
int main(){
	dataList list;
	list.createList(9);
	InserSort(list,0,8);
	list.disPlay();
	return 0;
}





