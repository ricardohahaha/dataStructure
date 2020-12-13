#include"StdAfx.h"
#include<iostream>
using namespace std;
const int DefaultVertices=30;
typedef char T;
typedef int E;
const E maxWeight=1000;
class Graph{
public:
	virtual T getValue(int i)=0;
	virtual E getWeight(int v1,int v2)=0;
	virtual int getFirstNeighbor(int v)=0;
	virtual int getNextNeighbor(int v,int w)=0;
	virtual bool insertVertex(const T& vertex)=0;
	virtual bool insertEdge(int v1,int v2,E cost)=0;
	virtual bool removeVertex(int v)=0;
	virtual bool removeEdge(int v1,int v2)=0;
	virtual int getVertexPos(T vertex)=0;
};
struct Edge{
	int dest;
	E cost;
	Edge *link;
	Edge(){};
	Edge(int num,E weight):dest(num),cost(weight),link(NULL){};
};
struct Vertex{
	T data;
	Edge *head;
};
class Graphlink:public Graph{
public:
	Graphlink(int sz=DefaultVertices);
	~Graphlink();
	T getValue(int v){ return(v>=0&&v<numVertices)?NodeTable[v].data:0;}
	E getWeight(int v1,int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v,int w);
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1,int v2,E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1,int v2);
	int NumberOfVertices(){return numVertices;}
	int NumberOfEdges(){return numEdges;}
	int getVertexPos(T vertex);
	void CreateGraphlink();
	void Graphlink::DisplayGraph();
