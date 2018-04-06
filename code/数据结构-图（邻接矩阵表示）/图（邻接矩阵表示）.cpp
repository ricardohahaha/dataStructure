#include"StdAfx.h"
#include<iostream>
using namespace std;
const int DefaultVertices=30;
typedef char T;
typedef int E;
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
class Graphmtx:public Graph{
public:
	Graphmtx(int sz);
	~Graphmtx(){delete[]VerticesList; delete[]Edge;}
	int getVertexPos(T vertex){
		for(int i=0;i<numVertices;i++){
			if(VerticesList[i]==vertex) return i;
		}
		return -1;
	}
	bool GraphmtxEmpty()const{
		if(numEdges==0)return true;
		else return false;
	}
	bool GraphmtxFull()const{
		if(numVertices==maxVertices||numEdges==maxVertices*(maxVertices-1)/2) return true;
		else return false;
	}
	int NumberOfVertices(){return numVertices;}
	int NumberOfEdges(){return numEdges;}
	T getValue(int i){return i>=0&&i<=numVertices?VerticesList[i]:NULL;}
	E getWeight(int v1,int v2){return v1!=-1&&v2!=-1?Edge[v1][v2]:0;}
    int getFirstNeighbor(int v);	
	int getNextNeighbor(int v,int w);
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1,int v2,E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1,int v2);
	void CreateGraphmtx();
	void DisplayGraph();
private:
	int maxVertices;
	int numEdges;
	int numVertices;
	static const E maxWeight=1000;
	T  *VerticesList;
	E * *Edge;
};
Graphmtx::Graphmtx(int sz){
	maxVertices=sz;
	numVertices=0;
	numEdges=0;
	int i,j;
	VerticesList=new T[maxVertices];
	Edge=new E*[maxVertices];
	for(int i=0;i<maxVertices;i++)
    {
	 Edge[i] = new E[maxVertices]; 
	}
	for(i=0;i<maxVertices;i++){
		for(j=0;j<maxVertices;j++)
		{
			if(i==j) Edge[i][j]=0;
			else {Edge[i][j]=maxWeight;}
		}
	}
}
int Graphmtx::getFirstNeighbor(int v){
	if(v!=-1){
		for(int col=0;col<numVertices;col++){
			if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
		}
	}
	return -1;
}
int Graphmtx::getNextNeighbor(int v,int w){
	if(v!=-1&&w!=-1){
		for(int col=w+1;col<numVertices;col++){
			if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
		}
		return -1;
	}
	else return -1;
}
bool Graphmtx::insertVertex(const T& vertex){
	if(numVertices==maxVertices) return false;
	VerticesList[numVertices++]=vertex;
	return true;
}
bool Graphmtx::insertEdge(int v1,int v2,E cost){
	if((v1>-1&&v1<numVertices)&&(v2>-1&&v2<numVertices)&&(Edge[v1][v2]==maxWeight)){
		Edge[v1][v2]=Edge[v2][v1]=cost;
		numEdges++;
		return true;
	}
	else return false;
}
bool Graphmtx::removeVertex(int v){
	if(v<0||v>numVertices) return false;
	if(numVertices==1) return false;
	int i;
	VerticesList[v]=VerticesList[numVertices-1];
	for(i=0;i<numVertices;i++){
		if(Edge[i][v]>0&&Edge[i][v]<maxWeight) numEdges--;
	}
	for(i=0;i<numVertices;i++){
		Edge[i][v]=Edge[i][numVertices-1];
	}
	numVertices--;
	for(i=0;i<numVertices;i++){
		Edge[v][i]=Edge[numVertices][i];
	}
	return true;
}
bool Graphmtx::removeEdge(int v1,int v2){
	if((v1>-1&&v1<numVertices)&&(v2>-1&&v2<numVertices)&&(Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight)){
		Edge[v1][v2]=Edge[v2][v1]=maxWeight;
	    numEdges--;
		return true;
	}
	else return false;
}
void Graphmtx::CreateGraphmtx(){
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
void Graphmtx::DisplayGraph(){
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
void DFS_(Graphmtx &G,int v,bool visited[]);
void DFS(Graphmtx &G,const T &v);
int main(){
	int i,j;
	Graphmtx myGraphmtx(30);
	myGraphmtx.CreateGraphmtx();
	myGraphmtx.DisplayGraph();
	i=myGraphmtx.getVertexPos('0');
	j=myGraphmtx.getVertexPos('1');
	//myGraphmtx.removeEdge(i,j);
	//myGraphmtx.DisplayGraph();
	DFS(myGraphmtx,'A');
	return 0;
}
void DFS_(Graphmtx &G,int v,bool visited[]){
	cout<<G.getValue(v)<<" ";
	visited[v]=true;
	int w=G.getFirstNeighbor(v);
	while(w!=-1){
		if(visited[w]==false)DFS_(G,w,visited);
		w=G.getNextNeighbor(v,w);
	}
}
void DFS(Graphmtx &G,const T &v){
	int i,loc,n=G.NumberOfVertices();
	bool *visited=new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	loc=G.getVertexPos(v);
	DFS_(G,loc,visited);
	delete[]visited;
}





