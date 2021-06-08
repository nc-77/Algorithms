#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt;
ll ab,ac,ba,bc,ca,cb; 
void move(char a,char c)
{
  	cnt++;
  	//cout<<a<<"->"<<c<<endl;
  	if(a=='a'&&c=='b') ab++;
  	if(a=='a'&&c=='c') ac++;
  	if(a=='b'&&c=='a') ba++;
  	if(a=='b'&&c=='c') bc++;
  	if(a=='c'&&c=='a') ca++;
  	if(a=='c'&&c=='b') cb++;
}
  
void hanoi(int n,char a,char b,char c)
{
  	
  	if(n==1)
  	move(a,c);
  	else
  	{
  		hanoi(n-1,a,c,b);
  		move(a,c);
  		hanoi(n-1,b,a,c); 
	  }
}
 int main()
 {
 	int n;
 	cin>>n;
 	hanoi(n,'a','b','c');
 	cout<<"A->B:"<<ab<<endl;
	cout<<"A->C:"<<ac<<endl;
	cout<<"B->A:"<<ba<<endl;
	cout<<"B->C:"<<bc<<endl;
	cout<<"C->A:"<<ca<<endl;
	cout<<"C->B:"<<cb<<endl;
	cout<<"SUM:"<<cnt;
  } 