private:
	Vertex *NodeTable;
	int maxVertices;
	int numEdges;
	int numVertices;
};
void DFS_(Graphlink &G,int v,bool visited[]);
void Graphlink::CreateGraphlink(){
	E weight;
	int i,j,k;
	int v,e;
	T value,value1,value2;
	cout<<"请输入顶点数和边数"<<endl;
	cin>>v>>e;
	cout<<"请依次输入各点的信息"<<endl;
	for(i=0;i<v;i++){
		cin>>value;
		insertVertex(value);
	}
	cout<<"请输入边的两端点和权值"<<endl;
	i=0;
	while(i<e){
		cin>>value1>>value2>>weight;
		j=getVertexPos(value1);
		k=getVertexPos(value2);
		if(j==-1||k==-1)
		{cout<<"边的两端点信息有误，重新输入!"<<endl;}
		else{
			insertEdge(j,k,weight);
			i++;
		}
	}
};
void Graphlink::DisplayGraph(){
	E w;
	T value1,value2;
	int i,j,n,m;
	n=NumberOfVertices();
	m=NumberOfEdges();
	cout<<"图中共有"<<n<<"个顶点,"<<m<<"条边"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			w=getWeight(i,j);
			if(w>0&&w<maxWeight){
				value1=getValue(i);
				value2=getValue(j);
				cout<<"("<<value1<<","<<value2<<","<<w<<")"<<endl;
			}
		}
	}
}
int Graphlink::getVertexPos(T v){
	for(int i=0;i<numVertices;i++){
		if(NodeTable[i].data==v) return i;
	}
	return -1;
}
Graphlink::Graphlink(int sz){
	maxVertices=sz;numVertices=0;numEdges=0;
	NodeTable=new Vertex[maxVertices];
	if(NodeTable==NULL){cout<<"存储分配错误"<<endl;}
	for(int i=0;i<maxVertices;i++)
	{
	   NodeTable[i].head=NULL;
	}
}
Graphlink::~Graphlink(){
	for(int i=0;i<numVertices;i++){
		Edge *p=NodeTable[i].head;
		while(p!=NULL){
			NodeTable[i].head=p->link;
			delete p;
			p=NodeTable[i].head;
		}
	}
	delete[]NodeTable;
};
int Graphlink::getFirstNeighbor(int v){
	if(v!=-1){
		Edge *p=NodeTable[v].head;
		if(p!=NULL) return p->dest;
	}
	return -1;
};
int Graphlink::getNextNeighbor(int v,int w){
	if(v!=-1){
		Edge *p=NodeTable[v].head;
		while(p!=NULL&&p->dest!=w){
			p=p->link;
		}
		if(p!=NULL&&p->link!=NULL){
			return p->link->dest;
		}
	}
	return -1;
}
E Graphlink::getWeight(int v1,int v2){
	if(v1!=-1&&v2!=-1){
		Edge *p=NodeTable[v1].head;
		while(p!=NULL&&p->dest!=v2){
			p=p->link;
		}
		if(p!=NULL) return p->cost;
	}
	return 0;
}
bool Graphlink::insertVertex(const T &vertex){
	if(numVertices==maxVertices) return false;
	NodeTable[numVertices].data=vertex;
	numVertices++;
	return true;
}
bool Graphlink::removeVertex(int v){
	if(numVertices==1||v<0||v>=numVertices) return false;
	Edge *p,*s,*t;
	int k;
	while(NodeTable[v].head!=NULL){
		p=NodeTable[v].head;
		k=p->dest;
		s=NodeTable[k].head;
		t=NULL;
		while(s!=NULL&&s->dest!=v){
			t=s;s=s->link;
		}
		if(s!=NULL){
			if(t==NULL) NodeTable[k].head=s->link;
			else t->link=s->link;
			delete s;
		}
		NodeTable[v].head=p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	NodeTable[v].data=NodeTable[numVertices].data;
	p=NodeTable[v].head=NodeTable[numVertices].head;
	while(p!=NULL){
		s=NodeTable[p->dest].head;
		while(s!=NULL)
		{
			if(s->dest==numVertices){s->dest=v;break;}
			else s=s->link;
		}
	}
	return true;
};
bool Graphlink::insertEdge(int v1,int v2,E weight)
{
	if(v1>=0&&v1<numVertices&&v2>=0&&v2<numVertices){
		Edge *q,*p=NodeTable[v1].head;
		while(p!=NULL&&p->dest!=v2)
		{
			p=p->link;
		}
		if(p!=NULL) return false;
		p=new Edge;
		q=new Edge;
		p->dest=v2;
		p->cost=weight;
		p->link=NodeTable[v1].head;
		NodeTable[v1].head=p;
		q->dest=v1;
		q->cost=weight;
		q->link=NodeTable[v2].head;
		NodeTable[v2].head=q;
		numEdges++;
		return true;
	}
	return false;
};
bool Graphlink::removeEdge(int v1,int v2){
	if(v1!=-1&&v2!=-1){
		Edge *p=NodeTable[v1].head,*q=NULL,*s=p;
		while(p!=NULL&&p->dest!=v2){
			q=p;
			p=p->link;}
		if(p!=NULL){
			if(p==s)NodeTable[v1].head=p->link;
			else q->link=p->link;
			delete p;
		}
		else return false;
		p=NodeTable[v2].head;
		q=NULL,s=p;
		while(p->dest!=v1){
			q=p;
			p=p->link;
		}
		if(p==s) NodeTable[v2].head=p->link;
		else q->link=p->link;
		delete p;
		return true;
	}
	return false;
};
void DFS(Graphlink &G,const T &v){
	int i,loc,n;
	n=G.NumberOfVertices();
	bool *visited=new bool[n];
	for(i=0;i<n;i++)
	{
		visited[i]=false;
	}
	loc=G.getVertexPos(v);
	DFS_(G,loc,visited);
	delete []visited;
};
void DFS_(Graphlink &G,int v,bool visited[]){
	cout<<G.getValue(v)<<" ";
	visited[v]=true;
	int w=G.getFirstNeighbor(v);
	while(w!=-1){
		if(visited[w]==false)DFS_(G,w,visited);
		w=G.getNextNeighbor(v,w);
	}
};
int main(){
	Graphlink G;
	G.CreateGraphlink();
	//G.DisplayGraph();
	DFS(G,'A');
	return 0;
}


	



	


