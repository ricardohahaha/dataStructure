#include"StdAfx.h"
#include<iostream>
#include"���ݽṹ-�����.h"
using namespace std;
void dataList::createList(int number){
	cout<<"������"<<number<<"������"<<endl;
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
void QuickSort(dataList &L,const int left,const int right){
	if(left<right){
		int pivot=L.Partition(left,right);
		QuickSort(L,left,pivot-1);
		QuickSort(L,pivot+1,right);
	}
};
int dataList::Partition(const int low,const int high){
	int i=low;
	int j=high;
	Element key=Vector[i];
	while(i!=j)
	{
		for(;i<j;j--)
		{
			if(Vector[j]<key)
			{
				Swap(Vector[j],Vector[i]);
				break;
			}
		}
		key=Vector[j];
		for(;i<j;i++)
		{
			if(Vector[i]>key)
			{
				Swap(Vector[i],Vector[j]);
				break;
			}
		}
		key=Vector[i];
	}
	return i;
};
int main(){
	dataList list;
	list.createList(5);
	QuickSort(list,0,4);
	list.disPlay();
	return 0;
}
