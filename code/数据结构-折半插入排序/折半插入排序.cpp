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
void BinaryInsertSort(dataList &L,const int left,const int right)
{
	Element temp;
	int i,low,high,middle,k;
	for(i=left+1;i<=right;i++)
	{
		temp=L[i];
		low=left;
		high=i-1;
		while(low<=high){
			middle=(low+high)/2;
			if(temp<L[middle])
				high=middle-1;
			else low=middle+1;
		}
		for(k=i-1;k>=low;k--)
		{
			L[k+1]=L[k];
		}
		L[low]=temp;
	}
}
int main(){
	dataList list;
	list.createList(9);
	BinaryInsertSort(list,0,8);
	list.disPlay();
	return 0;
}

