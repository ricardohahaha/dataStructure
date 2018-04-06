#include"StdAfx.h"
#include<iostream>
using namespace std;
typedef int T;
const int increament=20;
class Stack{
public:
	Stack(){};
	virtual void Push(const T&x)=0;
	virtual bool Pop(T& x)=0;
	virtual bool getTop(T &X)const=0;
	virtual bool IsEmpty()const=0;
	virtual bool IsFull()const=0;
	virtual int getSize()const=0;
	virtual void Output()const=0;
};
class SeqStack:public Stack{
private:
	T *elements;
	int top;
	int maxSize;
	void overProcess();
public:
	SeqStack(int sz=50);
	~SeqStack(){delete[]elements;}
	void Push(const T&x);
	bool Pop(T& x);
	bool getTop(T &X)const;
	bool IsEmpty()const{return (top==-1)?true:false;}
	bool IsFull()const{return (top==maxSize-1)?true:false;}
	int getSize()const{return top+1;}
	void MakeEmpty(){top=-1;}
	void Output()const;
};
void SeqStack::Output()const{
	for(int i=0;i<=top;i++)
	{
		cout<<i+1<<":"<<elements[i]<<endl;
	}
}
SeqStack::SeqStack(int sz):top(-1),maxSize(sz){
	elements=new T[maxSize];
}
void SeqStack::overProcess(){
	T *newArray=new T[maxSize+increament];
	if(newArray==NULL){cout<<"´æ´¢·ÖÅäÊ§°Ü"<<endl;exit(1);}
	for(int i=0;i<=top;i++){
		newArray[i]=elements[i];
	}
	maxSize=maxSize+increament;
	delete[]elements;
	elements=newArray;
}
bool SeqStack::getTop(T &x) const{
	if(IsEmpty()==true) return false;
	x=elements[top];
	return true;
}
void SeqStack::Push(const T&x){

	if(IsFull()==true) overProcess();
	elements[++top]=x;
}
bool SeqStack::Pop(T &x){
	if(IsEmpty()==true) return false;
	x=elements[top--];
	return true;
}
int main(){
	int x;
	SeqStack mySeqStack(2);
	for(int i=1;i<=5;i++)
	{
	mySeqStack.Push(i);
	}
	mySeqStack.Output();
	mySeqStack.Pop(x);
	mySeqStack.Push(15);
	mySeqStack.Output();
	return 0;
}


