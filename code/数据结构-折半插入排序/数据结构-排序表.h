typedef int T;
const int DefaultSize=100;
class Element{
public:
	T key;
	T otherdata;
	bool operator==(Element &x){
		key=x.key;otherdata=x.otherdata;return this;}
	bool operator<=(Element &x){
		return key<=x.key;}
	bool operator>=(Element &x){
		return key>=x.key;}
	bool operator>(Element &x){
		return key>x.key;}
	bool operator<(Element &x){
		return key<x.key;}
};
class dataList{
public:
	dataList(int maxSz=DefaultSize):maxSize(maxSz),currentSize(0){
		Vector=new Element[maxSize];}
	void Swap(Element &x,Element &y){
		Element temp=x;x=y;y=temp;}
	int Length(){return currentSize;}
	int Partition(const int low,const int high);
	Element&operator[](int i){return Vector[i];}
	void createList(int number);
	void disPlay();
private:
	Element *Vector;
	int maxSize;
	int currentSize;
};
