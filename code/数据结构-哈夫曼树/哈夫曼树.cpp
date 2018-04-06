#include"stdafx.h"
#include<iostream>
#include"优先级队列.h"
using namespace std;
const int defaultSize=20;
typedef int K;
struct HuffmanNode{
	K data;
	HuffmanNode *lChild,*rChild,*Parent;
	HuffmanNode():lChild(NULL),rChild(NULL),Parent(NULL){}
	HuffmanNode(K d,HuffmanNode *l,HuffmanNode *r,HuffmanNode *p):data(d),lChild(l),rChild(r),Parent(p){};
	bool operator<=(HuffmanNode& R){return data<=R.data;}
	bool operator>(HuffmanNode& R){return data>R.data;}
};
class HuffmanTree{
public:
	HuffmanTree(K w[],int n);
	~HuffmanTree(){deleteTree(root);}
protected:
	HuffmanNode *root;
	void deleteTree(HuffmanNode *t);
	void mergeTree(HuffmanNode *&ht1,HuffmanNode *&h2,HuffmanNode *&h);
};
HuffmanTree::HuffmanTree(K w[],int n){
	PQueue queue;
	HuffmanTree *parent,*first,*second,*work;
	for(int i=0;i<n;i++){
		work.data=w[i];
		work.lChild=NULL;
		work.rChild=NULL;
		work.Parent=NULL;
		queue.


