#include<bits/stdc++.h>
using namespace std;
ll f[100];
int main()
{	f[0]=1,f[1]=3,f[2]=5;
	for(int i=3;i<=80;i++)
	f[i]=f[i-2]+f[i-1];
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}
