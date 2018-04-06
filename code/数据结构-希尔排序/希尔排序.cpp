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
};
void ShellSort(dataList &L,int left,int right)
{
	int i,j,gap;
	gap=right-left+1;
	Element temp;
	do{
		gap=gap/3+1;
		for(i=left+gap;i<=right;i++)
		{
			if(L[i]<L[i-gap]){
				temp=L[i];
				j=i-gap;
				do{
					L[j+gap]=L[j];
					j=j-gap;
				}while(j>=left&&temp<L[j]);
				L[j+gap]=temp;
			}
		}
	}while(gap>1);
}
int main(){
	dataList list;
	list.createList(9);
	ShellSort(list,0,8);
	list.disPlay();
	return 0;
}









