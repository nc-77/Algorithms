#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double h,w;
		cin>>h>>w;
		w=w/2;
		double bz=(h-100)*0.9;
		
		if(fabs(bz-w)<bz*0.1) cout<<"You are wan mei!"<<endl;
		else if(w>bz) cout<<"You are tai pang le!"<<endl;
		else cout<<"You are tai shou le!"<<endl;
	}
}
