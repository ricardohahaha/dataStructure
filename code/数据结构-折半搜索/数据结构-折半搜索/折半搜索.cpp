#include"stdafx.h"
#include<iostream>
using namespace std;
typedef int K;
const int defaultSize=100;
class dataNode{
	friend class SortedList;
public:
	dataNode(const K x):key(x){};
	dataNode(){};
	void setKey(const K newkey){key=newkey;}
	void operator=(dataNode &x){key=x.key;}
	bool operator<(dataNode &x){return key<x.key;}
private:
	K key;
};
typedef dataNode E;
class dataList{
public:
	dataList(int sz=defaultSize):maxSize(defaultSize),currentSize(0){Element=new dataNode[sz];}
	~dataList(){delete []Element;}
	virtual bool insert(E &e)=0;
	virtual bool remove(const K key,E &e)=0;
	virtual void createList()=0;
	virtual void disPlay()=0;
	int getSize(){return currentSize;}
protected:
	dataNode *Element;
	int maxSize;
	int currentSize;
};
class SortedList:public dataList{
public:
	SortedList(int sz=100):dataList(sz){};
	~SortedList(){};
	int BinarySearch(const K key);
	bool insert(E &e);
	bool remove(const K key,E &e);
	void  createList();
	E &operator[](int i){return Element[i];}
	void disPlay(){for(int i=0;i<currentSize;i++){
		cout<<Element[i].key<<" ";}
	cout<<endl;
	}
};
bool SortedList::remove(const K k,E &e){
	int i;
	for(i=0;i<currentSize&&Element[i].key!=k;i++);
	if(i==currentSize)return false;
	e=Element[i];
	Element[i]=Element[currentSize-1];
	currentSize--;
	return true;
}
bool SortedList::insert(E &e){
	if(currentSize==maxSize)
	{
		cout<<"有序顺序表已满"<<endl;
		return false;}
	Element[currentSize]=e;
	currentSize++;
	return true;
}
void SortedList::createList(){
	cout<<"输入当前数组元素个数"<<endl;
	cin>>currentSize;
	cout<<"请输入搜索表"<<endl;
	for(int i=0;i<currentSize;i++){
		cin>>Element[i].key;
	}
}
void ShellSort(SortedList &L,int left,int right)
{
	int i,j,gap;
	gap=right-left;
	dataNode temp;
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
int SortedList::BinarySearch(const K x){
	int high=currentSize-1,low=0,mid;
	while(low<=high){
		mid=(high+low)/2;
		if(x>Element[mid].key) low=mid+1;
		else if(x<Element[mid].key) high=mid-1;
		else return mid+1;
	}
	return 0;
}
int main(){
	SortedList list;
	list.createList();
	ShellSort(list,0,list.getSize()-1);
	list.disPlay();
	cout<<"搜索的值是第"<<list.BinarySearch(35)<<"个元素";
	return 0;
}

	





