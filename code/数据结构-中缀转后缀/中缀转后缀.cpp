#include"StdAfx.h"
#include"Õ»-Á´Õ».h"
using namespace std;
void change();
int isp(char);
int icp(char);
void main(){
	change();
}
void change(){
	LinkStack s;
	char ch='#',ch1,op;
	s.Push(ch);cin>>ch;
	while(s.IsEmpty()!=false||ch!='#'){
		if(isdigit(ch)){cout<<ch;cin>>ch;}
		else{
			s.GetTop(ch1);
			if(isp(ch1)<icp(ch))
			{
				s.Push(ch);cin>>ch;
			}
			else if(isp(ch1)>icp(ch))
			{
				s.Pop(op);cout<<op;
			}
			else{
				s.Pop(op);
				if(op=='(') cin>>ch;
			}
		}
	}
}
int isp(char sp){
	switch(sp){
	case'#':return 0;break;
	case'(':return 1;break;
	case'*':return 5;break;
	case'%':return 5;break;
    case'/':return 5;break;
	case'+':return 3;break;
    case'-':return 3;break;
	case')':return 6;break;     
	}
}
int icp(char cp){
	switch(cp){
	case'#':return 0;break;
	case'(':return 6;break;
	case'*':return 4;break;
	case'%':return 4;break;
    case'/':return 4;break;
	case'+':return 2;break;
    case'-':return 2;break;
	case')':return 1;break;     
	}
}
