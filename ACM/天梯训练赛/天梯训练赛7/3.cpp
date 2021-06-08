#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{	int s1=0,s2=0,flag=0;
	int a,b;
	cin>>a>>b;
	int x1,x2,y1,y2;
	int k;
	cin>>k;
	while(k--)
	{
		cin>>x1>>x2>>y1>>y2;
		if(x2==y2) continue;
		if(x1+y1==x2) s1++;
		if(x1+y1==y2) s2++;
		if(s1>a) 
		{
			flag=1;
			break;
		}
		if(s2>b) 
		{
			flag=2;
			break;
		}
	}
	if(flag==1) 
	{
		cout<<'A'<<endl;
		cout<<s2;
	}
	else
	{
		cout<<'B'<<endl;
		cout<<s1;
	}
}
