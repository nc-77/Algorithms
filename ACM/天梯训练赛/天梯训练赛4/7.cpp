#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int sx,h,w;
		cin>>sx>>h>>w;
		if(sx==1)
		{
			if(h<130)
			cout<<"duo chi yu! ";
			else if(h==130)
			cout<<"wan mei! ";
			else
			cout<<"ni li hai! ";
			if(w<27)
			cout<<"duo chi rou!"<<endl;
			else if(w==27)
			cout<<"wan mei!"<<endl;
			else cout<<"shao chi rou!"<<endl;
		}
		else 
		{
			if(h<129)
			cout<<"duo chi yu! ";
			else if(h==129)
			cout<<"wan mei! ";
			else
			cout<<"ni li hai! ";
			if(w<25)
			cout<<"duo chi rou!"<<endl;
			else if(w==25)
			cout<<"wan mei!"<<endl;
			else cout<<"shao chi rou!"<<endl;
		}
	}
}
